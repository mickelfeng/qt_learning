/********************************************************************************
** Form generated from reading UI file 'amendpwdialog.ui'
**
** Created: Mon Feb 16 12:46:44 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AMENDPWDIALOG_H
#define UI_AMENDPWDIALOG_H

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

class Ui_AmendPWDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *userLabel;
    QLabel *passworLable;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *userLineEdit;
    QLineEdit *pwLineEdit;
    QLineEdit *newPWlineEdit;
    QLineEdit *newPwlineEdit2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *amendOKButton;
    QPushButton *amendCancleButton;

    void setupUi(QDialog *AmendPWDialog)
    {
        if (AmendPWDialog->objectName().isEmpty())
            AmendPWDialog->setObjectName(QString::fromUtf8("AmendPWDialog"));
        AmendPWDialog->resize(336, 250);
        verticalLayout_4 = new QVBoxLayout(AmendPWDialog);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(30, 30, 30, 50);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        userLabel = new QLabel(AmendPWDialog);
        userLabel->setObjectName(QString::fromUtf8("userLabel"));

        verticalLayout->addWidget(userLabel);

        passworLable = new QLabel(AmendPWDialog);
        passworLable->setObjectName(QString::fromUtf8("passworLable"));

        verticalLayout->addWidget(passworLable);

        label = new QLabel(AmendPWDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(AmendPWDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        userLineEdit = new QLineEdit(AmendPWDialog);
        userLineEdit->setObjectName(QString::fromUtf8("userLineEdit"));
        userLineEdit->setMaxLength(10);

        verticalLayout_2->addWidget(userLineEdit);

        pwLineEdit = new QLineEdit(AmendPWDialog);
        pwLineEdit->setObjectName(QString::fromUtf8("pwLineEdit"));
        pwLineEdit->setMaxLength(16);
        pwLineEdit->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(pwLineEdit);

        newPWlineEdit = new QLineEdit(AmendPWDialog);
        newPWlineEdit->setObjectName(QString::fromUtf8("newPWlineEdit"));
        newPWlineEdit->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(newPWlineEdit);

        newPwlineEdit2 = new QLineEdit(AmendPWDialog);
        newPwlineEdit2->setObjectName(QString::fromUtf8("newPwlineEdit2"));
        newPwlineEdit2->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(newPwlineEdit2);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 20, -1, 0);
        amendOKButton = new QPushButton(AmendPWDialog);
        amendOKButton->setObjectName(QString::fromUtf8("amendOKButton"));

        horizontalLayout_2->addWidget(amendOKButton);

        amendCancleButton = new QPushButton(AmendPWDialog);
        amendCancleButton->setObjectName(QString::fromUtf8("amendCancleButton"));

        horizontalLayout_2->addWidget(amendCancleButton);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(AmendPWDialog);

        QMetaObject::connectSlotsByName(AmendPWDialog);
    } // setupUi

    void retranslateUi(QDialog *AmendPWDialog)
    {
        AmendPWDialog->setWindowTitle(QApplication::translate("AmendPWDialog", "\345\257\206\347\240\201\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        userLabel->setText(QApplication::translate("AmendPWDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        passworLable->setText(QApplication::translate("AmendPWDialog", "\345\257\206  \347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AmendPWDialog", "\346\226\260\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AmendPWDialog", "\347\241\256\350\256\244\346\226\260\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        amendOKButton->setText(QApplication::translate("AmendPWDialog", "\347\241\256\350\256\244", 0, QApplication::UnicodeUTF8));
        amendCancleButton->setText(QApplication::translate("AmendPWDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AmendPWDialog: public Ui_AmendPWDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AMENDPWDIALOG_H
