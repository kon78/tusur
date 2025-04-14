/*
* Лабораторная работа No4
* “Исследование массивов, указателей, ссылок.”
*
* Developer: Половян КА 318OOP/C++
* OS: Windows 10
* locale (кодировка): UTF-8
*/

enum class ProgrEnum {Task_1, Task_2, Task_3/*, Task_4,...*/};
const ProgrEnum progrEnum = ProgrEnum::Task_1;

#include <iostream>
#include "sorting.h"

using namespace std;

int main(int* argc, char* argv[])
{
    if constexpr (progrEnum== ProgrEnum::Task_1) {
        cout << "Задание 1.\n";
        const unsigned int rnd_const1 = 73129;
        const unsigned int rnd_const2 = 95121;
        const unsigned int rnd_devis = 100000;
        const int size_arr = 10;
        int arr_int[size_arr] = {0};
        // cout << "size array is " << (sizeof(arr_int)/sizeof(int)) << endl;
        if( (sizeof(arr_int)/sizeof(int)) != size_arr ){
            cout << "Error! Array not equal " << size_arr << endl;
        }else{
            unsigned value = size_arr + (size_arr / 2);
            for (int i = 0; i < size_arr; ++i)
            {
                // вычисляем новое значение value
                value = (value * rnd_const1 + rnd_const2) % rnd_devis;
                arr_int[i] = value;
            }
            //смотрим что получилось до сортировки
            for (auto elem : arr_int)
                cout << elem << " ";
            cout << endl;

            bubbleSort(arr_int, sizeof(arr_int)/sizeof(int));
            //сортируем buble-sort(пузырьковая)

            //смотрим что получилось после сортировки
            for (auto elem : arr_int)
                cout << elem << " ";
            cout << endl;
            cout << "Max elem is " << arr_int[0] << " Min elem is " << arr_int[9] << '\n';
        }
    }
    else if constexpr (progrEnum == ProgrEnum::Task_2) {
        // task 2
    }
    else if constexpr (progrEnum == ProgrEnum::Task_3) {
        // task 3
    }
    else {
        // ...
    }
return 0;
}
