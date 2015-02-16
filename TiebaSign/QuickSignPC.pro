#-------------------------------------------------
#
# Project created by QtCreator 2013-01-10T13:28:59
#
#-------------------------------------------------

QT       += core
QT      +=  network
QT += script
QT       -= gui

TARGET = QuickSignPC
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Httper.cpp \
    S_IO.cpp

HEADERS += \
    Httper.h \
    H_IO.h

RC_FILE = myapp.rc
