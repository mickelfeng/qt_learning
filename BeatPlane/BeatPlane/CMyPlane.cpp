/*************************************************
Author:Micooz
Date:2013-10-23
Description:战机实现
**************************************************/
#include "CMyPlane.h"
#include "Config.h"
#include "CTimeDelay.h"

extern CTimeDelay timeController;

CMyPlane::CMyPlane()
{
    this->Init();
}

void CMyPlane::Init()
{
    m_score = 0;
    m_bullet_sum = 0;
    MAX_BULLETS = 4;
    m_bul_speed = 300;
    m_bullets.clear();
    m_hp = 1;
}

QList<ShuttleBulltets>* CMyPlane::getBullets()
{
    return &m_bullets;
}

//发射子弹，同时控制屏幕上的所有子弹位置
void CMyPlane::setShoot()
{
    //if(timeController.Delay(speed,this)) //这里会和该类使用延时函数地址冲突，所以随便换一个地址
    if(timeController.Delay(m_bul_speed,this - 5))
    {
        if(m_bullet_sum < MAX_BULLETS)
        {
            ShuttleBulltets t_b;
            t_b.setPos(this->x() + 40,this->y() - 20);
            m_bullets.append(t_b);
            ++m_bullet_sum;
        }
    }
    //显示所有子弹，并调整下次出现的位置
    QList<ShuttleBulltets>::iterator it = m_bullets.begin();
    for( ; it != m_bullets.end(); )//++it)
    {
        it->display();

        it->setOffset(0,-5);
        if(it->y() < -30 )
        {
            //子弹超出屏幕
            it = m_bullets.erase(it);
            --m_bullet_sum;
        }
        else
        {
            ++it;
        }
    }    
}

void CMyPlane::setDamage(int val)
{
    QList<ShuttleBulltets>::iterator it = m_bullets.begin();

    for( ; it!=m_bullets.end();++it)
    {
        it->setDamage(val);
    }

}

void CMyPlane::setBulSpeed(int speed)
{
    m_bul_speed = speed;
}

void CMyPlane::incScore(int ds)
{
    m_score += ds;
}

int CMyPlane::getScore()const
{
    return m_score;
}

void CMyPlane::setScore(int s)
{
    m_score = s;
}

void CMyPlane::Reset()
{
    m_score = 0;
    m_bullets.clear();
    m_bullet_sum = 0;
    setHp(1);
    m_destroyed = false;
    m_execRender = true;
}
