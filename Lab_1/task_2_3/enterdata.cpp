#include <iostream>
#include "enterdata.h"//подключаем заголовочный файл

using namespace std;

float EnterData(){
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
  return AnyValue;
}
