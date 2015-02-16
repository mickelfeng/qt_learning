/********************************************************************************
** Form generated from reading UI file 'linepainter.ui'
**
** Created: Wed Jun 19 18:30:25 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINEPAINTER_H
#define UI_LINEPAINTER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_linepainter
{
public:

    void setupUi(QDialog *linepainter)
    {
        if (linepainter->objectName().isEmpty())
            linepainter->setObjectName(QString::fromUtf8("linepainter"));
        linepainter->resize(400, 300);

        retranslateUi(linepainter);

        QMetaObject::connectSlotsByName(linepainter);
    } // setupUi

    void retranslateUi(QDialog *linepainter)
    {
        linepainter->setWindowTitle(QApplication::translate("linepainter", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class linepainter: public Ui_linepainter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINEPAINTER_H
