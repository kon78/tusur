#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "falcirc.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    lineEdit_1 = new QLineEdit();//объявляем объекты, замещаем nullptr
    lineEdit_2 = new QLineEdit();

    // Устанавлвиваем в gridLayout
    ui->gridLayout->addWidget(lineEdit_1,0,1);
    ui->gridLayout->addWidget(lineEdit_2,0,2);

    scene = new QGraphicsScene(0, 0, 800, 600, this);

    ui->graphicsView->setScene(scene);
    scene->addRect(scene->sceneRect());

   f = new FalCirc(scene);//объявляем обьект и свойства
   scene->addItem(f);

   f->setCallbackFunc(getPosition);//устанавливаем адрес функции
   anim_timer = new QTimer(this);
   connect(anim_timer, SIGNAL(timeout()),scene, SLOT(advance()));//timer --> advance Qt signal/slot
   anim_timer->start(1000/60);
}

MainWindow::~MainWindow()
{
    delete ui;
}
