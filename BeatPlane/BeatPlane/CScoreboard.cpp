/*************************************************
Author:Micooz
Date:2013-10-23
Description:计分板实现
**************************************************/
#include "CScoreboard.h"
#include "Config.h"

extern QPainter *p;

CScoreboard::CScoreboard()
{
    static QImage* m_src = 0;
    if(!m_src)
    {
        m_src = new QImage("src/font.png");
    }

    //0-9x帧
    QRect rects[11]={
        QRect(179,0,27,31),
        QRect(272,0,6,31),
        QRect(149,0,30,34),
        QRect(29,0,27,39),
        QRect(0,0,29,39),
        QRect(237,0,35,31),
        QRect(206,0,31,31),
        QRect(278,0,34,31),
        QRect(87,0,33,34),
        QRect(120,0,29,34),
        QRect(56,0,31,34),
    };

    if(m_src)
    {
        QImage t_img;
        for(int i = 0;i<11;++i)
        {
            t_img = m_src->copy(rects[i]);
            t_img = t_img.scaled(rects[i].width() * SCALE,rects[i].height() * SCALE);
            m_frames.append(t_img);
        }
    }
}

void CScoreboard::display(int score, int x, int y)
{
    //分解得分
    int n = 1;
    m_scores.clear();
    int t_s = score;
    if(score == 0) m_scores.push_back(0);
    while(t_s / n !=0)
    {
        m_scores.push_front(score % 10);
        score /= 10;
        n*=10;
    }
    //分别渲染
    QList<int>::iterator it = m_scores.begin();

    for( ; it!=m_scores.end(); ++it)
    {
        const QImage &t_img = m_frames.at(*it);

        p->drawImage(x,y,t_img);
        x += t_img.width();
    }
}
