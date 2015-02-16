#-------------------------------------------------
#
# Project created by QtCreator 2013-11-09T13:44:29
#
#-------------------------------------------------

QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DigDuck
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ipinfo.cpp \
    portscan.cpp

HEADERS  += mainwindow.h \
    ipinfo.h \
    portscan.h

FORMS    += mainwindow.ui
RC_FILE   = ico.rc

RESOURCES += \
    resources.qrc

OTHER_FILES += \
    style.qss

CONFIG += thread
