#ifndef CMYPLANE_H
#define CMYPLANE_H

#include "CPlane.h"
#include "CBullet.h"
#include <QList>

class CMyPlane : public CPlane
{
public:
    CMyPlane();
    void setShoot();
    void setScore(int);
    void setDamage(int);
    void setBulSpeed(int);
    int getScore()const;
    void incScore(int);
    void Reset();
    QList<ShuttleBulltets>* getBullets();

    int m_bullet_sum;
    int MAX_BULLETS;
private:
    void Init(void);
    QList<ShuttleBulltets> m_bullets;
    int m_score;
    int m_bul_speed;
};

#endif // CMYPLANE_H
