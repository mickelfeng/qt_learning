#ifndef SETUPDIALOG_H
#define SETUPDIALOG_H

#include <QDialog>
#include <QSpinBox>
#include <QLineEdit>
#include <QString>
#include <QPixmap>
#include <QToolButton>
namespace Ui {
class SetupDialog;
}

class SetupDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SetupDialog(QWidget *parent = 0);
    ~SetupDialog();
    int awardLevels();
    int awardnCnt(int n);
    QString awardName(int n);
public slots:

    void updateAwardName(int n,QString name);

signals:
    void signalUpdatePeopleList();
    void signalUpdateAwardPic(int , QPixmap);
    void signalUpdateBgMusic(QString musicpath);
private:
    Ui::SetupDialog *ui;
    QList<QSpinBox*> spinList;
    QList<QLineEdit*> lineEditList;

    QString pickupPick(QString s);
private slots:
    void updatePeopleList(const QStringList &list);
    void on_updateListPushButton_clicked();
    void on_setupAward1IconToolButton_clicked();
    void on_setupAward2IconToolButton_clicked();
    void on_setupAward3IconToolButton_clicked();
    void on_setupAward4IconToolButton_clicked();
    void on_setupAward5IconToolButton_clicked();
    void on_setupAward6IconToolButton_clicked();
    void on_pushButton_clicked();
    void on_changeMusicPushButton_clicked();
};

#endif // SETUPDIALOG_H
