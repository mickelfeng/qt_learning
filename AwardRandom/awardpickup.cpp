#include "awardpickup.h"
#include "ui_awardpickup.h"
#include <QPainter>
#include <QDebug>
#include <QFileDialog>
#include <QTime>
#include <QTimer>
#include <QMessageBox>
#include <QKeyEvent>
#include "setupdialog.h"
#include <phonon>
#include <QFile>
#include "helpdialog.h"
AwardPickup::AwardPickup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AwardPickup)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowCloseButtonHint|Qt::WindowMinMaxButtonsHint);
    setFocus();
    resize(800,600);
    setFocusPolicy(Qt::StrongFocus);
    bgmusicfile = tr("://images//musicOfBackground.mp3");
    pollingmusicfile = tr("://images//musicOfRolling.mp3");
    stopmusicfile = tr("://images//musicOfDraw.mp3");

    bgfile = tr("://images//灯笼鞭炮.jpg");
    bg = QPixmap(bgfile);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(slotTimeout()));
    isRolling = false;
    isSaveResult = false;
    pickupIndex = -1;

    totalPeople = 0;
    totalAward = 0;
    nothaveTotalPeople = 0;
    qsrand(QTime(0,0,0).msecsTo(QTime::currentTime()));
    awardPicture << QPixmap(":\\images\\award1.png")
                << QPixmap(":\\images\\award2.png")
                << QPixmap(":\\images\\award3.png")
                << QPixmap(":\\images\\award4.png")
                << QPixmap(":\\images\\award5.png")
                << QPixmap(":\\images\\award6.png");
    awardToolButtonList << ui->award1ToolButton
                        << ui->award2ToolButton
                        << ui->award3ToolButton
                        << ui->award4ToolButton
                        << ui->award5ToolButton
                        << ui->award6ToolButton;
    awardnListWidgetList<< ui->award1ListWidget
                        << ui->award2ListWidget
                        << ui->award3ListWidget
                        << ui->award4ListWidget
                        << ui->award5ListWidget
                        << ui->award6ListWidget;
    for(int i=0;i<awardToolButtonList.count();i++){
        awardToolButtonList.at(i)->setIcon(QIcon(awardPicture.at(i)));
    }
    QPalette p = ui->curAwardLabel->palette();
    p.setColor(QPalette::WindowText,QColor(255,201,14,200));
    ui->curAwardLabel->setPalette(p);
    slotBrowseHeadPath();//加载头像
    on_setupToolButton_clicked();//设置
    //on_award4ToolButton_clicked();//默认开始抽4等奖
    awardToolButtonList.at(totalAward-1)->click();
    updateMusic();
}

AwardPickup::~AwardPickup()
{
    if(!isSaveResult && (level1people.count()>0 ||
                         level2people.count()>0 ||
                         level3people.count()>0 ||
                         level4people.count()>0 ||
                         level5people.count()>0 ||
                         level6people.count()>0)){
        if(QMessageBox::warning(this,tr("抽奖结果未保存"),tr("是否要保存投资结果？"),QMessageBox::Ok|QMessageBox::Cancel) == QMessageBox::Ok)
            on_saveResultToolButton_clicked();
    }
    delete ui;
}

void AwardPickup::updateMusic()
{
    bgmusic=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(bgmusicfile));
    rollmusic=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(pollingmusicfile));
    rollfinishedmusic=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(stopmusicfile));
}
void AwardPickup::slotUpdateBgMusic(QString mp)
{
    if(bgmusic->state()==Phonon::PlayingState){
        bgmusic->stop();
        ui->musicToolButton->setChecked(false);
    }
    //qDebug() << mp;
    bgmusic=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(mp));
}

void AwardPickup::hideAwardInfo(int cnt)
{
    if(cnt == 1){
        ui->award1CntLabel->hide();
        ui->award1ListWidget->hide();
        ui->award1TCntLabel->hide();
        ui->award1ToolButton->hide();
    }
    if(cnt == 2){
        ui->award2CntLabel->hide();
        ui->award2ListWidget->hide();
        ui->award2TCntLabel->hide();
        ui->award2ToolButton->hide();
    }
    if(cnt == 3){
        ui->award3CntLabel->hide();
        ui->award3ListWidget->hide();
        ui->award3TCntLabel->hide();
        ui->award3ToolButton->hide();
    }
    if(cnt == 4){
        ui->award4CntLabel->hide();
        ui->award4ListWidget->hide();
        ui->award4TCntLabel->hide();
        ui->award4ToolButton->hide();
    }
    if(cnt == 5){
        ui->award5CntLabel->hide();
        ui->award5ListWidget->hide();
        ui->award5TCntLabel->hide();
        ui->award5ToolButton->hide();
    }
    if(cnt == 6){
        ui->award6CntLabel->hide();
        ui->award6ListWidget->hide();
        ui->award6TCntLabel->hide();
        ui->award6ToolButton->hide();
    }
}

