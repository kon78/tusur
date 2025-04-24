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
