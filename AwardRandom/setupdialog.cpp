#include "setupdialog.h"
#include "ui_setupdialog.h"

#include <QPixmap>
#include <QFileDialog>
#include <QDebug>
SetupDialog::SetupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetupDialog)
{
    ui->setupUi(this);
    spinList << ui->award1CntSpinBox
             << ui->award2CntSpinBox
             << ui->award3CntSpinBox
             << ui->award4CntSpinBox
             << ui->award5CntSpinBox
             << ui->award6CntSpinBox;
    lineEditList << ui->award1LineEdit
                << ui->award2LineEdit
                << ui->award3LineEdit
                << ui->award4LineEdit
                << ui->award5LineEdit
                << ui->award6LineEdit;
}

SetupDialog::~SetupDialog()
{
    delete ui;
}

int SetupDialog::awardLevels()
{
    return ui->awardLevelsSpinBox->value();
}
int SetupDialog::awardnCnt(int n)
{
    if(spinList.count()>=n)
        return spinList.at((n-1)%6)->value();
    else{
        qDebug() << "spinList out range" << spinList.count() << n;
        return 0;
    }
}
QString SetupDialog::awardName(int n)
{
    return lineEditList.at((n-1)%6)->text();
}
void SetupDialog::updateAwardName(int n, QString name)
{
    lineEditList.at((n-1)%6)->setText(name);
}

void SetupDialog::updatePeopleList(const QStringList &list)
{
    ui->peopleListWidget->addItems(list);
    ui->totalPeopleCntLabel->setText(QString::number(list.count()));
}

void SetupDialog::on_updateListPushButton_clicked()
{
    emit signalUpdatePeopleList();
}

QString SetupDialog::pickupPick(QString s)
{
    return QFileDialog::getOpenFileName(this,
        tr("选择%1的图片").arg(s),
        QDir::homePath(),
        tr("Image Files (*.png *.jpg *.bmp)"));
}

void SetupDialog::on_setupAward1IconToolButton_clicked()
{
    QString fn = pickupPick(ui->award1LineEdit->text());
    if(!fn.isEmpty()){
        QPixmap pix(fn);
        ui->setupAward1IconToolButton->setIcon(QIcon(pix));
        emit signalUpdateAwardPic(0, pix);
    }
}

void SetupDialog::on_setupAward2IconToolButton_clicked()
{
    QString fn = pickupPick(ui->award2LineEdit->text());
     if(!fn.isEmpty()){
         QPixmap pix(fn);
         ui->setupAward2IconToolButton->setIcon(QIcon(pix));
         emit signalUpdateAwardPic(1, pix);
     }

}

void SetupDialog::on_setupAward3IconToolButton_clicked()
{
    QString fn = pickupPick(ui->award3LineEdit->text());
    if(!fn.isEmpty()){
        QPixmap pix(fn);
        ui->setupAward3IconToolButton->setIcon(QIcon(pix));
        emit signalUpdateAwardPic(2, pix);
    }
}

void SetupDialog::on_setupAward4IconToolButton_clicked()
{
    QString fn = pickupPick(ui->award4LineEdit->text());
    if(!fn.isEmpty()){
        QPixmap pix(fn);
        ui->setupAward4IconToolButton->setIcon(QIcon(pix));
        emit signalUpdateAwardPic(3, pix);
    }
}

void SetupDialog::on_setupAward5IconToolButton_clicked()
{
    QString fn = pickupPick(ui->award5LineEdit->text());
    if(!fn.isEmpty()){
        QPixmap pix(fn);
        ui->setupAward5IconToolButton->setIcon(QIcon(pix));
        emit signalUpdateAwardPic(4, pix);
    }
}

void SetupDialog::on_setupAward6IconToolButton_clicked()
{
    QString fn = pickupPick(ui->award6LineEdit->text());
    if(!fn.isEmpty()){
        QPixmap pix(fn);
        ui->setupAward6IconToolButton->setIcon(QIcon(pix));
        emit signalUpdateAwardPic(5, pix);
    }
}

void SetupDialog::on_pushButton_clicked()
{
    QString fn = pickupPick(tr("选择背景图片"));
    if(!fn.isEmpty()){
        QPixmap pix(fn);
        emit signalUpdateAwardPic(6, pix);
    }
}

void SetupDialog::on_changeMusicPushButton_clicked()
{
    QString fn = QFileDialog::getOpenFileName(this,
            tr("选择背景音乐"),
            QDir::homePath(),
            tr("Image Files (*.mp3)"));
    if(!fn.isEmpty()){
        emit signalUpdateBgMusic(fn);
    }
}
