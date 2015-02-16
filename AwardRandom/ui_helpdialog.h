/********************************************************************************
** Form generated from reading UI file 'helpdialog.ui'
**
** Created: Mon Feb 16 11:39:49 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPDIALOG_H
#define UI_HELPDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_HelpDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *HelpDialog)
    {
        if (HelpDialog->objectName().isEmpty())
            HelpDialog->setObjectName(QString::fromUtf8("HelpDialog"));
        HelpDialog->resize(800, 600);
        verticalLayout = new QVBoxLayout(HelpDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textBrowser = new QTextBrowser(HelpDialog);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);


        retranslateUi(HelpDialog);

        QMetaObject::connectSlotsByName(HelpDialog);
    } // setupUi

    void retranslateUi(QDialog *HelpDialog)
    {
        HelpDialog->setWindowTitle(QApplication::translate("HelpDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        textBrowser->setHtml(QApplication::translate("HelpDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">1.\351\200\211\346\213\251\345\217\202\344\270\216\346\212\275\345\245\226\344\272\272\345\221\230\345\244\264\345\203\217\346\211\200\345\234\250\347\233\256\345\275\225\357\274\214\350\257\267\345\260\206\345\244\264\345\203\217\347\232\204\346\226\207\344\273\266\345\220\215\344\275\277\347\224\250\345\257\271\345\272\224\347\232\204\344\272\272\347\232\204\347\234\237\345\256\236\345\220\215\345\255\227\357\274\214\346\255\244\345\220\215\345\255\227\345\260\206\344\274\232\346\230\276\347\244\272\345\234\250\346\212\275\345\245"
                        "\226\347\225\214\351\235\242</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/doc/help1.JPG\" /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">2.\350\256\276\347\275\256\345\245\226\351\241\271\347\272\247\345\210\253\346\225\260\351\207\217\357\274\214\346\234\200\345\244\232\345\217\257\350\256\2766\347\272\247\357\274\214\345\217\212\345\220\204\345\245\226\351\241\271\347\232\204\345\220\215\347\247\260\345\217\212\346\257\217\344\270\252\345\245\226\351\241\271\347\232\204\346\225\260\351\207\217\357\274\214\345\271\266\345\217\257\344\270\272\345\220\204\345\245\226\351\241\271\350\256\276\347\275\256\345\220\210\351\200\202\347\232\204\345\233\276\347\211\207\357\274\214\345\245\226\351\241\271\345\233\276\347\211\207\345\272\224\344\270\272320x320\347\232\204png\345\233\276\343\200\202\350"
                        "\277\230\345\217\257\344\273\245\345\234\250\350\277\231\351\207\214\351\207\215\346\226\260\350\256\276\347\275\256\345\217\202\344\270\216\346\212\275\345\245\226\344\272\272\345\221\230\345\244\264\345\203\217\346\211\200\345\234\250\347\233\256\345\275\225\343\200\202\344\270\213\351\235\242\350\277\230\345\217\257\344\273\245\350\256\276\347\275\256\350\203\214\346\231\257\345\233\276\347\211\207\357\274\2101024x768\344\273\245\344\270\212\357\274\211\357\274\214\350\203\214\346\231\257\351\237\263\344\271\220\350\256\276\347\275\256\347\255\211</p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/doc/help2.JPG\" /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">3.\346\212\275\345\245\226\346\223\215\344\275\234\347\225\214\351\235\242\357\274\232</p>\n"
"<p align=\"center\" style=\" margin-top:0px; marg"
                        "in-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/doc/help4.JPG\" /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\234\254\346\212\275\345\245\226\350\275\257\344\273\266\347\224\261\345\256\213\345\276\267\351\224\213\347\213\254\347\253\213\350\256\276\350\256\241\345\256\214\346\210\220\357\274\214\346\204\237\350\260\242\346\210\221\347\232\204\347\210\261\344\272\272\347\273\231\344\272\210\347\232\204\346\224\257\346\214\201\343\200\202\347\225\214\351\235\242\344\270\255\346\211\200\344\275\277\347\224\250\351\203\250\345\210\206\346\214\211\351\222\256\345\233\276\347\211\207\346\235\245\350\207\252\347\275\221\347\273\234\357\274\214\345\246\202\344\275\240\345\217\221\347"
                        "\216\260\346\234\211\344\276\265\346\235\203\350\241\214\344\270\272\357\274\214\350\257\267\347\253\213\345\215\263\345\221\212\347\237\245\346\234\254\344\272\272\357\274\214\346\234\254\344\272\272\345\260\206\344\272\210\344\273\245\345\210\240\351\231\244\343\200\202\350\201\224\347\263\273\345\212\236\346\263\225\357\274\232song_df@QQ.com</p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\234\200\345\220\216\347\245\235\344\272\272\344\272\272\346\212\275\345\210\260\345\244\247\345\245\226\357\274\201\357\274\201\357\274\201</p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HelpDialog: public Ui_HelpDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPDIALOG_H
