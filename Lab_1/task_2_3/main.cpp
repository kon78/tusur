//#include <QCoreApplication>

//директивы препроцессору
#include <iostream>//поточный модуль
#include <stdio.h>
#include <math.h>//для математики

//используем пространство имен std, можно не писать запись std::count
using namespace std;

//определения/назначения
#define MainProgram true //может быть число 0,1 ...

//основной блок/функция программы без аргументов
int main(int argc, char *argv[])
{//блок стейтменов начало

  float SpeedMove, TimeMove, DistanceMove;//task 1

#ifndef MainProgram
  QCoreApplication a(argc, argv);

  return a.exec();
#endif

#ifdef MainProgram
//value PascalCase
  cout << "Задача 1.\nВычисление скорости прямолиненйного движения.\n";
  cout << "(по расстоянию и времени.)\n";
  cout << endl;
/*
 * используемые переменные SpeedMove TimeMove DistanceMove
 * DistanceMove=SpeedMove*TimeMove
 * тип данных float, проверка ввода на посторонние символы,
*/


  bool CycleInputLogicSpeed = false;
  bool CycleInputLogicTime = false;

  //цикл для ввода данных пользователем
  while(true){

    if(CycleInputLogicSpeed == false){
      while(true){
        cout << "Введите пройденное расстояние (в метрах): ";
        cin >> SpeedMove;

        if(cin.fail()){
          cin.clear();
          cin.ignore(32767,'\n');//не больше 10 символов и удалить разделитеь строк
          //CycleInputLogicSpeed=false;//повторный ввод
          cout << "\n!!!<<<Неправильный ввод данных. Некорректное данное.>>>!!!\n";
        }else{
          CycleInputLogicSpeed=true;//если все хорошо
          break;//если все хорошо идем дальше
        }
         }//while
      }//if


    if(CycleInputLogicTime == false){
      cout << "Введите затраченное время (в секундах): ";
//      cin.clear();//очищаем биты ошибок
      cin >> TimeMove;

    if(cin.good()){
      cin.ignore(32767,'\n');
      CycleInputLogicTime=true;//если все хорошо
    }else{
      CycleInputLogicTime=true;//повторный ввод
      cout << "\n!!!<<<Неправильный ввод данных. Некорректное данное.>>>!!!\n";
    }
    }

    if(CycleInputLogicSpeed & CycleInputLogicTime){
      break;
    }else{
      cin.clear();//очищаем биты ошибок
      cin.ignore(10,'\n');
    }


    //scanf("5%f",&SpeedMove);//%f-float
    //scanf("5%f",&TimeMove);//%f-float
  }
  //пока не будут введены корректные данные

  DistanceMove = SpeedMove * TimeMove;

//если при вводе не было ошибок,
  cout << "Задача 1.\n";
  cout << "Были введены следующие данные, скорость: " << SpeedMove << " (м) время: " << TimeMove << " (с)\n";
  cout << "Результат: " << DistanceMove << " м/с";
  cout << endl;
#endif

}//блок стейтменов окончание
