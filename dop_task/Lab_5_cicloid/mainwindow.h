#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QWidget>
#include <QLineEdit>
#include "falcirc.h"

class FalCirc;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static void getPosition(QPointF point){//статическая функция для обратного вызова callback
      lineEdit_1->setText(QString::number(point.x()));//вывод в форму
      lineEdit_2->setText(QString::number(point.y()));
    }

private:
    Ui::MainWindow *ui{nullptr};
  QGraphicsScene* scene{nullptr};
  QGraphicsView* graphicsView{nullptr};
  QTimer* anim_timer{nullptr};
  FalCirc* f{nullptr};
  static inline QLineEdit* lineEdit_1{nullptr};
  static inline QLineEdit* lineEdit_2{nullptr};
};

#endif // MAINWINDOW_H
