/*
    精灵类（核心类）
    控制动画和动画速度,动画基于单帧渲染
*/
#ifndef QSPRITE_H
#define QSPRITE_H

#include <QImage>
#include <QList>

class QSprite
{
public:
    QSprite();
    //~QSprite();
    //QSprite(QImage *src,QRect *rects,int n = 1);
    void setResource(const QImage *src,const QRect *rects,const int &n = 1);
    void display(int from = 0,int to = -1,int x = -1, int y = -1,int f = 0);    
    void setPos(int x,int y);
    void setOffset(int dx,int dy);

    QRect* Region();
    void destroy();
    bool IsDestroyed()const;
    bool IsFinishRender()const;

    int Width(int index = 0)const;
    int Height(int index = 0)const;
    int x()const;
    int y()const;
protected:

    //帧列表
    QList<QImage> m_frames;
    //判定有效区域
    QRect m_reg;
    QPoint m_pos;
    //标志位
    bool m_execRender;//直接控制是否进行渲染
    bool m_destroyed;
private:
    //精灵初始化
    void Init(void);

    int m_nframe;
    //表示正在渲染指定范围内的第几帧
    int m_animate_i;
};

#endif // QSPRITE_H
