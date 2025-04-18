/*
* Лабораторная работа No4
* “Исследование массивов, указателей, ссылок.”
*
* Developer: Половян КА 318OOP/C++
* OS: Windows 10
* locale (кодировка): UTF-8
*/

enum class ProgrEnum {Task_1, Task_2, Task_3, Task_4};
const ProgrEnum progrEnum = ProgrEnum::Task_4;

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
      cout << "Задание 3.\n";
      const char alphaBeg = 'a';
      const char alphaEnd = 'z';
      char alpha = alphaBeg;
      cout << "alpha" << "\tcode ASCII\n";
      do{
        cout << "  " << alpha
        << "\t    " << static_cast<int>(alpha) << "\n";
        ++alpha;
      if(
      static_cast<int>(alpha) ==  static_cast<int>(alphaEnd+1)
          )
      break;
   }while(true);
      }
      else if constexpr (progrEnum == ProgrEnum::Task_4){
        cout << "Задание 4.\na)\n";
        unsigned int numb, alg;
        enum {alg_recur=0, alg_iter=1,err_numb=20};
//        const int err_numb(10);//ограничение, можно увеличить
        cout << "Нахождение факториала от числа с использованием (0-рекурсии,1-итерации)\nпример: 1,2...n (через пробел) 0,1 " << endl;

        cin >> numb >> alg;
//        cout << ((numb >= 1 && numb <= err_numb)?"true\n":"false\n");
//        cout << ((alg == alg_recur || alg == alg_iter)?"true\n":"false\n");

        if(cin.fail()){cout << "Ошибка ввода!\n";exit(0);}//здесь сбрасывемся по ошибке

        if(!
             (numb >= 0 && numb <= err_numb) && //проверка ввода
             (alg == alg_recur || alg == alg_iter)
           ){
          cout << "слишком большое число для данного типа int или неверно выбран алгоритм\n";
        }else{
          switch(alg){
          case(alg_recur)://рекурсия
          {
            cout << "рекурсия\n";
          }
          case(alg_iter)://итерация
          {
            cout << "Итераия.\n";

            constexpr size_t N{20};
            unsigned long int arr_fib[N]={1,0};//начальный массив, чтобы тип unsigned long int перекрыл INT_MAX
            if(sizeof(arr_fib)/sizeof(unsigned long int) != N){//проверяем массив
              cout << "Error! Array not equal " << N << endl;
            }else{
          //содержимое массива
              if(numb == 0){
                cout << "Факториал для " << numb << " равен " << arr_fib[0] << endl; //0=1
              }else{

//                cout << INT_MAX << endl;
//                unsigned long int n = INT_MAX-2;
//                for(int i = 1; i < 5; ++i){
//                  n += 1;
//                  if(n > INT_MAX){cout << "override!\n";break;}
//                  cout << n << endl;
//                }
//                exit(0);

                //[1][1][2][6][24][120][720]...
                for(unsigned int i = 1; i <= numb-1; i++){
                  arr_fib[i] = arr_fib[i-1] * (i+1);
                  //если fac(n) > INT_MAX, непредвиденное поведение
//                  if(arr_fib[i] / arr_fib[i-1] != numb)cout << "override!\n";
//                  cout << arr_fib[i] << "/" << arr_fib[i-1] << "=" <<  arr_fib[i]/arr_fib[i-1] << " " << i << endl;

                  if(arr_fib[i]/arr_fib[i-1] != (i+1)){
                    arr_fib[i] = 0;
                    break;
                  }

//                  arr_fib[i] = ( ((arr_fib[i] == INT_MAX))?-1:arr_fib[i] );

//                  if(
//                     arr_fib[i] < 0
//                     ){
//                    cout << "Превышен максимальный диапазон " << INT_MAX <<"\n" ;
//                    exit(0);
//                  }

                }
              }
              if(numb != 0 && arr_fib[numb-1] != 0)
                cout << "Факториал для " << numb << " равен " << arr_fib[numb-1] << endl;
              else
                cout << "Факториал для " << numb << " превышает " << INT_MAX << endl;
           cout << '\n';
        }

          }
          }
\

        }
    }
    else {
        // ...
    }

    return 0;
}
