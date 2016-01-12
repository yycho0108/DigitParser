#ifndef INPUTWIDGET_H
#define INPUTWIDGET_H

#include <QWidget>
#include <QFrame>
#include <QImage>
#include <QPen>
#include <QBrush>
#include <vector>

class InputWidget : public QFrame
{
    using BYTE = unsigned char;
    using IMGTYPE = std::vector<std::vector<unsigned char>>;
private:
    bool drawing;
    bool erasing;
    QPoint last;
    QImage image;

    QBrush myBrush;
    QPen myPen;
    QBrush myEBrush;
    QPen myEraser;

public:
    InputWidget(QWidget* parent);

signals:

public slots:
    void clear();
    std::vector<double> evaluate();
    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);

};

#endif // INPUTWIDGET_H
