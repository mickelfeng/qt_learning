/********************************************************************************
** Form generated from reading UI file 'Settings.ui'
**
** Created: Mon Feb 16 11:07:44 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_6;
    QSpinBox *spHp;
    QLabel *label_7;
    QSpinBox *spBulSum;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_7;
    QSpinBox *spDam;
    QLabel *label_9;
    QLineEdit *editBulSpeed;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *editX;
    QLabel *label_6;
    QLineEdit *editY;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QCheckBox *chcShowFps;
    QLabel *label_3;
    QSpinBox *spFps;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnRefresh;
    QPushButton *btnSave;
    QPushButton *btnCancel;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->resize(308, 216);
        Settings->setWindowOpacity(0.9);
        groupBox = new QGroupBox(Settings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(9, 9, 291, 110));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 0, 1, 1, 2);

        spHp = new QSpinBox(groupBox);
        spHp->setObjectName(QString::fromUtf8("spHp"));
        spHp->setMinimum(1);

        gridLayout->addWidget(spHp, 0, 4, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 0, 5, 1, 3);

        spBulSum = new QSpinBox(groupBox);
        spBulSum->setObjectName(QString::fromUtf8("spBulSum"));
        spBulSum->setMinimum(1);
        spBulSum->setMaximum(20);

        gridLayout->addWidget(spBulSum, 0, 8, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 2);

        horizontalSpacer_7 = new QSpacerItem(21, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 1, 2, 1, 2);

        spDam = new QSpinBox(groupBox);
        spDam->setObjectName(QString::fromUtf8("spDam"));
        spDam->setMinimum(1);

        gridLayout->addWidget(spDam, 1, 4, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 1, 5, 1, 2);

        editBulSpeed = new QLineEdit(groupBox);
        editBulSpeed->setObjectName(QString::fromUtf8("editBulSpeed"));

        gridLayout->addWidget(editBulSpeed, 1, 7, 1, 2);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 2);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 2, 1, 1);

        editX = new QLineEdit(groupBox);
        editX->setObjectName(QString::fromUtf8("editX"));

        gridLayout->addWidget(editX, 2, 3, 1, 3);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 2, 6, 1, 1);

        editY = new QLineEdit(groupBox);
        editY->setObjectName(QString::fromUtf8("editY"));

        gridLayout->addWidget(editY, 2, 7, 1, 2);

        groupBox_2 = new QGroupBox(Settings);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 120, 223, 52));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        chcShowFps = new QCheckBox(groupBox_2);
        chcShowFps->setObjectName(QString::fromUtf8("chcShowFps"));
        chcShowFps->setLayoutDirection(Qt::LeftToRight);
        chcShowFps->setTristate(false);

        gridLayout_2->addWidget(chcShowFps, 0, 0, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 1, 1, 1);

        spFps = new QSpinBox(groupBox_2);
        spFps->setObjectName(QString::fromUtf8("spFps"));
        spFps->setMinimum(5);
        spFps->setMaximum(999);
        spFps->setValue(5);

        gridLayout_2->addWidget(spFps, 0, 2, 1, 1);

        widget = new QWidget(Settings);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 180, 239, 25));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnRefresh = new QPushButton(widget);
        btnRefresh->setObjectName(QString::fromUtf8("btnRefresh"));

        horizontalLayout->addWidget(btnRefresh);

        btnSave = new QPushButton(widget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        horizontalLayout->addWidget(btnSave);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        QWidget::setTabOrder(spHp, spDam);
        QWidget::setTabOrder(spDam, editX);
        QWidget::setTabOrder(editX, editY);
        QWidget::setTabOrder(editY, editBulSpeed);
        QWidget::setTabOrder(editBulSpeed, chcShowFps);
        QWidget::setTabOrder(chcShowFps, spFps);
        QWidget::setTabOrder(spFps, btnRefresh);
        QWidget::setTabOrder(btnRefresh, btnSave);
        QWidget::setTabOrder(btnSave, btnCancel);

        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "\346\270\270\346\210\217\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Settings", "\346\210\230\346\234\272\350\256\276\345\256\232", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Settings", "HP\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        spHp->setStatusTip(QApplication::translate("Settings", "1", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        label_7->setText(QApplication::translate("Settings", "\345\261\217\345\271\225\345\255\220\345\274\271\346\225\260\351\207\217\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        spBulSum->setStatusTip(QApplication::translate("Settings", "5", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        label_2->setText(QApplication::translate("Settings", "\346\224\273\345\207\273\345\212\233\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        spDam->setStatusTip(QApplication::translate("Settings", "2", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        label_9->setText(QApplication::translate("Settings", "\345\255\220\345\274\271\351\200\237\345\272\246\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        editBulSpeed->setStatusTip(QApplication::translate("Settings", "7", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        label_4->setText(QApplication::translate("Settings", "\350\265\267\345\247\213\344\275\215\347\275\256\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Settings", "X\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        editX->setStatusTip(QApplication::translate("Settings", "3", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        label_6->setText(QApplication::translate("Settings", "Y\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        editY->setStatusTip(QApplication::translate("Settings", "4", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        groupBox_2->setTitle(QApplication::translate("Settings", "\345\205\250\345\261\200\350\256\276\345\256\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        chcShowFps->setStatusTip(QApplication::translate("Settings", "8", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        chcShowFps->setText(QApplication::translate("Settings", "\346\230\276\347\244\272FPS", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Settings", "\345\210\267\346\226\260\351\227\264\351\232\224(ms)\357\274\232", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        spFps->setStatusTip(QApplication::translate("Settings", "9", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        btnRefresh->setText(QApplication::translate("Settings", "\345\210\267\346\226\260\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        btnSave->setText(QApplication::translate("Settings", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("Settings", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
