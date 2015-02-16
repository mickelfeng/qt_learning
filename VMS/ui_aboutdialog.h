/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created: Mon Feb 16 12:46:44 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *iconLabel;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_10;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_11;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_5;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QString::fromUtf8("AboutDialog"));
        AboutDialog->resize(400, 300);
        horizontalLayout_4 = new QHBoxLayout(AboutDialog);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 20, 150, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        iconLabel = new QLabel(AboutDialog);
        iconLabel->setObjectName(QString::fromUtf8("iconLabel"));
        iconLabel->setMinimumSize(QSize(100, 100));
        iconLabel->setMaximumSize(QSize(100, 100));
        iconLabel->setScaledContents(true);

        horizontalLayout_3->addWidget(iconLabel);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(90, 20, -1, -1);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_10 = new QLabel(AboutDialog);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout->addWidget(label_10);

        label = new QLabel(AboutDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(60, 14));

        verticalLayout->addWidget(label);

        label_3 = new QLabel(AboutDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(60, 14));

        verticalLayout->addWidget(label_3);

        label_6 = new QLabel(AboutDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMaximumSize(QSize(60, 14));

        verticalLayout->addWidget(label_6);

        label_8 = new QLabel(AboutDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMaximumSize(QSize(60, 14));

        verticalLayout->addWidget(label_8);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_11 = new QLabel(AboutDialog);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_2->addWidget(label_11);

        label_2 = new QLabel(AboutDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(36, 14));

        verticalLayout_2->addWidget(label_2);

        label_4 = new QLabel(AboutDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(70, 14));

        verticalLayout_2->addWidget(label_4);

        label_7 = new QLabel(AboutDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMaximumSize(QSize(216, 14));
        label_7->setOpenExternalLinks(true);

        verticalLayout_2->addWidget(label_7);

        label_9 = new QLabel(AboutDialog);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMaximumSize(QSize(110, 14));
        label_9->setOpenExternalLinks(true);

        verticalLayout_2->addWidget(label_9);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 150, 20);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_5 = new QLabel(AboutDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(100, 0));

        horizontalLayout_2->addWidget(label_5);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(AboutDialog);

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QApplication::translate("AboutDialog", "\345\205\263\344\272\216", 0, QApplication::UnicodeUTF8));
        iconLabel->setText(QString());
        label_10->setText(QApplication::translate("AboutDialog", "\351\241\271 \347\233\256 \345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AboutDialog", "\344\275\234    \350\200\205\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AboutDialog", "\346\214\207\345\257\274\346\225\231\345\270\210\357\274\232", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("AboutDialog", "\351\241\271\347\233\256\345\234\260\345\235\200\357\274\232", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("AboutDialog", "\350\201\224\347\263\273\351\202\256\347\274\226\357\274\232", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("AboutDialog", "VMS", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AboutDialog", "\350\265\265\350\245\277\345\205\203", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AboutDialog", "\345\210\230\351\276\231 \345\274\240\346\226\260\345\274\272", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("AboutDialog", "<html><head/><body><p><a href=\"http://git.oschina.net/SharerMax/VMS\"><span style=\" text-decoration: underline; color:#0000ff;\">http://git.oschina.net/SharerMax/VMS</span></a></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("AboutDialog", "<html><head/><body><p><a href=\"mailto:mdcw1103@gmail.com\"><span style=\" text-decoration: underline; color:#0000ff;\">mdcw1103@gmail.com</span></a></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("AboutDialog", "\345\244\247\350\277\236\344\270\234\350\275\257\344\277\241\346\201\257\345\255\246\351\231\242", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
