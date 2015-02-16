#ifndef CPLANE_H
#define CPLANE_H

#include "QSprite.h"

class CPlane:public QSprite
{
public:
    CPlane();
    //CPlane(QImage *src, QRect *rects, int n = 1, int hp = 1);
    int getHp()const;
    void setHp(int);
    void decHp(int);
protected:
    void Init(void);
    int m_hp;    
private:

};

#endif // CPLANE_H
