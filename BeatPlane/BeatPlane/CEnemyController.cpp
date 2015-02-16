/*************************************************
Author:Micooz
Date:2013-10-23
Description:敌机控制器实现
**************************************************/
#include "CEnemyController.h"
#include "Config.h"
#include "CTimeDelay.h"
#include "CRandom.h"

extern CTimeDelay timeController;

CEnemyController::CEnemyController()
{
    m_nCount = 0;
    m_level = 1;
    m_score = 0;
}

void CEnemyController::addEnemy(int type /* =1 */)
{
    static CEnemy t_en; //使用静态变量解决内存占用过高问题

    t_en.setType(type);

    //任意初始化一个位置
    int w = t_en.Width();
    int h = t_en.Height();

    t_en.setPos(CRandom::random(0, SWIDTH - w ) , - CRandom::random(h,h + 100));
    
    m_enemies.append(t_en);
    ++m_nCount;
}

//依据分数控制飞机数量和速度
void CEnemyController::Render(CMyPlane* my)
{
    this->refreshLevel(my);
    this->generateEnemy();
    //计算每个敌机的位置，并根据级别调整飞行快慢
    QList<CEnemy>::iterator it = m_enemies.begin();
           
    for(  ; it!=m_enemies.end() ; )//++it )
    {
        int type = it->EnemyType();

        if(type == 1)
        {
            if(timeController.Delay(CRandom::random(5,20),it->address()) )
            {
                it->setOffset(0,1);
            }
        }
        else if(type == 2)
        {
            if(timeController.Delay(CRandom::random(10,30),it->address()))
            {
                it->setOffset(0,1);
            }
        }
        else if(type == 3)
        {
            if(timeController.Delay(CRandom::random(15,40),it->address()))
            {
                it->setOffset(0,1);
            }
        }

        if(it->y() > SHEIGHT)
        {
            //超出屏幕则移动到最开始,并重设位置
            //it->setOffset(0,999);
            it->setPos(CRandom::random(0,SWIDTH - it->Width()),  - it->Height() - 20 );
        }

        //击毁动画
        if(it->getHp() <= 0)
        {
            it->destroy();
            if(type == 1)
            {
                it->display(1,4,-1,-1,100);
            }
            else if(type == 2)
            {
                it->display(2,5,-1,-1,100);
            }
            else if(type == 3)
            {
                it->display(3,8,-1,-1,100);
            }
            if(it->IsFinishRender())
            {
                //敌机爆炸完毕
                it = m_enemies.erase(it);
                --m_nCount;

                my->incScore( it->getScore() );

                cout<<"Enemy(type:"<<type<<") down."<<endl;
                continue;
            }
        }
        else
        {
            //敌机正常运行
            if(type == 1)
            {
                it->display();
            }
            else if(type == 2)
            {
                it->display(0,1,-1,-1,500);
            }
            else if(type == 3)
            {
                it->display(0,2,-1,-1,400);
            }
        }

        //攻击判定
        QRect * e,*m; //敌机，战机，子弹判定区
        e = it->Region();
        m = my->Region();

        if(  e && m && e->intersects(*m) )
        {
            //战机与敌机接触，销毁战机，游戏结束
            cout<<"Bumping into enemy:"<<type<<endl;
            my->decHp(1);
        }

        //子弹接触判定
        QList<ShuttleBulltets>* buls = my->getBullets();
        QList<ShuttleBulltets>::iterator it_b = buls->begin();
        QRect *b;

        for( ; it_b !=buls->end() ; )//++ it_b )
        {
            b = it_b->Region();
            if(b && e && b->intersects(*e) && it->y() > it->Height())
            {
                //击中目标-hp
                it->decHp(it_b->getDamage());
                //并销毁该发子弹
                it_b = buls->erase(it_b); //erase here
                my->m_bullet_sum --;
            }
            else
            {
                ++it_b;
            }
        }//for

        ++it;

    }//for
}

//按数量随机产生敌机
void CEnemyController::generateEnemy()
{
    if( timeController.Delay(CRandom::random(1000,2500),this))
    {
        switch (m_level)
        {
            case 1:case 2://1,2级只有第一种
            {
                if(m_nCount < 10) this->addEnemy(1);
                break;
            }
            case 3:case 4://3,4级只有前两种
            {
                if(m_nCount < 15) this->addEnemy(CRandom::random(1,2));
                break;
            }
            case 5:case 6: //5,6级有各种敌机
            {
                if(m_nCount < 20) this->addEnemy(CRandom::random(1,3));
                break;
            }
            default://超过6级就只有中型和大型敌机
            {
                if(m_nCount < 25) this->addEnemy(CRandom::random(2,3));
                break;
            }
        }
    }
}
//按得分定义级别
void CEnemyController::refreshLevel(CMyPlane*my)
{
    //级别按分数定义
    m_score = my->getScore();
    if(m_score <1000)
        m_level = 1;
    else if(m_score <= 5000)
        m_level = 2;
    else if(m_score <= 10000)
        m_level = 3;
    else if(m_score <= 50000)
        m_level = 4;
    else if(m_score <= 100000)
        m_level = 5;
    else if(m_score <= 500000)
        m_level = 6;
    else if(m_score <= 1000000)
        m_level = 7;
    else
        m_level = 8;
}
//重置控制器
void CEnemyController::Reset()
{
    m_level = 1;
    m_score = 0;
    m_nCount = 0;
    m_enemies.clear();
}
