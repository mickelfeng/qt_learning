#ifndef AWARDPICKUP_H
#define AWARDPICKUP_H

#include <QWidget>
#include "people.h"
#include <phonon>
#include <QToolButton>
#include <QListWidget>
namespace Ui {
class AwardPickup;
}

class AwardPickup : public QWidget
{
    Q_OBJECT
    
public:
    explicit AwardPickup(QWidget *parent = 0);
    ~AwardPickup();
    void music(int, bool ison);
private:
    enum AWARD_LEVEL{NotHave,L1,L2,L3,L4,L5,L6};
    Ui::AwardPickup *ui;
    QPixmap bg;
    QString bgfile;
    QString bgmusicfile;
    QString pollingmusicfile;
    QString stopmusicfile;
    QList<QListWidget*> awardnListWidgetList;
    QList<QToolButton*> awardToolButtonList;
    QList<QPixmap> awardPicture;
    QList<People> peopleList;
    QList<People> level1people,level2people,level3people,level4people,level5people,level6people;
    QStringList peopleNameList;
    QStringList awardNameList;
    QList<int> awardnTotal;
    QList<int> awardnCnt;
    QTimer *timer;
    int pickupIndex;
    int totalPeople;
    int totalAward;
    int nothaveTotalPeople;
    bool isRolling;
    bool isSaveResult;
    Phonon::MediaObject *bgmusic,*rollmusic,*rollfinishedmusic;

    int curAwardLevel;

    void hideAwardInfo(int cnt);
    void updateMusic();
signals:
    void sigUpdateList(const QStringList &list);
protected:
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);
private slots:
    void slotBrowseHeadPath();

    void slotTimeout();
    void on_award1ToolButton_clicked();
    void on_award2ToolButton_clicked();
    void on_award3ToolButton_clicked();
    void on_award4ToolButton_clicked();
    void on_setupToolButton_clicked();
    void on_musicToolButton_toggled(bool checked);
    void on_award5ToolButton_clicked();
    void on_award6ToolButton_clicked();

    void slotUpdateAwardPic(int awardlevel, QPixmap);
    void slotUpdateBgMusic(QString mp);
    void on_saveResultToolButton_clicked();
    void on_helpToolButton_clicked();
};

#endif // AWARDPICKUP_H
