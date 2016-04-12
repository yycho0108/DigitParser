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
    ../Learn/OpenCV/05_ConvNet/ActivationLayer.cpp \
    ../Learn/OpenCV/05_ConvNet/ConvNet.cpp \
    ../Learn/OpenCV/05_ConvNet/ConvolutionLayer.cpp \
    ../Learn/OpenCV/05_ConvNet/DenseLayer.cpp \
    ../Learn/OpenCV/05_ConvNet/FlattenLayer.cpp \
    ../Learn/OpenCV/05_ConvNet/Parser.cpp \
    ../Learn/OpenCV/05_ConvNet/PoolLayer.cpp \
    ../Learn/OpenCV/05_ConvNet/SoftMaxLayer.cpp \
    ../Learn/OpenCV/05_ConvNet/Utility.cpp \

HEADERS  += mainwindow.h \
    inputwidget.h \
    ../Learn/OpenCV/05_ConvNet/ActivationLayer.h \
    ../Learn/OpenCV/05_ConvNet/ConvNet.h \
    ../Learn/OpenCV/05_ConvNet/ConvolutionLayer.h \
    ../Learn/OpenCV/05_ConvNet/DenseLayer.h \
    ../Learn/OpenCV/05_ConvNet/FlattenLayer.h \
    ../Learn/OpenCV/05_ConvNet/Layer.h \
    ../Learn/OpenCV/05_ConvNet/Parser.h \
    ../Learn/OpenCV/05_ConvNet/PoolLayer.h \
    ../Learn/OpenCV/05_ConvNet/SoftMaxLayer.h \
    ../Learn/OpenCV/05_ConvNet/Utility.h

FORMS    += mainwindow.ui
LIBS += -L/usr/local/lib -lopencv_imgproc -lopencv_core -lopencv_highgui
