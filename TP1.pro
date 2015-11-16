QT += core
QT -= gui

TARGET = TP1
CONFIG += console
CONFIG += c++14
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Folder.cpp \
    File.cpp \
    Element.cpp \
    Partition.cpp

HEADERS += \
    Folder.h \
    File.h \
    Element.h \
    Partition.h

