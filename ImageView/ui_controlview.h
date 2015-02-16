/********************************************************************************
** Form generated from reading UI file 'controlview.ui'
**
** Created: Mon Feb 16 11:29:19 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLVIEW_H
#define UI_CONTROLVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlView
{
public:
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *ControlView)
    {
        if (ControlView->objectName().isEmpty())
            ControlView->setObjectName(QString::fromUtf8("ControlView"));
        ControlView->resize(479, 358);
        ControlView->setStyleSheet(QString::fromUtf8("#control_view_menu{\n"
"	background-color: qlineargradient(spread:pad, x1:0.523, y1:0, x2:0.477, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(217, 217, 217, 255));\n"
"	border-radius:3px;\n"
"}\n"
"\n"
"#control_view_menu QLabel{\n"
"		min-width:30px;\n"
"		max-width:30px;	\n"
"		min-height:30px;\n"
"		max-height:30px;\n"
"		border-radius:3px;\n"
"		color:rgb(103,103,103);\n"
"		font:12pt;\n"
"	    font:  12pt;\n"
"}\n"
"\n"
"#control_view_menu QLabel:hover{\n"
"		 	\n"
"	 \n"
"	background-color: qlineargradient(spread:pad, x1:0.523, y1:0, x2:0.477, y2:1, stop:0 rgba(88, 159, 203, 255), stop:1 rgba(36, 118, 167, 255));\n"
"}\n"
"\n"
"#control_view_advance QLabel{\n"
"		min-width:50px;\n"
"		max-width:50px;	\n"
"		min-height:50px;\n"
"		max-height:50px;\n"
"		\n"
"		background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"#control_view_advance QLabel:hover{ \n"
"	border:3px solid rgb(255, 85, 0);\n"
"}"));
        verticalLayout = new QVBoxLayout(ControlView);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(ControlView);

        QMetaObject::connectSlotsByName(ControlView);
    } // setupUi

    void retranslateUi(QWidget *ControlView)
    {
        ControlView->setWindowTitle(QApplication::translate("ControlView", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ControlView: public Ui_ControlView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLVIEW_H
