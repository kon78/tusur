/*
 * заголовочный файл main.cpp
 * в нем содержится основная функция - точка входа main(...)
*/
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
