#include"task1.h"
#include<algorithm>
#include<string>
#include<iostream>
//реализация функций \
// функция \
double - возвращаемый тип \
GameCards - название \
(void) - функция без параметров

//задаяа 1 - игральные карты. вероятность вынуть из колоды 52 карты 1 карту туз (масть на важна) \
             4 туза --> (4/52) = 0.0769 --> P=7.69% ~ 8%
double GameCards(){
//локальные переменные
    const short int game_cards = max_cards; //сколько карт в колоде
//тело функции
    return round(
                (( count_tuz / (double)game_cards )) * percent_per);
}

//задача 2 - игральные кубики, бросаются кубики с 6 сторонами, найти вероятность, что сумма \
             выпавших очков будет равна 7. \
             2 кубика - 6 граней --> 6*6=36 всего комбинаций для двух кубиков \
             7 --> (1,6)/(2,5)/(3,4)/(4,3)/(5,2)/(6,1) сочетания - 6 пар нужных комбинаций \
             P=6/36=0.16(6)-->16.6% ~ 17%

double CuteBones(){
  //локальные переменные
  const int min_bone = 2;//игральные кости ограничения на выпадение
  const int max_bone = 12;
  const int all_bones = (6*6);
  int count_comb = 0;//число комбинация для заданного выигрыша

  //тело функции i,j-счетчики
    if(bones_wine >= min_bone && bones_wine <= max_bone){
    for(int i = 1; i < 7; ++i){ //число очков 1 - 6 на кубиках
      for(int j = 1; j < 7; ++j){
        if ((i + j) == bones_wine){ //условия
          ++count_comb;
//        std::cout << i << " + " << j << std::endl;
    }
  }
}

}
//std::cout << count_comb << " " << all_bones << " " << percent_per << std::endl;
  return round(
               ( count_comb / (double)all_bones ) * percent_per
    );
}

//задача 3 - игра в кубики М А М А --> ААММ AMAM АММА MAAM МАМА MMAA \
                          p(c) \
             M A M A --> М 2/4 \
             M A A   --> A 2/3 при условии, что М уже поставили первой \
             M A     --> M 1/2 \
             A       -->   1 \
             P = 2/4 * 2/3 * 1/2 = 0.5 * 0.(6) * 0.5 * 1 = 0.1(6)5 ~ 15-16% в зависимости от точности \
                 либо 1/6(комбинаций)

//немного забегаю вперед в плане знаний, чтобы не выписывать все слова из исходного
double PermutationWords(){
  int count_words = 0;
  std::string s = "MAMA";
  std::sort(s.begin(),s.end());//

  do{
    std::cout << s << '\n';
    ++count_words;
  }while(std::next_permutation(s.begin(),s.end()));

return ((1 / (double)count_words) * percent_per); //1-имеющее смысл слово МАМА
}


