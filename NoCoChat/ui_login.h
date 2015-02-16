/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created: Mon Feb 16 12:55:56 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QPushButton *ok;
    QPushButton *cancel;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLineEdit *user_id;
    QLabel *label;
    QLineEdit *name;
    QLabel *label_2;
    QRadioButton *male;
    QRadioButton *female;
    QLabel *label_3;
    QLineEdit *pwd;
    QLabel *label_4;
    QLineEdit *pwd_1;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(346, 394);
        Login->setMinimumSize(QSize(346, 394));
        Login->setMaximumSize(QSize(346, 394));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/Novo_Dangos_001.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Login->setWindowIcon(icon);
        Login->setStyleSheet(QString::fromUtf8("background-image: url(:/img/login.jpg);"));
        ok = new QPushButton(Login);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(40, 230, 75, 23));
        cancel = new QPushButton(Login);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(40, 270, 75, 23));
        widget = new QWidget(Login);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 40, 271, 181));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 12pt"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        user_id = new QLineEdit(widget);
        user_id->setObjectName(QString::fromUtf8("user_id"));
        user_id->setStyleSheet(QString::fromUtf8("font: 12pt"));

        gridLayout->addWidget(user_id, 0, 1, 1, 2);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 12pt"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        name = new QLineEdit(widget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setStyleSheet(QString::fromUtf8("font: 12pt"));

        gridLayout->addWidget(name, 1, 1, 1, 2);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        male = new QRadioButton(widget);
        male->setObjectName(QString::fromUtf8("male"));
        male->setStyleSheet(QString::fromUtf8("font: 12pt"));

        gridLayout->addWidget(male, 2, 1, 1, 1);

        female = new QRadioButton(widget);
        female->setObjectName(QString::fromUtf8("female"));
        female->setStyleSheet(QString::fromUtf8("font: 12pt"));

        gridLayout->addWidget(female, 2, 2, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 12pt"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        pwd = new QLineEdit(widget);
        pwd->setObjectName(QString::fromUtf8("pwd"));
        pwd->setStyleSheet(QString::fromUtf8("font: 12pt"));

        gridLayout->addWidget(pwd, 3, 1, 1, 2);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 12pt"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        pwd_1 = new QLineEdit(widget);
        pwd_1->setObjectName(QString::fromUtf8("pwd_1"));
        pwd_1->setStyleSheet(QString::fromUtf8("font: 12pt"));

        gridLayout->addWidget(pwd_1, 4, 1, 1, 2);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "\346\263\250\345\206\214\350\264\246\346\210\267", 0, QApplication::UnicodeUTF8));
        ok->setText(QApplication::translate("Login", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        cancel->setText(QApplication::translate("Login", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Login", "\345\270\220\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Login", "\346\230\265\347\247\260\357\274\232", 0, QApplication::UnicodeUTF8));
        name->setText(QString());
        label_2->setText(QApplication::translate("Login", "\346\200\247\345\210\253\357\274\232", 0, QApplication::UnicodeUTF8));
        male->setText(QApplication::translate("Login", "\347\224\267", 0, QApplication::UnicodeUTF8));
        female->setText(QApplication::translate("Login", "\345\245\263", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Login", "\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Login", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