void AwardPickup::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(0,0,bg.scaled(size()));

}

void AwardPickup::slotBrowseHeadPath()
{
     QFileDialog* openFilePath = new QFileDialog( this, tr("选择员工头像目录"));     //打开一个目录选择对话框
     openFilePath-> setFileMode( QFileDialog::DirectoryOnly );
     peopleList.clear();
     peopleNameList.clear();
     if ( openFilePath->exec() == QDialog::Accepted )
     {
         QStringList list;
         list << "*.jpg"<<"*.png"<<"*.bmp";
         QFileInfoList files= openFilePath->directory().entryInfoList(list,QDir::Files);
         foreach(QFileInfo fi, files){
             People p(fi.absoluteFilePath());
             p.setName(fi.baseName());
             peopleNameList << fi.baseName();
             p.setAwardLevel(NotHave);
            peopleList << p;
         }
         //qDebug() << peopleList.count();
         nothaveTotalPeople = totalPeople = peopleList.count();
         if(totalPeople <= 0){
             QMessageBox::warning(this,tr("没有员工头像"),tr("请把员工头像文件存好再进行"));
         }
         else{
             ui->totalCntLabel->setText(QString::number(totalPeople));
             emit sigUpdateList(peopleNameList);
         }
     }
     else{
         exit(0);
     }
     delete openFilePath;
}

void AwardPickup::keyPressEvent(QKeyEvent *key)
{
    switch(key->key()){
    case Qt::Key_Space:

        if(totalPeople <= 0){
            QMessageBox::warning(this,tr("错误"),tr("没有员工头像文件，请把员工头像文件存好再进行"));
            return;
        }
        if(peopleList.count() == 1){
            QMessageBox::warning(this,tr("错误"),tr("只剩最后一人：")+peopleList.first().getName());
            return;
        }
        if(curAwardLevel == -1 || totalAward == 0){
            QMessageBox::warning(this,tr("错误"),tr("请选择要抽的奖项"));
            return;
        }
        if(awardnCnt.at((curAwardLevel-1)%totalAward) == awardnTotal.at((curAwardLevel-1)%totalAward)){
            QMessageBox::warning(this,tr("错误"),tr("当前奖项已经抽满"));
            return;
        }
        if(isRolling){
            rollmusic->stop();
            rollfinishedmusic->play();
            isRolling = false;
            timer->stop();
            People p = peopleList.takeAt(pickupIndex);
            switch(curAwardLevel){
            case L1:
                ui->award1ListWidget->addItem(p.getName());
                level1people << p;
                ui->award1CntLabel->setText(QString::number(ui->award1ListWidget->count()));
                awardnCnt[(curAwardLevel-1)%totalAward] = level1people.count();
                if(level1people.count() == ui->award1TCntLabel->text().toInt()){
                    ui->award1TCntLabel->setEnabled(false);
                    ui->award1CntLabel->setEnabled(false);
                    ui->award1ListWidget->setEnabled(false);
                    ui->award1ToolButton->setEnabled(false);
                }
                break;

            case L2:
                ui->award2ListWidget->addItem(p.getName());
                level2people << p;
                ui->award2CntLabel->setText(QString::number(ui->award2ListWidget->count()));
                awardnCnt[(curAwardLevel-1)%totalAward] = level2people.count();
                if(level2people.count() == ui->award2TCntLabel->text().toInt()){
                    ui->award2TCntLabel->setEnabled(false);
                    ui->award2CntLabel->setEnabled(false);
                    ui->award2ListWidget->setEnabled(false);
                    ui->award2ToolButton->setEnabled(false);
                }
                break;
            case L3:
                ui->award3ListWidget->addItem(p.getName());
                level3people << p;
                ui->award3CntLabel->setText(QString::number(ui->award3ListWidget->count()));
                awardnCnt[(curAwardLevel-1)%totalAward] = level3people.count();
                if(level3people.count() == ui->award3TCntLabel->text().toInt()){
                    ui->award3TCntLabel->setEnabled(false);
                    ui->award3CntLabel->setEnabled(false);
                    ui->award3ListWidget->setEnabled(false);
                    ui->award3ToolButton->setEnabled(false);
                }
                break;
            case L4:
                ui->award4ListWidget->addItem(p.getName());
                level4people << p;
                ui->award4CntLabel->setText(QString::number(ui->award4ListWidget->count()));
                awardnCnt[(curAwardLevel-1)%totalAward] = level4people.count();
                if(level4people.count() == ui->award4TCntLabel->text().toInt()){
                    ui->award4TCntLabel->setEnabled(false);
                    ui->award4CntLabel->setEnabled(false);
                    ui->award4ListWidget->setEnabled(false);
                    ui->award4ToolButton->setEnabled(false);
                }
                break;
            case L5:
                ui->award5ListWidget->addItem(p.getName());
                level5people << p;
                ui->award5CntLabel->setText(QString::number(ui->award5ListWidget->count()));
                awardnCnt[(curAwardLevel-1)%totalAward] = level5people.count();
                if(level5people.count() == ui->award5TCntLabel->text().toInt()){
                    ui->award5TCntLabel->setEnabled(false);
                    ui->award5CntLabel->setEnabled(false);
                    ui->award5ListWidget->setEnabled(false);
                    ui->award5ToolButton->setEnabled(false);
                }
                break;
            case L6:
                ui->award6ListWidget->addItem(p.getName());
                level6people << p;
                ui->award6CntLabel->setText(QString::number(ui->award6ListWidget->count()));
                awardnCnt[(curAwardLevel-1)%totalAward] = level6people.count();
                if(level6people.count() == ui->award6TCntLabel->text().toInt()){
                    ui->award6TCntLabel->setEnabled(false);
                    ui->award6CntLabel->setEnabled(false);
                    ui->award6ListWidget->setEnabled(false);
                    ui->award6ToolButton->setEnabled(false);
                }
                break;
            }

            ui->totalCntLabel->setText(QString::number(peopleList.count()));
        }
        else{
            isRolling = true;
            timer->start(100);
            rollmusic->play();
            rollfinishedmusic->stop();
        }

        break;

    }
}


