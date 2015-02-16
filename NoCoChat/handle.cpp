/**
 * 文件名：handle.cpp
 * 文件功能：定义handle类的所有函数
 * 类的作用：所有界面的业务操作函数集合
 * 类的继承：QObejct
 * 作者：NoCo_jancojie
 */
#include "handle.h"

Handle::Handle(QObject *parent) :
    QObject(parent)
{
//    从配置文件中读取服务器的ip
    ip=config.getValue("ip");
//    从配置文件中读取服务器的端口
    port=config.getValue("port").toInt();
    qDebug()<<port<<ip;
}
/**
 * @brief 信息处理
 * @param message 服务器返回的源信息
 * 协议例子[length=32]<loginuser><userid:>用户名<name:>名称<password:>密码
 * @return 返回处理后的信息（清楚相应的标记头保留信息源）
 */
QString Handle::changeMessage(QString message)
{

//    正则规范:提取[length=15]中的15
    QString pattern="(?:\\[length=)(\\d+)(?:\\])";
//    使用正则规范创建正则表达式对象
    QRegExp reg(pattern);
//    使用字符串对象中的分割函数，并使用正则对象进行分割，0为分割前 1为分割后
    QStringList list=message.split(reg);
//    返回相应的信息
    if(list.size()>1){
        return list[1];
    }else
    {
        return "";
    }


}
/**
 * @brief 单协议信息提取（提取协议中相关信息并保存）
 * @param command 经过处理的信息
 * @return 一个key value集合对<信息名,信息>
 * 返回信息使用方法 QMap map=return 信息=map[信息名]
 * API使用规范:key=command 返回该命令的类别 入login、register等
 */
QMap<QString, QString> Handle::getCommand(QString command)
{
//    正则规范：提取<TYPE：>信息 中的TYPE和信息
    QString pattern="(?:<)([a-zA-Z0-9_\\u4e00-\\u9fa5\\w]+)(?::>)([a-zA-Z0-9\-\/_.=:!?@#$%^&;*)(;'| \u4e00-\u9fa5\\w]+)";
//  QString message="[length=32]<loginuser><userid:>用户名<name:>名称<password:>密码";

//        使用正则规范创建正则表达式对象
    QRegExp reg(pattern);
//    定义一个标志位，用于判断是否已到达字符串的末尾
    int i=0;
//    创建QMap对象保存查找后的信息
    QMap<QString,QString> map;
//    定义循环，重复查找，直到字符串结束
    while(true){
//        查找符合正则规范的字符串，并返回是否查找成功 -1为不成功
        i=command.indexOf(reg,i+1);
//        当返回的标志位为-1，则跳出循环
        if(i==-1)
        {
            break;
        }
//        把查找到的key和value放进map<key,value>
        map.insert(reg.cap(1),reg.cap(2));
    }
    QString pattern_1 ="(?:<)([a-zA-Z0-9_\u4e00-\u9fa5\\w]+)(?:>)";
    QRegExp reg_1(pattern_1);
    command.indexOf(reg_1);
    map.insert("command",reg_1.cap(1));
//    返回结果集
    return map;

}
/**
 * @brief 多协议处理函数
 * @param command 多命令杂合
 * @param head 第一个属性 例如：user（无需冒号）
 * @return 一条指令为一个QMap 所有指令为一个QList
 * 返回信息使用方法  QList<QString,QString> >=return QMap map QMap map= 信息=map[信息名]
 */
QList<QMap<QString,QString> > Handle::getCommand(QString command, QString head)
{
    QString pattern ="(?:<"+head+":>)";
    QRegExp reg(pattern);
    QStringList commands=command.split(reg);
    QList<QMap<QString,QString> >result;
    for(int i=1;i<commands.size();i++)
    {
        commands[i]=commands[0]+"<"+head+":>"+commands[i];
        result.push_back(getCommand(commands[i]));
    }
    return result;
}
/**
 * @brief 注册处理函数（用于进行注册操作业务处理，并返回处理结果）
 * @param userId 用户名的id 唯一标示不可变
 * @param userName 用户的昵称
 * @param pwd 用的密码
 * @return 返回是否注册成功 true注册成功 false 注册不成功(用户名被占用等原因)
 * API调用规范：传入的所有参数应该已做编码处理(UTF-8)，函数不做任何编码处理，也不做任何的安全性处理。
 */
