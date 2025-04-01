//TODO: snake_case названия переменных
//TODO: сочетания и перестановки - https://qna.habr.com/q/571320
//TODO: проверка деление на 0 в задачах 1.
/*
* Лабораторная работа No3
* Исследование функций С++ в IDE (интегрированной среде разработки) Qt Creator
*
* Developer: Половян КА 318OOP/C++
* OS: Windows 10
* locale (кодировка): UTF-8
*/

#include <iostream>

#define Unit 5

#if Unit == 1
#include "task1.h"//заголовочный файл для задачи 1
#endif

#if Unit == 2
#include "task2.h"//заголовочный файл для задачи 2
#endif

#if Unit == 4
#include "task4.h"//заголовочный файл для задачи 4
#endif

#if Unit == 5
#include "task5.h"//заголовочный файл для задачи 5
#endif
using namespace std;
int main(int argc, char *argv[])
{
#if Unit == 1
//  double probability_cards; //ответ
cout << "Задание 1.а" << endl;
// Вызов функции задания 1 из отдельного файла (*.h ) или модуля (*.срр + *.h)
if(max_cards != 0){
  cout << "Вероятность вынуть из колоды (" << max_cards << " карты) туза (без масти) будет равна "
       << (int)GameCards() << "%\n";
}else{
  cout << "Error! Деление на 0!\n";
  exit(progr_err);
}

cout << "Задание 1.б" << endl;
cout << "Вероятность выпадения " << bones_wine << " очков " << " будет равна "
     << (int)CuteBones() << "%\n";

cout << "Задание 1.в" << endl;
cout << "Вероятность составить слово МАМА из четырех букв М А М А будет равна "
     << (int)PermutationWords() << "%\n";
#elif Unit == 2
std::cout << "Задание 2" << std::endl;
// Вызов функции задания 2 из отдельного файла (*.h ) или модуля (*.срр + *.h)

//Если я правильно понял, в данном случае функция void PrintChar(...) можно обьявить либо в определении \
функции void PrintChar(int a = 'a',char b = 'b',char c = 'c', char d = 'd') в файле main.cpp \
либо объявить в файле task2.h\

//вариант без аргументов, все аргументы объявлены в заголовочном файле
  PrintChar();//объявления в заголовочном файле, на экране будет a=97 b=b c=c d=d

//вариант с аргументами
  PrintChar(0,0,0,0);//на экране будет a=0 b= c= d=

  PrintChar(0);//на экране будет a=0 b=b c=c d=d

  PrintChar(10,'f');//на экране будет a=10 b=f c=c d=d

  PrintChar((int)nullptr);//на экране будет a=0 b=b c=c d=d :)

#elif Unit == 3
std::cout << "Задание 3" << std::endl;
// Вызов функции задания 3 из отдельного файла (*.h ) или модуля (*.срр + *.h)

#elif Unit == 4
  for (int i = 0; i < 10; ++i){
//    getAnimalName(i);//error invalid conversation int to Animal
    getAnimalName((Animal)i);//преобразование
  }
#elif Unit == 5
  int numb_1 = -9, numb_2 = -3;
  cout << "Из двух чисел " << numb_1 << " " << numb_2 << " большим будет " <<MyMax(numb_1,numb_2) << endl;
  numb_1 = static_cast<unsigned short>(6);
  numb_2 = static_cast<unsigned short>(0);
  cout << "Из двух чисел " << numb_1 << " " << numb_2 << " большим будет " <<MyMax(numb_1,numb_2) << endl;

  for(;;){//бесконечный цикл
    cout << "Введите числа (целые/со знаком через пробел) :";
    cin >> numb_1 >> numb_2;
    if(cin.fail()){
      cout << "Ошибка! Повторите ввод\n";
      cin.clear();//удаляем лишнее
      cin.ignore(32767,'\n');
    }else{//ищем максимум
      cout << "Из двух чисел " << numb_1 << " " << numb_2 << " большим будет " <<MyMax(numb_1,numb_2) << endl;
      break;
    }
  }

#else
// Вызов функции задания 4 из отдельного файла (*.h ) или модуля (*.срр + *.h)
//...
#endif
  return 0;
  }
