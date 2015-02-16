#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include "MainRender.h"
#include "CConfig.h"

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT
public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();
    void loadini();
    void saveini();
public slots:
    void on_btnCancel_clicked();
    void on_btnRefresh_clicked();
    void on_btnSave_clicked();
private:
    Ui::Settings *ui;
    CConfig *m_con;
    bool m_isavailable;
private slots:
    void on_spHp_valueChanged(int arg1);
    void on_spDam_valueChanged(int arg1);
    void on_editX_lostFocus();
    void on_editY_lostFocus();
    void on_spBulSum_valueChanged(int arg1);
    void on_editBulSpeed_lostFocus();
    void on_chcShowFps_stateChanged(int arg1);
    void on_spFps_valueChanged(int arg1);
};

#endif // SETTINGS_H
