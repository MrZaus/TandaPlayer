# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

TARGET = TandaPlayer

QT = core gui widgets
CONFIG += c++23
HEADERS = \
   $$PWD/common.h \
   $$PWD/controlswidget.h \
   $$PWD/displaywidget.h \
   $$PWD/mainwindow.h \
   $$PWD/mimefilterproxymodel.h \
   $$PWD/tandatreeitem.h \
   $$PWD/tandatreemodel.h \
   $$PWD/wavewidget.h

SOURCES = \
   $$PWD/controlswidget.cpp \
   $$PWD/displaywidget.cpp \
   $$PWD/main.cpp \
   $$PWD/mainwindow.cpp \
   $$PWD/mimefilterproxymodel.cpp \
   $$PWD/tandatreeitem.cpp \
   $$PWD/tandatreemodel.cpp \
   $$PWD/wavewidget.cpp

RESOURCES = \
   $$PWD/resources.qrc

INCLUDEPATH = \
    $$PWD/.

#DEFINES = 

