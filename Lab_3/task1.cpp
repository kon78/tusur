//реализация функций \
задаяа 1 - игральные карты. вероятность вынуть из колоды 52 карты 1 карту туз (масть на важна) \
           4 туза --> (4/52) * 4 = 0.308 --> 30.8%
//#include"task1.h"
// функция \
double - возвращаемый тип \
GameCards - название \
(void) - функция без параметров

    enum{max_cards=52, count_tuz=4, percent_per=100};
double GameCards(){
//локальные переменные
    const short int game_cards = max_cards; //сколько карт в колоде
    double answ;
    //тело функции
  if (game_cards != 0){
    answ = (( 4 / (double)game_cards ) * (double)count_tuz) * (double)percent_per;
//    return (double)(( 4 / game_cards ) * 4) * 100;
    return answ;
    }else{
      return -1; //ошибка
    }
}
