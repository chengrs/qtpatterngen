#-------------------------------------------------
#
# Project created by QtCreator 2014-11-19T11:00:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = patterngen
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
        CanvasArea.cpp \
        ConfigDialog.cpp \
        Pattern.cpp \
    PatternBox.cpp \
    PatternColor.cpp \
    PatternHBar.cpp \
    PatternVBar.cpp \
    PatternChecker.cpp \
    PatternHStripe.cpp

HEADERS += MainWindow.h \
        CanvasArea.h \
        ConfigDialog.h \
        Pattern.h \
        PatternColor.h \
        PatternHBar.h \
        PatternVBar.h \
    Colors.h \
    PatternBox.h \
    PatternChecker.h \
    PatternHStripe.h
