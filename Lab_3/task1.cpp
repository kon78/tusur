#include"task1.h"

//реализация функций \
// функция \
double - возвращаемый тип \
GameCards - название \
(void) - функция без параметров

//задаяа 1 - игральные карты. вероятность вынуть из колоды 52 карты 1 карту туз (масть на важна) \
             4 туза --> (4/52) * 4 = 0.308 --> 30.8%
double GameCards(){
//локальные переменные
    const short int game_cards = max_cards; //сколько карт в колоде
//тело функции
    return (( count_tuz / (double)game_cards ) * count_tuz) * percent_per;
}
