#include "inputwidget.h"
#include <QMouseEvent>
#include <QPainter>
#include <QDebug>

InputWidget::InputWidget(QWidget* parent):
    QFrame(parent),image(28,28,QImage::Format_RGB888)
{
    image.fill(QColor::fromRgb(0,0,0));
    drawing = false;
    erasing = false;

    myBrush = QBrush(QColor::fromRgb(255,255,255));
    myPen = QPen(myBrush,15.0);

    myEBrush = QBrush(QColor::fromRgb(0,0,0));
    myEraser = QPen(myEBrush,15.0);
}

void InputWidget::mousePressEvent(QMouseEvent *e){
    if(e->button() == Qt::LeftButton){
        last = e->pos();
        drawing = true;
    }
    if(e->button() == Qt::RightButton){
        last = e->pos();
        erasing = true;
    }
    e->accept();
}

void InputWidget::mouseMoveEvent(QMouseEvent *e){
    QPoint now = e->pos();
    if(drawing){
       QPainter p(&image);
       p.setPen(myPen);
       p.drawLine(last,now);
       update();
       //update(QRect(last,now).normalized().adjusted(-3,-3,3,3));
    }else if(erasing){
        QPainter p(&image);
        p.setPen(myEraser);
        p.drawLine(last,now);
        update();
    }
    last = now;

    e->accept();
}
void InputWidget::mouseReleaseEvent(QMouseEvent *e){
    drawing = false;
    erasing = false;
    e->accept();
}

void InputWidget::paintEvent(QPaintEvent *e){
    QPainter p(this);
    QRect r = e->rect();
    p.drawImage(r,image);
    e->accept();
}

void InputWidget::resizeEvent(QResizeEvent *e){
    image = image.scaled(e->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    myPen.setWidth(image.width()/14);
    myEraser.setWidth(image.width()/14);
}


void InputWidget::clear(){
    image.fill(QColor::fromRgb(0,0,0));
    update();
}

std::vector<double> InputWidget::evaluate(){
    auto q = qDebug();
    auto img = image.scaled(28,28,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    std::vector<double> dat;
    dat.reserve(28*28);
    for(int i=0;i<28;++i){
        auto l = (QRgb*)img.scanLine(i);
        for(int j=0;j<28;++j){
            auto val = qGray(l[j])/256.0;
            q << ((val > 0.5)?1:0);
            //auto val = 1.0 - qGray(l[j])/256.0;
            dat.push_back(val); //invert
           //q << (val > 0.8? 2: dat.back()>0.4?1:0);
        }
      q << '\n';
    }
    return dat;
}
