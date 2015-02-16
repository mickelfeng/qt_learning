#-------------------------------------------------
#
# Project created by QtCreator 2013-09-27T22:06:29
#
#-------------------------------------------------

QT       += core
QT       += opengl
#QT       += phonon
#QT       -= gui

TARGET = BeatPlane
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    MainRender.cpp \
    QSprite.cpp \
    CBullet.cpp \
    CEnemy.cpp \
    CPlane.cpp \
    CMyPlane.cpp \
    CEnemyController.cpp \
    CScoreboard.cpp \
    CTimeDelay.cpp \
    CRandom.cpp \
    Settings.cpp \
    CConfig.cpp

HEADERS += \
    Config.h \
    MainRender.h \
    QSprite.h \
    CBullet.h \
    CEnemy.h \
    CPlane.h \
    CMyPlane.h \
    CEnemyController.h \
    CScoreboard.h \
    CTimeDelay.h \
    CRandom.h \
    Settings.h \
    CConfig.h

FORMS += \
    Settings.ui

#LIBS += -L G:\\Programs\\FMOD\\SoundSystem\\FMOD\\Programmers\\API\\Windows\\api\\lib\\libfmodex.a

#INCLUDEPATH += G:/Programs/FMOD SoundSystem/FMOD Programmers API Windows/api/inc

#INCLUDEPATH += fmod/
#LIBS += -lfmodL
