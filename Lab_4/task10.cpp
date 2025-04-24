#include"task10.h"
void ChangeArray(char* addr, int ssize){
  if(addr != nullptr && ssize != 0){
    char* pmem = addr;
//    for(unsigned int i = 0; i < (unsigned int)ssize; ++i )
//      std::cout << (int)*addr << " ";
    std::cout << std::endl;
    char beg;
    char end;
    for(unsigned int i = 0; i < ((unsigned int)ssize); i++){
      //0%2-->0 2%2-->0 11%2-->1
      if(addr > addr + ssize){
        std::cout << "Error! Address out range!\n";
        exit(0);
      }
      if((i % 2) == 0){
        std::cout << "change\n";
        beg = *addr; end = *(++addr);
        std::swap(beg,end);
        addr = pmem;
        *addr = beg; *(++addr) = end;
        pmem = ++addr;
      }
    }
  }else{
    std::cout << "Error! Nullptr!\n";
    exit(0);
  }
}
