/*
 * заголовочный файл main.cpp
 * в нем содержится основная функция - точка входа main(...)
*/

#if 0 //Задание 1


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

#if 1
#endif
