#-------------------------------------------------
#
# Project created by QtCreator 2013-01-06T20:31:32
#
#-------------------------------------------------

QT       += core gui phonon

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = award-pickup
TEMPLATE = app

RC_FILE = awardpickup.rc

SOURCES += main.cpp\
        awardpickup.cpp \
    people.cpp \
    setupdialog.cpp \
    helpdialog.cpp

HEADERS  += awardpickup.h \
    people.h \
    setupdialog.h \
    helpdialog.h

FORMS    += awardpickup.ui \
    setupdialog.ui \
    helpdialog.ui

RESOURCES += \
    awardpickup.qrc
