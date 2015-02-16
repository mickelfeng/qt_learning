#ifndef CENEMY_H
#define CENEMY_H

#include "CPlane.h"
#include <QRegion>

class CEnemy:public CPlane
{
public:
    CEnemy(int type = 1);
    int EnemyType()const;
    int getScore()const;
    void setType(int type);
    //返回当前实例的地址
    void* address();
private:
    void initEnemy(int type = 1);
    int m_type;
    int m_give_score;
    //QImage* m_shootSrc;
    //指定区域用于攻击判定
    QRegion m_reg;
};

#endif // CENEMY_H
