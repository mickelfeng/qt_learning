//延时类，该类用于延时执行某函数，使用对象指针作为互斥条件
//该类只允许单实例
#ifndef CTIMEDENY_H
#define CTIMEDENY_H
#include <QList>
#include <QDateTime>

struct TimeDelayItem
{
    void *address;
    qint64 timeBefore;
};

class CTimeDelay
{
public:
    CTimeDelay();
    int Delay(unsigned int msec = 0, void *obj = 0);
private:
    QList<TimeDelayItem> m_objs;
    qint64 CurrentMsecs(void);
};

#endif // CTIMEDENY_H
