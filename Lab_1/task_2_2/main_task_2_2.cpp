//директивы препроцессора
//#include <QCoreApplication>
#include <iostream>

//директива препроцессору
#define mainProgramm true

//основной блок программы \
аргументы передаваемые в тело функции main из командной строки

int main(int argc, char *argv[])
{
#ifndef mainProgramm
  QCoreApplication a(argc, argv);
  //исключаем этот блок и работаем в другом
  return a.exec();
#endif

  char* facultet="УДО";//си-строка
  char* group="Группа 318 OOP_C++";
  char* stud="Половян К.А.";
#ifdef mainProgramm
  //здесь будет основной код программы
  //установки флага вывода cout \t символ табуляции endl-окончание потока
  char newline = '\n';//символьный тип данных, перевод строки
  std::cout << "*****" << "\t\t\t" << "ТУСУР" << "\t\t\t" << "*****" << std::endl;
//  std::cout << "\n";//\n символ перевода строки в консоли
  std::cout << newline;//еще вариант перевода строки
  std::cout << std::endl;
  std::cout.width(58);//выставляем длину
  std::cout.setf(std::ios::right);//выравниваем по правому краю
  std::cout << "Факультет: " << facultet << std::endl;
  std::cout.width(52);
  std::cout << "Группа: " << group << std::endl;
  std::cout.width(54);
  std::cout << "Студент: " << stud << std::endl;
#endif

  return 0;
}
