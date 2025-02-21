//#include <QCoreApplication>

//директивы препроцессору
#include <iostream>//поточный модуль
#include <stdio.h>
#include <math.h>//для математики
#include "task1.h"//"" для заголовочых файлов пользователя
#include "task2.h"
#include "task3.h"
#include "enterdata.h"

//используем пространство имен std, можно не писать запись std::cout
using namespace std;

//определения/назначения
#define MainProgram true
//#define TaskFirst true//задача 1
//#define TaskTwo true//задача 2
//#define TaskTree true//задача 3

//основной блок/функция программы без аргументов
int main(int argc, char *argv[])
{//блок стейтменов начало
#ifndef MainProgram
  QCoreApplication a(argc, argv);

  return a.exec();
#endif

#ifndef TaskFirst
  cout << "Задача 1.\nВычисление скорости прямолиненйного движения.\n";
  cout << "(по расстоянию и времени.)\n";
  cout << endl;

/*
 * используемые переменные Distance TimeMove SpeedMove
 * Speed=Distance/Time
 * тип данных float, проверка ввода
*/
  Distance=0;TimeMove=0;SpeedMove=0;//обнуляемся

  cout << "Введите расстояние (м) :";
  Distance = EnterData();//первая переменная

  cout << "Введите время (с) :";
  TimeMove = EnterData();//вторая переменная

  //если вторая переменная не нуль, делаем расчет
  if(TimeMove != 0){
    SpeedMove = Distance / TimeMove;
  }else{
    cout << "На нуль не делим!\n";
    exit(-1);//выход из программы с ошибкой
  }

//и выводим результат
  cout << "Задача 1.\n";
  cout << "Были введены следующие данные, дистанция: " << Distance << " (м) время: " << TimeMove << " (с)\n";
  cout.setf(ios::fixed);cout.precision(3);//точность до 3 знаков после запятой
  cout << "Результат: " << SpeedMove << " м/с";
  cout << endl;
#endif
/**************************************************************************************************************/

#ifndef TaskTwo
  cout << "\nЗадача 2.\nВычислить ускорение (по начальной скорости, конечной скорости и времени).\n";
  cout << endl;
  /*
   * используемые переменные SpeedPoint1, SpeedPoint2, TimePoint1, TimePoint2, AccelerationAll
   * AccelerationAll = (SpeedPoint2-SpeedPoint1)/(TimePoint2-TimePoint1)
   * тип данных float, проверка ввода
  */

  //обнуляемся
  SpeedPoint1=0;SpeedPoint2=0;TimePoint1=0;TimePoint2=0;
  SpeedPoint1 = EnterData();//первая переменная
  SpeedPoint2 = EnterData();
  TimePoint1 = EnterData();
  TimePoint2 = EnterData();//четвертая переменная

  //если знаменатель не нуль, делаем расчет
  if(TimePoint2 != TimePoint1){
    AccelerationAll = (SpeedPoint2-SpeedPoint1)/(TimePoint2-TimePoint1);
  }else{
    cout << "На нуль не делим!\n";
    exit(-1);//выход из программы с ошибкой
  }

  //и выводим результат
    cout << "Задача 2.\n";
    cout << "Были введены следующие данные\nначальная скорость " << SpeedPoint1 << " (м/с)\n"
         << "конечная скорость " << SpeedPoint2 << " (м/с)\n"
         << "начальное время " << TimePoint1 << " (c)\n"
         << "конечное время " << TimePoint2 << " (c)\n";

    cout << "Результат: " << AccelerationAll << " ускорение м2/с ";
    if(AccelerationAll < 0){
      cout << "Торможение!\n";
    }else{
      cout << "Разгон!\n";
    }
    cout << endl;
#endif
/**************************************************************************************************************/
#ifndef TaskTree
  cout << "\nЗадача 3.\nВычислить радиус круга (по длине его окружности)\n";
  cout << endl;
  /* используемые переменные CircleSquare CircleLong CircleRadius
   * <<R=L/(2*Pi)>>
   * тип данных float, проверка ввода
  */

  //обнуляемся
  CircleSquare=0; CircleLong=0; CircleRadius=0;
  CircleLong = EnterData();//длина круга
  CircleRadius = CircleLong / (2 * PiConst);

  //и выводим результат
    cout << "Задача 3.\n";
    cout << "Были введены следующие данные\nдлина окружности " << CircleLong << " (м)\n";
  cout.setf(ios::fixed);cout.precision(6);//точность до 6 знаков после запятой
  cout << "Результат: " << CircleRadius << "(радиус) м " << " площадь круга "
       << (PiConst * (CircleRadius*CircleRadius)) << " (м2)\n";
#endif

  return 0;
}//блок стейтменов окончание
