//TODO: snake_case названия переменных

/*
* Лабораторная работа No3
* Исследование функций С++ в IDE (интегрированной среде разработки) Qt Creator
*
* Developer: Половян КА 318OOP/C++
* OS: Windows 10
* locale (кодировка): UTF-8
*/

#include <iostream>
#include "task1.h"//заголовочный файл для задачи 1

#define Unit 1


using namespace std;
int main(int argc, char *argv[])
{
#if Unit == 1
//  double probability_cards; //ответ
cout << "Задание 1" << endl;
// Вызов функции задания 1 из отдельного файла (*.h ) или модуля (*.срр + *.h)
if(max_cards != 0){
  cout << "Вероятность вынуть из колоды (" << max_cards << " карты) туза (без масти) будет равна "
       << GameCards() << "%\n";
}else{
  cout << "Error! Деление на 0!\n";
  exit(progr_err);
}

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