bool Handle::registered(QString userId, QString userName, QString pwd)
{
//    拼接服务器请求协议
    QString command="<loginuser><userid:>"+userId+"<name:>"+userName+"<password:>"+pwd;
//    计算协议长度，添加协议头
    command="[length="+QString::number(command.size())+"]"+command;
//    连接服务器
   if(tcp.tcpconnect(ip,port))
   {
//    发送协议
    tcp.send(command);
//    获取服务器返回的协议，并进行相关处理，取得结果集
    QMap<QString,QString>result=getCommand(changeMessage(tcp.read()));

//    若返回的type字段值为1则注册成功，否则注册失败
    if(result["type"]=="1")
    {
        return true;
    }
    else
    {
        return false;
    }
   }else{
       return false;
   }
}
/**
 * @brief 创建聊天室处理函数（用于进行创建聊天室操作业务处理，并返回处理结果）
 * @param userId 用户名的id 群主的id
 * @param talkroomid 聊天室的id
 * @param talkroomname 聊天室的名字
 * @return 返回是否创建成功 true创建成功 false 创建不成功(用户名被占用等原因)
 * API调用规范：传入的所有参数应该已做编码处理(UTF-8)，函数不做任何编码处理，也不做任何的安全性处理。
 */
bool Handle::creatTalkroom(QString userId, QString talkroomid, QString talkroomname)
{
//    拼接服务器请求协议
    QString command="<login talkroom><userid:>"+userId+"<talkroomid:>"+talkroomid+"<talkroomname:>"+talkroomname;
//    计算协议长度，添加协议头
    command="[length="+QString::number(command.size())+"]"+command;
//    连接服务器
    if(tcp.tcpconnect(ip,port))
    {
//    发送协议
    tcp.send(command);
//    获取服务器返回的协议，并进行相关处理，取得结果集
    QMap<QString,QString> result=getCommand(changeMessage(tcp.read()));
//    若返回的type字段值为1则注册成功，否则注册失败
    if(result["type"]=="1")
    {
        return true;
    }
    else
    {
        return false;
    }
    }else{
        return false;
    }
}
/**
 * @brief 登录处理函数（用于进行登录操作业务处理，并返回处理结果）
 * @param userId 用户名的id 群主的id
 * @param pwd 用户密码
 * @param port(int) 程序开始时绑定的端口
 * @return 返回是否登录成功 username 登录成功 1 用户名或密码错误 2已有用户登录 3未知错误
 * API调用规范：传入的所有参数应该已做编码处理(UTF-8)，函数不做任何编码处理，也不做任何的安全性处理。
 */
QString Handle::signIn(QString userId, QString pwd,int port)
{
//    拼接服务器请求协议
    QString command="<signin><userid:>"+userId+"<password:>"+pwd+"<ip:>"+tcp.getLocalAddress()+"<port:>"+QString::number(port);
//    计算协议长度，添加协议头
    command="[length="+QString::number(command.size())+"]"+command;
//    连接服务器
    if(tcp.tcpconnect(ip,this->port)){
//    发送协议
    tcp.send(command);
//    获取服务器返回的协议，并进行相关处理，取得结果集
    QMap<QString,QString> result=getCommand(changeMessage(tcp.read()));
    qDebug()<<result;
//    若返回的type字段值为1则注册成功，否则注册失败
//    遍历map
        if(result["command"]=="signinresultunsuccessful")
        {

            return result["type"];
        }else{

            return result["username"];
        }
    }else{
        return "3";
    }
}
/**
 * @brief 获取所有用户列表(用于添加好友)
 * @param userId 当前用户的id
 * @return 用户列表的集合
 * API调用规范：返回的是一个QList<QMap<QString,QString>>对象。
 * QMap key表：<userid>用户名<name>名字<sex>性别<department>系别<major>专业
 */
QList<QMap<QString,QString> > Handle::getUserList(QString userId)
{
//    拼接服务器请求协议
    QList<QMap<QString,QString> > result;
    QString command="<getaddlist><userid:>"+userId;
//     计算协议长度，添加协议头
    command="[length="+QString::number(command.size())+"]"+command;
//    连接服务器
    if(tcp.tcpconnect(ip,port))
    {
//    发送协议
        tcp.send(command);
//    获取服务器返回的协议，并进行相关处理，取得结果集
        result =getCommand(changeMessage(tcp.read()),"userid");

    }
      return result;
}
/**
 * @brief 好友添加函数
 * @param userId 当前登录用户id
 * @param adduserid 添加好友的用户id
 * @return QMap<QString,QString>
 * 结构：
 * 好友在线：<adduserfriendback><userId>请求方id<fromuserid>被请求方id<type>1(同意)或者<type>0(不同意)<ip:>ip<port>端口
 * 还有不在线：<unok><userId:>"+fuserId+"<name:>"+fname;请求< getfriendscache:><userid:>用户Id
 * API提示：请使用QMap key="command" 判断返回的命令集
 */
