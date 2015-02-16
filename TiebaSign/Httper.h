#ifndef HTTPER_H
#define HTTPER_H

#include <QtNetwork/QNetworkAccessManager>
#include <QStringList>
#include"H_IO.h"

typedef QStringList listForums;

class Httper{
public:
    Httper(const QString*un,const QString*pw);
    bool Login();
    bool needVcode(QString* _out_vcodestr);
    void showVcodeImage();
    void getForums();
    void translateReturn(const int * _in_no, const QString *_in_item);

    void autoSign();
    QString getTbs();
    //data
    listForums m_forumLike;
    int success;
    int jump;
    int failed;
private:
    QNetworkAccessManager* m_ntManager;
    QString getToken();

    int Sign(const QString & kw);
    void getUID();

    QString m_uid;
    QString m_un;
    QString m_pw;
    QString m_vcode;
    bool m_islogin;
};
#endif // HTTPER_H
