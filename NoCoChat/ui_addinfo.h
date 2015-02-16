/********************************************************************************
** Form generated from reading UI file 'addinfo.ui'
**
** Created: Mon Feb 16 12:55:56 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDINFO_H
#define UI_ADDINFO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddInfo
{
public:
    QTabWidget *tabWidget;
    QWidget *addfriend;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *friend_id;
    QLineEdit *friend_name;
    QCheckBox *male;
    QCheckBox *female;
    QPushButton *friend_searchbtn;
    QTableWidget *friend_table;
    QWidget *addgroup;
    QLabel *label_3;
    QLineEdit *group_id;
    QPushButton *group_searchbtn;
    QTableWidget *group_table;
    QLabel *label_4;
    QLineEdit *group_name;
    QWidget *creatgroup;
    QPushButton *c_btn;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLineEdit *c_group_id;
    QLabel *label_6;
    QLineEdit *c_group_name;

    void setupUi(QDialog *AddInfo)
    {
        if (AddInfo->objectName().isEmpty())
            AddInfo->setObjectName(QString::fromUtf8("AddInfo"));
        AddInfo->resize(499, 444);
        tabWidget = new QTabWidget(AddInfo);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 500, 444));
        tabWidget->setIconSize(QSize(16, 16));
        addfriend = new QWidget();
        addfriend->setObjectName(QString::fromUtf8("addfriend"));
        label = new QLabel(addfriend);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(21, 16, 41, 20));
        label->setStyleSheet(QString::fromUtf8("font: 10pt"));
        label_2 = new QLabel(addfriend);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 40, 40, 16));
        label_2->setStyleSheet(QString::fromUtf8("font: 10pt"));
        friend_id = new QLineEdit(addfriend);
        friend_id->setObjectName(QString::fromUtf8("friend_id"));
        friend_id->setGeometry(QRect(57, 16, 113, 20));
        friend_id->setStyleSheet(QString::fromUtf8("font: 10pt"));
        friend_name = new QLineEdit(addfriend);
        friend_name->setObjectName(QString::fromUtf8("friend_name"));
        friend_name->setGeometry(QRect(57, 38, 113, 20));
        male = new QCheckBox(addfriend);
        male->setObjectName(QString::fromUtf8("male"));
        male->setGeometry(QRect(190, 18, 71, 16));
        male->setStyleSheet(QString::fromUtf8("font: 10pt"));
        male->setChecked(false);
        female = new QCheckBox(addfriend);
        female->setObjectName(QString::fromUtf8("female"));
        female->setGeometry(QRect(190, 40, 71, 16));
        female->setStyleSheet(QString::fromUtf8("font: 10pt"));
        friend_searchbtn = new QPushButton(addfriend);
        friend_searchbtn->setObjectName(QString::fromUtf8("friend_searchbtn"));
        friend_searchbtn->setGeometry(QRect(240, 25, 75, 23));
        friend_searchbtn->setStyleSheet(QString::fromUtf8("font: 10pt"));
        friend_table = new QTableWidget(addfriend);
        if (friend_table->columnCount() < 5)
            friend_table->setColumnCount(5);
        QFont font;
        font.setPointSize(10);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        friend_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        friend_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        friend_table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        friend_table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        friend_table->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        friend_table->setObjectName(QString::fromUtf8("friend_table"));
        friend_table->setGeometry(QRect(0, 60, 495, 360));
        friend_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tabWidget->addTab(addfriend, QString());
        addgroup = new QWidget();
        addgroup->setObjectName(QString::fromUtf8("addgroup"));
        label_3 = new QLabel(addgroup);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 20, 81, 16));
        label_3->setStyleSheet(QString::fromUtf8("font: 12pt"));
        group_id = new QLineEdit(addgroup);
        group_id->setObjectName(QString::fromUtf8("group_id"));
        group_id->setGeometry(QRect(90, 20, 181, 22));
        group_id->setStyleSheet(QString::fromUtf8("font: 12pt"));
        group_searchbtn = new QPushButton(addgroup);
        group_searchbtn->setObjectName(QString::fromUtf8("group_searchbtn"));
        group_searchbtn->setGeometry(QRect(290, 30, 75, 23));
        group_table = new QTableWidget(addgroup);
        if (group_table->columnCount() < 2)
            group_table->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        group_table->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        group_table->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        group_table->setObjectName(QString::fromUtf8("group_table"));
        group_table->setGeometry(QRect(0, 79, 495, 341));
        label_4 = new QLabel(addgroup);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 50, 71, 20));
        label_4->setStyleSheet(QString::fromUtf8("font: 12pt"));
        group_name = new QLineEdit(addgroup);
        group_name->setObjectName(QString::fromUtf8("group_name"));
        group_name->setGeometry(QRect(90, 50, 181, 22));
        group_name->setStyleSheet(QString::fromUtf8("font: 12pt"));
        tabWidget->addTab(addgroup, QString());
        creatgroup = new QWidget();
        creatgroup->setObjectName(QString::fromUtf8("creatgroup"));
        c_btn = new QPushButton(creatgroup);
        c_btn->setObjectName(QString::fromUtf8("c_btn"));
        c_btn->setGeometry(QRect(180, 90, 75, 23));
        layoutWidget = new QWidget(creatgroup);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 30, 255, 52));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 12pt"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        c_group_id = new QLineEdit(layoutWidget);
        c_group_id->setObjectName(QString::fromUtf8("c_group_id"));
        c_group_id->setStyleSheet(QString::fromUtf8("font: 12pt"));

        gridLayout->addWidget(c_group_id, 0, 1, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font: 12pt"));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        c_group_name = new QLineEdit(layoutWidget);
        c_group_name->setObjectName(QString::fromUtf8("c_group_name"));
        c_group_name->setStyleSheet(QString::fromUtf8("font: 12pt"));

        gridLayout->addWidget(c_group_name, 1, 1, 1, 1);

        tabWidget->addTab(creatgroup, QString());

        retranslateUi(AddInfo);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AddInfo);
    } // setupUi

    void retranslateUi(QDialog *AddInfo)
    {
        AddInfo->setWindowTitle(QApplication::translate("AddInfo", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AddInfo", "\345\270\220\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AddInfo", "\346\230\265\347\247\260\357\274\232", 0, QApplication::UnicodeUTF8));
        male->setText(QApplication::translate("AddInfo", "\347\224\267", 0, QApplication::UnicodeUTF8));
        female->setText(QApplication::translate("AddInfo", "\345\245\263", 0, QApplication::UnicodeUTF8));
        friend_searchbtn->setText(QApplication::translate("AddInfo", "\346\237\245\346\211\276", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = friend_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("AddInfo", "ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = friend_table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("AddInfo", "\346\230\265\347\247\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = friend_table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("AddInfo", "\346\200\247\345\210\253", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = friend_table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("AddInfo", "\347\263\273\345\210\253", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = friend_table->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("AddInfo", "\344\270\223\344\270\232", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(addfriend), QApplication::translate("AddInfo", "\346\267\273\345\212\240\345\245\275\345\217\213", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AddInfo", "\350\201\212\345\244\251\345\256\244ID\357\274\232", 0, QApplication::UnicodeUTF8));
        group_id->setText(QString());
        group_searchbtn->setText(QApplication::translate("AddInfo", "\346\237\245\346\211\276", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = group_table->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("AddInfo", "ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = group_table->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("AddInfo", "\347\276\244\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AddInfo", "\350\201\212\345\244\251\345\256\244\345\220\215:", 0, QApplication::UnicodeUTF8));
        group_name->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(addgroup), QApplication::translate("AddInfo", "\346\267\273\345\212\240\347\276\244", 0, QApplication::UnicodeUTF8));
        c_btn->setText(QApplication::translate("AddInfo", "\345\210\233\345\273\272", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("AddInfo", "\350\201\212\345\244\251\345\256\244ID\357\274\232", 0, QApplication::UnicodeUTF8));
        c_group_id->setText(QString());
        label_6->setText(QApplication::translate("AddInfo", "\350\201\212\345\244\251\345\256\244\345\220\215:", 0, QApplication::UnicodeUTF8));
        c_group_name->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(creatgroup), QApplication::translate("AddInfo", "\345\210\233\345\273\272\347\276\244", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddInfo: public Ui_AddInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDINFO_H
