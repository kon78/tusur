/*
* Лабораторная работа No4
* “Исследование массивов, указателей, ссылок.”
*
* Developer: Половян КА 318OOP/C++
* OS: Windows 10
* locale (кодировка): UTF-8
*/

enum class ProgrEnum {Task_1, Task_2, Task_3/*, Task_4,...*/};
const ProgrEnum progrEnum = ProgrEnum::Task_2;

#include <iostream>
#include "sorting.h"

using namespace std;

int main(int argc, char* argv[])
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
        // task 2a
#if 0
      cout << "Задание 2.\na\n)";
      constexpr size_t N{5}, M{5};
      // Инициализация
      int arr[N][M] = {
      {1, 0, 0, 0, 0}, /*строка №0*/
      {0, 1, 0, 0, 0}, /*строка №1*/
      {0, 0, 1, 0, 0}, /*строка №2*/
      {0, 0, 0, 1, 0}, /*строка №3*/
      {0, 0, 0, 0, 1}  /*строка №4*/
      };

      for(auto i = 0; (size_t)i < N; i++){
          for(auto j = 0; (size_t)j < M; j++){
              cout << arr[i][j] << " ";
              }
          cout << endl;
          }
#endif

#if 1
      cout << "Задание 2.\nb\n)";

      const int beg = 15;//rand()-->int
      const int end = -15;
      constexpr size_t N{8}, M{8};
      //int rnd_numb;
      int arr[N][M];//8x8

      //привожу к типу size_t int C-style cast
      for(auto i = 0; (size_t)i < N; i++){
       for(auto j = 0; (size_t)j < M; j++){
     //rand -15 15
     arr[i][j] = rand() % (beg - end + 1) + end;
     cout << arr[i][j] << " ";
     }
       cout << endl;
     }
     cout << "-----------------------------\n";
     //calculate sum
     //1 2; 2 3; 3 4; n n+1 arr[k][l]
     int sum_right_diag(0);
     for(auto k = 0; (size_t)k < N; k++){
       for(auto l = k+1; (size_t)l < M; l++){
         sum_right_diag += arr[k][l];
         cout << arr[k][l] << " ";
       }
       cout << endl;
     }
     cout << "sum=" << sum_right_diag << endl;
#endif



    }
    else if constexpr (progrEnum == ProgrEnum::Task_3) {
        // task 3
    }
    else {
        // ...
    }
return 0;
}
