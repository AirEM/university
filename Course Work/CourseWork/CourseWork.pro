#-------------------------------------------------
#
# Project created by QtCreator 2019-06-28T18:23:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CourseWork
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

CONFIG += c++11

SOURCES += \
    Camera/camera.cpp \
    Command/addconecommand.cpp \
    Command/addcubecommand.cpp \
    Command/addlightcommand.cpp \
    Command/addspherecommand.cpp \
    Command/cleancommand.cpp \
    Command/deletelightcommand.cpp \
    Command/rendercommand.cpp \
    Drawer/qtdrawer.cpp \
    Geometry/vector3d.cpp \
    Proxy/proxy.cpp \
    Manager/drawmanager.cpp \
    Manager/scenemanager.cpp \
    Mediator/mediator.cpp \
    Object/Light/light.cpp \
    Object/Material/material.cpp \
    Object/cone.cpp \
    Object/cube.cpp \
    Object/sphere.cpp \
    Scene/scene.cpp \
    facade/facade.cpp \
    lightdialog.cpp \
        main.cpp \
        mainwindow.cpp \
    renderarea.cpp

HEADERS += \
    Camera/camera.h \
    Command/addconecommand.h \
    Command/addcubecommand.h \
    Command/addlightcommand.h \
    Command/addspherecommand.h \
    Command/basecommand.h \
    Command/cleancommand.h \
    Command/deletelightcommand.h \
    Command/rendercommand.h \
    Drawer/basedrawer.h \
    Drawer/qtdrawer.h \
    Geometry/vector3d.h \
    Proxy/proxy.h \
    Manager/basemanager.h \
    Manager/drawmanager.h \
    Manager/scenemanager.h \
    Mediator/mediator.h \
    Object/Light/light.h \
    Object/Material/material.h \
    Object/baseobject.h \
    Object/cone.h \
    Object/cube.h \
    Object/sphere.h \
    Scene/scene.h \
    facade/facade.h \
    lightdialog.h \
        mainwindow.h \
    renderarea.h

FORMS += \
        lightdialog.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
