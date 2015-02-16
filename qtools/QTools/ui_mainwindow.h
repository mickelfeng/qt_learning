/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Jun 19 19:57:53 2013
**      by: Qt User Interface Compiler version 4.8.1
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
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QFrame *frame;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_8;
    QRadioButton *recHexSel;
    QRadioButton *recCharSel;
    QCheckBox *timecheck;
    QCheckBox *linecheckBox;
    QPushButton *pushButton_2;
    QPushButton *RecClrButton;
    QCheckBox *stopDisSelBox;
    QSplitter *splitter_rec;
    QPlainTextEdit *ReceiveText;
    QTextEdit *textEdit;
    QFrame *frame_2;
    QPlainTextEdit *SendTextEdit;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QRadioButton *sendHexSel;
    QRadioButton *sendCharSel;
    QPushButton *pushButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *sendTextEdit_1;
    QPlainTextEdit *sendTextEdit_2;
    QPlainTextEdit *sendTextEdit_3;
    QPlainTextEdit *sendTextEdit_4;
    QPushButton *sendButton;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *autosendBox;
    QSpinBox *sendmsBox;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *PortBox;
    QLabel *label_2;
    QComboBox *bandrate;
    QLabel *label_4;
    QComboBox *databox;
    QFormLayout *formLayout_2;
    QLabel *label_3;
    QComboBox *checkbox;
    QLabel *label_5;
    QComboBox *stopbox;
    QLabel *label_6;
    QComboBox *flowbox;
    QPushButton *OpenButton;
    QPushButton *searchbutton;
    QPushButton *pushButton_3;
    QWidget *tab_2;
    QSplitter *splitter;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 800, 584));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setBold(false);
        font.setWeight(50);
        tabWidget->setFont(font);
        tabWidget->setMouseTracking(false);
        tabWidget->setFocusPolicy(Qt::WheelFocus);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        frame = new QFrame(tab);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 351, 560));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayoutWidget = new QWidget(frame);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 341, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(horizontalLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_8->setFont(font1);

        horizontalLayout->addWidget(label_8);

        recHexSel = new QRadioButton(horizontalLayoutWidget);
        recHexSel->setObjectName(QString::fromUtf8("recHexSel"));
        recHexSel->setFont(font1);
        recHexSel->setChecked(true);

        horizontalLayout->addWidget(recHexSel);

        recCharSel = new QRadioButton(horizontalLayoutWidget);
        recCharSel->setObjectName(QString::fromUtf8("recCharSel"));
        recCharSel->setFont(font1);

        horizontalLayout->addWidget(recCharSel);

        timecheck = new QCheckBox(horizontalLayoutWidget);
        timecheck->setObjectName(QString::fromUtf8("timecheck"));
        timecheck->setFont(font1);
        timecheck->setFocusPolicy(Qt::WheelFocus);

        horizontalLayout->addWidget(timecheck);

        linecheckBox = new QCheckBox(horizontalLayoutWidget);
        linecheckBox->setObjectName(QString::fromUtf8("linecheckBox"));
        linecheckBox->setFont(font1);

        horizontalLayout->addWidget(linecheckBox);

        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 530, 75, 23));
        pushButton_2->setFont(font1);
        RecClrButton = new QPushButton(frame);
        RecClrButton->setObjectName(QString::fromUtf8("RecClrButton"));
        RecClrButton->setGeometry(QRect(260, 530, 75, 24));
        RecClrButton->setFont(font1);
        stopDisSelBox = new QCheckBox(frame);
        stopDisSelBox->setObjectName(QString::fromUtf8("stopDisSelBox"));
        stopDisSelBox->setGeometry(QRect(100, 530, 91, 20));
        stopDisSelBox->setFont(font1);
        splitter_rec = new QSplitter(frame);
        splitter_rec->setObjectName(QString::fromUtf8("splitter_rec"));
        splitter_rec->setGeometry(QRect(0, 40, 341, 481));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter_rec->sizePolicy().hasHeightForWidth());
        splitter_rec->setSizePolicy(sizePolicy);
        splitter_rec->setMaximumSize(QSize(584, 481));
        splitter_rec->setOrientation(Qt::Horizontal);
        splitter_rec->setOpaqueResize(true);
        splitter_rec->setHandleWidth(2);
        splitter_rec->setChildrenCollapsible(true);
        ReceiveText = new QPlainTextEdit(splitter_rec);
        ReceiveText->setObjectName(QString::fromUtf8("ReceiveText"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ReceiveText->sizePolicy().hasHeightForWidth());
        ReceiveText->setSizePolicy(sizePolicy1);
        ReceiveText->setMinimumSize(QSize(100, 481));
        ReceiveText->setMaximumSize(QSize(341, 481));
        ReceiveText->setSizeIncrement(QSize(0, 0));
        QFont font2;
        font2.setPointSize(12);
        font2.setKerning(true);
        ReceiveText->setFont(font2);
        ReceiveText->setMouseTracking(false);
        ReceiveText->setFocusPolicy(Qt::WheelFocus);
        ReceiveText->setContextMenuPolicy(Qt::DefaultContextMenu);
        ReceiveText->setInputMethodHints(Qt::ImhNone);
        ReceiveText->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        ReceiveText->setUndoRedoEnabled(true);
        ReceiveText->setLineWrapMode(QPlainTextEdit::WidgetWidth);
        ReceiveText->setReadOnly(true);
        ReceiveText->setTabStopWidth(80);
        ReceiveText->setCursorWidth(1);
        ReceiveText->setTextInteractionFlags(Qt::TextSelectableByMouse);
        splitter_rec->addWidget(ReceiveText);
        textEdit = new QTextEdit(splitter_rec);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMaximumSize(QSize(241, 481));
        textEdit->setFrameShape(QFrame::NoFrame);
        textEdit->setReadOnly(true);
        textEdit->setTextInteractionFlags(Qt::NoTextInteraction);
        splitter_rec->addWidget(textEdit);
        frame_2 = new QFrame(tab);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(350, 0, 441, 551));
        frame_2->setLayoutDirection(Qt::LeftToRight);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        SendTextEdit = new QPlainTextEdit(frame_2);
        SendTextEdit->setObjectName(QString::fromUtf8("SendTextEdit"));
        SendTextEdit->setGeometry(QRect(0, 170, 441, 131));
        QFont font3;
        font3.setPointSize(12);
        font3.setItalic(false);
        SendTextEdit->setFont(font3);
        SendTextEdit->setMouseTracking(false);
        SendTextEdit->setFocusPolicy(Qt::WheelFocus);
        SendTextEdit->setAcceptDrops(false);
        SendTextEdit->setTextInteractionFlags(Qt::TextEditorInteraction);
        horizontalLayoutWidget_2 = new QWidget(frame_2);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, 130, 222, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(horizontalLayoutWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        label_7->setFont(font4);

        horizontalLayout_2->addWidget(label_7);

        sendHexSel = new QRadioButton(horizontalLayoutWidget_2);
        sendHexSel->setObjectName(QString::fromUtf8("sendHexSel"));
        sendHexSel->setFont(font1);

        horizontalLayout_2->addWidget(sendHexSel);

        sendCharSel = new QRadioButton(horizontalLayoutWidget_2);
        sendCharSel->setObjectName(QString::fromUtf8("sendCharSel"));
        sendCharSel->setFont(font1);

        horizontalLayout_2->addWidget(sendCharSel);

        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(360, 140, 75, 24));
        pushButton->setFont(font1);
        verticalLayoutWidget = new QWidget(frame_2);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 330, 441, 221));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(20);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        sendTextEdit_1 = new QPlainTextEdit(verticalLayoutWidget);
        sendTextEdit_1->setObjectName(QString::fromUtf8("sendTextEdit_1"));
        sendTextEdit_1->setMaximumSize(QSize(439, 40));
        QFont font5;
        font5.setPointSize(12);
        sendTextEdit_1->setFont(font5);

        verticalLayout->addWidget(sendTextEdit_1);

        sendTextEdit_2 = new QPlainTextEdit(verticalLayoutWidget);
        sendTextEdit_2->setObjectName(QString::fromUtf8("sendTextEdit_2"));
        sendTextEdit_2->setMaximumSize(QSize(439, 40));
        sendTextEdit_2->setFont(font5);

        verticalLayout->addWidget(sendTextEdit_2);

        sendTextEdit_3 = new QPlainTextEdit(verticalLayoutWidget);
        sendTextEdit_3->setObjectName(QString::fromUtf8("sendTextEdit_3"));
        sendTextEdit_3->setMaximumSize(QSize(439, 40));
        sendTextEdit_3->setFont(font5);

        verticalLayout->addWidget(sendTextEdit_3);

        sendTextEdit_4 = new QPlainTextEdit(verticalLayoutWidget);
        sendTextEdit_4->setObjectName(QString::fromUtf8("sendTextEdit_4"));
        sendTextEdit_4->setMaximumSize(QSize(439, 40));
        sendTextEdit_4->setFont(font5);

        verticalLayout->addWidget(sendTextEdit_4);

        sendButton = new QPushButton(frame_2);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setGeometry(QRect(360, 300, 75, 24));
        sendButton->setFont(font1);
        horizontalLayoutWidget_4 = new QWidget(frame_2);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(0, 300, 191, 31));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        autosendBox = new QCheckBox(horizontalLayoutWidget_4);
        autosendBox->setObjectName(QString::fromUtf8("autosendBox"));
        QFont font6;
        font6.setPointSize(10);
        font6.setBold(true);
        font6.setItalic(false);
        font6.setWeight(75);
        autosendBox->setFont(font6);

        horizontalLayout_4->addWidget(autosendBox);

        sendmsBox = new QSpinBox(horizontalLayoutWidget_4);
        sendmsBox->setObjectName(QString::fromUtf8("sendmsBox"));
        sendmsBox->setMaximum(10000);
        sendmsBox->setValue(10);

        horizontalLayout_4->addWidget(sendmsBox);

        horizontalLayoutWidget_3 = new QWidget(frame_2);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(0, 30, 301, 71));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setHorizontalSpacing(2);
        formLayout->setVerticalSpacing(2);
        label = new QLabel(horizontalLayoutWidget_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font4);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        PortBox = new QComboBox(horizontalLayoutWidget_3);
        PortBox->setObjectName(QString::fromUtf8("PortBox"));
        PortBox->setEditable(false);
        PortBox->setDuplicatesEnabled(false);
        PortBox->setFrame(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, PortBox);

        label_2 = new QLabel(horizontalLayoutWidget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font4);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        bandrate = new QComboBox(horizontalLayoutWidget_3);
        bandrate->setObjectName(QString::fromUtf8("bandrate"));

        formLayout->setWidget(1, QFormLayout::FieldRole, bandrate);

        label_4 = new QLabel(horizontalLayoutWidget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font4);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        databox = new QComboBox(horizontalLayoutWidget_3);
        databox->setObjectName(QString::fromUtf8("databox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, databox);


        horizontalLayout_3->addLayout(formLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_2->setHorizontalSpacing(2);
        formLayout_2->setVerticalSpacing(2);
        label_3 = new QLabel(horizontalLayoutWidget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font4);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_3);

        checkbox = new QComboBox(horizontalLayoutWidget_3);
        checkbox->setObjectName(QString::fromUtf8("checkbox"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, checkbox);

        label_5 = new QLabel(horizontalLayoutWidget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font4);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_5);

        stopbox = new QComboBox(horizontalLayoutWidget_3);
        stopbox->setObjectName(QString::fromUtf8("stopbox"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, stopbox);

        label_6 = new QLabel(horizontalLayoutWidget_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font4);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_6);

        flowbox = new QComboBox(horizontalLayoutWidget_3);
        flowbox->setObjectName(QString::fromUtf8("flowbox"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, flowbox);


        horizontalLayout_3->addLayout(formLayout_2);

        OpenButton = new QPushButton(frame_2);
        OpenButton->setObjectName(QString::fromUtf8("OpenButton"));
        OpenButton->setGeometry(QRect(300, 30, 140, 67));
        OpenButton->setFont(font1);
        searchbutton = new QPushButton(frame_2);
        searchbutton->setObjectName(QString::fromUtf8("searchbutton"));
        searchbutton->setGeometry(QRect(0, 0, 151, 31));
        searchbutton->setFont(font1);
        pushButton_3 = new QPushButton(frame_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(300, 0, 141, 31));
        pushButton_3->setFont(font1);
        horizontalLayoutWidget_2->raise();
        pushButton->raise();
        verticalLayoutWidget->raise();
        sendButton->raise();
        horizontalLayoutWidget_4->raise();
        SendTextEdit->raise();
        horizontalLayoutWidget_3->raise();
        OpenButton->raise();
        searchbutton->raise();
        pushButton_3->raise();
        sendTextEdit_1->raise();
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(0, 0, 0, 0));
        splitter->setOrientation(Qt::Horizontal);
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setFont(font4);
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\267\245\345\205\267\347\256\261 @\345\220\276\344\271\220", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "\346\216\245\346\224\266\346\225\260\346\215\256\357\274\232", 0, QApplication::UnicodeUTF8));
        recHexSel->setText(QApplication::translate("MainWindow", "HEX", 0, QApplication::UnicodeUTF8));
        recCharSel->setText(QApplication::translate("MainWindow", "\345\255\227\347\254\246", 0, QApplication::UnicodeUTF8));
        timecheck->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        linecheckBox->setText(QApplication::translate("MainWindow", "\346\215\242\350\241\214", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        RecClrButton->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272", 0, QApplication::UnicodeUTF8));
        stopDisSelBox->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\346\230\276\347\244\272", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\346\225\260\346\215\256\357\274\232", 0, QApplication::UnicodeUTF8));
        sendHexSel->setText(QApplication::translate("MainWindow", "HEX", 0, QApplication::UnicodeUTF8));
        sendCharSel->setText(QApplication::translate("MainWindow", "\345\255\227\347\254\246", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272", 0, QApplication::UnicodeUTF8));
        sendButton->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
        autosendBox->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\345\217\221\351\200\201(ms):", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207\357\274\232", 0, QApplication::UnicodeUTF8));
        bandrate->clear();
        bandrate->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "4800", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "9600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "14400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "19200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "115200", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215\357\274\232", 0, QApplication::UnicodeUTF8));
        databox->clear();
        databox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "5bit", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "6bit", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "7bit", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "8bit", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215\357\274\232", 0, QApplication::UnicodeUTF8));
        checkbox->clear();
        checkbox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "None \346\227\240", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Odd \345\245\207", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Even \345\201\266", 0, QApplication::UnicodeUTF8)
        );
        label_5->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215\357\274\232", 0, QApplication::UnicodeUTF8));
        stopbox->clear();
        stopbox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1bit", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1.5bit", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2bit", 0, QApplication::UnicodeUTF8)
        );
        label_6->setText(QApplication::translate("MainWindow", "\346\265\201\346\216\247\345\210\266\357\274\232", 0, QApplication::UnicodeUTF8));
        flowbox->clear();
        flowbox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "OFF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\347\241\254\344\273\266", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "XON/XOFF", 0, QApplication::UnicodeUTF8)
        );
        OpenButton->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", 0, QApplication::UnicodeUTF8));
        searchbutton->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\346\220\234\347\264\242", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "\345\233\276\345\275\242\346\230\276\347\244\272", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\344\270\262\345\217\243", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
