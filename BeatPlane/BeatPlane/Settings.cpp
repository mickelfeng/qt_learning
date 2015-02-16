/*************************************************
Author:Micooz
Date:2013-10-23
Description:设置窗口实现
**************************************************/
#include <QMessageBox>
#include <QTimer>
#include <QFileInfo>

#include "Settings.h"
#include "ui_Settings.h"
#include "Config.h"
#include "CConfig.h"

extern MainRender *myRender;
extern QTimer *timer;

Settings::Settings(QWidget *parent) :
    QDialog(parent)
{
    ui = new Ui::Settings;
    ui->setupUi(this);

    m_con = 0;

    if( ! (QFileInfo(QString("conf.ini")).exists()) )
    {
        cout<<"Couldn't find conf.ini"<<endl;
        m_isavailable = false;
    }
    else
    {
        m_isavailable = true;
    }
}

Settings::~Settings()
{
    delete ui;
    delete m_con;
}

void Settings::loadini()
{
    if(!m_isavailable) return;

    if(!m_con)
    {
        m_con = new CConfig("beatplane","conf.ini");
    }

    //全局配置读取
    m_con->setNode("GLOBAL");
    ui->chcShowFps->setChecked(m_con->read("FPS_SHOW").toInt());
    ui->spFps->setValue(m_con->read("FPS").toInt());
    //战机配置读取
    m_con->setNode("MyPlane");
    ui->spHp->setValue(1);
    ui->editX->setText(m_con->read("START_POS_X").toString());
    ui->editY->setText(m_con->read("START_POS_Y").toString());
    ui->spBulSum->setValue(m_con->read("BULLET_SHUTTLE_MAX").toInt());
    //ui->spPerBul->setValue(m_con->read("BULLET_SHUTTLE_SIZE").toInt());
    ui->editBulSpeed->setText(m_con->read("BULLET_SPEED").toString());
    ui->spDam->setValue(m_con->read("BULLET_DAMAGE").toInt());
    //敌机配置读取
    //m_con->setNode("Enemy1");
    //ui->spHp1->setValue(m_con->read("HP").toInt());
    //ui->spScore1->setValue(m_con->read("SCORE").toInt());
    //m_con->setNode("Enemy2");
    //ui->spHp2->setValue(m_con->read("HP").toInt());
    //ui->spScore2->setValue(m_con->read("SCORE").toInt());
    //m_con->setNode("Enemy3");
    //ui->spHp3->setValue(m_con->read("HP").toInt());
    //ui->spScore3->setValue(m_con->read("SCORE").toInt());
}

void Settings::saveini()
{
    if(m_con && m_isavailable)
    {
        //全局写入
        m_con->setNode("GLOBAL");
        m_con->write("FPS_SHOW", (ui->chcShowFps->isChecked())?1:0);
        m_con->write("FPS",ui->spFps->value());
        //战机写入
        m_con->setNode("MyPlane");
        m_con->write("START_POS_X",ui->editX->text().toInt());
        m_con->write("START_POS_Y",ui->editY->text().toInt());
        m_con->write("BULLET_SHUTTLE_MAX", ui->spBulSum->value());
        //m_con->write("BULLET_SHUTTLE_SIZE", ui->spPerBul->value());
        m_con->write("BULLET_SPEED", ui->editBulSpeed->text().toInt());
        m_con->write("BULLET_DAMAGE", ui->spDam->value());
        //敌机写入
        //m_con->setNode("Enemy1");
        //m_con->write("HP",ui->spHp1->value());
        //m_con->write("SCORE",ui->spScore1->value());
        //m_con->setNode("Enemy2");
        //m_con->write("HP",ui->spHp2->value());
        //m_con->write("SCORE",ui->spScore2->value());
        //m_con->setNode("Enemy3");
        //m_con->write("HP",ui->spHp3->value());
        //m_con->write("SCORE",ui->spScore3->value());
        QMessageBox::information(this,QString("提示"),QString("配置已保存！"));
    }
    else
    {
        QMessageBox::information(this,QString("提示"),QString("配置文件初始化失败！"));
    }
}

void Settings::on_btnCancel_clicked()
{
    this->hide();
}

void Settings::on_btnRefresh_clicked()
{
    this->loadini();
}

void Settings::on_btnSave_clicked()
{
    this->saveini();
}

//战机HP设置
void Settings::on_spHp_valueChanged(int arg1)
{
    myRender->m_my.setHp(arg1);
    cout<<"change my plane's hp to:"<<arg1<<endl;
}

//战机伤害设置
void Settings::on_spDam_valueChanged(int arg1)
{
    myRender->m_my.setDamage(arg1);
}

//X
void Settings::on_editX_lostFocus()
{
    myRender->START_POS_X = ui->editX->text().toInt();
}

//Y
void Settings::on_editY_lostFocus()
{
    myRender->START_POS_Y = ui->editY->text().toInt();
}

//屏幕子弹数量
void Settings::on_spBulSum_valueChanged(int arg1)
{
    myRender->m_my.MAX_BULLETS = arg1;
}

//子弹速度
void Settings::on_editBulSpeed_lostFocus()
{
    myRender->m_my.setBulSpeed(ui->editBulSpeed->text().toInt());
}

//是否显示FPS
void Settings::on_chcShowFps_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
    {
        myRender->SHOW_FPS = true;
    }
    else
    {
        myRender->SHOW_FPS = false;
    }
}

//刷新时间间隔
void Settings::on_spFps_valueChanged(int arg1)
{
    timer->start(arg1);
}
