/*************************************************
Author:Micooz
Date:2013-10-23
Description:主渲染窗口实现
**************************************************/
#include <QMouseEvent>
#include <QTime>
#include <QMessageBox>
#include <QTimer>
#include "CTimeDelay.h"
#include "Config.h"
#include "MainRender.h"
#include "Settings.h"

QPainter*p;
QTimer *timer;
Settings *frmSet;
CTimeDelay timeController;

MainRender::MainRender(QWidget *parent) :
    QWidget(parent)
{
    //全局变量初始化
    p = new QPainter();
    frmSet = new Settings;
    timer = new QTimer(this);
    timer->setInterval(10);
    connect(timer,SIGNAL(timeout()),this,SLOT(repaint()));
    //设置默认参数
    cout<<"Initializing & Configuring Game..."<<endl;
    START_POS_X = 140;
    START_POS_Y = 560;
    SHOW_FPS = true;
    m_fps = 0.0;
    m_font.setFamily("Comic Sans MS");
    m_font.setWeight(10);
    m_font.setBold(true);
    m_brush.setStyle(Qt::SolidPattern);
    m_brush.setColor(QColor::fromRgb(97,99,98,200));
    //启动渲染
    this->Game_Init();
}

MainRender::~MainRender()
{
    cout<<"Dispose Resources..."<<endl;

    delete p;
    delete frmSet;
    timer->stop();
    timer->disconnect();
    delete timer;
    
    cout<<"Game Window Closed."<<endl;    
}

//游戏初始化
void MainRender::Game_Init(void)
{
    this->setFixedSize(SWIDTH,SHEIGHT);
    this->setMouseTracking(false);//Loading状态不捕获鼠标
    this->setFocusPolicy(Qt::StrongFocus);
    //加载贴图资源，对象初始化
    cout<<"Loading resource..."<<endl;
    this->m_fontSrc.load("src/font.png");
    this->m_shootSrc.load("src/shoot.png");
    this->m_shoot_backgroundSrc.load("src/shoot_background.png");
    //背景使用两张相同的图是为了滚动
    //这里传临时变量地址无妨，仅作构造
    m_background_1.setResource(&m_shoot_backgroundSrc,&(QRect(0,76,480,850)));
    m_background_1.setPos(0,0);
    m_background_2.setResource(&m_shoot_backgroundSrc,&(QRect(0,76,480,850)));
    m_background_2.setPos(0,0);
    m_welcome.setResource(&m_shoot_backgroundSrc,&(QRect(486,841,428,82)));
    m_welcome.setPos(20,300);
    //战机
    QRect myplane_rects[6]={
        QRect(166,362,100,113),
        QRect(1,100,100,128),
        QRect(161,236,108,126),
        QRect(330,627,101,124),
        QRect(330,497,101,130),
        QRect(431,627,93,124)
    };
    m_my.setResource(&m_shootSrc,myplane_rects,6);
    m_my.setPos(START_POS_X,START_POS_Y);
    //loading帧
    QRect loading_rects[3]={
        QRect(0,38,173,38),
        QRect(0,0,173,38),
        QRect(492,666,173,38)
    };
    m_loading.setResource(&m_shoot_backgroundSrc,loading_rects,3);
    m_loading.setPos(100,380);
    //菜单项
    QRect menu_rects[2] = {
        QRect(0,977,161,45),
        QRect(161,977,160,45)
    };
    m_menus[0].spr.setResource(&m_shoot_backgroundSrc, menu_rects,2);
    m_menus[0].text = QString("继续游戏");
    m_menus[1].spr.setResource(&m_shoot_backgroundSrc, menu_rects,2);
    m_menus[1].text = QString("重新开始");
    m_menus[2].spr.setResource(&m_shoot_backgroundSrc, menu_rects,2);
    m_menus[2].text = QString("参数调整");
    //加载完毕
    m_status = LOADING;
    cout<<"Waiting for Running Game now!"<<endl;
    timer->start();
}

//游戏开始
void MainRender::Game_Run(void)
{
    this->setMouseTracking(true);

    timer->start();

    m_status = RUNNING;
}

//游戏暂停
void MainRender::Game_Pause(void)
{
    //保存当前帧
    m_pauseFrame = QPixmap::grabWidget(this);
    this->setCursor(Qt::ArrowCursor);

    m_status = PAUSE;
}

//重新开始
void MainRender::Game_Restart(void)
{
    m_my.Reset();
    m_my.setPos(START_POS_X,START_POS_Y);
    m_my.setScore(0);
    m_eCon.Reset();
    this->Game_Run();
}



