#include "Httper.h"
#include <QCoreApplication>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QRegExp>
#include <QtScript/QScriptEngine>
#include <QtScript/QScriptValue>
#include <QtScript/QScriptValueIterator>
#include <QFile>
#include <QTimer>
using namespace IO;

Httper::Httper(const QString *un, const QString *pw)
    :success(0),jump(0),failed(0){
    m_un=*un;
    m_pw=*pw;
}

//查询是不是需要验证码
bool Httper::needVcode(QString *_out_vcodestr){
    QNetworkRequest req("http://passport.baidu.com/v2/api/?logincheck&callback=bdPass.api.login._needCodestringCheckCallback&username="+m_un);
    QNetworkReply *rtn = m_ntManager->get(req);
    QEventLoop eventLoop;
        QObject::connect(m_ntManager,SIGNAL(finished(QNetworkReply*)),&eventLoop,SLOT(quit()));
    eventLoop.exec();

    QString rep_str(rtn->readAll());

    rep_str.remove("bdPass.api.login._needCodestringCheckCallback(");
    rep_str.remove(")");
    rep_str="["+rep_str+"]";

    //qDebug()<<rep_str;

    QScriptValue sc;
    QScriptEngine engine;
    sc=engine.evaluate(rep_str);
    QScriptValueIterator it(sc);
    it.next();

    QString code_str = it.value().property("codestring").toString();

    //qDebug()<<code_str;

    if(code_str.length()>30){
        *_out_vcodestr = code_str;
        return true;
    }
    return false;
}

//登录函数
bool Httper::Login(){
    QString _token = getToken();//important
    QString _vcodestr;
    if(needVcode(&_vcodestr)){
        QString _param("http://passport.baidu.com/cgi-bin/genimage?"+_vcodestr);

        QNetworkRequest req(_param);
        QNetworkReply *rtn = m_ntManager->get(req);
        QEventLoop eventLoop;
            QObject::connect(m_ntManager,SIGNAL(finished(QNetworkReply*)),&eventLoop,SLOT(quit()));
        eventLoop.exec();

        QFile file("vcode.jpg");
        if(file.open(QIODevice::WriteOnly))
        {
            file.write(rtn->readAll());
            file.flush();
            file.close();
        }

        system("vcode.jpg");

        cout<<QString("请输入图片所示验证码: ");cout.flush();
        char _vcode[4];
        cin>>_vcode;
        m_vcode=QString(_vcode);
    }

    QString data_str("username="+m_un+"&password="+m_pw+ "&codestring="+ _vcodestr +"&verifycode="+ m_vcode +"&token=" +_token+"&tpl=mn&staticpage=http://www.baidu.com/cache/user/html/jump.html&callback=parent.bdPass.api.login._postCallback&isPhone=0&charset=utf-8&loginType=1&ppui_logintime=47078&mem_pass=on");

    QByteArray data;
    data.append(data_str.toStdString().c_str());

    int contentLength = data.length();
    QNetworkRequest req;
    req.setUrl(QUrl("http://passport.baidu.com/v2/api/?login"));
    req.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    req.setHeader(QNetworkRequest::ContentLengthHeader,contentLength);
    QNetworkReply *rtn = m_ntManager->post(req,data);

    QEventLoop eventLoop;
        QObject::connect(m_ntManager,SIGNAL(finished(QNetworkReply*)),&eventLoop,SLOT(quit()));
    eventLoop.exec();

    QString rep_str(rtn->readAll());

    //qDebug()<<rep_str<<endl;

    QRegExp ex("error=0");

    m_islogin = (ex.indexIn(rep_str)!=-1)?true:false;

    if(m_islogin){
        cout<<QString("Notice:用户名和密码正确!\n")<<endl;
    }else{
        cout<<QString("Notice:用户名或密码错误!请重新输入!\n")<<endl;
    }

    return m_islogin;
}

