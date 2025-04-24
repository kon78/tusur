#ifndef TASK8_H
#define TASK8_H
#include<iostream>
enum{phaseW=0,phaseU,phaseV};
constexpr int LEN_ARR{3};
enum{CW=0,CCW};//CW-по часовой CCW-против часовой
const char rotate_motor[][20]={"clock wise","counter clock wise"};
void Phase(char(&arr)[LEN_ARR]);
#endif // TASK8_H
