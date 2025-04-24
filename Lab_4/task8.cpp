#include"task8.h"
void Phase(char(&ref_arr)[LEN_ARR]){
  if(sizeof(ref_arr)/sizeof(char) == LEN_ARR){
    //по часовой и против часовой
    std::cout << "Фазы " << ref_arr[phaseU] << " " << ref_arr[phaseV] << " " << ref_arr[phaseW] << " нейтраль N " << rotate_motor[CW] << std::endl;
    std::cout << "Фазы " << ref_arr[phaseV] << " " << ref_arr[phaseU] << " " << ref_arr[phaseW] << " нейтраль N " << rotate_motor[CCW] << std::endl;


  }else{
    std::cout << "Error! Reference!";
    exit(0);
  }
}
