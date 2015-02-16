#-------------------------------------------------
#
# Project created by QtCreator 2014-08-02T16:02:47
#
#-------------------------------------------------

QT       += core gui winextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyImageView
TEMPLATE = app


SOURCES += main.cpp\
       src/ui/mainwindow.cpp \
    src/picview/ui/mainview.cpp \
    src/picview/ui/controlview.cpp \
    src/picview/ui/imageview.cpp

HEADERS  += src/ui/mainwindow.h \
    src/picview/ui/mainview.h \
    src/picview/ui/controlview.h \
    src/picview/ui/imageview.h \
    src/picview/picview.h

FORMS    += src/ui/mainwindow.ui \
   src/picview/ui/mainview.ui \
    src/picview/ui/controlview.ui \
    src/picview/ui/imageview.ui

RESOURCES += \
    rs.qrc
