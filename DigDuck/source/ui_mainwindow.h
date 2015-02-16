/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Feb 16 11:04:52 2015
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
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_portScan;
    QAction *action_about;
    QAction *action_host;
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label;
    QLineEdit *lineEdit_end;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_6;
    QLineEdit *lineEdit_port;
    QPushButton *pushButton_portBegin;
    QPushButton *pushButton_portEnd;
    QLabel *label_7;
    QTextEdit *textEdit_port;
    QLineEdit *lineEdit_begin;
    QProgressBar *progressBar;
    QWidget *page_2;
    QGroupBox *groupBox;
    QTableView *tableView;
    QPushButton *pushButton_interface;
    QGroupBox *groupBox_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label_3;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(705, 419);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        action_portScan = new QAction(MainWindow);
        action_portScan->setObjectName(QString::fromUtf8("action_portScan"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/port.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_portScan->setIcon(icon);
        action_about = new QAction(MainWindow);
        action_about->setObjectName(QString::fromUtf8("action_about"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_about->setIcon(icon1);
        action_host = new QAction(MainWindow);
        action_host->setObjectName(QString::fromUtf8("action_host"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/ftp.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_host->setIcon(icon2);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 701, 351));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 170, 51, 20));
        lineEdit_end = new QLineEdit(page);
        lineEdit_end->setObjectName(QString::fromUtf8("lineEdit_end"));
        lineEdit_end->setGeometry(QRect(63, 35, 133, 20));
        label_5 = new QLabel(page);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(9, 35, 48, 16));
        label_4 = new QLabel(page);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(9, 9, 48, 16));
        label_6 = new QLabel(page);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(220, 10, 36, 16));
        lineEdit_port = new QLineEdit(page);
        lineEdit_port->setObjectName(QString::fromUtf8("lineEdit_port"));
        lineEdit_port->setGeometry(QRect(270, 10, 171, 20));
        pushButton_portBegin = new QPushButton(page);
        pushButton_portBegin->setObjectName(QString::fromUtf8("pushButton_portBegin"));
        pushButton_portBegin->setGeometry(QRect(480, 10, 75, 41));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_portBegin->sizePolicy().hasHeightForWidth());
        pushButton_portBegin->setSizePolicy(sizePolicy);
        pushButton_portEnd = new QPushButton(page);
        pushButton_portEnd->setObjectName(QString::fromUtf8("pushButton_portEnd"));
        pushButton_portEnd->setGeometry(QRect(600, 10, 75, 41));
        sizePolicy.setHeightForWidth(pushButton_portEnd->sizePolicy().hasHeightForWidth());
        pushButton_portEnd->setSizePolicy(sizePolicy);
        label_7 = new QLabel(page);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(220, 40, 36, 16));
        textEdit_port = new QTextEdit(page);
        textEdit_port->setObjectName(QString::fromUtf8("textEdit_port"));
        textEdit_port->setGeometry(QRect(9, 61, 681, 281));
        sizePolicy.setHeightForWidth(textEdit_port->sizePolicy().hasHeightForWidth());
        textEdit_port->setSizePolicy(sizePolicy);
        textEdit_port->setMinimumSize(QSize(0, 0));
        lineEdit_begin = new QLineEdit(page);
        lineEdit_begin->setObjectName(QString::fromUtf8("lineEdit_begin"));
        lineEdit_begin->setGeometry(QRect(63, 9, 133, 20));
        progressBar = new QProgressBar(page);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(270, 40, 201, 20));
        progressBar->setValue(0);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        groupBox = new QGroupBox(page_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 10, 701, 211));
        tableView = new QTableView(groupBox);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(20, 20, 611, 181));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy1);
        pushButton_interface = new QPushButton(groupBox);
        pushButton_interface->setObjectName(QString::fromUtf8("pushButton_interface"));
        pushButton_interface->setGeometry(QRect(650, 20, 31, 181));
        groupBox_2 = new QGroupBox(page_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 230, 691, 111));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 30, 91, 20));
        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(150, 30, 331, 20));
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(650, 20, 31, 71));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 60, 441, 31));
        stackedWidget->addWidget(page_2);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 705, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        sizePolicy1.setHeightForWidth(statusBar->sizePolicy().hasHeightForWidth());
        statusBar->setSizePolicy(sizePolicy1);
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(pushButton_portBegin, pushButton_portEnd);
        QWidget::setTabOrder(pushButton_portEnd, textEdit_port);
        QWidget::setTabOrder(textEdit_port, lineEdit_begin);
        QWidget::setTabOrder(lineEdit_begin, tableView);
        QWidget::setTabOrder(tableView, pushButton_interface);
        QWidget::setTabOrder(pushButton_interface, lineEdit);
        QWidget::setTabOrder(lineEdit, lineEdit_end);
        QWidget::setTabOrder(lineEdit_end, pushButton);
        QWidget::setTabOrder(pushButton, lineEdit_port);

        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu->menuAction());
        menu->addAction(action_about);
        menu_2->addAction(action_portScan);
        menu_2->addAction(action_host);
        mainToolBar->addAction(action_portScan);
        mainToolBar->addAction(action_host);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        action_portScan->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243\346\211\253\346\217\217", 0, QApplication::UnicodeUTF8));
        action_about->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", 0, QApplication::UnicodeUTF8));
        action_host->setText(QApplication::translate("MainWindow", "\347\275\221\345\215\241\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_host->setToolTip(QApplication::translate("MainWindow", "\347\275\221\345\215\241\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        lineEdit_end->setText(QApplication::translate("MainWindow", "42.121.4.45", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "\347\273\223\346\235\237IP\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213IP\357\274\232", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243\357\274\232", 0, QApplication::UnicodeUTF8));
        lineEdit_port->setText(QApplication::translate("MainWindow", "21,22,3389,80", 0, QApplication::UnicodeUTF8));
        pushButton_portBegin->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", 0, QApplication::UnicodeUTF8));
        pushButton_portEnd->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "\350\277\233\345\272\246\357\274\232", 0, QApplication::UnicodeUTF8));
        lineEdit_begin->setText(QApplication::translate("MainWindow", "42.121.4.41", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "\347\275\221\345\215\241\345\210\227\350\241\250", 0, QApplication::UnicodeUTF8));
        pushButton_interface->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "IP\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "IP\345\234\260\345\235\200\346\210\226\350\200\205\345\237\237\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("MainWindow", "www.cnsecer.com", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        label_3->setText(QString());
        menu->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\212\237\350\203\275", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
