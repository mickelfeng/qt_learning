//该类控制敌机随机生成逻辑，并提供渲染通道

#ifndef CENEMYCONTROLLER_H
#define CENEMYCONTROLLER_H
#include <QList>
#include "CEnemy.h"
#include "CMyPlane.h"

class CEnemyController//:public QSprite//暂时继承一下，因为要用到延时和随机数生成函数，写完后把两个函数独立出来
{
public:
    CEnemyController();
    //void setScore(int);
    void Render(CMyPlane *my);
    void Reset();
private: 
    void addEnemy(int type = 1);
    void generateEnemy();
    void refreshLevel(CMyPlane *my);

    //有序保存各种类型的敌机
    QList<CEnemy> m_enemies;
    //敌机数量
    int m_nCount;
    //游戏级别
    int m_level;
    //游戏得分
    int m_score;
};

#endif // CENEMYCONTROLLER_H
