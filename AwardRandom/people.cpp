#include "people.h"
#include <QDebug>
People::People(const QString &picpath)
{
    hdPic = QPixmap(picpath);
}

QPixmap People::getHead()
{
    return hdPic;
}
QString People::getName()
{
    return name;
}
void People::setName(QString n)
{
    name = n;
    qDebug() << n;
}

void People::setAwardLevel(int level)
{
    awardLevel = level;
}
int People::getAwardLevel()
{
    return awardLevel;
}