//2D渲染，游戏逻辑
void MainRender::paintEvent(QPaintEvent*)
{
    static int frames = 0;//帧数

    if(!p->isActive())
    {
        p->begin(this);
            /*** Begin Rendering ***/
            if(m_status == LOADING)
            {
                m_background_1.display();//显示背景
                m_welcome.display();//飞机大战
                m_loading.display(0,-1,-1,-1,1000);//小飞机加载动画
                m_font.setFamily(QString("微软雅黑"));
                m_font.setWeight(10);
                m_font.setPixelSize(30);
                p->setFont(m_font);
                p->drawText(95,441,192,32,Qt::AlignCenter,QString("按回车键继续"));

                m_my.display(0,1,-1,-1,300);//战机

                this->showFPS(SHOW_FPS);
            }
            else if(m_status == RUNNING)
            {
                static int dy = 0;
                m_background_1.display(0,-1,0,dy);
                m_background_2.display(0,-1,0, dy - m_background_2.Height());
                dy += 1;
                if(dy > m_background_2.Height())
                {
                    dy = 0;
                }

                if(m_my.getHp() <=0 )
                {
                    m_my.destroy();
                    m_my.display(2,5,-1,-1,200);
                    if(m_my.IsFinishRender())
                    {
                        this->Game_Pause();
                        cout<<"Game Over!"<<endl;
                    }
                }
                else
                {
                    m_my.display(0,1,-1,-1,300);
                    m_my.setShoot();
                }

                m_eCon.Render(&m_my);

                this->showScore(true);
                this->showFPS(SHOW_FPS);
            }
            else if(m_status == PAUSE)
            {
                //渲染暂停前的一帧
                p->drawPixmap(0,0,m_pauseFrame);

                this->showMenu();

                this->showScore(true);
                this->showFPS(false);
            }
            /*** End Rendering ***/
        p->end();
        //统计帧数，暂停状态下不进行统计
        if(m_status != PAUSE)
            ++frames;
        static int spend = 0;

        if(spend = timeController.Delay(1000,this))
        {
            m_fps = (float)frames/spend*1000;
            frames = 0;
            spend = 0;
        }
    }

    //this->repaint();发生非法递归
    //QMetaObject::invokeMethod(this,"repaint",Qt::QueuedConnection);可行，但CPU占用过高
    //改为Timer触发repaint
}

//显示FPS
void MainRender::showFPS(bool show = true)
{
    if(show)
    {
        m_font.setPixelSize(10);
        m_font.setWeight(20);
        p->setFont(m_font);
        p->drawText(270,1,112,38,
            Qt::AlignCenter,QString("FPS:%1").arg(QString::number(m_fps,'f',2)));
    }
}

//显示分数
void MainRender::showScore(bool show = true)
{
    if(show)
    {
//        m_font.setPixelSize(15);
//        m_font.setWeight(30);
//        m_font.setBold(true);
//        p->setFont(m_font);
//        p->drawText(1,1,100,25,Qt::AlignLeft,QString("分数:%1").arg(m_my.getScore()));
        m_scoreboard.display(m_my.getScore(),10,10);
    }
}

//显示菜单
void MainRender::showMenu()
{
    //设置画笔
    m_pen.setWidth(3);
    m_pen.setColor(QColor::fromRgb(77,79,78));
    p->setPen(m_pen);

    for(int i = 0;i<3;++i)
    {
        Menu &m = m_menus[i];

        m.spr.display(0,0,125,200 + 45 * i );

        if (m_status == PAUSE)
        {
            //鼠标经过填充颜色
            if(m.spr.Region()->contains(  m_mousePos  ))
            {
                m.spr.display(1,1,125,200 + 45 * i);
                //p->fillRect(m.where,m_brush);
                //cout<<"Mouse in the Menu:"<<i + 1<<endl;
            }
        }
        m_font.setPixelSize(13);
        p->setFont(m_font);
        p->drawText(*(m.spr.Region()),Qt::AlignCenter,m.text);
    }
}

//鼠标移动响应
void MainRender::mouseMoveEvent(QMouseEvent *e)
{
    m_mousePos = e->pos();
    if(m_status == RUNNING)
    {
        //移动鼠标调整战机位置，并判断边界条件
        if(  !m_my.IsDestroyed() &&  m_my.Region()->contains(e->pos()))
        {
            this->setCursor(Qt::BlankCursor);
        }

        int x = e->x();
        int y = e->y();
        int dx = m_my.Width() / 2;
        int dy = m_my.Height() / 2;

        const int fix_pix = 20; //修正值

        if(x < dx - fix_pix    || y > (SHEIGHT - dy)  +  fix_pix   || x > (SWIDTH - dx)  + fix_pix  )
        {
            this->setCursor(Qt::ArrowCursor);
        }
        else
        {
            m_my.setPos(x - dx , y - dy);
        }
    }
}

//鼠标点击响应
void MainRender::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        cout<<"MouseLeft Click At:("<<e->x()<<","<<e->y()<<")"<<endl;

        for(int i = 0;i<3;++i)
        {
            Menu &m = m_menus[i];
            if(m.spr.Region()->contains(e->pos()))
            {
                //点中菜单项
                switch (i) {
                case 0:
                {
                    //继续
                    this->Game_Run();
                    break;
                }
                case 1:
                {
                    this->Game_Restart();
                    break;
                }
                case 2:
                {
                    //设置参数
                    if(frmSet)
                    {
                        frmSet->loadini();
                        frmSet->show();
                    }

                    break;
                }
                default:
                    break;
                }


            }

        }

    }
}

//键盘响应
void MainRender::keyPressEvent(QKeyEvent *e)
{
    //cout<<"Pressed key:"<<e->key()<<endl;
    if(e->key() == Qt::Key_Return)//Qt::Key_Enter无效
    {
        //按下回车键
        if(m_status == LOADING)
        {
            m_my.setPos(START_POS_X,START_POS_Y);
            this->Game_Run();

            cout<<"Enter Pressed,Game Start."<<endl;
        }
    }
    else if(e->key() == Qt::Key_Escape)
    {
        if(m_status == RUNNING)
        {
            this->Game_Pause();
            cout<<"Esc Pressed,Game Pause."<<endl;
        }
        else if(m_status == PAUSE)
        {
            this->setCursor(Qt::BlankCursor);
            m_status = RUNNING;
            cout<<"Esc Pressed,Game Continue."<<endl;
        }

    }
}



