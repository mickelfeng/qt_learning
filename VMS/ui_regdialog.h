/********************************************************************************
** Form generated from reading UI file 'regdialog.ui'
**
** Created: Mon Feb 16 12:46:44 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGDIALOG_H
#define UI_REGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RegDialog
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *userLabel;
    QLineEdit *userLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *passworLable;
    QLineEdit *pwLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *regButton;
    QPushButton *cancleButton;

    void setupUi(QDialog *RegDialog)
    {
        if (RegDialog->objectName().isEmpty())
            RegDialog->setObjectName(QString::fromUtf8("RegDialog"));
        RegDialog->resize(300, 200);
        horizontalLayout_4 = new QHBoxLayout(RegDialog);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(30, 20, 30, 20);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 10, -1, 10);
        userLabel = new QLabel(RegDialog);
        userLabel->setObjectName(QString::fromUtf8("userLabel"));

        horizontalLayout->addWidget(userLabel);

        userLineEdit = new QLineEdit(RegDialog);
        userLineEdit->setObjectName(QString::fromUtf8("userLineEdit"));
        userLineEdit->setMaxLength(10);

        horizontalLayout->addWidget(userLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 10, 0, 10);
        passworLable = new QLabel(RegDialog);
        passworLable->setObjectName(QString::fromUtf8("passworLable"));

        horizontalLayout_2->addWidget(passworLable);

        pwLineEdit = new QLineEdit(RegDialog);
        pwLineEdit->setObjectName(QString::fromUtf8("pwLineEdit"));
        pwLineEdit->setMaxLength(16);
        pwLineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(pwLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(50);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        regButton = new QPushButton(RegDialog);
        regButton->setObjectName(QString::fromUtf8("regButton"));

        horizontalLayout_3->addWidget(regButton);

        cancleButton = new QPushButton(RegDialog);
        cancleButton->setObjectName(QString::fromUtf8("cancleButton"));

        horizontalLayout_3->addWidget(cancleButton);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout);


        retranslateUi(RegDialog);

        QMetaObject::connectSlotsByName(RegDialog);
    } // setupUi

    void retranslateUi(QDialog *RegDialog)
    {
        RegDialog->setWindowTitle(QApplication::translate("RegDialog", "\347\224\250\346\210\267\346\263\250\345\206\214", 0, QApplication::UnicodeUTF8));
        userLabel->setText(QApplication::translate("RegDialog", "\347\224\250\346\210\267\345\220\215", 0, QApplication::UnicodeUTF8));
        passworLable->setText(QApplication::translate("RegDialog", "\345\257\206  \347\240\201", 0, QApplication::UnicodeUTF8));
        regButton->setText(QApplication::translate("RegDialog", "\346\263\250\345\206\214", 0, QApplication::UnicodeUTF8));
        cancleButton->setText(QApplication::translate("RegDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RegDialog: public Ui_RegDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGDIALOG_H
