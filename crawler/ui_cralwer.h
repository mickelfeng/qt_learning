/********************************************************************************
** Form generated from reading UI file 'cralwer.ui'
**
** Created: Mon Feb 16 10:52:23 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CRALWER_H
#define UI_CRALWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Cralwer
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Cralwer)
    {
        if (Cralwer->objectName().isEmpty())
            Cralwer->setObjectName(QString::fromUtf8("Cralwer"));
        Cralwer->resize(400, 300);
        menuBar = new QMenuBar(Cralwer);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Cralwer->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Cralwer);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Cralwer->addToolBar(mainToolBar);
        centralWidget = new QWidget(Cralwer);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Cralwer->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Cralwer);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Cralwer->setStatusBar(statusBar);

        retranslateUi(Cralwer);

        QMetaObject::connectSlotsByName(Cralwer);
    } // setupUi

    void retranslateUi(QMainWindow *Cralwer)
    {
        Cralwer->setWindowTitle(QApplication::translate("Cralwer", "Cralwer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Cralwer: public Ui_Cralwer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CRALWER_H
