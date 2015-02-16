/********************************************************************************
** Form generated from reading UI file 'painterdialog.ui'
**
** Created: Wed Jun 19 20:27:39 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAINTERDIALOG_H
#define UI_PAINTERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_PainterDialog
{
public:

    void setupUi(QDialog *PainterDialog)
    {
        if (PainterDialog->objectName().isEmpty())
            PainterDialog->setObjectName(QString::fromUtf8("PainterDialog"));
        PainterDialog->resize(700, 400);
        PainterDialog->setMinimumSize(QSize(700, 400));
        PainterDialog->setMaximumSize(QSize(700, 400));

        retranslateUi(PainterDialog);

        QMetaObject::connectSlotsByName(PainterDialog);
    } // setupUi

    void retranslateUi(QDialog *PainterDialog)
    {
        PainterDialog->setWindowTitle(QApplication::translate("PainterDialog", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PainterDialog: public Ui_PainterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAINTERDIALOG_H
