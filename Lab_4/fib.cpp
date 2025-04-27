#include "fib.h"

using namespace  std;

void Fibonachi(int(&arr_fib)[size_fib],const int& size_arr){
  int n_el(1);//элемент ряда

  if(sizeof(arr_fib)/sizeof(int) != size_arr)//проверяем размер массива
    cout << "Error! Array not equal " << size_arr << endl;
  else{
    //считаем
    while(n_el <= size_arr){
      arr_fib[n_el+1] = arr_fib[n_el-1] + arr_fib[n_el];
      ++n_el;//икремент
      if(n_el >= 20)break;
    }
  }
}
