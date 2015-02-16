#ifndef CBULLET_H
#define CBULLET_H

#include "CEnemy.h"

//定义单发子弹
class CBullet:public QSprite
{
public:
    CBullet();
    ~CBullet();
    int setHit(CEnemy*);
    void setDamage(int damage = 1);
    int getDamage()const;
private:
    int m_damage;
    //QImage *m_bulletSrc;
};

#define BULLET_SHUTTLE 2

//定义一梭子弹
class ShuttleBulltets:public CBullet
{
public:
    ShuttleBulltets()
    {
        setDamage(1);
    }

    ~ShuttleBulltets()
    {

    }
    
    void setOffset(int dx, int dy)
    {
        for(int i=0;i<BULLET_SHUTTLE;++i)
        {
            m_buls[i].setOffset(dx,dy);
        }
        CBullet::setOffset(dx,dy);
    }
        
    void setPos(int x, int y)
    {
        for(int i=0;i<BULLET_SHUTTLE;++i)
        {
            m_buls[i].setPos(x,y - i*25);
        }
        CBullet::setPos(x,y);
    }
    
    void display()
    {
        for(int i=0;i<BULLET_SHUTTLE;++i)
        {
            m_buls[i].display();
        }
    }
    
    QRect* Region()
    {
        if(m_destroyed)
        {
            return 0;
        }
        else
        {
            m_reg.setTopLeft(m_pos);
            m_reg.setWidth(m_buls[0].Width());
            m_reg.setHeight(70);

            return &m_reg;
        }
    }

private:
    // int n = 3; -- forbids
     CBullet m_buls[BULLET_SHUTTLE];
};

#endif // CBULLET_H