//获取验证令牌
QString Httper::getToken(){
    m_ntManager = new QNetworkAccessManager;
    QNetworkRequest req;
    req.setUrl(QUrl("http://passport.baidu.com/v2/api/?getapi&class=login&tpl=mn&tangram=true"));
    QNetworkReply *rep=m_ntManager->get(req);

    QEventLoop eventLoop;
    QObject::connect(m_ntManager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    eventLoop.exec();       //block until finish

    //qDebug()<<rep->rawHeaderPairs().at(0);
    rep=m_ntManager->get(req);
    //qDebug()<< m_ntManager->cookieJar()->cookiesForUrl(req.url());
    QEventLoop eventLoop_twice;
    QObject::connect(m_ntManager, SIGNAL(finished(QNetworkReply*)), &eventLoop_twice, SLOT(quit()));
    eventLoop.exec();       //block until finish

    QString _rep_str(rep->readAll());
    QString _token="";
    QRegExp regx("login_token='([a-zA-Z0-9]+)'");
    if(_rep_str.indexOf(regx)>=0)
        _token = regx.cap(1);

    return _token;
}

QString Httper::getTbs(){
    QNetworkRequest req;
    req.setUrl(QUrl("http://tieba.baidu.com/dc/common/tbs"));
    QNetworkReply *rep= m_ntManager->get(req);

    QEventLoop eventLoop;
    QObject::connect(m_ntManager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    eventLoop.exec();//block until finish

    //qDebug()<<rep->readAll();
    QString res_str(rep->readAll());
    res_str="("+res_str+")";

    QScriptEngine engine;
    QScriptValue sc=engine.evaluate(res_str);

     QString tbs;
     tbs=sc.property("tbs").toString();

    return tbs;
}

int Httper::Sign(const QString &kw){
    QNetworkRequest req;
    req.setUrl(QUrl("http://tieba.baidu.com/sign/add"));
    req.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    QString _tbs =getTbs();

    QByteArray data = QString("ie=utf-8&kw="+ kw +"&tbs="+ _tbs).toAscii();

    QNetworkReply *rep=    m_ntManager->post(req,data);

    QEventLoop eventLoop;
    QObject::connect(m_ntManager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    eventLoop.exec();       //block until finish

    QString res_str(rep->readAll());

    res_str="["+res_str+"]";

    QScriptValue sc;
    QScriptEngine engine;
    sc=engine.evaluate(res_str);
    QScriptValueIterator it(sc);
    it.next();

    //qDebug()<<res_str;
    return it.value().property("no").toInt32();
}

void Httper::translateReturn(const int *_in_no,const QString* _in_item){
    switch (*_in_no) {
        case 0:
            cout<<QString("Notice:")<<*_in_item<<QString("吧\t\t签到成功!")<<endl;
            success++;
            break;
        case 1002:
            cout<<QString("Notice:")<<*_in_item<<QString("吧\t\t不能签到!已跳过.")<<endl;
            jump++;
            break;
        case 1007:
            cout<<QString("Notice:签到太频繁了点，休息片刻再来吧")<<endl;
            failed++;
            break;
        default:
            cout<<QString("Notice:")<<*_in_item<<QString("签到失败! 错误代码:")<<*_in_no<<endl;
            failed++;
            break;
    }//end of switch
}

void Httper::getUID(){
    QNetworkRequest req;
    req.setUrl(QUrl("http://tieba.baidu.com/f/user/json_userinfo"));

    QNetworkReply *rep= m_ntManager->get(req);

    QEventLoop eventLoop;
    QObject::connect(m_ntManager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    eventLoop.exec();       //block until finish
    QString res_str(rep->readAll());

    //qDebug()<<res_str;

    QRegExp ex("user_portrait\":\"([a-zA-Z0-9]+)");

    if(res_str.indexOf(ex))
        m_uid= ex.cap(1);
    else
        m_uid.clear();
}

void Httper::getForums(){
    cout<<QString("Notice:正在获取我喜爱的贴吧...请稍后...\n")<<endl;
    getUID();

    //qDebug()<<"###uid:"<<m_uid;

    QNetworkRequest req(QUrl("http://tieba.baidu.com/home/main?id="+m_uid));
    QNetworkReply *rep=  m_ntManager->get(req);

    QEventLoop eventLoop;
    QObject::connect(m_ntManager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    eventLoop.exec();       //block until finish

    QString res_str(rep->readAll());

    //cout<<res_str<<endl;

    QRegExp ex;
    ex.setPattern(QString("forumArr\":.*, \"ihome"));
    ex.setCaseSensitivity(Qt::CaseSensitive);
    ex.setPatternSyntax(QRegExp::RegExp);
    ex.setMinimal(true);
    
    ex.indexIn(res_str);
    QString pre_str = ex.cap(0);
    pre_str.remove("forumArr\":");
    pre_str.remove(", \"ihome");
    //pre_str.remove(QChar(';'));
    
    QScriptValue sc;
    QScriptEngine engine;
    sc=engine.evaluate(pre_str);
    QScriptValueIterator it(sc);


    if(it.hasNext()) cout<<QString("经  验\t等级\t已签到\t已拉黑\t贴吧名")<<endl;
    //bool flag=1;
    QString forum_name,score_left,level_id,is_sign,is_black;
    QScriptValue item;
    while(it.hasNext()){
        it.next();
        
        item=it.value();
        
        forum_name=item.property("forum_name").toString();
        score_left=item.property("score_left").toString();
        level_id=item.property("level_id").toString();
        is_sign=item.property("is_sign").toString();
        is_black=item.property("is_black").toString();
        //
        cout<<score_left<<"\t";
        cout<<level_id<<"\t";

        if(is_sign=="1")
            cout<<QString("是\t");
        else
            cout<<"  \t";

        if(is_black=="1")
            cout<<QString("是\t");
        else
            cout<<"  \t";

        cout<<forum_name;
        cout<<endl;

        if(is_black !="1" &&is_sign!="1" && !forum_name.isEmpty() ) m_forumLike.append(forum_name);
    }//end of while
    cout<<QString("经  验\t等级\t已签到\t已拉黑\t贴吧名\n")<<endl;
}

void Httper::autoSign(){
    if(!m_islogin) Login();
    if(m_islogin){

        getForums();

        cout<<QString("Notice:正在签到中...请勿关闭程序...")<<endl;
        cout<<QString("Notice:程序将每隔3秒进行签到...请耐心等待\n")<<endl;

        foreach (QString item, m_forumLike) {
            int re_code=Sign(item);
            translateReturn(&re_code,&item);
            QEventLoop eventloop;
            QTimer::singleShot(3000,&eventloop,SLOT(quit()));
            eventloop.exec();
        }//end of foreach
    }

}
