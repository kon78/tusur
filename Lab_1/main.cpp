/*
* Лабораторная работа No1
* Исследование комментариев С++:
*
* Developer: Половян КА 318OOP/C++
* OS: Windows 10
* locale (кодировка): UTF-8
*/

/*
 * заголовочный файл main.cpp
 * в нем содержится основная функция - точка входа main(...)
*/
#if 1 //Задание 1


#include<iostream> //препроцессор директива подключается модуль/библиотека
#define qtComment false //выключаем код Qt
#define task_1_main_comment false //для комментариев директивой

#ifndef qtComment
#include <QCoreApplication> // это фрагмент кода не будет компилироваться
#endif

//точка входа int main(...) \
int argc     - число аргументов из командной строки \
char *argv[] - массив аргументов, слова, цифры, опции и т.д.

int main(int argc, char *argv[])
{//блок стейтменов начало

/*
 * навсякий случай комментируем текст // и \ но можно и убрать
*/
#ifndef task_1_main_comment
//Номер группы: group_cpp_318//ООП_С++, факультет: УДО ТУСУР \
Разработчик: Половян Константин Анатольевич \
Номер лабораторной работы: 1
#endif

  #if 0
/* основной блок приложения qt, в него можно передать аргументы командной строки
 * сейчас этот блок кода не будет компилироваться
*/
      QCoreApplication a(argc, argv);

      return a.exec();


  #endif

//оператор return \
  успешный выход 0-success \
                 1-error
return 0;
}//блок стейтменов конец

//режимы сборки \
режим debug - main.exe-63кБ main.o-17кБ; \
режим release main.exe-16кБ main.o-2кБ

#endif

#if 0 //Задание 2
//директивы препроцессора
//#include <QCoreApplication>
#include <iostream>

//директива препроцессору
#define mainProgramm true

//основной блок программы \
аргументы передаваемые в тело функции main из командной строки

int main(int argc, char *argv[])
{
// исключаем этот блок
#ifndef mainProgramm
  QCoreApplication a(argc, argv);
  return a.exec();
#endif

#ifdef mainProgramm
  char* facultet="УДО";// си-строка
  char* group="Группа 318 OOP_C++";
  char* stud="Половян К.А.";

  //здесь будет основной код программы
  //установки флага вывода cout \t символ табуляции endl-окончание потока

  char newline = '\n';// символьный тип данных, перевод строки
  std::cout << "*****" << "\t\t\t" << "ТУСУР" << "\t\t\t" << "*****" << std::endl;

  std::cout << newline;// еще вариант перевода строки
  std::cout << std::endl;
  std::cout.width(58);// выставляем длину
  std::cout.setf(std::ios::right);// выравниваем по правому краю
  std::cout << "Факультет: " << facultet << std::endl;
  std::cout.width(52);
  std::cout << "Группа: " << group << std::endl;
  std::cout.width(54);
  std::cout << "Студент: " << stud << std::endl;
#endif

  return 0;
}

#endif

#if 0 //Задание 3
//директивы препроцессору
#include <iostream>//поточный модуль
#include <stdio.h>
#include <math.h>//для математики

//используем пространство имен std, можно не писать запись std::cout
using namespace std;

// функция для проверки вводимых данных \
  можно разместить перед main()

//[тип float] [имя функции] (параметры передаваемые в функцию) \
  сейчас их нет, void
float EnterData(void){
  float AnyValue;
/*
   * проверка ввода считается достаточно ответственой и требовательной частью программы
   * лучше всего подошли бы regex-регулярные выражения, поиск запрещенных символов
   * /,a-z A-Z/
*/
  while (true) // цикл продолжается до тех пор, пока пользователь не введёт корректное значение
    {
      cout << "Введите параметр: ";

      cin >> AnyValue;//поток ввода читает число, то есть 2.2sdw или 22 sdsx ds --> в переменную 22
                      //ws22 --> cin.fail()-true ошибка, повторяем цикл

      if (cin.fail()) // если предыдущее извлечение оказалось неудачным
                      //fail()-true, если ошибка

      {//в этом блоке обработка ошибки
        cin.clear(); // то возвращаем cin в 'обычный' режим работы, очищаем
        cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера 32767-все и \n
        cout << "\n!!!!!<<Ошибка ввода>>!!!!!" << endl;//сообщение об ошибке

      }else
        if(cin.good())
        {
          cin.ignore(32767,'\n');
          break;}
  }
  cout << "Было введено значение: " << AnyValue << "\n";

  return AnyValue;//возвращаемое значение
}

//#include <QCoreApplication>

////директивы препроцессору
//#include <iostream>//поточный модуль
//#include <stdio.h>
//#include <math.h>//для математики

