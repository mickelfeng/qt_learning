/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Feb 16 11:01:33 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_Clear;
    QPushButton *pushButton_Login;
    QLineEdit *lineEdit_Passwd;
    QLineEdit *lineEdit_Username;
    QLabel *label_Username;
    QLabel *label_Passwd;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(352, 211);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setBold(true);
        font.setWeight(75);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton_Clear = new QPushButton(centralWidget);
        pushButton_Clear->setObjectName(QString::fromUtf8("pushButton_Clear"));
        pushButton_Clear->setGeometry(QRect(220, 160, 75, 23));
        pushButton_Login = new QPushButton(centralWidget);
        pushButton_Login->setObjectName(QString::fromUtf8("pushButton_Login"));
        pushButton_Login->setGeometry(QRect(100, 159, 75, 23));
        lineEdit_Passwd = new QLineEdit(centralWidget);
        lineEdit_Passwd->setObjectName(QString::fromUtf8("lineEdit_Passwd"));
        lineEdit_Passwd->setGeometry(QRect(140, 100, 151, 20));
        lineEdit_Passwd->setContextMenuPolicy(Qt::DefaultContextMenu);
        lineEdit_Passwd->setAcceptDrops(false);
        lineEdit_Passwd->setEchoMode(QLineEdit::Password);
        lineEdit_Username = new QLineEdit(centralWidget);
        lineEdit_Username->setObjectName(QString::fromUtf8("lineEdit_Username"));
        lineEdit_Username->setGeometry(QRect(140, 70, 151, 20));
        lineEdit_Username->setFocusPolicy(Qt::StrongFocus);
        label_Username = new QLabel(centralWidget);
        label_Username->setObjectName(QString::fromUtf8("label_Username"));
        label_Username->setGeometry(QRect(60, 71, 71, 16));
        label_Passwd = new QLabel(centralWidget);
        label_Passwd->setObjectName(QString::fromUtf8("label_Passwd"));
        label_Passwd->setGeometry(QRect(60, 101, 71, 16));
        MainWindow->setCentralWidget(centralWidget);
        pushButton_Clear->raise();
        pushButton_Login->raise();
        label_Username->raise();
        label_Passwd->raise();
        lineEdit_Passwd->raise();
        lineEdit_Username->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        pushButton_Clear->setText(QApplication::translate("MainWindow", "\351\207\215\347\275\256", 0, QApplication::UnicodeUTF8));
        pushButton_Login->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        label_Username->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_Passwd->setText(QApplication::translate("MainWindow", "\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