void AwardPickup::slotTimeout()
{
    int i = qrand()%peopleList.count();
    while(i==pickupIndex){
        i = qrand()%peopleList.count();
    }
    if(peopleList[i].getAwardLevel()==NotHave){

        ui->headPicLabel->setPixmap(peopleList[i].getHead());
        ui->nameLabel->setText(peopleList[i].getName());
    }
    pickupIndex = i;
}

void AwardPickup::on_award1ToolButton_clicked()
{
    ui->curAwardPicLabel->setPixmap(awardPicture.at(0));
    ui->curAwardLabel->setText(tr("现在抽：%1").arg(awardNameList.at(0)));
    curAwardLevel = L1;
}

void AwardPickup::on_award2ToolButton_clicked()
{
    ui->curAwardPicLabel->setPixmap(awardPicture.at(1));
    ui->curAwardLabel->setText(tr("现在抽：%1").arg(awardNameList.at(1)));
    curAwardLevel = L2;
}

void AwardPickup::on_award3ToolButton_clicked()
{
   ui->curAwardPicLabel->setPixmap(awardPicture.at(2));
   ui->curAwardLabel->setText(tr("现在抽：%1").arg(awardNameList.at(2)));
   curAwardLevel = L3;
}

void AwardPickup::on_award4ToolButton_clicked()
{
    ui->curAwardPicLabel->setPixmap(awardPicture.at(3));
    ui->curAwardLabel->setText(tr("现在抽：%1").arg(awardNameList.at(3)));
    curAwardLevel = L4;
}

void AwardPickup::on_award5ToolButton_clicked()
{    ui->curAwardPicLabel->setPixmap(awardPicture.at(4));
     ui->curAwardLabel->setText(tr("现在抽：%1").arg(awardNameList.at(4)));
     curAwardLevel = L5;

}
void AwardPickup::on_award6ToolButton_clicked()
{    ui->curAwardPicLabel->setPixmap(awardPicture.at(5));
     ui->curAwardLabel->setText(tr("现在抽：%1").arg(awardNameList.at(5)));
     curAwardLevel = L6;

}


