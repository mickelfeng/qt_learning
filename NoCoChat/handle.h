#ifndef HANDLE_H
#define HANDLE_H
/**
 * 文件名：handle.h
 * 文件功能：定义handle类的相关成员和声明所有成员函数
 * 类的作用：所有界面的业务操作函数集合
 * 类的继承：QObejct
 * 作者：NoCo_jancojie
 */

#include <QObject>
#include "tcpnet.h"
#include "config.h"
#include <QRegExp>
#include <QMap>
#include <QStringList>
#include <QDebug>
#include <QList>
#include <QMessageBox>
#include "QMainWindow"
class Handle : public QObject
{
    Q_OBJECT
public:
    explicit Handle(QObject *parent = 0);
//    设置主窗口
    void setWindow(QMainWindow *m);
//    信息提取
    QString  changeMessage(QString message);
//    单协议处理
    QMap<QString, QString> getCommand(QString command);
//    多协议处理
    QList<QMap<QString,QString> >getCommand(QString command,QString head);
//    注册处理
    bool registered(QString userId,QString userName,QString pwd);
//    创建聊天室
    bool creatTalkroom(QString userId, QString talkroomid, QString talkroomname);
//    登录处理
    QString signIn(QString userId, QString pwd,int port);
//    获取用户列表
     QList<QMap<QString, QString> > getUserList(QString userId);
//    获取聊天室列表
     QList<QMap<QString,QString> >getRoomList();
//    获取聊天室列表
     QList<QMap<QString,QString> >getRoomList(QString roomId,QString roomName="_empty_");
//    获取个人聊天室列表
     QList<QMap<QString,QString> >getMyRoomList(QString userid);
//    添加好友
    QMap<QString,QString> addFriend(QString userId, QString adduserid);
//   创建聊天室
    QMap<QString,QString> creatRoom(QString userId, QString roomId,QString roomName);
//    获取所有好友列表
    QList<QMap<QString,QString> >getFriendList(QString userid);
//    获取聊天室成员列表
     QList<QMap<QString,QString> >getRoomFriendList(QString userid,QString roomid);
//     加入聊天室
    QMap<QString,QString> addRoom(QString userId, QString roomId);
//    添加好友进入聊天室
    int requestFriendToRoom(QString friendId,QString userId,QString roomName, QString roomId);
//    下线
    void lamdownline(QString userId);
//    离线好友申请信息的添加
    void reactionCacheRequest(QString userId);
//    获取邀请进群离线信息
    void reactionCacheRoomRequest(QString userId);


signals:

public slots:

private:

protected:
//    tcp对象
    TcpNet tcp;
//    配置文件对象
    Config config;
    QString ip;
    int port;
    QMainWindow *window;

};

#endif // HANDLE_H
