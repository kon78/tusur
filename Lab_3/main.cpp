//TODO: snake_case названия переменных
//TODO: сочетания и перестановки - https://qna.habr.com/q/571320
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

#define Unit 2


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
