/*************************************************
Author:Micooz
Date:2013-10-23
Description:子弹实现
**************************************************/
#include "CBullet.h"

CBullet::CBullet()
{
    static QImage* m_bulletSrc = new QImage("src/shoot.png");

    this->setResource(m_bulletSrc,&(QRect(1005,987,8,21)));

    m_destroyed = 0;
}

CBullet::~CBullet()
{

}

int CBullet::setHit(CEnemy *enemy)
{
    enemy->decHp(1);
    return enemy->getHp();
}

void CBullet::setDamage(int damage /* =1 */)
{
    m_damage = damage;
}

int CBullet::getDamage()const
{
    return m_damage;
}
