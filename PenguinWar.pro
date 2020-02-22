#-------------------------------------------------
#
# Project created by QtCreator 2020-02-16T20:13:50
# yongheng0852@live.cn
#
#-------------------------------------------------

#加载多基础模块
QT       += core gui

#加载多媒体模块
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PenguinWar
TEMPLATE = app


DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
    main.cpp \
    Bullet.cpp \
    Player.cpp \
    Enemy.cpp \
    Game.cpp \
    Score.cpp \
    Health.cpp

HEADERS += \
    Bullet.h \
    Player.h \
    Enemy.h \
    ClassType.h \
    Game.h \
    Score.h \
    Health.h

RC_ICONS = ./logo.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
