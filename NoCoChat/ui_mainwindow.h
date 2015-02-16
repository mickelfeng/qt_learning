/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Feb 16 12:55:56 2015
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
#include <QtGui/QLayout>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *portrait;
    QLabel *user_name;
    QLabel *portrait_1;
    QTabWidget *tabWidget;
    QWidget *linkman;
    QToolBox *toolBox;
    QWidget *myfriend;
    QWidget *stranger;
    QWidget *blacklist;
    QWidget *group_0;
    QToolBox *group;
    QWidget *mygroup;
    QWidget *addlink;
    QPushButton *addfriend;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(255, 542);
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        portrait = new QLabel(centralwidget);
        portrait->setObjectName(QString::fromUtf8("portrait"));
        portrait->setGeometry(QRect(12, 20, 71, 61));
        portrait->setFrameShape(QFrame::NoFrame);
        portrait->setPixmap(QPixmap(QString::fromUtf8(":/img/Person.png")));
        portrait->setScaledContents(true);
        user_name = new QLabel(centralwidget);
        user_name->setObjectName(QString::fromUtf8("user_name"));
        user_name->setGeometry(QRect(94, 10, 171, 21));
        user_name->setLayoutDirection(Qt::LeftToRight);
        user_name->setStyleSheet(QString::fromUtf8("font: 10pt;"));
        user_name->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        portrait_1 = new QLabel(centralwidget);
        portrait_1->setObjectName(QString::fromUtf8("portrait_1"));
        portrait_1->setGeometry(QRect(8, 10, 81, 81));
        portrait_1->setFrameShape(QFrame::Box);
        portrait_1->setFrameShadow(QFrame::Plain);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 100, 257, 451));
        tabWidget->setSizeIncrement(QSize(0, 0));
        tabWidget->setBaseSize(QSize(0, 0));
        QFont font;
        font.setPointSize(10);
        tabWidget->setFont(font);
        tabWidget->setFocusPolicy(Qt::NoFocus);
        tabWidget->setContextMenuPolicy(Qt::DefaultContextMenu);
        tabWidget->setInputMethodHints(Qt::ImhNone);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(16, 16));
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        linkman = new QWidget();
        linkman->setObjectName(QString::fromUtf8("linkman"));
        linkman->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(linkman->sizePolicy().hasHeightForWidth());
        linkman->setSizePolicy(sizePolicy);
        linkman->setMinimumSize(QSize(0, 0));
        linkman->setMaximumSize(QSize(16777215, 16777215));
        linkman->setSizeIncrement(QSize(0, 0));
        linkman->setBaseSize(QSize(0, 0));
        linkman->setFocusPolicy(Qt::TabFocus);
        linkman->setLayoutDirection(Qt::LeftToRight);
        linkman->setAutoFillBackground(false);
        linkman->setInputMethodHints(Qt::ImhNone);
        toolBox = new QToolBox(linkman);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setGeometry(QRect(-1, 0, 253, 421));
        toolBox->setInputMethodHints(Qt::ImhNone);
        toolBox->setFrameShape(QFrame::NoFrame);
        toolBox->setFrameShadow(QFrame::Plain);
        toolBox->setLineWidth(1);
        toolBox->setMidLineWidth(0);
        myfriend = new QWidget();
        myfriend->setObjectName(QString::fromUtf8("myfriend"));
        myfriend->setGeometry(QRect(0, 0, 253, 358));
        toolBox->addItem(myfriend, QString::fromUtf8("\346\210\221\347\232\204\345\245\275\345\217\213"));
        stranger = new QWidget();
        stranger->setObjectName(QString::fromUtf8("stranger"));
        stranger->setGeometry(QRect(0, 0, 253, 358));
        toolBox->addItem(stranger, QString::fromUtf8("\351\231\214\347\224\237\344\272\272"));
        blacklist = new QWidget();
        blacklist->setObjectName(QString::fromUtf8("blacklist"));
        blacklist->setGeometry(QRect(0, 0, 253, 358));
        toolBox->addItem(blacklist, QString::fromUtf8("\351\273\221\345\220\215\345\215\225"));
        tabWidget->addTab(linkman, QString());
        group_0 = new QWidget();
        group_0->setObjectName(QString::fromUtf8("group_0"));
        group = new QToolBox(group_0);
        group->setObjectName(QString::fromUtf8("group"));
        group->setGeometry(QRect(-2, 0, 257, 421));
        mygroup = new QWidget();
        mygroup->setObjectName(QString::fromUtf8("mygroup"));
        mygroup->setGeometry(QRect(0, 0, 257, 400));
        group->addItem(mygroup, QString::fromUtf8("\346\210\221\347\232\204\347\276\244"));
        tabWidget->addTab(group_0, QString());
        addlink = new QWidget();
        addlink->setObjectName(QString::fromUtf8("addlink"));
        addfriend = new QPushButton(addlink);
        addfriend->setObjectName(QString::fromUtf8("addfriend"));
        addfriend->setGeometry(QRect(17, 30, 211, 351));
        QFont font1;
        font1.setPointSize(34);
        addfriend->setFont(font1);
        tabWidget->addTab(addlink, QString());
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        toolBox->setCurrentIndex(2);
        toolBox->layout()->setSpacing(0);
        group->setCurrentIndex(0);
        group->layout()->setSpacing(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        MainWindow->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        portrait->setText(QString());
        user_name->setText(QString());
        portrait_1->setText(QString());
#ifndef QT_NO_STATUSTIP
        linkman->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        toolBox->setItemText(toolBox->indexOf(myfriend), QApplication::translate("MainWindow", "\346\210\221\347\232\204\345\245\275\345\217\213", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(stranger), QApplication::translate("MainWindow", "\351\231\214\347\224\237\344\272\272", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(blacklist), QApplication::translate("MainWindow", "\351\273\221\345\220\215\345\215\225", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(linkman), QApplication::translate("MainWindow", "  \350\201\224\347\263\273\344\272\272 ", 0, QApplication::UnicodeUTF8));
        group->setItemText(group->indexOf(mygroup), QApplication::translate("MainWindow", "\346\210\221\347\232\204\347\276\244", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(group_0), QApplication::translate("MainWindow", "   \347\276\244   ", 0, QApplication::UnicodeUTF8));
        addfriend->setText(QApplication::translate("MainWindow", "\345\220\204\347\247\215\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(addlink), QApplication::translate("MainWindow", "   \346\267\273\345\212\240   ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
