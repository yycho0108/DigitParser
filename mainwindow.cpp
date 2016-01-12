#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    net.load("net.txt");
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

    net.feedForward(input);
    auto res = net.getResults();

    int maxIndex=0;
    double maxVal=0;

    for(int i=0;i<10;++i){
        if(res[i]>maxVal){
            maxIndex=i;
            maxVal=res[i];
        }
        auto t = QString::number(i) + " : ";
        auto t_val = QString::number(res[i]*100,'f',2);
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
    std::vector<double> targetVal(10);
    int val = ui->resEdit->text().toInt();
    targetVal[val] = 1.0;
    net.backProp(targetVal);
}

void MainWindow::save(){
    qDebug() << "SAVE";
    net.save("net.txt");
}
