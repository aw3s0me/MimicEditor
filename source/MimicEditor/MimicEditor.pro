#-------------------------------------------------
#
# Project created by QtCreator 2013-03-08T16:40:54
#
#-------------------------------------------------

QT       += core gui network widgets
QT       += svg
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MimicEditor
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    schemaitem.cpp \
    schemascene.cpp \
    schematextitem.cpp \
    schemaarrowitem.cpp \
    schemaview.cpp \
    commands.cpp \
    schemapolyarrowitem.cpp

HEADERS  += mainwindow.h \
    schemascene.h \
    schemaitem.h \
    schematextitem.h \
    schemaarrowitem.h \
    schemaview.h \
    commands.h \
    schemapolyarrowitem.h

FORMS    += mainwindow.ui

RESOURCES += \
    Resources.qrc
