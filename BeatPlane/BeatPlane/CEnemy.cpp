/*************************************************
Author:Micooz
Date:2013-10-23
Description:敌机实现
**************************************************/
#include "CEnemy.h"

CEnemy::CEnemy( int type /* = 1 */)
{
    initEnemy(type);
}

void CEnemy::initEnemy(int type)
{
    m_type = type;

    static QImage* m_shootSrc = new QImage("src/shoot.png");

    switch (m_type) {
    case 1:
    {
        m_hp = 1;
        m_give_score = 1000;
        QRect rects[5]={
            QRect(538,612,51,40),
            QRect(269,347,54,50),
            QRect(877,704,53,39),
            QRect(269,296,54,51),
            QRect(930,704,55,39)
        };
        this->setResource(m_shootSrc,rects,5);
        break;
    }
    case 2:
    {
        m_hp = 5;
        m_give_score = 2000;
        QRect rects[6]={
            QRect(0,0,69,95),
            QRect(431,528,71,95),
            QRect(534,656,70,95),
            QRect(604,656,68,95),
            QRect(672,656,72,95),
            QRect(744,656,67,95)
        };
        this->setResource(m_shootSrc,rects,6);
        break;
    }
    case 3:
    {
        m_hp = 10;
        m_give_score = 3000;
        QRect rects[9]={
            QRect(334,751,171,257),
            QRect(505,751,169,257),
            QRect(166,751,168,257),
            QRect(0,482,166,262),
            QRect(0,227,166,255),
            QRect(842,751,163,257),
            QRect(166,488,164,257),
            QRect(674,751,168,257),
            QRect(0,751,166,257)
        };
        this->setResource(m_shootSrc,rects,9);
        break;
    }
    default:
        break;
    }
}

void *CEnemy::address()
{
    return this;
}

int CEnemy::EnemyType()const
{
    return m_type;
}

int CEnemy::getScore()const
{
    return m_give_score;
}

void CEnemy::setType(int type)
{
    m_type = type;
}
