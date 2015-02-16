/********************************************************************************
** Form generated from reading UI file 'purchasemsgdialog.ui'
**
** Created: Mon Feb 16 12:46:44 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PURCHASEMSGDIALOG_H
#define UI_PURCHASEMSGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_purchaseMSGDialog
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_8;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QVBoxLayout *verticalLayout;
    QLineEdit *pMSGPIDLineEdit;
    QLineEdit *pMSGIDLineEdit;
    QLineEdit *pMSGNameLineEdit;
    QLineEdit *pMSGKindLineEdit;
    QLineEdit *pMSGWeightLineEdit;
    QLineEdit *pMSGPriceLineEdit;
    QLineEdit *pMSGTimeLlineEdit;
    QLineEdit *pMSGPayLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pMSGOKButton;

    void setupUi(QDialog *purchaseMSGDialog)
    {
        if (purchaseMSGDialog->objectName().isEmpty())
            purchaseMSGDialog->setObjectName(QString::fromUtf8("purchaseMSGDialog"));
        purchaseMSGDialog->resize(400, 300);
        horizontalLayout_3 = new QHBoxLayout(purchaseMSGDialog);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(40, 15, 40, 15);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 5, -1, 0);
        label_8 = new QLabel(purchaseMSGDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_2->addWidget(label_8);

        label = new QLabel(purchaseMSGDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 25));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(purchaseMSGDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(16777215, 25));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(purchaseMSGDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(16777215, 25));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(purchaseMSGDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(16777215, 25));

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(purchaseMSGDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMaximumSize(QSize(16777215, 25));

        verticalLayout_2->addWidget(label_5);

        label_6 = new QLabel(purchaseMSGDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMaximumSize(QSize(16777215, 25));

        verticalLayout_2->addWidget(label_6);

        label_7 = new QLabel(purchaseMSGDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMaximumSize(QSize(16777215, 25));

        verticalLayout_2->addWidget(label_7);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 5, -1, -1);
        pMSGPIDLineEdit = new QLineEdit(purchaseMSGDialog);
        pMSGPIDLineEdit->setObjectName(QString::fromUtf8("pMSGPIDLineEdit"));
        pMSGPIDLineEdit->setEnabled(false);
        pMSGPIDLineEdit->setMaximumSize(QSize(16777215, 25));

        verticalLayout->addWidget(pMSGPIDLineEdit);

        pMSGIDLineEdit = new QLineEdit(purchaseMSGDialog);
        pMSGIDLineEdit->setObjectName(QString::fromUtf8("pMSGIDLineEdit"));
        pMSGIDLineEdit->setEnabled(false);
        pMSGIDLineEdit->setMaximumSize(QSize(16777215, 25));

        verticalLayout->addWidget(pMSGIDLineEdit);

        pMSGNameLineEdit = new QLineEdit(purchaseMSGDialog);
        pMSGNameLineEdit->setObjectName(QString::fromUtf8("pMSGNameLineEdit"));
        pMSGNameLineEdit->setEnabled(false);
        pMSGNameLineEdit->setMaximumSize(QSize(16777215, 25));

        verticalLayout->addWidget(pMSGNameLineEdit);

        pMSGKindLineEdit = new QLineEdit(purchaseMSGDialog);
        pMSGKindLineEdit->setObjectName(QString::fromUtf8("pMSGKindLineEdit"));
        pMSGKindLineEdit->setEnabled(false);
        pMSGKindLineEdit->setMaximumSize(QSize(16777215, 25));

        verticalLayout->addWidget(pMSGKindLineEdit);

        pMSGWeightLineEdit = new QLineEdit(purchaseMSGDialog);
        pMSGWeightLineEdit->setObjectName(QString::fromUtf8("pMSGWeightLineEdit"));
        pMSGWeightLineEdit->setEnabled(false);
        pMSGWeightLineEdit->setMaximumSize(QSize(16777215, 25));

        verticalLayout->addWidget(pMSGWeightLineEdit);

        pMSGPriceLineEdit = new QLineEdit(purchaseMSGDialog);
        pMSGPriceLineEdit->setObjectName(QString::fromUtf8("pMSGPriceLineEdit"));
        pMSGPriceLineEdit->setEnabled(false);
        pMSGPriceLineEdit->setMaximumSize(QSize(16777215, 25));

        verticalLayout->addWidget(pMSGPriceLineEdit);

        pMSGTimeLlineEdit = new QLineEdit(purchaseMSGDialog);
        pMSGTimeLlineEdit->setObjectName(QString::fromUtf8("pMSGTimeLlineEdit"));
        pMSGTimeLlineEdit->setEnabled(false);
        pMSGTimeLlineEdit->setMaximumSize(QSize(16777215, 25));

        verticalLayout->addWidget(pMSGTimeLlineEdit);

        pMSGPayLineEdit = new QLineEdit(purchaseMSGDialog);
        pMSGPayLineEdit->setObjectName(QString::fromUtf8("pMSGPayLineEdit"));
        pMSGPayLineEdit->setEnabled(false);
        pMSGPayLineEdit->setMaximumSize(QSize(16777215, 25));

        verticalLayout->addWidget(pMSGPayLineEdit);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 35, -1);
        horizontalSpacer = new QSpacerItem(218, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pMSGOKButton = new QPushButton(purchaseMSGDialog);
        pMSGOKButton->setObjectName(QString::fromUtf8("pMSGOKButton"));

        horizontalLayout_2->addWidget(pMSGOKButton);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_3);


        retranslateUi(purchaseMSGDialog);

        QMetaObject::connectSlotsByName(purchaseMSGDialog);
    } // setupUi

    void retranslateUi(QDialog *purchaseMSGDialog)
    {
        purchaseMSGDialog->setWindowTitle(QApplication::translate("purchaseMSGDialog", "\346\224\266\350\264\255\350\257\246\347\273\206\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("purchaseMSGDialog", "\346\224\266\350\264\255ID", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("purchaseMSGDialog", "\345\206\234\346\210\267ID\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("purchaseMSGDialog", "\345\247\223\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("purchaseMSGDialog", "\350\224\254\350\217\234\345\223\201\347\247\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("purchaseMSGDialog", "\345\207\200\351\207\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("purchaseMSGDialog", "\344\273\267\346\240\274\357\274\232", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("purchaseMSGDialog", "\346\224\266\350\264\255\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("purchaseMSGDialog", "\345\272\224\344\273\230\357\274\232", 0, QApplication::UnicodeUTF8));
        pMSGOKButton->setText(QApplication::translate("purchaseMSGDialog", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class purchaseMSGDialog: public Ui_purchaseMSGDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PURCHASEMSGDIALOG_H
