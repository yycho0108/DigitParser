#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDebug>

std::vector<cv::Mat> output;

void setup(ConvNet& net){
    /* ** CONV LAYER TEST ** */

    net.push_back(new ConvolutionLayer(1,12));
    net.push_back(new ActivationLayer("relu"));
    net.push_back(new PoolLayer(Size(2,2),Size(2,2)));

    net.push_back(new ConvolutionLayer(12,16));
    net.push_back(new ActivationLayer("relu"));
    net.push_back(new PoolLayer(Size(2,2),Size(2,2)));

    net.push_back(new FlattenLayer(16));
    net.push_back(new DenseLayer(1,84));
    net.push_back(new ActivationLayer("sigmoid"));
    net.push_back(new DenseLayer(1,10));
    net.push_back(new ActivationLayer("sigmoid"));
    net.push_back(new SoftMaxLayer());

    net.setup(Size(28,28));
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setup(net);
    net.load("save");
    for(int i=0;i<10;++i){
        auto s = QString::number(i);
        s += " : 0%";
        ui->probList->addItem(s);
    }
    connect(ui->action_Save,SIGNAL(triggered()),this,SLOT(save()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_clearBtn_clicked()
{
    ui->inputWidget->clear();
}

void MainWindow::on_evalBtn_clicked()
{
    auto input = ui->inputWidget->evaluate();

    output = net.FF(input);

    int maxIndex=0;
    double maxVal=0;

    for(int i=0;i<10;++i){
        auto val = output[0].at<float>(i);
        if(val>maxVal){
            maxIndex=i;
            maxVal = val;
        }
        auto t = QString::number(i) + " : ";
        auto t_val = QString::number(val*100,'f',2);
        t += t_val;
        ui->probList->item(i)->setText(t);
    }

    ui->resEdit->setText(QString::number(maxIndex));
}

void MainWindow::resizeEvent(QResizeEvent *){
    auto& l = this->ui->probList;
    QSize s = l->size();
    s.setHeight(s.height()/10);
    l->setGridSize(s);
}

void MainWindow::on_BPBtn_clicked()
{
    std::vector<Mat> targetVal;
    targetVal.push_back(cv::Mat::zeros(10,1,cv::DataType<float>::type));

    int val = ui->resEdit->text().toInt();
    targetVal.front().at<float>(val) = 1.0;
    net.BP(output,targetVal);
}

void MainWindow::save(){
    qDebug() << "SAVE";
    net.save("save");
}
