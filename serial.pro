# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

TEMPLATE = app
TARGET = serial
DESTDIR = ../x64/Debug
QT += core gui widgets webchannel
CONFIG += debug greaterThan(QT_MAJOR_VERSION,4): QT +=widgets printsupport
DEFINES += _UNICODE WIN64 QT_DLL QT_WEBCHANNEL_LIB QT_WIDGETS_LIB
INCLUDEPATH += ./GeneratedFiles \
    . \
    ./GeneratedFiles/$(ConfigurationName)
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/$(ConfigurationName)
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(serial.pri)