QMap<QString,QString> Handle::addFriend(QString userId,QString adduserid)
{
    //    拼接服务器请求协议
   QMap<QString,QString> result;
        QString command="<adduserfriend><userid:>"+userId+"<fromuserid:>"+adduserid;
    //     计算协议长度，添加协议头
        command="[length="+QString::number(command.size())+"]"+command;
    //    连接服务器
        if(tcp.tcpconnect(ip,port))
        {
            //    发送协议
            tcp.send(command);
            //    获取服务器返回的协议，并进行相关处理，取得结果集
           result=getCommand(changeMessage(tcp.read()));

        }
        return result;
}
/**
 * @brief 获取好友列表
 * @param userid 登录的用户名
 * @return QList集合，结构如下：
 * QList list list[i]是一个好友 内部为QMap QMap的内部结构为：
 * <fuserId>用户名，<fname>名称<extraName>备注<sname>好友分组名<ip>(_empty_)<port>(0)
 * ip 为(_empty_)和port为(0)时代表好友不在线 括号是必须项
 */
QList<QMap<QString,QString> >Handle::getFriendList(QString userid)
{
            //    拼接服务器请求协议
    QList<QMap<QString,QString> > result;
                QString command="<getmyuserfriend><fromuserid:>"+userid;
            //     计算协议长度，添加协议头
                command="[length="+QString::number(command.size())+"]"+command;
            //    连接服务器
                if(tcp.tcpconnect(ip,port))
                {
                    //    发送协议
                    tcp.send(command);
                    //    获取服务器返回的协议，并进行相关处理，取得结果集
                    result =getCommand(changeMessage(tcp.read()),"fuserId");

                }
                return result;
}
/**
 * @brief 获取所有聊天室列表
 * @return QList集合，结构如下：
 * QList list list[i]是一个聊天室 内部为QMap QMap的内部结构为：
 * <talkroomid:>聊天室ID<talkroomname:>聊天室名
 */
QList<QMap<QString,QString> >Handle::getRoomList()
{
            //    拼接服务器请求协议
                QList<QMap<QString,QString> > result;
                QString command="<findtalkroom><talkroomid:>_empty_<talkroomname:>_empty_";
            //     计算协议长度，添加协议头
                command="[length="+QString::number(command.size())+"]"+command;
            //    连接服务器
                if(tcp.tcpconnect(ip,port))
                {
                    //    发送协议
                    tcp.send(command);
                    //    获取服务器返回的协议，并进行相关处理，取得结果集
                    result =getCommand(changeMessage(tcp.read()),"talkroomid");

                }
                return result;
}
/**
 * @brief 获取所有聊天室列表
 * @param roomId 聊天室id
 * @param roomName 聊天室名字
 * @return QList集合，结构如下：
 * QList list list[i]是一个聊天室 内部为QMap QMap的内部结构为：
 * <talkroomid:>聊天室ID<talkroomname:>聊天室名
 */
QList<QMap<QString,QString> >Handle::getRoomList(QString roomId, QString roomName)
{
            //    拼接服务器请求协议
                QList<QMap<QString,QString> > result;
                QString command="<findtalkroom><talkroomid:>"+roomId+"<talkroomname:>"+roomName;
            //     计算协议长度，添加协议头
                command="[length="+QString::number(command.size())+"]"+command;
            //    连接服务器
                if(tcp.tcpconnect(ip,port))
                {
                    //    发送协议
                    tcp.send(command);
                    //    获取服务器返回的协议，并进行相关处理，取得结果集
                    result =getCommand(changeMessage(tcp.read()),"talkroomid");

                }
                return result;
}
/**
 * @brief 获取个人聊天室列表
 * @param userid 登录的用户名
 * @return QList集合，结构如下：
 * QList list list[i]是一个聊天室 内部为QMap QMap的内部结构为：
 * <talkroomid:>聊天室ID<talkroomname:>聊天室名
 */
