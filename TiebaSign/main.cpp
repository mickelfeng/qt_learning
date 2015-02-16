#include <QCoreApplication>
#include <QTextCodec>
#include <QTimer>
#include <QNetworkConfigurationManager>
#include <conio.h>

#include "Httper.h"
#include "H_IO.h"

void signByHand();
void quirePassword(QString * _out_str);

Httper *myhttp;
QString username;
QString password;

enum passportAccess{
    Continue,
    Ok,
    Exit
}loginFlag=Continue;

using namespace IO;

//>>>>>>>>>>>>>> 入口函数
int main(int argc, char *argv[]){
    QCoreApplication app(argc, argv);
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
    //
    cout<<QString("\n\n>>>>>>> 欢迎使用  【百度贴吧自动签到程序PC版 v2.0.0】  By lipeiyi2006 <<<<<<<\n")<<endl;
    cout<<QString("\t\t【更新记录 v2.0.0 】\n")<<endl;
    cout<<QString("\t\t1.新增结束后再次列出签到结果.\n")<<endl;
    cout<<QString("\t\t2.新增开机自动启动.\n")<<endl;
    cout<<QString("\t\t3.新增自动签到.\n")<<endl;
    cout<<QString("\t\t4.新增自动自动检查网络连接.\n")<<endl;
    cout<<QString("\t\t5.取消结束后再次签到其他ID.\n")<<endl;
    cout<<QString("【特别提醒】在使用过程中所造成的用户和密码等隐私信息的泄露,后果自负.\n")<<endl;
    cout<<QString("确认使用?(y/n). ");  cout.flush();

    QString is_confirm;
    getString(&is_confirm);

    if(is_confirm=="y")
      signByHand();

    cout<<QString("全部签到已完成: 成功: ")<<
          myhttp->success<<QString(" 跳过: ")<<
          myhttp->jump<<QString(" 失败: ")<<
          myhttp->failed<<"\n"<<endl;

    myhttp->getForums();

    delete myhttp; //######## delete
    //system("explorer http://tieba.baidu.com/p/2096132957");

    cout<<endl;
    cout<<QString("请按回车键退出!")<<endl;
    //return app.exec();
    getchar();
    return 0;
}//end of main

//手动签到
void signByHand(){
    cout<<QString("Notice:签到之前,需要提供百度账户的用户名和密码,以便取得喜爱的贴吧列表 :\n")<<endl;

    loginFlag = Continue ;
    while(loginFlag==Continue){
        cout<<QString("△用户名:");cout.flush();
        getString(&username);
        cout<<QString("△密 码:");cout.flush();
        quirePassword(&password);
        cout<<endl;
        cout<<QString("Notice:正在验证用户名和密码...请稍候...\n")<<endl;
        myhttp=new Httper(&username,&password); //######## new
        loginFlag = (myhttp->Login())?Ok:Continue;
    }//end of while

    if(loginFlag==Ok)
        myhttp->autoSign();
}


//请求密码
void quirePassword(QString *_out_str){
    _out_str->clear();
    char t;
    while(true){
        t=_getch();
        if(t=='\r') break;
        if(t=='\b'){
            if(_out_str->isEmpty()) continue;
            *_out_str=_out_str->mid(0,_out_str->length()-1);
            cout<<"\b \b";
            cout.flush();
        }else{
            _out_str->push_back(t);
            cout<<'*';
            cout.flush();
        }//end of if
    }//end of while
    _out_str->simplified();
    _out_str->trimmed();
}
