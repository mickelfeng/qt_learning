/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Feb 16 12:46:44 2015
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
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *exitaction;
    QAction *farmerDataAction;
    QAction *purchaseDataAction;
    QAction *regAction;
    QAction *amendAction;
    QAction *aboutAction;
    QAction *currrentUserAction;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_10;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout_17;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLineEdit *purchaseIDLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QComboBox *purchaseKindcomBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QSpinBox *purchaseWeightSpinBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QDoubleSpinBox *purchasePriceDoubleSpinBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QDateEdit *purchaseTimeDateEdit;
    QPushButton *purchaseAddButton;
    QTableView *purchaseTableView;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *purchaseCancelButton;
    QPushButton *purchaseRefreshButton;
    QPushButton *purchaseCommitButton;
    QWidget *page_3;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_23;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_2;
    QLineEdit *farmerNameLineEdit;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QLineEdit *farmerIDLineEdit;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_19;
    QComboBox *farmerSexCBox;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_20;
    QLineEdit *farmerTelLineEdit;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_21;
    QLineEdit *farmerAddRLineEdit;
    QPushButton *farmerOkButton;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_2;
    QPushButton *farmerAddButton;
    QPushButton *farmerSelectButton;
    QPushButton *farmerAmendButton;
    QPushButton *farmerDeleteButton;
    QHBoxLayout *horizontalLayout_11;
    QLabel *farmerStatusLabel;
    QPushButton *farmerCancelButton;
    QPushButton *farmerRefreshButton;
    QPushButton *farmerCommitButton;
    QStackedWidget *farmerStackedWidget;
    QWidget *page_9;
    QHBoxLayout *horizontalLayout_26;
    QTableView *farmerTableView;
    QWidget *page_10;
    QHBoxLayout *horizontalLayout_16;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_14;
    QCheckBox *farmerNameCheckBox;
    QCheckBox *farmerIDCheckBox;
    QCheckBox *farmerSexCheckBox;
    QCheckBox *farmerAddrCheckBox;
    QTableView *farmerSelectTableView;
    QMenuBar *menuBar;
    QMenu *filemenu;
    QMenu *helpmenu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        exitaction = new QAction(MainWindow);
        exitaction->setObjectName(QString::fromUtf8("exitaction"));
        farmerDataAction = new QAction(MainWindow);
        farmerDataAction->setObjectName(QString::fromUtf8("farmerDataAction"));
        purchaseDataAction = new QAction(MainWindow);
        purchaseDataAction->setObjectName(QString::fromUtf8("purchaseDataAction"));
        regAction = new QAction(MainWindow);
        regAction->setObjectName(QString::fromUtf8("regAction"));
        amendAction = new QAction(MainWindow);
        amendAction->setObjectName(QString::fromUtf8("amendAction"));
        aboutAction = new QAction(MainWindow);
        aboutAction->setObjectName(QString::fromUtf8("aboutAction"));
        currrentUserAction = new QAction(MainWindow);
        currrentUserAction->setObjectName(QString::fromUtf8("currrentUserAction"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_10 = new QHBoxLayout(centralWidget);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        horizontalLayout_17 = new QHBoxLayout(page);
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(10);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, -1, -1, -1);
        label_4 = new QLabel(page);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        purchaseIDLineEdit = new QLineEdit(page);
        purchaseIDLineEdit->setObjectName(QString::fromUtf8("purchaseIDLineEdit"));

        horizontalLayout->addWidget(purchaseIDLineEdit);


        horizontalLayout_6->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(page);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(35, 0));

        horizontalLayout_2->addWidget(label_5);

        purchaseKindcomBox = new QComboBox(page);
        purchaseKindcomBox->setObjectName(QString::fromUtf8("purchaseKindcomBox"));
        purchaseKindcomBox->setMinimumSize(QSize(80, 0));
        purchaseKindcomBox->setEditable(true);

        horizontalLayout_2->addWidget(purchaseKindcomBox);


        horizontalLayout_6->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_6 = new QLabel(page);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(55, 0));

        horizontalLayout_3->addWidget(label_6);

        purchaseWeightSpinBox = new QSpinBox(page);
        purchaseWeightSpinBox->setObjectName(QString::fromUtf8("purchaseWeightSpinBox"));
        purchaseWeightSpinBox->setMinimumSize(QSize(50, 0));
        purchaseWeightSpinBox->setMaximum(10000);

        horizontalLayout_3->addWidget(purchaseWeightSpinBox);


        horizontalLayout_6->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_7 = new QLabel(page);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(55, 0));

        horizontalLayout_4->addWidget(label_7);

        purchasePriceDoubleSpinBox = new QDoubleSpinBox(page);
        purchasePriceDoubleSpinBox->setObjectName(QString::fromUtf8("purchasePriceDoubleSpinBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(purchasePriceDoubleSpinBox->sizePolicy().hasHeightForWidth());
        purchasePriceDoubleSpinBox->setSizePolicy(sizePolicy);
        purchasePriceDoubleSpinBox->setMinimumSize(QSize(50, 20));
        purchasePriceDoubleSpinBox->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_4->addWidget(purchasePriceDoubleSpinBox);


        horizontalLayout_6->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_8 = new QLabel(page);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(35, 0));

        horizontalLayout_5->addWidget(label_8);

        purchaseTimeDateEdit = new QDateEdit(page);
        purchaseTimeDateEdit->setObjectName(QString::fromUtf8("purchaseTimeDateEdit"));
        purchaseTimeDateEdit->setMinimumSize(QSize(90, 0));
        purchaseTimeDateEdit->setCorrectionMode(QAbstractSpinBox::CorrectToPreviousValue);
        purchaseTimeDateEdit->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 0, 0)));
        purchaseTimeDateEdit->setCurrentSection(QDateTimeEdit::YearSection);
        purchaseTimeDateEdit->setCalendarPopup(true);

        horizontalLayout_5->addWidget(purchaseTimeDateEdit);


        horizontalLayout_6->addLayout(horizontalLayout_5);

        purchaseAddButton = new QPushButton(page);
        purchaseAddButton->setObjectName(QString::fromUtf8("purchaseAddButton"));

        horizontalLayout_6->addWidget(purchaseAddButton);


        verticalLayout->addLayout(horizontalLayout_6);

        purchaseTableView = new QTableView(page);
        purchaseTableView->setObjectName(QString::fromUtf8("purchaseTableView"));

        verticalLayout->addWidget(purchaseTableView);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        purchaseCancelButton = new QPushButton(page);
        purchaseCancelButton->setObjectName(QString::fromUtf8("purchaseCancelButton"));

        horizontalLayout_7->addWidget(purchaseCancelButton);

        purchaseRefreshButton = new QPushButton(page);
        purchaseRefreshButton->setObjectName(QString::fromUtf8("purchaseRefreshButton"));

        horizontalLayout_7->addWidget(purchaseRefreshButton);

        purchaseCommitButton = new QPushButton(page);
        purchaseCommitButton->setObjectName(QString::fromUtf8("purchaseCommitButton"));

        horizontalLayout_7->addWidget(purchaseCommitButton);


        verticalLayout->addLayout(horizontalLayout_7);


        horizontalLayout_17->addLayout(verticalLayout);

        stackedWidget->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        horizontalLayout_13 = new QHBoxLayout(page_3);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, -1, -1, 0);
        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(10);
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        horizontalLayout_23->setContentsMargins(0, -1, 10, -1);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_2 = new QLabel(page_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_8->addWidget(label_2);

        farmerNameLineEdit = new QLineEdit(page_3);
        farmerNameLineEdit->setObjectName(QString::fromUtf8("farmerNameLineEdit"));
        farmerNameLineEdit->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_8->addWidget(farmerNameLineEdit);


        horizontalLayout_23->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_9 = new QLabel(page_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_9->addWidget(label_9);

        farmerIDLineEdit = new QLineEdit(page_3);
        farmerIDLineEdit->setObjectName(QString::fromUtf8("farmerIDLineEdit"));
        farmerIDLineEdit->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_9->addWidget(farmerIDLineEdit);


        horizontalLayout_23->addLayout(horizontalLayout_9);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(0);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_19 = new QLabel(page_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_20->addWidget(label_19);

        farmerSexCBox = new QComboBox(page_3);
        farmerSexCBox->setObjectName(QString::fromUtf8("farmerSexCBox"));
        farmerSexCBox->setMaximumSize(QSize(35, 16777215));
        farmerSexCBox->setEditable(false);
        farmerSexCBox->setMaxVisibleItems(2);
        farmerSexCBox->setMaxCount(2);

        horizontalLayout_20->addWidget(farmerSexCBox);


        horizontalLayout_23->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(0);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label_20 = new QLabel(page_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_21->addWidget(label_20);

        farmerTelLineEdit = new QLineEdit(page_3);
        farmerTelLineEdit->setObjectName(QString::fromUtf8("farmerTelLineEdit"));
        farmerTelLineEdit->setMinimumSize(QSize(100, 0));

        horizontalLayout_21->addWidget(farmerTelLineEdit);


        horizontalLayout_23->addLayout(horizontalLayout_21);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(0);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        label_21 = new QLabel(page_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        horizontalLayout_22->addWidget(label_21);

        farmerAddRLineEdit = new QLineEdit(page_3);
        farmerAddRLineEdit->setObjectName(QString::fromUtf8("farmerAddRLineEdit"));
        farmerAddRLineEdit->setMinimumSize(QSize(120, 0));

        horizontalLayout_22->addWidget(farmerAddRLineEdit);


        horizontalLayout_23->addLayout(horizontalLayout_22);

        farmerOkButton = new QPushButton(page_3);
        farmerOkButton->setObjectName(QString::fromUtf8("farmerOkButton"));

        horizontalLayout_23->addWidget(farmerOkButton);


        verticalLayout_3->addLayout(horizontalLayout_23);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 10, -1, -1);
        farmerAddButton = new QPushButton(page_3);
        farmerAddButton->setObjectName(QString::fromUtf8("farmerAddButton"));

        verticalLayout_2->addWidget(farmerAddButton);

        farmerSelectButton = new QPushButton(page_3);
        farmerSelectButton->setObjectName(QString::fromUtf8("farmerSelectButton"));

        verticalLayout_2->addWidget(farmerSelectButton);

        farmerAmendButton = new QPushButton(page_3);
        farmerAmendButton->setObjectName(QString::fromUtf8("farmerAmendButton"));

        verticalLayout_2->addWidget(farmerAmendButton);

        farmerDeleteButton = new QPushButton(page_3);
        farmerDeleteButton->setObjectName(QString::fromUtf8("farmerDeleteButton"));

        verticalLayout_2->addWidget(farmerDeleteButton);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, -1, 0, -1);
        farmerStatusLabel = new QLabel(page_3);
        farmerStatusLabel->setObjectName(QString::fromUtf8("farmerStatusLabel"));
        farmerStatusLabel->setMinimumSize(QSize(15, 0));
        farmerStatusLabel->setMaximumSize(QSize(20, 300));
        farmerStatusLabel->setWordWrap(true);

        horizontalLayout_11->addWidget(farmerStatusLabel);


        verticalLayout_2->addLayout(horizontalLayout_11);

        farmerCancelButton = new QPushButton(page_3);
        farmerCancelButton->setObjectName(QString::fromUtf8("farmerCancelButton"));

        verticalLayout_2->addWidget(farmerCancelButton);

        farmerRefreshButton = new QPushButton(page_3);
        farmerRefreshButton->setObjectName(QString::fromUtf8("farmerRefreshButton"));

        verticalLayout_2->addWidget(farmerRefreshButton);

        farmerCommitButton = new QPushButton(page_3);
        farmerCommitButton->setObjectName(QString::fromUtf8("farmerCommitButton"));

        verticalLayout_2->addWidget(farmerCommitButton);


        horizontalLayout_12->addLayout(verticalLayout_2);

        farmerStackedWidget = new QStackedWidget(page_3);
        farmerStackedWidget->setObjectName(QString::fromUtf8("farmerStackedWidget"));
        page_9 = new QWidget();
        page_9->setObjectName(QString::fromUtf8("page_9"));
        horizontalLayout_26 = new QHBoxLayout(page_9);
        horizontalLayout_26->setSpacing(6);
        horizontalLayout_26->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        farmerTableView = new QTableView(page_9);
        farmerTableView->setObjectName(QString::fromUtf8("farmerTableView"));

        horizontalLayout_26->addWidget(farmerTableView);

        farmerStackedWidget->addWidget(page_9);
        page_10 = new QWidget();
        page_10->setObjectName(QString::fromUtf8("page_10"));
        horizontalLayout_16 = new QHBoxLayout(page_10);
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, -1, 400, -1);
        label_10 = new QLabel(page_10);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_15->addWidget(label_10);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        farmerNameCheckBox = new QCheckBox(page_10);
        farmerNameCheckBox->setObjectName(QString::fromUtf8("farmerNameCheckBox"));

        horizontalLayout_14->addWidget(farmerNameCheckBox);

        farmerIDCheckBox = new QCheckBox(page_10);
        farmerIDCheckBox->setObjectName(QString::fromUtf8("farmerIDCheckBox"));

        horizontalLayout_14->addWidget(farmerIDCheckBox);

        farmerSexCheckBox = new QCheckBox(page_10);
        farmerSexCheckBox->setObjectName(QString::fromUtf8("farmerSexCheckBox"));

        horizontalLayout_14->addWidget(farmerSexCheckBox);

        farmerAddrCheckBox = new QCheckBox(page_10);
        farmerAddrCheckBox->setObjectName(QString::fromUtf8("farmerAddrCheckBox"));

        horizontalLayout_14->addWidget(farmerAddrCheckBox);


        horizontalLayout_15->addLayout(horizontalLayout_14);


        verticalLayout_4->addLayout(horizontalLayout_15);

        farmerSelectTableView = new QTableView(page_10);
        farmerSelectTableView->setObjectName(QString::fromUtf8("farmerSelectTableView"));

        verticalLayout_4->addWidget(farmerSelectTableView);


        horizontalLayout_16->addLayout(verticalLayout_4);

        farmerStackedWidget->addWidget(page_10);

        horizontalLayout_12->addWidget(farmerStackedWidget);


        verticalLayout_3->addLayout(horizontalLayout_12);


        horizontalLayout_13->addLayout(verticalLayout_3);

        stackedWidget->addWidget(page_3);

        horizontalLayout_10->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 23));
        filemenu = new QMenu(menuBar);
        filemenu->setObjectName(QString::fromUtf8("filemenu"));
        helpmenu = new QMenu(menuBar);
        helpmenu->setObjectName(QString::fromUtf8("helpmenu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setMovable(false);
        mainToolBar->setAllowedAreas(Qt::TopToolBarArea);
        mainToolBar->setIconSize(QSize(24, 24));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(filemenu->menuAction());
        menuBar->addAction(helpmenu->menuAction());
        filemenu->addAction(purchaseDataAction);
        filemenu->addAction(farmerDataAction);
        filemenu->addSeparator();
        filemenu->addAction(regAction);
        filemenu->addAction(amendAction);
        filemenu->addSeparator();
        filemenu->addAction(exitaction);
        helpmenu->addAction(aboutAction);
        helpmenu->addAction(currrentUserAction);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);
        farmerStackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "VMS\347\256\241\347\220\206\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
        exitaction->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        farmerDataAction->setText(QApplication::translate("MainWindow", "\345\206\234\346\210\267\350\265\204\346\226\231", 0, QApplication::UnicodeUTF8));
        purchaseDataAction->setText(QApplication::translate("MainWindow", "\346\224\266\350\264\255\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        purchaseDataAction->setToolTip(QApplication::translate("MainWindow", "\346\224\266\350\264\255\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        regAction->setText(QApplication::translate("MainWindow", "\346\263\250\345\206\214\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        regAction->setToolTip(QApplication::translate("MainWindow", "\346\263\250\345\206\214\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        amendAction->setText(QApplication::translate("MainWindow", "\345\257\206\347\240\201\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        amendAction->setToolTip(QApplication::translate("MainWindow", "\345\257\206\347\240\201\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        aboutAction->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        aboutAction->setToolTip(QApplication::translate("MainWindow", "\345\205\263\344\272\216", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        currrentUserAction->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        currrentUserAction->setToolTip(QApplication::translate("MainWindow", "\345\275\223\345\211\215\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("MainWindow", "\345\206\234\346\210\267ID\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "\347\247\215\347\261\273\357\274\232", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "\345\207\200\351\207\215(Kg):", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "\344\273\267\346\240\274(\345\205\203):", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264:", 0, QApplication::UnicodeUTF8));
        purchaseAddButton->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        purchaseCancelButton->setText(QApplication::translate("MainWindow", "\346\222\244\351\224\200", 0, QApplication::UnicodeUTF8));
        purchaseRefreshButton->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260", 0, QApplication::UnicodeUTF8));
        purchaseCommitButton->setText(QApplication::translate("MainWindow", "\346\217\220\344\272\244\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\345\247\223\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "\347\274\226\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "\346\200\247\345\210\253:", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "\347\224\265\350\257\235:", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "\344\275\217\345\235\200:", 0, QApplication::UnicodeUTF8));
        farmerOkButton->setText(QApplication::translate("MainWindow", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        farmerAddButton->setText(QApplication::translate("MainWindow", "\345\275\225\345\205\245", 0, QApplication::UnicodeUTF8));
        farmerSelectButton->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276", 0, QApplication::UnicodeUTF8));
        farmerAmendButton->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271", 0, QApplication::UnicodeUTF8));
        farmerDeleteButton->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        farmerStatusLabel->setText(QString());
        farmerCancelButton->setText(QApplication::translate("MainWindow", "\346\222\244\351\224\200", 0, QApplication::UnicodeUTF8));
        farmerRefreshButton->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260", 0, QApplication::UnicodeUTF8));
        farmerCommitButton->setText(QApplication::translate("MainWindow", "\346\217\220\344\272\244\347\241\256\350\256\244", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276\346\235\241\344\273\266\357\274\232", 0, QApplication::UnicodeUTF8));
        farmerNameCheckBox->setText(QApplication::translate("MainWindow", "\345\247\223\345\220\215", 0, QApplication::UnicodeUTF8));
        farmerIDCheckBox->setText(QApplication::translate("MainWindow", "\347\274\226\345\217\267", 0, QApplication::UnicodeUTF8));
        farmerSexCheckBox->setText(QApplication::translate("MainWindow", "\346\200\247\345\210\253", 0, QApplication::UnicodeUTF8));
        farmerAddrCheckBox->setText(QApplication::translate("MainWindow", "\344\275\217\345\235\200", 0, QApplication::UnicodeUTF8));
        filemenu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", 0, QApplication::UnicodeUTF8));
        helpmenu->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        statusBar->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