QList<QMap<QString,QString> >Handle::getMyRoomList(QString userid)
{
            //    拼接服务器请求协议
    QList<QMap<QString,QString> > result;
                QString command="<getmytalkroom><userid:>"+userid;
            //     计算协议长度，添加协议头
                command="[length="+QString::number(command.size())+"]"+command;
            //    连接服务器
                if(tcp.tcpconnect(ip,port))
                {
                    //    发送协议
                    tcp.send(command);
                    //    获取服务器返回的协议，并进行相关处理，取得结果集
                    result =getCommand(changeMessage(tcp.read()),"talkroomid");

                }
                return result;
}
/**
 * @brief 获取聊天室成员列表
 * @param userid 登录的用户名
 * @param roomid 聊天室的id
 * @return QList集合，结构如下：
 * QList list list[i]是一个成员 内部为QMap QMap的内部结构为：
 * <talkroomid:>聊天室id <talkroomname:>聊天室名<userId:> 用户名<name:>名称<ip:>_empty_<port:>0
 * ip 为_empty_和port为0是代表成员不在线
 */
QList<QMap<QString,QString> >Handle::getRoomFriendList(QString userid,QString roomid)
{
            //    拼接服务器请求协议
            QList<QMap<QString,QString> > result;
                QString command="<getmytalkroomuser><userid:>"+userid+"<talkroomid:>"+roomid;
            //     计算协议长度，添加协议头
                command="[length="+QString::number(command.size())+"]"+command;
            //    连接服务器
                if(tcp.tcpconnect(ip,port))
                {
                    //    发送协议
                    tcp.send(command);
                    //    获取服务器返回的协议，并进行相关处理，取得结果集
                     result =getCommand(changeMessage(tcp.read()),"talkroomid");

                }
                qDebug()<<result;
                return result;
    }
/**
 * @brief 聊天室创建函数
 * @param userId 当前登录用户id
 * @param roomId 创建的聊天室id
 * @param roomName 创建的聊天室名字
 * @return QMap<QString,QString>
 * 结构：
 * <type:>1<talkroomid:>聊天室ID<talkroomname:>聊天室名
 * <type:>0<talkroomname:>聊天室名
 * 1代表创建成功 0代表创建失败(不成功原因为：聊天室id重复)
 * APi使用提示：不能保证QMap一定带有type，请使用者先判断QMap的大小
 */
QMap<QString,QString> Handle::creatRoom(QString userId, QString roomId,QString roomName)
{
    //    拼接服务器请求协议
     QMap<QString,QString>  result;
        QString command="<logintalkroom><userid:>"+userId+"<talkroomid:>"+roomId+"<talkroomname:>"+roomName;
    //     计算协议长度，添加协议头
        command="[length="+QString::number(command.size())+"]"+command;
    //    连接服务器
        if(tcp.tcpconnect(ip,port))
        {
            //    发送协议
            tcp.send(command);
            //    获取服务器返回的协议，并进行相关处理，取得结果集
            result=getCommand(changeMessage(tcp.read()));

        }
        return result;
}
/**
 * @brief 加入聊天室函数
 * @param userId 当前登录用户id
 * @param roomId 需要进入的群id
 * @return QMap<QString,QString>
 * 结构：
 * <talkroomid:>群id<talkroomname:>群名称<fromuserid:>申请者id<type:>0拒绝1同意
 * APi使用提示：不能保证QMap一定带有type，请使用者先判断QMap的大小
 */
QMap<QString,QString> Handle::addRoom(QString userId, QString roomId)
{
    //    拼接服务器请求协议
    QMap<QString,QString>  result;
        QString command="<addtalkroominvite><userid:>"+userId+"<talkroomid:>"+roomId;
    //     计算协议长度，添加协议头
        command="[length="+QString::number(command.size())+"]"+command;
    //    连接服务器
        if (tcp.tcpconnect(ip,port))
    //    发送协议
        {
            tcp.send(command);
            //    获取服务器返回的协议，并进行相关处理，取得结果集
            result=getCommand(changeMessage(tcp.read()));

        }
        return result;
}
/**
 * @brief 邀请某人加入聊天室
 * @param roomName 聊天室名字
 * @param roomId 聊天室id
 * @param friendId 被邀请人的id
 * @param userId 登录用户id
 * @return type: 0拒绝进入 1成功加入 2对方不在线 3未知错误,建议重试
 * 结构：
 * <addtalkroomfriendback><fromid:>id（B）<fromname:>名称(B) <type:>1(同意) <ip:>ip<port:>port<talkroomid:>聊天室ID 或者<type:>0(不同意) <talkroomid:>聊天室ID
 * APi使用提示：不能保证QMap一定带有type，请使用者先判断QMap的大小
 */
