/*
* Лабораторная работа No4
* “Исследование массивов, указателей, ссылок.”
*
* Developer: Половян КА 318OOP/C++
* OS: Windows 10
* locale (кодировка): UTF-8
*/

enum class ProgrEnum {Task_1, Task_2, Task_3, Task_4, Task_5, Task_6, Task_7, Task_8, Task_9, Task_10};
const ProgrEnum progrEnum = ProgrEnum::Task_6;

#include <iostream>
#include "sorting.h"
#include "fact.h"
#include "fib.h"
#include "task4c.h"
#include "task5.h"
#include "task6.h"
#include "task8.h"
#include "task9.h"
#include "task10.h"

using namespace std;

int main()
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

    }else if constexpr (progrEnum == ProgrEnum::Task_5){
      unsigned int data_type;
      unsigned int arr_size;
      cout << "Задание 5.\n";
      cout << "Выберите тип данных char-1, 2-short, 3-int, 4-float, 5-double\n";
      cin >> data_type;
      if(cin.fail() || (data_type < 1 || data_type > 5)){
        cout << "Ошибка ввода или не правильно выбран тип данных!\n";
      exit(0);
      }

      cout << "Укажите размер массива ";
      cin >> arr_size;
      if(cin.fail() || arr_size == 0){
        cout << "Ошибка ввода или не правильно выбран тип данных!\n";
      exit(0);
      }
    MakeArray(data_type,arr_size);

    }else if constexpr (progrEnum == ProgrEnum::Task_6){
      int m; double fx; char cht;
      void* arr_val[elem_val]={nullptr};
      cout << "Задание 6.\n";
      cout << "Введите 2 числа и символ.\n";
      cout << "Целое ";
      cin >> m;
      if(cin.fail()){
        cout << "Ошибка ввода!\n";
        exit(0);
      }

      cout << "Дробное ";
      cin >> fx;
      if(cin.fail()){
        cout << "Ошибка ввода!\n";
        exit(0);
      }

      cout << "Символ ";
      cin >> cht;

//      arr_val[0]=&m; arr_val[1]=&fx; arr_val[2]=&cht;
//      PrintValueAddr(arr_val);

     cout << "Были введены " << m << " " << fx << " " << cht << '\n';

     cout << "Используя операторы & и *:\n";
     PrintValAddr(&m,sizeof(m));//передаем адрес и размер
     PrintValAddr(&fx,sizeof(fx));
     PrintValAddr(&cht,sizeof(cht));

    }else if constexpr (progrEnum == ProgrEnum::Task_7){
      cout << "Задание 7.\n";
      const int ssize(5);
      int iArrData[ssize]{5,7,2,9,8};
      int* ptr = nullptr;

      ptr = iArrData;//адрес массива в указатель
      if(sizeof(iArrData)/sizeof(int) == ssize){
        for(unsigned int i = 0; i < ssize; ++i){
          cout << "адрес ячейки " << ptr << " массива iArrData [" << i << "] = " << *ptr << endl;
          ++ptr;//increment ptr
        }
      }
    }else if constexpr (progrEnum == ProgrEnum::Task_8){
      cout << "Задание 8.\n";
      char arr[LEN_ARR]{'W', 'U', 'V'};
      char(&ref_arr)[LEN_ARR] = arr;//reference
      Phase(ref_arr);
    }else if constexpr (progrEnum == ProgrEnum::Task_9){
      cout << "Задание 9.\n";
      bool op1 = false; bool op2 = true;
      bool& ref_op1 = op1;
      bool& ref_op2 = op2;
#if 0
      EnumFuncLog enum_allfunc = (EnumFuncLog::fAnd);
        if(enum_allfunc == EnumFuncLog::fAnd){

          cout << "операнды " << ref_op1 << " " << ref_op2 << " результат " << BaseFunction(ref_op1,ref_op2,&LogAND) << endl;
          cout << "операнды " << ref_op1 << " " << ref_op2 << " результат " << BaseFunction(ref_op1,ref_op2,&LogAND) << endl;
        }
#endif

#if 1
    constexpr int ssize_func(3);
    EnumFuncLog enum_allfunc = (EnumFuncLog::fEnd);//fEnd=9
    std::function<bool(bool&,bool&)> arr_func[ssize_func] = {&LogAND, &LogOR, &LogXOR};//массив функций

    std::function<bool(bool&,bool&)> operation;
      for(unsigned int i = 0; i < (unsigned int)enum_allfunc; ++i){
//        std::function<bool(bool&,bool&)> operation;
        if(i == (unsigned int)EnumFuncLog::fAnd){
          operation = arr_func[(unsigned int)EnumFuncLog::fAnd];
          cout << "операнды " << ref_op1 << " " << ref_op2 << " результат " << BaseFunction(ref_op1,ref_op2,operation,&LogAND) << endl;
        }else if(i == (unsigned int)EnumFuncLog::fOr){
          operation = arr_func[(unsigned int)EnumFuncLog::fOr];
          cout << "операнды " << ref_op1 << " " << ref_op2 << " результат " << BaseFunction(ref_op1,ref_op2,operation,&LogOR) << endl;
        }else if(i == (unsigned int)EnumFuncLog::fXor){
          operation = arr_func[(unsigned int)EnumFuncLog::fXor];
          cout << "операнды " << ref_op1 << " " << ref_op2 << " результат " << BaseFunction(ref_op1,ref_op2,operation,&LogXOR) << endl;
        }else{
          cout << "нет такой операции\n";
        }
      }
#endif

    }else if constexpr (progrEnum == ProgrEnum::Task_10){
      cout << "Задание 10.\n";
      char arr_data[ssize_arr]{1,2,3,4,5,6,7,8,9,10,11,12};
      ChangeArray(arr_data, ssize_arr);
      for(auto el : arr_data)
        cout << (int)el << " ";
      cout << endl;
    }
    else {
      cout << "Нет задачи!\n";
      exit(0);
    }

    return 0;
}
