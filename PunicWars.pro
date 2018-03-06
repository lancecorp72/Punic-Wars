#-------------------------------------------------
#
# Project created by QtCreator 2018-02-22T19:01:50
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PunicWars
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG  += c++11
SOURCES += \
        main.cpp \
    Source/Game.cpp \
    Source/Tower.cpp \
    Source/Player1.cpp \
    Source/Bullet.cpp \
    Source/Ships.cpp \
    Source/Resource.cpp \
    Source/Path.cpp \
    Source/Tutorial.cpp \
    Source/ShipThrd.cpp \
    Source/TowerThrd.cpp \
    Source/BulletThrd.cpp

HEADERS += \
    Headers/Tower.h \
    Headers/Game.h \
    Headers/Player1.h \
    Headers/Bullet.h \
    Headers/Ships.h \
    Headers/Resource.h \
    Headers/Path.h \
    Headers/Tutorial.h \
    Headers/ShipThrd.h \
    Headers/TowerThrd.h \
    Headers/ShipMove.h \
    Headers/TowerShoot.h \
    Headers/BulletThrd.h \
    Headers/BulletMove.h

INCLUDEPATH += $$PWD/Headers

RESOURCES += \
    resource.qrc
