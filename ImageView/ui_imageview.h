/********************************************************************************
** Form generated from reading UI file 'imageview.ui'
**
** Created: Mon Feb 16 11:29:19 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEVIEW_H
#define UI_IMAGEVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageView
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *imageview_main_widget;

    void setupUi(QWidget *ImageView)
    {
        if (ImageView->objectName().isEmpty())
            ImageView->setObjectName(QString::fromUtf8("ImageView"));
        ImageView->resize(427, 317);
        ImageView->setStyleSheet(QString::fromUtf8("QWidget#imageview_main_widget{\n"
"	\n"
"}"));
        verticalLayout = new QVBoxLayout(ImageView);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        imageview_main_widget = new QWidget(ImageView);
        imageview_main_widget->setObjectName(QString::fromUtf8("imageview_main_widget"));

        verticalLayout->addWidget(imageview_main_widget);


        retranslateUi(ImageView);

        QMetaObject::connectSlotsByName(ImageView);
    } // setupUi

    void retranslateUi(QWidget *ImageView)
    {
        ImageView->setWindowTitle(QApplication::translate("ImageView", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ImageView: public Ui_ImageView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEVIEW_H
