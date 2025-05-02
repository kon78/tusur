#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QString>
#include <string>
#include "mycalc.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QLineEdit *lineEdit = new QLineEdit;
    myCalc *mCalc = new myCalc;

public slots:
    void add0();
    void add1();
    void add2();
    void add3();
    void add4();
    void add5();
    void add6();
    void add7();
    void add8();
    void add9();
    void add_clear();
    void cPlus();
    void cMinus();
    void cEqual();
    void cMult();
    void cDiv();
    void add_dot();
    void cSign();

private:
    Ui::MainWindow *ui;
    QString qOperand;
    std::string str;
    bool plus;
    bool minus;
    bool mult;
    bool divis;
};
#endif // MAINWINDOW_H
