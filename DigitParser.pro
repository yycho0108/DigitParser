#-------------------------------------------------
#
# Project created by QtCreator 2016-01-12T04:26:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DigitParser
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    inputwidget.cpp \
    ../MachineLearning/Layer.cpp \
    ../MachineLearning/Net.cpp \
    ../MachineLearning/Neuron.cpp \
    ../MachineLearning/Utility.cpp

HEADERS  += mainwindow.h \
    inputwidget.h \
    ../MachineLearning/Layer.h \
    ../MachineLearning/Net.h \
    ../MachineLearning/Neuron.h \
    ../MachineLearning/Utility.h

FORMS    += mainwindow.ui