int Handle::requestFriendToRoom(QString friendId,QString userId,QString roomName, QString roomId)
{
    //    拼接服务器请求协议
        QString command="<addtalkroomfriend><userid:>"+friendId+"<fromid:>"+userId+"<talkroomid:>"+roomId+"<talkroomname:>"+roomName;
    //     计算协议长度，添加协议头
        command="[length="+QString::number(command.size())+"]"+command;
    //    连接服务器
        if (tcp.tcpconnect(ip,port))
        {
            //    发送协议
            tcp.send(command);
            //    获取服务器返回的协议，并进行相关处理，取得结果集
            QMap<QString,QString>result=getCommand(changeMessage(tcp.read()));
            QMap<QString,QString>::iterator it;
            for(it=result.begin();it!=result.end();++it)
            {
                if(it.key()=="userId")
                {
                    return 2;
                }
                else
                {
                    if(it.key()=="type"&&it.value()=="0")
                    {
                        return 0;
                    }
                    else if(it.key()=="type"&&it.value()=="1")
                    {
                        return 1;
                    }
                }
            }
            return 3;
        }else{
            return 3;
        }
}
/**
 * @brief 用户下线
 * @param userId 登录用户id
 */
void Handle::lamdownline(QString userId)
{

            //    拼接服务器请求协议
                QString command="<Iamdownline><fromuserid:>"+userId;
            //     计算协议长度，添加协议头
                command="[length="+QString::number(command.size())+"]"+command;
            //    连接服务器
                if (tcp.tcpconnect(ip,port))
                {
                    //    发送协议
                    tcp.send(command);
                    //    获取服务器返回的协议，并进行相关处理，取得结果集
                    tcp.read();
                }
}
/**
 * @brief 回应离线的好友添加信息
 * @param userId 登录的好友号
 * @return
 * 返回的命令：
 * <fromuserid:>用户名(A)<fromname:>名称(A)<ip:>ip<port:>port<type>是否同意加好友
 */
void Handle::reactionCacheRequest(QString userId)
{
        QMap<QString,QString>  result;
//     拼接服务器请求协议
         QString command="<getfriendscache><userid:>"+userId;
//    计算协议长度，添加协议头
         command="[length="+QString::number(command.size())+"]"+command;
//    连接服务器
         if (tcp.tcpconnect(ip,port))
         {
             //    发送协议
             tcp.send(command);
             //    获取服务器返回的协议，并进行相关处理，取得结果集
             result=getCommand(changeMessage(tcp.read()));
             qDebug()<<result;
             if(result.contains("command")){
                 if(result["command"]=="addyou")
                 {
                     QString text="用户："+result["fromname"]+"申请添加你为好友,请问是否同意？";
                     QString command_1="";
                     if(QMessageBox::question(window,"好友申请",text,QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
                     {
                         command_1="<adduserfriendback><userId:>"+result["fromuserid"]+"<fromuserid:>"+userId+"<type:>1";
                         result.insert("type","1");
                     }else{
                         command_1="<adduserfriendback><userId:>"+result["fromuserid"]+"<fromuserid:>"+userId+"<type:>0";
                         result.insert("type","0");
                     }
                     if(tcp.tcpconnect(ip,port)){
                         tcp.send(command_1);
                         tcp.read();
                     }
                 }
             }

         }
}
/**
 * @brief 获取邀请进群信息
 * @param userId 登录的好友号
 * @return
 * 返回的命令：
 */
void Handle::reactionCacheRoomRequest(QString userId)
{
    QMap<QString,QString>  result;
//     拼接服务器请求协议
     QString command="<gettalkroomfriendscache><userid:>"+userId;
//    计算协议长度，添加协议头
     command="[length="+QString::number(command.size())+"]"+command;
//    连接服务器
     if (tcp.tcpconnect(ip,port))
     {
         //    发送协议
         tcp.send(command);
         //    获取服务器返回的协议，并进行相关处理，取得结果集
         result=getCommand(changeMessage(tcp.read()));
         if(result.contains("command")){
             if(result["command"]=="addtalkroomfriendyou")
             {
                 QString text="用户："+result["fromname"]+"("+result["fromid"]+")"+"邀请你加入"+result["talkroomname"]+"("+result["talkroomid"]+")聊天室"+",请问是否同意？";
                 QString type="0";
                 if(QMessageBox::question(window,"好友申请",text,QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
                 {
                     type="1";
                 }else{
                     type="0";
                 }
                 if(tcp.tcpconnect(ip,port)){
                     QString command_1="<addtalkroomfriendback><userid:>"+result["fromid"]+
                             "<fromuserid:>"+userId+"<type:>"+type+"<talkroomid:>"+result["talkroomid"];
                     tcp.send(command_1);
                     tcp.read();
                 }
             }
         }

     }
}
void Handle::setWindow(QMainWindow *m)
{
    this->window=m;
}
