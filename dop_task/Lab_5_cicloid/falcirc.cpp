#include "falcirc.h"

FalCirc::FalCirc(QGraphicsScene* parent)
{
  if(parent != nullptr)//минимальная провекра на nullptr
    main_widg = parent;

   setRect(400, 300, 20, 20);//размеры, объявляем и забыли
   t = 0; R = 100; m = 0.2;  h = 10; rotate = true;//начальные значения
}

void FalCirc::clockwise(){//выбор направления вращения
  if(GetAsyncKeyState('L')){
    rotate = false;
  }
  if(GetAsyncKeyState('R')){
    rotate = true;
  }
}

void FalCirc::advance(int phase)
{
    if(phase){
     clockwise();//опрос клавиш
     t+=0.1;
#if 1//выбор направления вращения шарика
     if(!rotate){
     x1=((R*(m+1))*(cos(m*t)))-(h*(cos((m+1)*t)));//против часовой
     y1=((R*(m+1))*(sin(m*t)))-(h*(sin((m+1)*t)));
     }else{
       x1=((R*(m+1))*(sin(m*t)))-(h*(sin((m+1)*t)));//по часовой
       y1=((R*(m+1))*(cos(m*t)))-(h*(cos((m+1)*t)));
     }
#endif
       x0=x1;
       y0=y1;
     constP.setX(qreal(x1));
     constP.setY(qreal(y1));
     callbackFunc(this->constP);//callback вызов с параметром точки
    #if 0 //передача координат без callback вызова
    MainWindow::getPosition(constP);//передача координат статическим полям lineEdit_1 lineEdit_2
    // callbackFunc();
    #endif

     main_widg->addLine(x0+400,y0+300,x1+400,y1+300);
     this->setPos(x1,y1);
     }
}

#if 1
void FalCirc::setCallbackFunc(void (*func)(QPointF point))
{
// Устанавливаем указатель на callback функцию
  if(func != nullptr)
    callbackFunc = func;
}
#endif
