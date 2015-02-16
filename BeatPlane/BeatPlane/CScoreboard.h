#ifndef CSCOREBOARD_H
#define CSCOREBOARD_H

#include <QImage>
//#include <QRect>
#include <QList>
#include "QSprite.h"

class CScoreboard
{
public:
    CScoreboard();

    void display( int score,int x = 0, int y = 0);

private:
    QList<QImage> m_frames;
    QList<int> m_scores;
};

#endif // CSCOREBOARD_H
