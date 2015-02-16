/*************************************************
Author:Micooz
Date:2013-10-23
Description:飞机类实现，做基类
**************************************************/
#include "CPlane.h"

extern QPainter *p;

CPlane::CPlane()
{
    this->Init();
}

//CPlane::CPlane(QImage *src,QRect *rects,int n /* =1 */,int hp /* =1 */)
//    :QSprite(src,rects,n)
//{
//    m_hp = hp;
//}

void CPlane::Init(void)
{
    m_hp = 1;
}

int CPlane::getHp()const
{
    return m_hp;
}

void CPlane::setHp(int hp)
{
    m_hp = hp;
}

void CPlane::decHp(int dhp)
{
    m_hp -= dhp;
}
