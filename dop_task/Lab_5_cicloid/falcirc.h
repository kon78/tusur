#pragma once
#ifndef FALCIRC_H
#define FALCIRC_H
#include <QGraphicsEllipseItem>
#include <QPointF>
#include <math.h>//sin cos
#include <windows.h>//для клавиш L-counter clock rotate
#include "mainwindow.h"

class FalCirc: public QGraphicsEllipseItem{
  public:
    FalCirc(QGraphicsScene* parent);
    void advance(int phase);
    void clockwise();
    QGraphicsScene* main_widg{nullptr};
    QPointF constP;
    void setCallbackFunc(void (*func)(QPointF point));
  private:
    void (*callbackFunc)(QPointF){nullptr};//для адреса функции getPosition
    double t;
    double x0, y0, x1, y1;
    double R;
    double m;
    double h;
    bool rotate;
};

#endif // FALCIRC_H