////используем пространство имен std, можно не писать запись std::cout
//using namespace std;

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
  float SpeedMove, TimeMove, Distance;//task 1 вычисление скорости прямолиненого движения
  Distance=0;TimeMove=0;SpeedMove=0;//обнуляемся

  cout << "Введите расстояние (м)\n";
  Distance = EnterData();//первая переменная

  cout << "Введите время (с)\n";
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
  float SpeedPoint1, SpeedPoint2, TimePoint1, TimePoint2, AccelerationAll;//task 2 вторая задача
  //обнуляемся

  SpeedPoint1=0;SpeedPoint2=0;TimePoint1=0;TimePoint2=0;
  cout << "Введите начальную скорость (м/с)\n";
  SpeedPoint1 = EnterData();//первая переменная
  cout << "Введите конечную скорость (м/с)\n";
  SpeedPoint2 = EnterData();
  cout << "Введите время начальное (с)\n";
  TimePoint1 = EnterData();
  cout << "Введите время конечное (с)\n";
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

    cout.setf(ios::fixed);cout.precision(3);//точность до 3 знаков после запятой
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

  float CircleSquare, CircleLong, CircleRadius;
  float PiConst = M_PI;// постоянная Pi

  //обнуляемся
  CircleSquare=0; CircleLong=0; CircleRadius=0;
  cout << "Введите радиус (м)\n";
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

#endif

//тестовые задания

/*
 * a)
1 #if 0 Подключаем библиотеку для ввода/вывода #endif   <--#if 0 должна быть одна строка
2 #include <iostream>
3 Int main() {/* Открытая скобка - окончание блока    <--I заглавная буква
4 стейтмена, кода относящийся к функции main */
//5  Тело \
6 функции \
7 \
8 } /* /* Закрытая скобка - окончание блока стейтмена, кода относящийся к функции main */ */ <--/**/не должно \
быть вложенности

//исправленный вариант

#if 0
#if 0 Подключаем библиотеку для ввода/вывода
#endif
#include <iostream>
int main()
{/* Открытая скобка - окончание блока
    стейтмена, кода относящийся к функции main */
  //тело
  return 0;
} /*Закрытая скобка - окончание блока стейтмена,
    кода относящийся к функции main*/
#endif

/*
b)
1 #if 0 Подключаем библиотеку для ввода/вывода
2 #endif
3 #include <iostream    <--парная скобка >
4 int MAIN() {/* Открытая скобка - окончание блока   <--название заглавными буквами MAIN
5 стейтмена, кода относящийся к функции main */
//6 // Тело функции
//7 //} /* /* Закрытая скобка - окончание блока стейтмена, кода относящийся к функции <--/**/многострочный \
комментарий

//исправленный вариант

#if 0
#if 0
Подключаем библиотеку для ввода/вывода
#endif
#include <iostream>
int main()
{/* Открытая скобка - окончание блока
    стейтмена, кода относящийся к функции main */
  //тело функции
  return 0;
}/*Закрытая скобка - окончание блока стейтмена, кода относящийся к функции*/
#endif

/*
c)
1#if 0
2 Подключаем библиотеку для ввода/вывода
3 #endif
4 #include <iostream    <-->нет парной скобки
5 int майн() /* Открытая скобка - окончание блока   <--майн русские символы
6
7 стейтмена, кода относящийся к функции main */
//8 // Тело функции
//9 } /* */ Закрытая скобка - окончание блока стейтмена, кода относящийся к функции <--/*комментарии*/

//исправленный вариант
#if 0
#if 0
Подключаем библиотеку для ввода/вывода (здесь как комментарий)
#endif
#include <iostream>
int main()
{/* Открытая скобка - окончание блока

    стейтмена, кода относящийся к функции main */
  //тело функции
  return 0;
}/*Закрытая скобка - окончание блока стейтмена, кода относящийся к функции*/
#endif

/* d)
2 * Лабораторная работа No1
3 * Исследование комментариев С++:
4 *
5 * Developer:
6 * /   <--пробел между символами
7
8 #if 0
9 Подключаем библиотеку для ввода/вывода
10 #endif
11 #include <iostream   <-->нет парной скобки
12 int майн() { /* Открытая скобка - окончание блока    <--майн русские символы
13 //
14 стейтмена, кода относящийся к функции main */
//15 // Тело функции
//16 } //Закрытая скобка - окончание блока стейтмена, кода относящийся к функции

//исправленный вариант
#if 0
/* Лабораторная работа No1
 * Исследование комментариев С++:
 *
 * Developer:
 */

 #if 0
 Подключаем библиотеку для ввода/вывода
 #endif
 #include <iostream>
 int main()
 { /* Открытая скобка - окончание блока
              //
              стейтмена, кода относящийся к функции main */
// Тело функции
   return 0;
 } //Закрытая скобка - окончание блока стейтмена, кода относящийся к функции
#endif

 /*
 f)
 1 / *    <--/ *пробел между символами
 2 * Лабораторная работа No1
 3 * Исследование комментариев С++:
 4 *
 5 * Developer:
 6 * /    <--* /пробел между символами
 7
 8 #if 0
 9 Подключаем библиотеку для ввода/вывода
 10 #endif
 11 #   <-- # перенос, допускается в одну строку
 12 include <iostream>
 13 int main() } /* *Открытая скобка - окончание блока  <-- {нет парной скобки
 14 //
 15 стейтмена, кода относящийся к функции main */
 //16 //// Тело функции

 //исправленный вариант
#if 0
/*
Лабораторная работа No1
Исследование комментариев С++:

Developer:
*/
#if 0
Подключаем библиотеку для ввода/вывода
#endif
#include <iostream>
int main()
{/* *Открытая скобка - окончание блока
//
    стейтмена, кода относящийся к функции main */
  //// Тело функции
  return 0;
}
#endif
