#-------------------------------------------------
#
# Project created by QtCreator 2013-03-08T16:40:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MimicEditor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    item.cpp

HEADERS  += mainwindow.h \
    scene.h \
    item.h

FORMS    += mainwindow.ui
