#ifndef TASK1_H
#define TASK1_H
#include<math.h>//для задачи 1.1 round
#include<algorithm>
#include<iostream>
#include<string>
enum{max_cards=52, count_tuz=4, percent_per=100,bones_wine=7,progr_err=1001};
void Propability();
double GameCards();// объявление функции
double CuteBones();
//int factorial(int n);
//int C(int n, int k);
double PermutationWords();
#if 1
void My_Swap(const std::string& word);
#endif
//enum{progr_err=-1};
#endif // TASK1_H
