#-------------------------------------------------
#
# Project created by QtCreator 2014-09-02T20:02:46
#
#-------------------------------------------------

QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NoCo_chat
TEMPLATE = app


SOURCES += main.cpp \
    mainwindow.cpp \
    signin.cpp \
    udpnet.cpp \
    tcpnet.cpp \
    handle.cpp \
    config.cpp \
    addinfo.cpp \
    login.cpp \
    chat.cpp \
    roomchat.cpp

HEADERS  += \
    mainwindow.h \
    signin.h \
    udpnet.h \
    tcpnet.h \
    handle.h \
    config.h \
    chat.h \
    addinfo.h \
    login.h \
    chat.h \
    roomchat.h

FORMS    += \
    mainwindow.ui \
    signin.ui \
    addinfo.ui \
    login.ui

RESOURCES += \
    images.qrc

