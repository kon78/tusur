#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),plus(false),minus(false),mult(false),divis(false)
{
    ui->setupUi(this);
    MainWindow::lineEdit = ui->lineEdit;
}

void MainWindow::add0(){
    if(!mCalc->getStat())
    lineEdit->setText(lineEdit->text() + "0");
}

void MainWindow::add1(){
    if(!mCalc->getStat())
    lineEdit->setText(lineEdit->text() + "1");
}

void MainWindow::add2(){
    if(!mCalc->getStat())
    lineEdit->setText(lineEdit->text() + "2");
}

void MainWindow::add3(){
    if(!mCalc->getStat())
    lineEdit->setText(lineEdit->text() + "3");
}

void MainWindow::add4(){
    if(!mCalc->getStat())
    lineEdit->setText(lineEdit->text() + "4");
}

void MainWindow::add5(){
    if(!mCalc->getStat())
    lineEdit->setText(lineEdit->text() + "5");
}

void MainWindow::add6(){
    if(!mCalc->getStat())
    lineEdit->setText(lineEdit->text() + "6");
}

void MainWindow::add7(){
    if(!mCalc->getStat())
    lineEdit->setText(lineEdit->text() + "7");
}

void MainWindow::add8(){
    if(!mCalc->getStat())
    lineEdit->setText(lineEdit->text() + "8");
}

void MainWindow::add9(){
    if(!mCalc->getStat())
    lineEdit->setText(lineEdit->text() + "9");
}

void MainWindow::cSign(){
    if(!mCalc->getStat())
    lineEdit->setText(lineEdit->text() + "-");
}

void MainWindow::add_clear(){
    lineEdit->clear();
    plus = false; minus = false; divis = false; mult = false;
    mCalc->Reset();
}

void MainWindow::cPlus(){
    if(!mCalc->getStat()){
        qOperand = lineEdit->text();
        str = qOperand.toStdString();
        mCalc->moveOpA(str);
        lineEdit->clear();
        plus = true; minus = false; mult = false; divis = false;
    }
}

void MainWindow::cMinus(){
    if(!mCalc->getStat()){
        qOperand = lineEdit->text();
        str = qOperand.toStdString();
        mCalc->moveOpA(str);
        lineEdit->clear();
        plus = false; minus = true; mult = false; divis = false;
    }
}

void MainWindow::cMult(){
    if(!mCalc->getStat()){
        qOperand = lineEdit->text();
        str = qOperand.toStdString();
        mCalc->moveOpA(str);
        lineEdit->clear();
        plus = false; minus = false; mult = true; divis = false;
    }
}

void MainWindow::cDiv(){
    if(!mCalc->getStat()){
        qOperand = lineEdit->text();
        str = qOperand.toStdString();
        mCalc->moveOpA(str);
        lineEdit->clear();
        plus = false; minus = false; mult = false; divis = true;
    }
}

void MainWindow::cEqual(){
    qOperand = lineEdit->text();
    str = qOperand.toStdString();
    mCalc->moveOpB(str);
    lineEdit->clear();
          if(plus){
        mCalc->run('p');
    }else if(minus){
        mCalc->run('m');
    }else if(divis){
        mCalc->run('d');
    }else if(mult){
        mCalc->run('u');
    }
    qOperand = QString::number(mCalc->result()),'f', 4;
    if(!mCalc->getStat())
        lineEdit->setText( qOperand );
    else
        lineEdit->setText( "ERROR!" );
}

void MainWindow::add_dot(){
    lineEdit->setText(lineEdit->text() + ".");
}

MainWindow::~MainWindow()
{
    delete ui;
}
