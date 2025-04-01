#include<iostream>
#include"task5.h"

using namespace std;

int MyMax(int first_numb, int second_numb){
  if(first_numb != second_numb){//0!=0 5!=5
    //сравнение
    return (
          (first_numb < second_numb)?(second_numb):(first_numb));
    return (
          (first_numb > second_numb)?(first_numb):(second_numb));

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
    return (
          (first_numb > second_numb)?(first_numb):(second_numb));

  }else{
    cout << "Сравнение не имеет смысла!\n";
    exit(-1);
  }
}
