/********************************************************************************
** Form generated from reading UI file 'setupdialog.ui'
**
** Created: Mon Feb 16 11:39:49 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUPDIALOG_H
#define UI_SETUPDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SetupDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *awardLevelsSpinBox;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *award1LineEdit;
    QSpinBox *award1CntSpinBox;
    QToolButton *setupAward1IconToolButton;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *award2LineEdit;
    QSpinBox *award2CntSpinBox;
    QToolButton *setupAward2IconToolButton;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *award3LineEdit;
    QSpinBox *award3CntSpinBox;
    QToolButton *setupAward3IconToolButton;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *award4LineEdit;
    QSpinBox *award4CntSpinBox;
    QToolButton *setupAward4IconToolButton;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *award5LineEdit;
    QSpinBox *award5CntSpinBox;
    QToolButton *setupAward5IconToolButton;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *award6LineEdit;
    QSpinBox *award6CntSpinBox;
    QToolButton *setupAward6IconToolButton;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_7;
    QListWidget *peopleListWidget;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QLabel *totalPeopleCntLabel;
    QPushButton *updateListPushButton;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton;
    QPushButton *changeMusicPushButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SetupDialog)
    {
        if (SetupDialog->objectName().isEmpty())
            SetupDialog->setObjectName(QString::fromUtf8("SetupDialog"));
        SetupDialog->resize(556, 462);
        verticalLayout_3 = new QVBoxLayout(SetupDialog);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(SetupDialog);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        awardLevelsSpinBox = new QSpinBox(SetupDialog);
        awardLevelsSpinBox->setObjectName(QString::fromUtf8("awardLevelsSpinBox"));
        awardLevelsSpinBox->setFont(font);
        awardLevelsSpinBox->setMinimum(1);
        awardLevelsSpinBox->setMaximum(6);
        awardLevelsSpinBox->setValue(6);

        horizontalLayout->addWidget(awardLevelsSpinBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        award1LineEdit = new QLineEdit(SetupDialog);
        award1LineEdit->setObjectName(QString::fromUtf8("award1LineEdit"));
        award1LineEdit->setFont(font);

        horizontalLayout_2->addWidget(award1LineEdit);

        award1CntSpinBox = new QSpinBox(SetupDialog);
        award1CntSpinBox->setObjectName(QString::fromUtf8("award1CntSpinBox"));
        award1CntSpinBox->setFont(font);
        award1CntSpinBox->setMaximum(100);
        award1CntSpinBox->setValue(1);

        horizontalLayout_2->addWidget(award1CntSpinBox);

        setupAward1IconToolButton = new QToolButton(SetupDialog);
        setupAward1IconToolButton->setObjectName(QString::fromUtf8("setupAward1IconToolButton"));
        setupAward1IconToolButton->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/award1.png"), QSize(), QIcon::Normal, QIcon::Off);
        setupAward1IconToolButton->setIcon(icon);
        setupAward1IconToolButton->setIconSize(QSize(48, 48));
        setupAward1IconToolButton->setAutoRaise(false);

        horizontalLayout_2->addWidget(setupAward1IconToolButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        award2LineEdit = new QLineEdit(SetupDialog);
        award2LineEdit->setObjectName(QString::fromUtf8("award2LineEdit"));
        award2LineEdit->setFont(font);

        horizontalLayout_3->addWidget(award2LineEdit);

        award2CntSpinBox = new QSpinBox(SetupDialog);
        award2CntSpinBox->setObjectName(QString::fromUtf8("award2CntSpinBox"));
        award2CntSpinBox->setFont(font);
        award2CntSpinBox->setMaximum(100);
        award2CntSpinBox->setValue(2);

        horizontalLayout_3->addWidget(award2CntSpinBox);

        setupAward2IconToolButton = new QToolButton(SetupDialog);
        setupAward2IconToolButton->setObjectName(QString::fromUtf8("setupAward2IconToolButton"));
        setupAward2IconToolButton->setAutoFillBackground(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/award2.png"), QSize(), QIcon::Normal, QIcon::Off);
        setupAward2IconToolButton->setIcon(icon1);
        setupAward2IconToolButton->setIconSize(QSize(48, 48));
        setupAward2IconToolButton->setAutoRaise(false);

        horizontalLayout_3->addWidget(setupAward2IconToolButton);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        award3LineEdit = new QLineEdit(SetupDialog);
        award3LineEdit->setObjectName(QString::fromUtf8("award3LineEdit"));
        award3LineEdit->setFont(font);

        horizontalLayout_4->addWidget(award3LineEdit);

        award3CntSpinBox = new QSpinBox(SetupDialog);
        award3CntSpinBox->setObjectName(QString::fromUtf8("award3CntSpinBox"));
        award3CntSpinBox->setFont(font);
        award3CntSpinBox->setMaximum(100);
        award3CntSpinBox->setValue(3);

        horizontalLayout_4->addWidget(award3CntSpinBox);

        setupAward3IconToolButton = new QToolButton(SetupDialog);
        setupAward3IconToolButton->setObjectName(QString::fromUtf8("setupAward3IconToolButton"));
        setupAward3IconToolButton->setAutoFillBackground(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/award3.png"), QSize(), QIcon::Normal, QIcon::Off);
        setupAward3IconToolButton->setIcon(icon2);
        setupAward3IconToolButton->setIconSize(QSize(48, 48));
        setupAward3IconToolButton->setAutoRaise(false);

        horizontalLayout_4->addWidget(setupAward3IconToolButton);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        award4LineEdit = new QLineEdit(SetupDialog);
        award4LineEdit->setObjectName(QString::fromUtf8("award4LineEdit"));
        award4LineEdit->setFont(font);

        horizontalLayout_5->addWidget(award4LineEdit);

        award4CntSpinBox = new QSpinBox(SetupDialog);
        award4CntSpinBox->setObjectName(QString::fromUtf8("award4CntSpinBox"));
        award4CntSpinBox->setFont(font);
        award4CntSpinBox->setMaximum(300);
        award4CntSpinBox->setValue(5);

        horizontalLayout_5->addWidget(award4CntSpinBox);

        setupAward4IconToolButton = new QToolButton(SetupDialog);
        setupAward4IconToolButton->setObjectName(QString::fromUtf8("setupAward4IconToolButton"));
        setupAward4IconToolButton->setAutoFillBackground(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/award4.png"), QSize(), QIcon::Normal, QIcon::Off);
        setupAward4IconToolButton->setIcon(icon3);
        setupAward4IconToolButton->setIconSize(QSize(48, 48));
        setupAward4IconToolButton->setAutoRaise(false);

        horizontalLayout_5->addWidget(setupAward4IconToolButton);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        award5LineEdit = new QLineEdit(SetupDialog);
        award5LineEdit->setObjectName(QString::fromUtf8("award5LineEdit"));
        award5LineEdit->setFont(font);

        horizontalLayout_6->addWidget(award5LineEdit);

        award5CntSpinBox = new QSpinBox(SetupDialog);
        award5CntSpinBox->setObjectName(QString::fromUtf8("award5CntSpinBox"));
        QFont font1;
        font1.setPointSize(22);
        award5CntSpinBox->setFont(font1);
        award5CntSpinBox->setMaximum(300);
        award5CntSpinBox->setValue(10);

        horizontalLayout_6->addWidget(award5CntSpinBox);

        setupAward5IconToolButton = new QToolButton(SetupDialog);
        setupAward5IconToolButton->setObjectName(QString::fromUtf8("setupAward5IconToolButton"));
        setupAward5IconToolButton->setAutoFillBackground(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/award5.png"), QSize(), QIcon::Normal, QIcon::Off);
        setupAward5IconToolButton->setIcon(icon4);
        setupAward5IconToolButton->setIconSize(QSize(48, 48));
        setupAward5IconToolButton->setAutoRaise(false);

        horizontalLayout_6->addWidget(setupAward5IconToolButton);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        award6LineEdit = new QLineEdit(SetupDialog);
        award6LineEdit->setObjectName(QString::fromUtf8("award6LineEdit"));
        award6LineEdit->setFont(font);

        horizontalLayout_8->addWidget(award6LineEdit);

        award6CntSpinBox = new QSpinBox(SetupDialog);
        award6CntSpinBox->setObjectName(QString::fromUtf8("award6CntSpinBox"));
        award6CntSpinBox->setFont(font);
        award6CntSpinBox->setMaximum(500);
        award6CntSpinBox->setValue(20);

        horizontalLayout_8->addWidget(award6CntSpinBox);

        setupAward6IconToolButton = new QToolButton(SetupDialog);
        setupAward6IconToolButton->setObjectName(QString::fromUtf8("setupAward6IconToolButton"));
        setupAward6IconToolButton->setAutoFillBackground(false);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/award6.png"), QSize(), QIcon::Normal, QIcon::Off);
        setupAward6IconToolButton->setIcon(icon5);
        setupAward6IconToolButton->setIconSize(QSize(48, 48));
        setupAward6IconToolButton->setAutoRaise(false);

        horizontalLayout_8->addWidget(setupAward6IconToolButton);


        verticalLayout->addLayout(horizontalLayout_8);


        horizontalLayout_9->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_7 = new QLabel(SetupDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_7);

        peopleListWidget = new QListWidget(SetupDialog);
        peopleListWidget->setObjectName(QString::fromUtf8("peopleListWidget"));

        verticalLayout_2->addWidget(peopleListWidget);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_8 = new QLabel(SetupDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QFont font2;
        font2.setPointSize(10);
        label_8->setFont(font2);
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_8);

        totalPeopleCntLabel = new QLabel(SetupDialog);
        totalPeopleCntLabel->setObjectName(QString::fromUtf8("totalPeopleCntLabel"));
        QFont font3;
        font3.setPointSize(15);
        totalPeopleCntLabel->setFont(font3);

        horizontalLayout_7->addWidget(totalPeopleCntLabel);

        updateListPushButton = new QPushButton(SetupDialog);
        updateListPushButton->setObjectName(QString::fromUtf8("updateListPushButton"));

        horizontalLayout_7->addWidget(updateListPushButton);


        verticalLayout_2->addLayout(horizontalLayout_7);


        horizontalLayout_9->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        pushButton = new QPushButton(SetupDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_10->addWidget(pushButton);

        changeMusicPushButton = new QPushButton(SetupDialog);
        changeMusicPushButton->setObjectName(QString::fromUtf8("changeMusicPushButton"));

        horizontalLayout_10->addWidget(changeMusicPushButton);

        buttonBox = new QDialogButtonBox(SetupDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_10->addWidget(buttonBox);


        verticalLayout_3->addLayout(horizontalLayout_10);


        retranslateUi(SetupDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SetupDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SetupDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SetupDialog);
    } // setupUi

    void retranslateUi(QDialog *SetupDialog)
    {
        SetupDialog->setWindowTitle(QApplication::translate("SetupDialog", "\345\245\226\351\241\271\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SetupDialog", "\345\245\226\351\241\271\347\255\211\347\272\247\346\225\260\357\274\232", 0, QApplication::UnicodeUTF8));
        award1LineEdit->setText(QApplication::translate("SetupDialog", "\347\245\236\347\247\230\345\244\247\345\245\226", 0, QApplication::UnicodeUTF8));
        setupAward1IconToolButton->setText(QApplication::translate("SetupDialog", "...", 0, QApplication::UnicodeUTF8));
        award2LineEdit->setText(QApplication::translate("SetupDialog", "\344\270\200\347\255\211\345\245\226", 0, QApplication::UnicodeUTF8));
        setupAward2IconToolButton->setText(QApplication::translate("SetupDialog", "...", 0, QApplication::UnicodeUTF8));
        award3LineEdit->setText(QApplication::translate("SetupDialog", "\344\272\214\347\255\211\345\245\226", 0, QApplication::UnicodeUTF8));
        setupAward3IconToolButton->setText(QApplication::translate("SetupDialog", "...", 0, QApplication::UnicodeUTF8));
        award4LineEdit->setText(QApplication::translate("SetupDialog", "\344\270\211\347\255\211\345\245\226", 0, QApplication::UnicodeUTF8));
        setupAward4IconToolButton->setText(QApplication::translate("SetupDialog", "...", 0, QApplication::UnicodeUTF8));
        award5LineEdit->setText(QApplication::translate("SetupDialog", "\345\233\233\347\255\211\345\245\226", 0, QApplication::UnicodeUTF8));
        setupAward5IconToolButton->setText(QApplication::translate("SetupDialog", "...", 0, QApplication::UnicodeUTF8));
        award6LineEdit->setText(QApplication::translate("SetupDialog", "\350\256\260\345\277\265\345\245\226", 0, QApplication::UnicodeUTF8));
        setupAward6IconToolButton->setText(QApplication::translate("SetupDialog", "...", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("SetupDialog", "\345\217\202\344\270\216\346\212\275\345\245\226\344\272\272\345\221\230\345\220\215\345\215\225", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("SetupDialog", "\346\200\273\344\272\272\346\225\260\357\274\232", 0, QApplication::UnicodeUTF8));
        totalPeopleCntLabel->setText(QString());
        updateListPushButton->setText(QApplication::translate("SetupDialog", "\351\207\215\346\226\260\345\212\240\350\275\275\345\217\202\344\270\216\346\212\275\345\245\226\344\272\272\345\221\230", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("SetupDialog", "\346\233\264\346\215\242\350\203\214\346\231\257\345\233\276", 0, QApplication::UnicodeUTF8));
        changeMusicPushButton->setText(QApplication::translate("SetupDialog", "\346\233\264\346\215\242\350\203\214\346\231\257\351\237\263\344\271\220", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SetupDialog: public Ui_SetupDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUPDIALOG_H