void AwardPickup::on_setupToolButton_clicked()
{
    SetupDialog setup(this);
    connect(&setup,SIGNAL(signalUpdatePeopleList()),this,SLOT(slotBrowseHeadPath()));
    connect(this,SIGNAL(sigUpdateList(QStringList)),&setup,SLOT(updatePeopleList(QStringList)));
    connect(&setup,SIGNAL(signalUpdateAwardPic(int,QPixmap)),this,SLOT(slotUpdateAwardPic(int,QPixmap)));
    connect(&setup,SIGNAL(signalUpdateBgMusic(QString)),this,SLOT(slotUpdateBgMusic(QString)));
    if(peopleNameList.count() > 0)
        emit sigUpdateList(peopleNameList);


    if(setup.exec() == QDialog::Accepted){
        totalAward = setup.awardLevels();
        for(int i=6;i>totalAward;i--)
            hideAwardInfo(i);

        if(totalAward >= 1){
            ui->award1TCntLabel->setText(QString::number(setup.awardnCnt(1)));
            awardnTotal<< setup.awardnCnt(1);
            awardNameList<<setup.awardName(1);
            awardnCnt<<0;
        }
        if(totalAward >= 2){
            ui->award2TCntLabel->setText(QString::number(setup.awardnCnt(2)));
            awardnTotal<< setup.awardnCnt(2);
            awardNameList<<setup.awardName(2);
            awardnCnt<<0;
        }
        if(totalAward >= 3){
            ui->award3TCntLabel->setText(QString::number(setup.awardnCnt(3)));
            awardnTotal<<setup.awardnCnt(3);
            awardNameList<<setup.awardName(3);
            awardnCnt<<0;
        }
        if(totalAward >= 4){
            ui->award4TCntLabel->setText(QString::number(setup.awardnCnt(4)));
            awardnTotal<<setup.awardnCnt(4);
            awardNameList<<setup.awardName(4);
            awardnCnt<<0;
        }

        if(totalAward >= 5){
            ui->award5TCntLabel->setText(QString::number(setup.awardnCnt(5)));
            awardnTotal<<setup.awardnCnt(5);
            awardNameList<<setup.awardName(5);
            awardnCnt<<0;
        }

        if(totalAward >= 6){
            ui->award6TCntLabel->setText(QString::number(setup.awardnCnt(6)));
            awardnTotal<<setup.awardnCnt(6);
            awardNameList<<setup.awardName(6);
            awardnCnt<<0;
        }

        awardToolButtonList.at(totalAward-1)->click();
    }
    else{
        exit(0);
    }
}

void AwardPickup::music(int, bool ison)
{

    if(ison)
        bgmusic->play();
    else
        bgmusic->stop();

}


void AwardPickup::on_musicToolButton_toggled(bool checked)
{
    music(0,checked);
}

void AwardPickup::slotUpdateAwardPic(int awardlevel,QPixmap p)
{
    if(awardlevel == 6){
        bg = p;
        update();
        return;
    }
    awardPicture.replace(awardlevel,p);
    awardToolButtonList.at(awardlevel)->setIcon(QIcon(p));
}

void AwardPickup::on_saveResultToolButton_clicked()
{
    QString savefile = QFileDialog::getSaveFileName(this, tr("保存抽奖结果"),
                                                    QDir::homePath()+"\\"+"抽奖结果.txt",
                               tr("文本文件(*.txt)"));

    if(savefile.isEmpty()){
        savefile = tr(".//抽奖结果.txt");
    }

    isSaveResult = true;
    QFile file(savefile);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qCritical() << "open file "+savefile+"fail";
        return;
    }
    QTextStream out(&file);
    out << tr("抽奖结果：\n");
    for(int i=0;i<totalAward;i++){
        out << i+1 << "," << awardNameList.at(i) << ":" << "\n";
        for(int j=0;j<awardnListWidgetList.at(i)->count();j++)
            out << "  " << j+1 <<awardnListWidgetList.at(i)->item(j)->text() << "\n";
        out << "\n";
    }
    file.close();
}

void AwardPickup::on_helpToolButton_clicked()
{
    HelpDialog help;
    help.resize(size());
    help.exec();
}
