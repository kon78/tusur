#include<iostream>
#include"task5.h"

using namespace std;

int MyMax(int first_numb, int second_numb){
  if(first_numb != second_numb){//0!=0 5!=5
    //сравнение
    return (
          (first_numb < second_numb)?(second_numb):(first_numb));
  }else{
    cout << "Сравнение не имеет смысла!\n";
    exit(-1);
  }
}

unsigned short MyMax(unsigned short first_numb, unsigned short second_numb){
  if(first_numb != second_numb){//0!=0 5!=5
    //сравнение
    return (
          (first_numb < second_numb)?(second_numb):(first_numb));
  }else{
    cout << "Сравнение не имеет смысла!\n";
    exit(-1);
  }
}

int MyMax(int first_numb, int second_numb, int limit_max, int limit_min){
int local_answ;
//  cout << first_numb << " " << second_numb << " " << limit_max << " " << limit_min <<endl;
  if(first_numb != second_numb && limit_max != limit_min){
    if(
       (first_numb <= limit_max && first_numb >= limit_min) &&
       (second_numb <= limit_max && second_numb >= limit_min)
       ){
      cout << "MyMax(4 param)\n";
      local_answ = (first_numb < second_numb)?(second_numb):(first_numb);
    }else{
      cout << "Превышены границы сравнения!\n";
      exit(-1);
    }
  }else{
    cout << "Сравнение не имеет смысла!\n";
    exit(-1);
  }
  return local_answ;
}
