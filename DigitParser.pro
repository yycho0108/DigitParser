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
    ../MachineLearning/MNIST/Layer.cpp \
    ../MachineLearning/MNIST/Net.cpp \
    ../MachineLearning/MNIST/Neuron.cpp \
    ../MachineLearning/MNIST/Utility.cpp

HEADERS  += mainwindow.h \
    inputwidget.h \
    ../MachineLearning/MNIST/Layer.h \
    ../MachineLearning/MNIST/Net.h \
    ../MachineLearning/MNIST/Neuron.h \
    ../MachineLearning/MNIST/Utility.h

FORMS    += mainwindow.ui
