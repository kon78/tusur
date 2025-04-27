#include<iostream>
#include"task6.h"

void PrintValAddr(void* addr,int vsize){
  enum{schar=sizeof(char),sdouble=sizeof(double),sint=sizeof(int)};
  if(addr != nullptr && vsize != 0){//проверем nullptr и 0 размер
    switch(vsize){
    case sint:{
      std::cout << "Значение по адресу " << addr << " переменной m --> ";
      PRINT_VAL_INT(static_cast<int*>(addr));//void --> int
      std::cout << '\n';
      break;
    }
    case sdouble: {
      std::cout << "Значение по адресу " << addr << " переменной fx --> ";
      PRINT_VAL_DOUBLE(static_cast<double*>(addr));//void --> double
      std::cout << '\n';
      break;
    }
    case schar: {
      std::cout << "Значение по адресу " << addr << " переменной cht --> ";
      PRINT_VAL_CHAR(static_cast<char*>(addr));//void --> char
      std::cout << '\n';
      break;
    }
    default:{std::cout << "Непредусмотренный тип данных!\n";break;}
    }
  }

}

#if 0
void PrintValueAddr(void*(&arr_val)[elem_val]){
  int* dat_int = nullptr;
  char* dat_char = nullptr;
  double* dat_double = nullptr;
  for(unsigned int i = 0; i < sizeof(arr_val)/sizeof(void*); ++i){
    if(*typeid(arr_val[i]).name() == 'i'){
      dat_int = (int*)(arr_val[i]);//& --> int*
      std::cout << "m=" << *dat_int << arr_val[i] << std::endl;
    }else if(*typeid(arr_val[i]).name() == 'c'){
      dat_char = (char*)(arr_val[i]);
      std::cout << "cht=" << *dat_char << arr_val[i] << std::endl;
    }else if(*typeid(arr_val[i]).name() == 'd'){
      dat_double = (double*)(arr_val[i]);
      std::cout << "fx=" << *dat_double << arr_val[i] << std::endl;
    }else{
      std::cout << "No matches\n";
    }
  }
}
#endif
