#include"task1.h"
//#include<algorithm>
//#include<string>
//#include<iostream>

/*реализация функций
// функция
double - возвращаемый тип
GameCards - название
(void) - функция без параметров */

/*задаяа 1 - игральные карты. вероятность вынуть из колоды 52 карты 1 карту туз (масть на важна)
             4 туза --> (4/52) = 0.0769 --> P=7.69% ~ 8% */

double GameCards(){
//локальные переменные
    const short int game_cards = max_cards; //сколько карт в колоде
//тело функции
    return round(
        (( count_tuz / static_cast<double>(game_cards) )) * percent_per);
}

/*задача 2 - игральные кубики, бросаются кубики с 6 сторонами, найти вероятность, что сумма \
             выпавших очков будет равна 7. \
             2 кубика - 6 граней --> 6*6=36 всего комбинаций для двух кубиков \
             7 --> (1,6)/(2,5)/(3,4)/(4,3)/(5,2)/(6,1) сочетания - 6 пар нужных комбинаций \
             P=6/36=0.16(6)-->16.6% ~ 17% */

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
    ( count_comb / static_cast<double>(all_bones) ) * percent_per
    );
}

/*задача 3 - игра в кубики М А М А --> ААММ AMAM АММА MAAM МАМА MMAA \
                          p(c) \
             M A M A --> М 2/4 \
             M A A   --> A 2/3 при условии, что М уже поставили первой \
             M A     --> M 1/2 \
             A       -->   1 \
             P = 2/4 * 2/3 * 1/2 = 0.5 * 0.(6) * 0.5 * 1 = 0.1(6)5 ~ 15-16% в зависимости от точности \
                 либо 1/6(комбинаций) */

//немного забегаю вперед в плане знаний, чтобы не выписывать все слова из исходного
double PermutationWords(){
  int count_words = 0;
  std::string s = "MAMA";
  std::sort(s.begin(),s.end());//

  do{
#if 0
//выводим все сочетания слова MAMA
    std::cout << s << '\n';
#endif
    ++count_words;
  }while(std::next_permutation(s.begin(),s.end()));

return ((1 / static_cast<double>(count_words)) * percent_per); //1-имеющее смысл слово МАМА
}

#if 1
void My_Swap(const std::string& word){
//         swap 1,2,3      swap с концов + само слово
//MAMA --> AMMA MMAA MAAM | AAMM AMAM | + MAMA
    std::string w1 = word;
    int cnt(1);//1-само слово мама
    std::cout << w1 << std::endl;
    for(unsigned int i = 0; i < w1.length()-1; ++i){
        std::swap(w1[i],w1[i+1]);
        ++cnt;
        std::cout << w1 << std::endl;
        w1.erase();
        w1 = word;
    }

//с начала и его конца с центру меняем местами буквы при условии что количество букв четное
unsigned int c_beg(0); unsigned int c_end(w1.length()-1);
for(unsigned int i = 0; i < w1.length()/2; ++i){
    std::swap(w1[c_beg+i],w1[c_end-i]);
    std::cout << w1 << std::endl;
    ++cnt;
}

#if 0
    std::swap(w1[0],w1[3]);
    std::cout << w1 << std::endl;
    ++cnt;

    std::swap(w1[1],w1[2]);
    std::cout << w1 << std::endl;
    ++cnt;
#endif

    std::cout << "Вероятность составить слово МАМА из четырех букв М А М А будет равна "
              << static_cast<int>((1 / static_cast<double>(cnt)) * percent_per) << "%\n";
}
#endif

void Propability(){
    //  double probability_cards; //ответ
    std::cout << "Задание 1.а" << std::endl;
    unsigned int tmp = max_cards; //для проверки, что max_cards не является 0
    // Вызов функции задания 1 из отдельного файла (*.h ) или модуля (*.срр + *.h)
    if(tmp != 0){
        std::cout << "Вероятность вынуть из колоды (" << max_cards << " карты) туза (без масти) будет равна "
                  << static_cast<int>(GameCards()) << "%\n";
    }else{
        std::cout << "Error! Деление на 0! " << " max_cards задана " << max_cards << '\n';
        exit(progr_err);
    }

    std::cout << "Задание 1.б" << std::endl;
    std::cout << "Вероятность выпадения " << bones_wine << " очков " << " будет равна "
              << static_cast<int>(CuteBones()) << "%\n";

    std::cout << "Задание 1.в" << std::endl;
    std::cout << "Вероятность составить слово МАМА из четырех букв М А М А будет равна "
              << static_cast<int>(PermutationWords()) << "%\n";

#if 1
    std::cout << "Вариант без алгоритмов std::next_permutation.\n";
    std::string w = "MAMA";

    My_Swap(w);
#endif

}

