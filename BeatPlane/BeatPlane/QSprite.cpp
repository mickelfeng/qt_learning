/*************************************************
Author:Micooz
Date:2013-10-23
Description:精灵实现
**************************************************/
#include "Config.h"
#include "QSprite.h"
#include "CTimeDelay.h"

extern CTimeDelay timeController;
extern QPainter *p;

QSprite::QSprite()
{
    this->Init();
}

void QSprite::Init(void)
{
    m_frames.clear();
    m_nframe = 0;
    m_animate_i = 0;
    m_pos.setX(0);
    m_pos.setY(0);
    m_destroyed = false;
    m_execRender = true;
}

//QSprite::QSprite(QImage *src,QRect *rects,int n/* =1 */)
//{
//    m_frames.clear();
//    m_nframe = 0;
//    m_destroyed = false;
//    m_execRender = true;
//    m_animate_i = 0;
//    m_pos = QPoint(0,0);
//    this->setResource(src,rects,n);
//}

void QSprite::setResource(const QImage *src, const QRect *rects, const int &n /* =1 */)
{
    if(src && n > 0)
    {
        static QImage t_img;
        for(int i = 0;i<n;++i)
        {
            t_img = src->copy(rects[i]);
            t_img = t_img.scaled(rects[i].width() * SCALE,rects[i].height() * SCALE);
            m_frames.append(t_img);
            ++m_nframe;
        }
    }
}

QRect* QSprite::Region()
{    
    if(m_destroyed)
    {
        return 0;
    }
    else
    {
        m_reg.setTopLeft(m_pos);
        m_reg.setWidth(Width());
        m_reg.setHeight(Height());
        
        return &m_reg;
    }
}

//从帧序列的from位置依次渲染到to位置，位置是x,y，渲染时间间隔f毫秒，默认重复动画
void QSprite::display(int from/* =0 */, int to/* =-1 */, 
                      int x/* =-1 */, int y/* =-1 */, int f /* =0 */
                      )
{
    if(!m_execRender) return;
        if(x != -1 && y != -1)
        {
            setPos(x,y);
        }
        if(to == -1) to = m_nframe - 1; //to为默认值-1表示渲染全部帧
        if(f > 0)
        {
            //当前帧保持(无变化)
            p->drawImage(m_pos,  m_frames[m_animate_i + from] );
            
            if(timeController.Delay(f,this - 9))
            {
                ++m_animate_i;
            }
            
            if(m_animate_i + from > to )
            {
                //最后一帧
                m_animate_i = 0;
                if(m_destroyed)
                {
                    //被销毁则不重复渲染
                    m_execRender = false;
                }
            }
        }
        else
        {
            //当f为0时仅渲染第一帧
            p->drawImage(m_pos,m_frames.at(from));
        }
}

void QSprite::setPos(int x, int y)
{
    m_pos.setX(x);
    m_pos.setY(y);
}

void QSprite::setOffset(int dx,int dy)
{
    m_pos.setX(m_pos.x()+dx);
    m_pos.setY(m_pos.y()+dy);
}

void QSprite::destroy()
{
    m_destroyed = true;
}

bool QSprite::IsDestroyed()const
{
    return m_destroyed;
}

bool QSprite::IsFinishRender()const
{
    return !m_execRender;
}

int QSprite::x()const
{
    return m_pos.x();
}

int QSprite::y()const
{
    return m_pos.y();
}

int QSprite::Width(int index /* =0 */) const
{
    //m_frames未初始化问题
    return m_frames.at(index).width();
}

int QSprite::Height(int index /* =0 */) const
{
    return m_frames.at(index).height();
}
