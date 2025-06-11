//TODO: snake_case названия переменных
//TODO: сочетания и перестановки - https://qna.habr.com/q/571320
//TODO: проверка деление на 0 в задачах 1.
//TODO: убрать из первого задания void My_Swap(const std::string& word);
/*
* Лабораторная работа No3
* Исследование функций С++ в IDE (интегрированной среде разработки) Qt Creator
*
* Developer: Половян КА 318OOP/C++
* OS: Windows 10
* locale (кодировка): UTF-8
*/

#include <iostream>

#define Unit 3

#if Unit == 1
#include "task1.h"//заголовочный файл для задачи 1
#endif

#if Unit == 2
#include "task2.h"//заголовочный файл для задачи 2
#endif

#if Unit == 3
#include "task3.h"
static int iValue(10);//глобальная переменная
#endif

#if Unit == 4
#include "task4.h"//заголовочный файл для задачи 4
#endif

#if Unit == 5
#include "task5.h"//заголовочный файл для задачи 5
#endif

#if Unit == 6
#include "task6.h"//заголовочный файл для задачи 6
#endif

#if Unit == 7
#include "task7.h"//заголовочный файл для задачи 7
#endif

using namespace std;
int main()
{
#if Unit == 1
    Propability();//1.а 1.б 1.в

#elif Unit == 2
std::cout << "Задание 2" << std::endl;
// Вызов функции задания 2 из отдельного файла (*.h ) или модуля (*.срр + *.h)

/*Если я правильно понял, в данном случае функция void PrintChar(...) можно обьявить либо в определении
функции void PrintChar(int a = 'a',char b = 'b',char c = 'c', char d = 'd') в файле main.cpp
либо объявить в файле task2.h */

//вариант без аргументов, все аргументы объявлены в заголовочном файле
  PrintChar();//объявления в заголовочном файле, на экране будет a=97 b=b c=c d=d, то есть значения по умолчанию

//вариант с аргументами
  PrintChar(0,0,0,0);//на экране будет a=0 b= c= d=

  PrintChar(10,'a','b','c');//на экране будет a=10 b=a c=b d=c

  PrintChar(11,'d','e');//на экране будет a=10 b=f c=c d=d

  PrintChar(12,'f');//на экране будет a=10 b=f c=c d=d

  PrintChar(13);//на экране будет a=13 b=b c=c d=d

  PrintChar(0);//на экране будет a=0 b=b c=c d=d

//  PrintChar(/*(int)nullptr*/0);//на экране будет a=0 b=b c=c d=d :) error


#elif Unit == 3
std::cout << "Задание 3" << std::endl;

cout << "global variable ";
cout << "iValue =" << iValue << '\n';

iValue = Initialization();//возращаемое значение из функции
cout << "local variable ";
cout << "iValue =" << iValue << '\n';

#elif Unit == 4
  for (int i = 0; i < 10; ++i){
//    getAnimalName(i);//error invalid conversation int to Animal
    getAnimalName((Animal)i);//преобразование
  }
#elif Unit == 5
  int numb_1 = -9, numb_2 = -3;
  cout << "Из двух чисел " << numb_1 << " " << numb_2 << " большим будет " << MyMax(numb_1,numb_2) << endl;
  numb_1 = static_cast<unsigned short>(6);
  numb_2 = static_cast<unsigned short>(0);
  cout << "Из двух чисел " << numb_1 << " " << numb_2 << " большим будет " << MyMax(numb_1,numb_2) << endl;

  for(;;){//бесконечный цикл
    cout << "Введите числа (целые/со знаком через пробел) :";
    cin >> numb_1 >> numb_2;
    if(cin.fail()){
      cout << "Ошибка! Повторите ввод\n";
      cin.clear();//удаляем лишнее
      cin.ignore(32767,'\n');
    }else{//ищем максимум
      cout << "Из двух чисел " << numb_1 << " " << numb_2 << " большим будет " << MyMax(numb_1,numb_2) << endl;
      break;
    }
  }

  numb_1 = static_cast<int>(-19);//сравниваемые числа
  numb_2 = static_cast<int>(-5);
  enum{limit=2147483000};
  int limit_min = INT_MIN + limit;
  int limit_max = INT_MAX - limit;
cout << "Из двух чисел " << numb_1 << " " << numb_2 << " большим будет "
     << MyMax(numb_1,numb_2,limit_max,limit_min) << endl;
//MyMax(int first_numb, int second_numb, int limit_max, int limit_min)

#elif Unit == 6
Task6();

#elif Unit == 7
  MapBuild();
  Elevator();
#else

    cout << "Нет такого задания!\n";

#endif
  return 0;
  }
