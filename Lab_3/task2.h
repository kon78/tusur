#ifndef TASK2_H
#define TASK2_H
#include<iostream>

/*
 * прототип функции с объявлениями парметров
 * параметр int a будет явно переопределяться пользователем
*/

void PrintChar(int a = 'a',char b = 'b',char c = 'c', char d = 'd');

/*
 * void PrintChar(int a,char,char c, char d = 'd');//правильно расположение справа
 * void PrintChar(int a = 'a',char,char c, char d);//неправильно
*/

#endif // TASK2_H
