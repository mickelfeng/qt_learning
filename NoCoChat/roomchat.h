#ifndef ROOMCHAT_H
#define ROOMCHAT_H

#include <QDialog>
#include <QSplitter>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>
#include <QResizeEvent>
#include <QFont>
#include <QFrame>
#include <QDateTime>
#include "udpnet.h"
#include <QFontDialog>
#include <QFile>
#include <QTextStream>
#include <QList>
#include <QMap>
#include <QTableWidget>
#include <QHeaderView>

class RoomChat : public QDialog
{
    Q_OBJECT
public:
    explicit RoomChat(QWidget *parent = 0);
    void init() ;   // 对象初始函数
    void setComponent() ;   // 将各部件布局到窗口中
    void setSize() ;    // 设置窗口各部件大小
    void sendInfo() ;
    void resizeEvent(QResizeEvent *);
    void setConnect() ;
    void setUdp(UDPNet *u);
    void message(QString head, QString msg);
    void setRoomName(QString rn);
    void setRoomId(QString id);
    void setRoomFriendList(QList<QMap<QString,QString> >list);
    void setUserName(QString name) ;    // 设置用户昵称
    void setUserId(QString id); // 设置用户帐号(ID)
    void setFriendBox();
    void creatfriendlist();
private:
    QString roomid;
    QString roomname;
    UDPNet *udp;
    QList<QMap<QString,QString> >friendlist;//群友列表
    QSplitter *splitter ;   // 分割主窗口
    QSplitter *Lsplitter ;  // 分割左边的主窗口
    QSplitter *LLsplitter;  //分割左边分割窗口（左）
    QSplitter *LRsplitter;  //分割左边分割窗口（右）
    QSplitter *Rsplitter ;  // 分割右边的窗口
    QDialog *center ;   // 聊天窗口中间工具栏区域
    QTextEdit *alltext ;    // 所有聊天内容显示区域
    QTextEdit *inputtext ;  // 本地信息输入区域
    QTextEdit *historytext ;    // 历史记录
    QPushButton *send ;     // 发送聊天信息按钮
    QPushButton *fontbtn ;  // 切换字体按钮
    QPushButton *history ;  // 查看历史记录按钮
    QFont font ;    // 字体
    QFrame *frame ;
    QDateTime time; // 用于获取当前系统时间的对象
    QFile file;
    QTextStream *textStream;
    bool flag;
    QString userid;
    QString username;
    QTableWidget *list;//用于放置所有聊天室成员

signals:

public slots:
    void setFont() ;    // 设置字体
    void showHistory() ;    // 显示历史记录
    void sendText() ;   // 发送聊天信息



};

#endif // ROOMCHAT_H
