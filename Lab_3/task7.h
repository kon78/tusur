#ifndef TASK7_H
#define TASK7_H
#include<iostream>
#include<stdio.h>
#include<string>//для 7 задачи scanf
void Elevator();
void MapBuild();
//              0          1          2         3           4           5         6         7
enum level{zero_floor=0,one_floor,two_floor,three_floor,four_floor,five_floor,six_floor,seven_flor};
enum move{down=0, up};
const int build_size = 7;
#endif // TASK7_H
