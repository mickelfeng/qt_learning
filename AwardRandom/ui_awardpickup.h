/********************************************************************************
** Form generated from reading UI file 'awardpickup.ui'
**
** Created: Mon Feb 16 11:39:49 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AWARDPICKUP_H
#define UI_AWARDPICKUP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AwardPickup
{
public:
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QLabel *curAwardLabel;
    QLabel *curAwardPicLabel;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *nameLabel;
    QLabel *headPicLabel;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *award1VerticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *award1TCntLabel;
    QToolButton *award1ToolButton;
    QLabel *award1CntLabel;
    QListWidget *award1ListWidget;
    QVBoxLayout *award2VerticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *award2TCntLabel;
    QToolButton *award2ToolButton;
    QLabel *award2CntLabel;
    QListWidget *award2ListWidget;
    QVBoxLayout *award3VerticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *award3TCntLabel;
    QToolButton *award3ToolButton;
    QLabel *award3CntLabel;
    QListWidget *award3ListWidget;
    QVBoxLayout *award4VerticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QLabel *award4TCntLabel;
    QToolButton *award4ToolButton;
    QLabel *award4CntLabel;
    QListWidget *award4ListWidget;
    QVBoxLayout *award5VerticalLayout;
    QHBoxLayout *horizontalLayout_7;
    QLabel *award5TCntLabel;
    QToolButton *award5ToolButton;
    QLabel *award5CntLabel;
    QListWidget *award5ListWidget;
    QVBoxLayout *award6VerticalLayout;
    QHBoxLayout *horizontalLayout_8;
    QLabel *award6TCntLabel;
    QToolButton *award6ToolButton;
    QLabel *award6CntLabel;
    QListWidget *award6ListWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *totalCntLabel_2;
    QLabel *totalCntLabel;
    QLabel *aboutLabel;
    QToolButton *helpToolButton;
    QToolButton *setupToolButton;
    QToolButton *saveResultToolButton;
    QToolButton *musicToolButton;
    QToolButton *quitToolButton;

    void setupUi(QWidget *AwardPickup)
    {
        if (AwardPickup->objectName().isEmpty())
            AwardPickup->setObjectName(QString::fromUtf8("AwardPickup"));
        AwardPickup->resize(1142, 773);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/awardpickup.png"), QSize(), QIcon::Normal, QIcon::Off);
        AwardPickup->setWindowIcon(icon);
        AwardPickup->setStyleSheet(QString::fromUtf8("QWidget::AwardPicup{background:url(:/images/bg1.jpg)}\n"
"#curAwardLabel{background: rgb(100, 155, 255,100)}\n"
"#curAwardPicLabel{background: rgb(100, 155, 255,100)}\n"
"#nameLabel{background: rgb(100, 155, 255,100)}\n"
"#headPicLabel{background: rgb(100, 155, 255,100)}\n"
"#award1CntLabel{background: rgb(100, 155, 255,100)}\n"
"#award1TCntLabel{background: rgb(100, 155, 255,100)}\n"
"#award2CntLabel{background: rgb(100, 155, 255,100)}\n"
"#award2TCntLabel{background: rgb(100, 155, 255,100)}\n"
"#award3CntLabel{background: rgb(100, 155, 255,100)}\n"
"#award3TCntLabel{background: rgb(100, 155, 255,100)}\n"
"#award4CntLabel{background: rgb(100, 155, 255,100)}\n"
"#award4TCntLabel{background: rgb(100, 155, 255,100)}\n"
"#award5CntLabel{background: rgb(100, 155, 255,100)}\n"
"#award5TCntLabel{background: rgb(100, 155, 255,100)}\n"
"#award6CntLabel{background: rgb(100, 155, 255,100)}\n"
"#award6TCntLabel{background: rgb(100, 155, 255,100)}\n"
"#totalCntLabel_2{background: rgb(100, 155, 255,100)}\n"
"#totalCntLabel"
                        "{background: rgb(100, 155, 255,100)}\n"
"#aboutLabel{background: rgb(100, 155, 255,100)}\n"
"QListWidget{background: rgb(100, 155, 255,100)}\n"
""));
        verticalLayout_9 = new QVBoxLayout(AwardPickup);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        curAwardLabel = new QLabel(AwardPickup);
        curAwardLabel->setObjectName(QString::fromUtf8("curAwardLabel"));
        curAwardLabel->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        curAwardLabel->setFont(font);
        curAwardLabel->setScaledContents(false);
        curAwardLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(curAwardLabel);

        curAwardPicLabel = new QLabel(AwardPickup);
        curAwardPicLabel->setObjectName(QString::fromUtf8("curAwardPicLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(curAwardPicLabel->sizePolicy().hasHeightForWidth());
        curAwardPicLabel->setSizePolicy(sizePolicy);
        curAwardPicLabel->setMinimumSize(QSize(320, 240));
        curAwardPicLabel->setMaximumSize(QSize(640, 480));
        curAwardPicLabel->setFrameShape(QFrame::Panel);
        curAwardPicLabel->setFrameShadow(QFrame::Sunken);
        curAwardPicLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(curAwardPicLabel);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        nameLabel = new QLabel(AwardPickup);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        QFont font1;
        font1.setPointSize(30);
        font1.setBold(true);
        font1.setWeight(75);
        nameLabel->setFont(font1);
        nameLabel->setScaledContents(false);
        nameLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(nameLabel);

        headPicLabel = new QLabel(AwardPickup);
        headPicLabel->setObjectName(QString::fromUtf8("headPicLabel"));
        sizePolicy.setHeightForWidth(headPicLabel->sizePolicy().hasHeightForWidth());
        headPicLabel->setSizePolicy(sizePolicy);
        headPicLabel->setMinimumSize(QSize(600, 480));
        headPicLabel->setMaximumSize(QSize(640, 480));
        headPicLabel->setFrameShape(QFrame::Panel);
        headPicLabel->setFrameShadow(QFrame::Sunken);
        headPicLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(headPicLabel);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);


        horizontalLayout_3->addLayout(verticalLayout);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_9->addLayout(horizontalLayout_3);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        award1VerticalLayout = new QVBoxLayout();
        award1VerticalLayout->setSpacing(6);
        award1VerticalLayout->setObjectName(QString::fromUtf8("award1VerticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        award1TCntLabel = new QLabel(AwardPickup);
        award1TCntLabel->setObjectName(QString::fromUtf8("award1TCntLabel"));
        award1TCntLabel->setMinimumSize(QSize(0, 0));
        award1TCntLabel->setMaximumSize(QSize(48, 16777215));
        QFont font2;
        font2.setPointSize(28);
        award1TCntLabel->setFont(font2);
        award1TCntLabel->setFrameShape(QFrame::Panel);
        award1TCntLabel->setFrameShadow(QFrame::Sunken);
        award1TCntLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(award1TCntLabel);

        award1ToolButton = new QToolButton(AwardPickup);
        award1ToolButton->setObjectName(QString::fromUtf8("award1ToolButton"));
        award1ToolButton->setAutoFillBackground(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/award1.png"), QSize(), QIcon::Normal, QIcon::Off);
        award1ToolButton->setIcon(icon1);
        award1ToolButton->setIconSize(QSize(48, 48));
        award1ToolButton->setAutoRaise(false);

        horizontalLayout_2->addWidget(award1ToolButton);

        award1CntLabel = new QLabel(AwardPickup);
        award1CntLabel->setObjectName(QString::fromUtf8("award1CntLabel"));
        award1CntLabel->setMinimumSize(QSize(0, 0));
        award1CntLabel->setMaximumSize(QSize(48, 16777215));
        award1CntLabel->setFont(font2);
        award1CntLabel->setFrameShape(QFrame::Panel);
        award1CntLabel->setFrameShadow(QFrame::Sunken);
        award1CntLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(award1CntLabel);


        award1VerticalLayout->addLayout(horizontalLayout_2);

        award1ListWidget = new QListWidget(AwardPickup);
        award1ListWidget->setObjectName(QString::fromUtf8("award1ListWidget"));
        sizePolicy.setHeightForWidth(award1ListWidget->sizePolicy().hasHeightForWidth());
        award1ListWidget->setSizePolicy(sizePolicy);
        award1ListWidget->setMaximumSize(QSize(180, 16777215));

        award1VerticalLayout->addWidget(award1ListWidget);


        horizontalLayout_9->addLayout(award1VerticalLayout);

        award2VerticalLayout = new QVBoxLayout();
        award2VerticalLayout->setSpacing(6);
        award2VerticalLayout->setObjectName(QString::fromUtf8("award2VerticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        award2TCntLabel = new QLabel(AwardPickup);
        award2TCntLabel->setObjectName(QString::fromUtf8("award2TCntLabel"));
        award2TCntLabel->setMinimumSize(QSize(0, 0));
        award2TCntLabel->setMaximumSize(QSize(48, 16777215));
        award2TCntLabel->setFont(font2);
        award2TCntLabel->setFrameShape(QFrame::Panel);
        award2TCntLabel->setFrameShadow(QFrame::Sunken);
        award2TCntLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(award2TCntLabel);

        award2ToolButton = new QToolButton(AwardPickup);
        award2ToolButton->setObjectName(QString::fromUtf8("award2ToolButton"));
        award2ToolButton->setAutoFillBackground(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/award2.png"), QSize(), QIcon::Normal, QIcon::Off);
        award2ToolButton->setIcon(icon2);
        award2ToolButton->setIconSize(QSize(48, 48));
        award2ToolButton->setAutoRaise(false);

        horizontalLayout_4->addWidget(award2ToolButton);

        award2CntLabel = new QLabel(AwardPickup);
        award2CntLabel->setObjectName(QString::fromUtf8("award2CntLabel"));
        award2CntLabel->setMinimumSize(QSize(0, 0));
        award2CntLabel->setMaximumSize(QSize(48, 16777215));
        award2CntLabel->setFont(font2);
        award2CntLabel->setFrameShape(QFrame::Panel);
        award2CntLabel->setFrameShadow(QFrame::Sunken);
        award2CntLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(award2CntLabel);


        award2VerticalLayout->addLayout(horizontalLayout_4);

        award2ListWidget = new QListWidget(AwardPickup);
        award2ListWidget->setObjectName(QString::fromUtf8("award2ListWidget"));
        sizePolicy.setHeightForWidth(award2ListWidget->sizePolicy().hasHeightForWidth());
        award2ListWidget->setSizePolicy(sizePolicy);
        award2ListWidget->setMaximumSize(QSize(180, 16777215));

        award2VerticalLayout->addWidget(award2ListWidget);


        horizontalLayout_9->addLayout(award2VerticalLayout);

        award3VerticalLayout = new QVBoxLayout();
        award3VerticalLayout->setSpacing(6);
        award3VerticalLayout->setObjectName(QString::fromUtf8("award3VerticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        award3TCntLabel = new QLabel(AwardPickup);
        award3TCntLabel->setObjectName(QString::fromUtf8("award3TCntLabel"));
        award3TCntLabel->setMinimumSize(QSize(0, 0));
        award3TCntLabel->setMaximumSize(QSize(48, 16777215));
        award3TCntLabel->setFont(font2);
        award3TCntLabel->setFrameShape(QFrame::Panel);
        award3TCntLabel->setFrameShadow(QFrame::Sunken);
        award3TCntLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(award3TCntLabel);

        award3ToolButton = new QToolButton(AwardPickup);
        award3ToolButton->setObjectName(QString::fromUtf8("award3ToolButton"));
        award3ToolButton->setAutoFillBackground(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/award3.png"), QSize(), QIcon::Normal, QIcon::Off);
        award3ToolButton->setIcon(icon3);
        award3ToolButton->setIconSize(QSize(48, 48));
        award3ToolButton->setAutoRaise(false);

        horizontalLayout_5->addWidget(award3ToolButton);

        award3CntLabel = new QLabel(AwardPickup);
        award3CntLabel->setObjectName(QString::fromUtf8("award3CntLabel"));
        award3CntLabel->setMinimumSize(QSize(0, 0));
        award3CntLabel->setMaximumSize(QSize(48, 16777215));
        award3CntLabel->setFont(font2);
        award3CntLabel->setFrameShape(QFrame::Panel);
        award3CntLabel->setFrameShadow(QFrame::Sunken);
        award3CntLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(award3CntLabel);


        award3VerticalLayout->addLayout(horizontalLayout_5);

        award3ListWidget = new QListWidget(AwardPickup);
        award3ListWidget->setObjectName(QString::fromUtf8("award3ListWidget"));
        sizePolicy.setHeightForWidth(award3ListWidget->sizePolicy().hasHeightForWidth());
        award3ListWidget->setSizePolicy(sizePolicy);
        award3ListWidget->setMaximumSize(QSize(180, 16777215));

        award3VerticalLayout->addWidget(award3ListWidget);


        horizontalLayout_9->addLayout(award3VerticalLayout);

        award4VerticalLayout = new QVBoxLayout();
        award4VerticalLayout->setSpacing(6);
        award4VerticalLayout->setObjectName(QString::fromUtf8("award4VerticalLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        award4TCntLabel = new QLabel(AwardPickup);
        award4TCntLabel->setObjectName(QString::fromUtf8("award4TCntLabel"));
        award4TCntLabel->setMinimumSize(QSize(0, 0));
        award4TCntLabel->setMaximumSize(QSize(48, 16777215));
        award4TCntLabel->setFont(font2);
        award4TCntLabel->setFrameShape(QFrame::Panel);
        award4TCntLabel->setFrameShadow(QFrame::Sunken);
        award4TCntLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(award4TCntLabel);

        award4ToolButton = new QToolButton(AwardPickup);
        award4ToolButton->setObjectName(QString::fromUtf8("award4ToolButton"));
        award4ToolButton->setAutoFillBackground(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/award4.png"), QSize(), QIcon::Normal, QIcon::Off);
        award4ToolButton->setIcon(icon4);
        award4ToolButton->setIconSize(QSize(48, 48));
        award4ToolButton->setAutoRaise(false);

        horizontalLayout_6->addWidget(award4ToolButton);

        award4CntLabel = new QLabel(AwardPickup);
        award4CntLabel->setObjectName(QString::fromUtf8("award4CntLabel"));
        award4CntLabel->setMinimumSize(QSize(0, 0));
        award4CntLabel->setMaximumSize(QSize(48, 16777215));
        award4CntLabel->setFont(font2);
        award4CntLabel->setFrameShape(QFrame::Panel);
        award4CntLabel->setFrameShadow(QFrame::Sunken);
        award4CntLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(award4CntLabel);


        award4VerticalLayout->addLayout(horizontalLayout_6);

        award4ListWidget = new QListWidget(AwardPickup);
        award4ListWidget->setObjectName(QString::fromUtf8("award4ListWidget"));
        sizePolicy.setHeightForWidth(award4ListWidget->sizePolicy().hasHeightForWidth());
        award4ListWidget->setSizePolicy(sizePolicy);
        award4ListWidget->setMaximumSize(QSize(180, 16777215));

        award4VerticalLayout->addWidget(award4ListWidget);


        horizontalLayout_9->addLayout(award4VerticalLayout);

        award5VerticalLayout = new QVBoxLayout();
        award5VerticalLayout->setSpacing(6);
        award5VerticalLayout->setObjectName(QString::fromUtf8("award5VerticalLayout"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        award5TCntLabel = new QLabel(AwardPickup);
        award5TCntLabel->setObjectName(QString::fromUtf8("award5TCntLabel"));
        award5TCntLabel->setMinimumSize(QSize(0, 0));
        award5TCntLabel->setMaximumSize(QSize(48, 16777215));
        award5TCntLabel->setFont(font2);
        award5TCntLabel->setFrameShape(QFrame::Panel);
        award5TCntLabel->setFrameShadow(QFrame::Sunken);
        award5TCntLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(award5TCntLabel);

        award5ToolButton = new QToolButton(AwardPickup);
        award5ToolButton->setObjectName(QString::fromUtf8("award5ToolButton"));
        award5ToolButton->setAutoFillBackground(false);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/award5.png"), QSize(), QIcon::Normal, QIcon::Off);
        award5ToolButton->setIcon(icon5);
        award5ToolButton->setIconSize(QSize(48, 48));
        award5ToolButton->setAutoRaise(false);

        horizontalLayout_7->addWidget(award5ToolButton);

        award5CntLabel = new QLabel(AwardPickup);
        award5CntLabel->setObjectName(QString::fromUtf8("award5CntLabel"));
        award5CntLabel->setMinimumSize(QSize(0, 0));
        award5CntLabel->setMaximumSize(QSize(48, 16777215));
        award5CntLabel->setFont(font2);
        award5CntLabel->setFrameShape(QFrame::Panel);
        award5CntLabel->setFrameShadow(QFrame::Sunken);
        award5CntLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(award5CntLabel);


        award5VerticalLayout->addLayout(horizontalLayout_7);

        award5ListWidget = new QListWidget(AwardPickup);
        award5ListWidget->setObjectName(QString::fromUtf8("award5ListWidget"));
        sizePolicy.setHeightForWidth(award5ListWidget->sizePolicy().hasHeightForWidth());
        award5ListWidget->setSizePolicy(sizePolicy);
        award5ListWidget->setMaximumSize(QSize(180, 16777215));

        award5VerticalLayout->addWidget(award5ListWidget);


        horizontalLayout_9->addLayout(award5VerticalLayout);

        award6VerticalLayout = new QVBoxLayout();
        award6VerticalLayout->setSpacing(6);
        award6VerticalLayout->setObjectName(QString::fromUtf8("award6VerticalLayout"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        award6TCntLabel = new QLabel(AwardPickup);
        award6TCntLabel->setObjectName(QString::fromUtf8("award6TCntLabel"));
        award6TCntLabel->setMinimumSize(QSize(0, 0));
        award6TCntLabel->setMaximumSize(QSize(48, 16777215));
        award6TCntLabel->setFont(font2);
        award6TCntLabel->setFrameShape(QFrame::Panel);
        award6TCntLabel->setFrameShadow(QFrame::Sunken);
        award6TCntLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(award6TCntLabel);

        award6ToolButton = new QToolButton(AwardPickup);
        award6ToolButton->setObjectName(QString::fromUtf8("award6ToolButton"));
        award6ToolButton->setAutoFillBackground(false);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/award6.png"), QSize(), QIcon::Normal, QIcon::Off);
        award6ToolButton->setIcon(icon6);
        award6ToolButton->setIconSize(QSize(48, 48));
        award6ToolButton->setAutoRaise(false);

        horizontalLayout_8->addWidget(award6ToolButton);

        award6CntLabel = new QLabel(AwardPickup);
        award6CntLabel->setObjectName(QString::fromUtf8("award6CntLabel"));
        award6CntLabel->setMinimumSize(QSize(0, 0));
        award6CntLabel->setMaximumSize(QSize(48, 16777215));
        award6CntLabel->setFont(font2);
        award6CntLabel->setFrameShape(QFrame::Panel);
        award6CntLabel->setFrameShadow(QFrame::Sunken);
        award6CntLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(award6CntLabel);


        award6VerticalLayout->addLayout(horizontalLayout_8);

        award6ListWidget = new QListWidget(AwardPickup);
        award6ListWidget->setObjectName(QString::fromUtf8("award6ListWidget"));
        sizePolicy.setHeightForWidth(award6ListWidget->sizePolicy().hasHeightForWidth());
        award6ListWidget->setSizePolicy(sizePolicy);
        award6ListWidget->setMaximumSize(QSize(180, 16777215));

        award6VerticalLayout->addWidget(award6ListWidget);


        horizontalLayout_9->addLayout(award6VerticalLayout);


        verticalLayout_9->addLayout(horizontalLayout_9);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        totalCntLabel_2 = new QLabel(AwardPickup);
        totalCntLabel_2->setObjectName(QString::fromUtf8("totalCntLabel_2"));
        totalCntLabel_2->setMinimumSize(QSize(100, 0));
        QPalette palette;
        QBrush brush(QColor(100, 155, 255, 100));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(0, 0, 127, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        totalCntLabel_2->setPalette(palette);
        QFont font3;
        font3.setPointSize(18);
        totalCntLabel_2->setFont(font3);
        totalCntLabel_2->setFrameShape(QFrame::Panel);
        totalCntLabel_2->setFrameShadow(QFrame::Sunken);
        totalCntLabel_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(totalCntLabel_2);

        totalCntLabel = new QLabel(AwardPickup);
        totalCntLabel->setObjectName(QString::fromUtf8("totalCntLabel"));
        totalCntLabel->setMinimumSize(QSize(100, 0));
        totalCntLabel->setFont(font2);
        totalCntLabel->setFrameShape(QFrame::Panel);
        totalCntLabel->setFrameShadow(QFrame::Sunken);
        totalCntLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(totalCntLabel);

        aboutLabel = new QLabel(AwardPickup);
        aboutLabel->setObjectName(QString::fromUtf8("aboutLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(aboutLabel->sizePolicy().hasHeightForWidth());
        aboutLabel->setSizePolicy(sizePolicy1);
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(12);
        font4.setBold(false);
        font4.setWeight(50);
        aboutLabel->setFont(font4);
        aboutLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(aboutLabel);

        helpToolButton = new QToolButton(AwardPickup);
        helpToolButton->setObjectName(QString::fromUtf8("helpToolButton"));
        helpToolButton->setAutoFillBackground(false);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        helpToolButton->setIcon(icon7);
        helpToolButton->setIconSize(QSize(48, 48));
        helpToolButton->setAutoRaise(false);

        horizontalLayout->addWidget(helpToolButton);

        setupToolButton = new QToolButton(AwardPickup);
        setupToolButton->setObjectName(QString::fromUtf8("setupToolButton"));
        setupToolButton->setAutoFillBackground(false);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/setup.png"), QSize(), QIcon::Normal, QIcon::Off);
        setupToolButton->setIcon(icon8);
        setupToolButton->setIconSize(QSize(48, 48));
        setupToolButton->setAutoRaise(false);

        horizontalLayout->addWidget(setupToolButton);

        saveResultToolButton = new QToolButton(AwardPickup);
        saveResultToolButton->setObjectName(QString::fromUtf8("saveResultToolButton"));
        saveResultToolButton->setAutoFillBackground(false);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/save1.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveResultToolButton->setIcon(icon9);
        saveResultToolButton->setIconSize(QSize(48, 48));
        saveResultToolButton->setAutoRaise(false);

        horizontalLayout->addWidget(saveResultToolButton);

        musicToolButton = new QToolButton(AwardPickup);
        musicToolButton->setObjectName(QString::fromUtf8("musicToolButton"));
        musicToolButton->setAutoFillBackground(false);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/music.png"), QSize(), QIcon::Normal, QIcon::Off);
        musicToolButton->setIcon(icon10);
        musicToolButton->setIconSize(QSize(48, 48));
        musicToolButton->setCheckable(true);
        musicToolButton->setAutoRaise(false);

        horizontalLayout->addWidget(musicToolButton);

        quitToolButton = new QToolButton(AwardPickup);
        quitToolButton->setObjectName(QString::fromUtf8("quitToolButton"));
        quitToolButton->setAutoFillBackground(false);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/quit.png"), QSize(), QIcon::Normal, QIcon::Off);
        quitToolButton->setIcon(icon11);
        quitToolButton->setIconSize(QSize(48, 48));
        quitToolButton->setAutoRaise(false);

        horizontalLayout->addWidget(quitToolButton);


        verticalLayout_9->addLayout(horizontalLayout);


        retranslateUi(AwardPickup);
        QObject::connect(quitToolButton, SIGNAL(clicked()), AwardPickup, SLOT(close()));

        QMetaObject::connectSlotsByName(AwardPickup);
    } // setupUi

    void retranslateUi(QWidget *AwardPickup)
    {
        AwardPickup->setWindowTitle(QApplication::translate("AwardPickup", "AwardPickup", 0, QApplication::UnicodeUTF8));
        curAwardLabel->setText(QString());
        curAwardPicLabel->setText(QString());
        nameLabel->setText(QString());
        headPicLabel->setText(QString());
        award1TCntLabel->setText(QString());
        award1ToolButton->setText(QApplication::translate("AwardPickup", "...", 0, QApplication::UnicodeUTF8));
        award1CntLabel->setText(QString());
        award2TCntLabel->setText(QString());
        award2ToolButton->setText(QApplication::translate("AwardPickup", "...", 0, QApplication::UnicodeUTF8));
        award2CntLabel->setText(QString());
        award3TCntLabel->setText(QString());
        award3ToolButton->setText(QApplication::translate("AwardPickup", "...", 0, QApplication::UnicodeUTF8));
        award3CntLabel->setText(QString());
        award4TCntLabel->setText(QString());
        award4ToolButton->setText(QApplication::translate("AwardPickup", "...", 0, QApplication::UnicodeUTF8));
        award4CntLabel->setText(QString());
        award5TCntLabel->setText(QString());
        award5ToolButton->setText(QApplication::translate("AwardPickup", "...", 0, QApplication::UnicodeUTF8));
        award5CntLabel->setText(QString());
        award6TCntLabel->setText(QString());
        award6ToolButton->setText(QApplication::translate("AwardPickup", "...", 0, QApplication::UnicodeUTF8));
        award6CntLabel->setText(QString());
        totalCntLabel_2->setText(QApplication::translate("AwardPickup", "\346\234\252\344\270\255\345\245\226\346\200\273\344\272\272\346\225\260\357\274\232", 0, QApplication::UnicodeUTF8));
        totalCntLabel->setText(QString());
        aboutLabel->setText(QApplication::translate("AwardPickup", "\346\234\254\346\212\275\345\245\226\350\275\257\344\273\266\347\224\261\345\256\213\345\276\267\351\224\213\344\270\252\344\272\272\345\217\213\346\203\205\346\217\220\344\276\233\n"
"\346\234\211\351\227\256\351\242\230\350\257\267\350\201\224\347\263\273QQ\357\274\23220068440", 0, QApplication::UnicodeUTF8));
        helpToolButton->setText(QApplication::translate("AwardPickup", "...", 0, QApplication::UnicodeUTF8));
        setupToolButton->setText(QApplication::translate("AwardPickup", "...", 0, QApplication::UnicodeUTF8));
        saveResultToolButton->setText(QApplication::translate("AwardPickup", "...", 0, QApplication::UnicodeUTF8));
        musicToolButton->setText(QApplication::translate("AwardPickup", "...", 0, QApplication::UnicodeUTF8));
        quitToolButton->setText(QApplication::translate("AwardPickup", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AwardPickup: public Ui_AwardPickup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AWARDPICKUP_H
