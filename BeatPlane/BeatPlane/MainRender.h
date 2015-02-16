#ifndef MAINRENDER_H
#define MAINRENDER_H
#include <QWidget>
#include <QFont>
#include <QPen>
#include <QList>

#include "Settings.h"
#include "QSprite.h"
#include "CMyPlane.h"
#include "CEnemy.h"
#include "CEnemyController.h"
#include "CScoreboard.h"

enum GAME_STATUS
{
  LOADING,
  PAUSE,
  RUNNING,
  END
};

struct Menu
{
    QSprite spr;
    QString text;
};

class MainRender : public QWidget
{
    Q_OBJECT
public:
    explicit MainRender(QWidget *parent = 0);
    ~MainRender();
    void paintEvent(QPaintEvent *e);

    //公开以下成员给Setting窗口更改
    CMyPlane m_my;
    int START_POS_X;
    int START_POS_Y;
    bool SHOW_FPS;
private:
    QFont m_font;
    QPen m_pen;
    QBrush m_brush;
    //游戏状态
    GAME_STATUS m_status;
    //渲染次数
    long long m_RenderTime;
    //资源
    QImage m_shootSrc;
    QImage m_fontSrc;
    QImage m_shoot_backgroundSrc;
    QImage m_button_bgSrc;
    QImage m_button_hover_bgSrc;
    Menu m_menus[3];
    //暂停帧
    QPixmap m_pauseFrame;
    //分数渲染控制

    CEnemyController m_eCon;
    CScoreboard m_scoreboard;

    QSprite m_background_1;
    QSprite m_background_2;
    QSprite m_welcome;
    QSprite m_loading;
    //帧率
    float m_fps;
    //鼠标位置
    QPoint m_mousePos;
protected:
    void showFPS(bool);
    void showScore(bool);
    void showMenu();
    void Game_Init(void);
    void Game_Run(void);
    void Game_Pause(void);
    void Game_Restart(void);
public slots:
    void mouseMoveEvent(QMouseEvent *);
    void keyPressEvent(QKeyEvent *);
    void mousePressEvent(QMouseEvent *);
};

#endif // MAINRENDER_H
