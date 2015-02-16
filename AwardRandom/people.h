#ifndef PEOPLE_H
#define PEOPLE_H
#include <QPixmap>
#include <QDir>
#include <QFileInfo>
#include <QString>

class People
{
public:
    People(const QString &picpath);
    QPixmap getHead();
    QString getName();
    void setName(QString n);
    void setAwardLevel(int level);
    int getAwardLevel();
private:
    QPixmap hdPic;
    QString name;
    int awardLevel;
};

#endif // PEOPLE_H
