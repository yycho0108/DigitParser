#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../Learn/OpenCV/05_ConvNet/ConvNet.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    ConvNet net;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void save();
private slots:
    void on_clearBtn_clicked();
    void on_evalBtn_clicked();
    void on_BPBtn_clicked();

private:
    Ui::MainWindow *ui;

    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *);
};

#endif // MAINWINDOW_H
