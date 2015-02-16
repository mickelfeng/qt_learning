/*************************************************
Author:Micooz
Date:2013-10-23
Description:延时类实现
**************************************************/
#include "CTimeDelay.h"

CTimeDelay::CTimeDelay()
{
    //
}

int CTimeDelay::Delay(unsigned int msec , void* obj)
{
    if(msec == 0 || !obj) return false;

    QList<TimeDelayItem>::iterator it = m_objs.begin();
    for(;it != m_objs.end() ;++it)
    {
        if(it->address == obj)
        {
            //item = *it;
            break;
        }
    }

    if(it == m_objs.end())
    {
        //没找到则添加
        TimeDelayItem item;
        item.address = obj;
        item.timeBefore = 0;
        m_objs.append(item);
        it = m_objs.end() - 1;
    }

    qint64 delta = CurrentMsecs() - it->timeBefore;

    if(delta >= msec || !delta)
    {
        it->timeBefore = CurrentMsecs();
        //return true;
        return delta;
    }
    return 0;
}

inline qint64 CTimeDelay::CurrentMsecs(void)
{
    return QDateTime::currentDateTime().toMSecsSinceEpoch();
}
