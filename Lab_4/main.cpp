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
#include "fact.h"
#include "fib.h"
#include "task4c.h"
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
#if 0
        cout << "Задание 4.\na)\n";
        unsigned int numb, alg;
        enum {alg_recur=0, alg_iter=1,err_numb=13};
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
            cout << "Рекурсия.\n";
            //если fact(numb) > 13 --> переполнение при типе данного INT
            if(!(numb >= err_numb))
              cout << "Факториал для " << numb << " равен " << fact(numb) << endl;
            else
              cout << "Факториал для " << numb << " превышает " << INT_MAX << endl;
            break;
          }
          case(alg_iter)://итерация
          {
            cout << "Итерация.\n";

            constexpr size_t N{20};
            unsigned long int arr_fib[N]={1,0};//начальный массив, чтобы тип unsigned long int перекрыл INT_MAX
            if(sizeof(arr_fib)/sizeof(unsigned long int) != N){//проверяем массив
              cout << "Error! Array not equal " << N << endl;
            }else{
          //содержимое массива
              if(numb == 0){
                cout << "Факториал для " << numb << " равен " << arr_fib[0] << endl; //0=1
              }else{

                //[1][1][2][6][24][120][720]...
                for(unsigned int i = 1; i <= numb-1; i++){
                  arr_fib[i] = arr_fib[i-1] * (i+1);
                  //если fac(n) > INT_MAX, непредвиденное поведение

                  if(arr_fib[i]/arr_fib[i-1] != (i+1)){
                    arr_fib[i] = 0;
                    break;
                  }
                }
              }
              if(numb != 0 && arr_fib[numb-1] != 0)
                cout << "Факториал для " << numb << " равен " << arr_fib[numb-1] << endl;
              else
                cout << "Факториал для " << numb << " превышает " << INT_MAX << endl;
           cout << '\n';
        }

              break;
          }
          default:cout << "Неверный выбор! " << alg_recur << " Рекурсия " << alg_iter << " Итерация " << endl;
            exit(0);//завершаем и сообщаем пользователю
            break;
          }

        }
#endif
#if 0
  cout << "Задание 4.\nб)\n";
  cout << "Число Фибоначчи.\n";
//  enum{size_fib=20};
  int arr_fib[size_fib]={0,1};
  int numb_fib,answer(0);
  Fibonachi(arr_fib,size_fib);
  cout << "Введите число/номер ряда Фибоначчи от 0 до " << size_fib << " ";
  cin >> numb_fib;

  if(cin.fail() || numb_fib > size_fib){cout << "Ошибка ввода или слишком большое значение!\n";exit(0);}//здесь сбрасывемся по ошибке
  else cin.ignore(32767,'\n');

  cout << "Было введено " << numb_fib << endl;
//  cout << sizeof(arr_fib)/sizeof(int) << endl;
  answer = arr_fib[numb_fib-1];
  cout << "Элемент ряда Фибоначчи " << numb_fib << " равен " << answer << endl;

//  for(auto el : arr_fib)//выводим на печать массив посчитанный в функции (для проверки)
//        cout << el << " ";
//      cout << endl;

#endif

#if 1
  //.   1 1 \
       2 1 3 \
      3 2 1 6 \
     4 3 2 1 10 \
    5 4 3 2 1 15 --> Sum[n + (n-1)],while n≠0\
         /\
     1->1+0=1 2->2+1=3 3->3+2+1=6 \

  const unsigned int target_sum = 21;
  //можно if constexpr в цикле while
  unsigned int sum(0);
  unsigned int numb(1);
  unsigned int cnt(1);
  while(true){
      SummNumb(numb,sum);
      PrintNum(numb);
      --numb;
      if(numb == 0){
        numb = ++cnt;
        cout << " " << sum << '\n';
        if(sum == target_sum)
        break;
        sum=0;
  }
  };
#endif

    }
    else {
        // ...
//      exit(0);
    }

    return 0;
}
