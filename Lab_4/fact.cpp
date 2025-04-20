#include"fact.h"
unsigned long int fact(int N){
    if(N < 0) // если отрицательное число
        return 0;
    if (N == 0) // 0=1
        return 1;
    else // считаем факториал
        return N * fact(N - 1); // рекурсия
}
