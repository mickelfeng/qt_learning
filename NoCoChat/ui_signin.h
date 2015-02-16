/********************************************************************************
** Form generated from reading UI file 'signin.ui'
**
** Created: Mon Feb 16 12:55:56 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNIN_H
#define UI_SIGNIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Signin
{
public:
    QPushButton *b_signin;
    QLineEdit *user_id;
    QLineEdit *password;
    QLabel *label;
    QLabel *label_2;
    QPushButton *b_login;

    void setupUi(QDialog *Signin)
    {
        if (Signin->objectName().isEmpty())
            Signin->setObjectName(QString::fromUtf8("Signin"));
        Signin->resize(389, 274);
        Signin->setMinimumSize(QSize(389, 274));
        Signin->setMaximumSize(QSize(389, 274));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/SiseChat.png"), QSize(), QIcon::Normal, QIcon::Off);
        Signin->setWindowIcon(icon);
        Signin->setStyleSheet(QString::fromUtf8("background-image: url(:/img/15.jpg);"));
        b_signin = new QPushButton(Signin);
        b_signin->setObjectName(QString::fromUtf8("b_signin"));
        b_signin->setGeometry(QRect(60, 210, 71, 31));
        b_signin->setStyleSheet(QString::fromUtf8("font: 75 12pt \"\346\245\267\344\275\223\";"));
        user_id = new QLineEdit(Signin);
        user_id->setObjectName(QString::fromUtf8("user_id"));
        user_id->setGeometry(QRect(150, 80, 141, 20));
        user_id->setStyleSheet(QString::fromUtf8("font: 12pt;"));
        password = new QLineEdit(Signin);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(150, 140, 141, 20));
        password->setStyleSheet(QString::fromUtf8("font: 12pt;"));
        password->setEchoMode(QLineEdit::Password);
        label = new QLabel(Signin);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 80, 61, 21));
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("font: 75 12pt \"\346\226\260\345\256\213\344\275\223\";"));
        label_2 = new QLabel(Signin);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 140, 61, 21));
        label_2->setStyleSheet(QString::fromUtf8("font: 75 12pt \"\346\226\260\345\256\213\344\275\223\";"));
        b_login = new QPushButton(Signin);
        b_login->setObjectName(QString::fromUtf8("b_login"));
        b_login->setGeometry(QRect(150, 210, 71, 31));
        b_login->setStyleSheet(QString::fromUtf8("font: 75 12pt \"\346\245\267\344\275\223\";"));

        retranslateUi(Signin);

        QMetaObject::connectSlotsByName(Signin);
    } // setupUi

    void retranslateUi(QDialog *Signin)
    {
        Signin->setWindowTitle(QApplication::translate("Signin", "\346\254\242\350\277\216\347\231\273\351\231\206NoCoChat", 0, QApplication::UnicodeUTF8));
        b_signin->setText(QApplication::translate("Signin", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Signin", "\345\270\220\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Signin", "\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        b_login->setText(QApplication::translate("Signin", "\346\263\250\345\206\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Signin: public Ui_Signin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNIN_H
