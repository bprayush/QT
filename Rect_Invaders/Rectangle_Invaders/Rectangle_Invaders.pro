#-------------------------------------------------
#
# Project created by QtCreator 2017-01-17T18:00:44
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Rectangle_Invaders
TEMPLATE = app


SOURCES += main.cpp \
    player.cpp \
    game.cpp \
    bullet.cpp \
    enemy.cpp \
    score.cpp \
    health.cpp \
    gameover.cpp

HEADERS  += \
    player.h \
    game.h \
    bullet.h \
    enemy.h \
    score.h \
    health.h \
    gameover.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
