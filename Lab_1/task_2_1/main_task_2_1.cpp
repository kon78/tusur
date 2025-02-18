//препроцессор директива подключается модуль/библиотека QCoreApplication
//для комментариев директивой
#define qtComment false
#define main_comment false

#include<iostream>

#ifndef qtComment
#include <QCoreApplication>
#endif

//точка входа, помоему так еще называется int main(){...} \
int argc-число аргументов из командной строки \
char *argv[]-массив аргументов, слова, цифры, опции и т.д.

int main(int argc, char *argv[])
{//блок стейтменов начало

#ifndef main_comment
//Номер группы: group_cpp_318//ООП_С++, факультет: УДО ТУСУР
//Разработчик: Половян КА
//Номер лабораторной работы: 1
#endif

  #ifndef qtComment
/* основной блок приложения qt, в него можно передать аргументы командной строки
      QCoreApplication a(argc, argv);

      return a.exec();
*/
  #endif
//успешный выход 0-success \
                 1-error
return 0;
}//блок стейтменов конец

//режимы сборки \
режим debug - task_2_1.exe-63кБ main.o-17кБ; \
режим release task_2_1.exe-16кБ main.o-2кБ
