//TODO: snake_case названия переменных

/*
* Лабораторная работа No3
* Исследование функций С++ в IDE (интегрированной среде разработки) Qt Creator
*
* Developer: Половян КА 318OOP/C++
* OS: Windows 10
* locale (кодировка): UTF-8
*/
#define Unit 1

#include <iostream>
#include "task1.h"//заголовочный файл для задачи 1
using namespace std;

//enum{max_cards=52, count_tuz=4, percent_per=100};

int main(int argc, char *argv[])
{
#if Unit == 1

cout << "Задание 1" << endl;
// Вызов функции задания 1 из отдельного файла (*.h ) или модуля (*.срр + *.h)
  probability_cards = GameCards();
  cout << "Вероятность вынуть из колоды (52 карты) туза (без масти) будет равна " << probability_cards << "%\n";
#elif Unit == 2
std::cout << "Задание 2" << std::endl;
// Вызов функции задания 2 из отдельного файла (*.h ) или модуля (*.срр + *.h)
#elif Unit == 3
std::cout << "Задание 3" << std::endl;
// Вызов функции задания 3 из отдельного файла (*.h ) или модуля (*.срр + *.h)
//.....
#else
// Вызов функции задания 4 из отдельного файла (*.h ) или модуля (*.срр + *.h)
//...
#endif

  return 0;
}
