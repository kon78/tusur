//TODO git ветка lab2, слить с веткой master!!!! LOCALE?
//TODO округление весов до целых наверно
//TODO binprintf(...) наверное можно убрать

/*
* Лабораторная работа No2
* Исследование ввода-вывода типов данных стандартной библиотеки С++
*
* Developer: Половян КА 318OOP/C++
* OS: Windows 10
* locale (кодировка): UTF-8
*/
#include <iostream>// подключаем библиотеку ввода/вывода
#include <task1.cpp>//
#include <bitset>//для вывода в бинарной форме

using namespace  std;
int main(int argc, char *argv[])
{
//Задание 1.“Калькулятор для расчета идеального веса“.
#if 0

  bunnerTask1();
  cout << "Для расчета пользователю необходимо ввести следующие данные:\n";
  cout << "\nвозвраст пациента, полных лет: ";
  cin >> patOldYears;
  cout << "\nвес пациента, кг: ";
  cin >> patMass;
  cout << "\nрост пациента, см: ";
  cin >> patHigh;
  cout << "\nПациаент мужчина-1, женщина-0 :";
  cin >> patSex;
  cout << "\nПодсчет идеального веса\na - по формуле Брока\nb - по индексу массы тела\nc - по индексу "
       << "массы тела с учетом вораста\n";

  cin.clear();  cin >> algProg;

/* проверка введенных данных
 * за основу взял таблицу из задания
*/
  errPatData = false;
  if(
     (patOldYears <= 19 || patOldYears > 100) || //от 19 до 100 лет - норма
     (patMass < 45 || patMass > 125) || //от 45 до 125 килограмм - норма
     (patHigh < 140 || patHigh > 215) //от 140 до 215 сантиметров - норма
     ){
    errPatData = true;
    cout << "Были введены неверные данные:\n";
    if(patOldYears <= 19 || patOldYears > 100)
      cout << "Неверный возраст пациента -->" << patOldYears << endl;

    if(patMass < 45 || patMass > 125)
      cout << "Неверный вес пациента -->" << patMass << endl;

    if(patHigh < 140 || patHigh > 215)
      cout << "Неверный рост пациента -->" << patHigh << endl;
    exit(1);
  }

  /*
   * формула Брока
   * мужчины вес = (рост см - 100) * 0.9
   * женщины вес = (рост см - 100) * 0.85
  */

//расчеты общий расчет по имеющимся данным
  if(algProg == 'a'){
    ((patSex)?brokCoef = 0.9:brokCoef = 0.89);//male female
    //расчет по формуле Брока
    patMassAlg = patMassBroke();
    answer();
    answerBroke(patMassAlg,patMass);//ответ на экран

  }else if(algProg == 'b'){
    /*
     * вес по индексу массы тела
     * индекс = вес, кг/(рост, м)2
     * вес,кг = индекс * рост,м2
    */
    if(patHigh != 0){//проверка на 0, на всякий случай
      indPatHigh = (float)patHigh / 100;//перевод в метры
      index = (float)patMass / (indPatHigh * indPatHigh);
      answer();
      answerIndMass(index);//ответ на экран
    }else{
      cout << "Рост пациента не может быть нулевым!\n";
    }
  }else if(algProg == 'c'){
    /*
     * вес по индексу массы тела и возрасту
    */
    selYears(patSex,patOldYears);//индекс в зависимости от возраста и пола пациента
    answer();
    answerIndMassOldYear(indexOldYears);
      if((patMass - normMass1) > 0){//избыточный вес
        cout << "Вес необходимо сбросить на " << (patMass - normMass1) << " килограмм.";
        cout << "\nНормальный вес пациента " << normMass1 << " килограмм." << endl;
      }else if((patMass - normMass1) < 0){//недостаточный вес
        cout << "Вес необходимо набрать на " << (normMass1 - patMass) << " килограмм.";
        cout << "\nНормальный вес пациента " << normMass1 << " килограмм." << endl;
      }else{
        cout << "Вес пациента в пределах нормы!\n";
      }
    }else{
    cout << "\nБыло введено значение отличное от a, b, c!!!\n";
//}

  }
#endif

//Задание 2. Вывод основных размеров типов даных С++.

#if 1
//char
  cout << "bool    : " << sizeof(bool) << " byte" << endl;
  cout << "int     : " << sizeof(int) << " bytes" << endl;
  cout << "char    : " << sizeof(char) << " bytes" << endl;
  cout << "wchar_t : " << sizeof(wchar_t) << " bytes" << endl;
  cout << "double  : " << sizeof(double) << " bytes" << endl;
  cout << "float   : " << sizeof(float) << " bytes" << endl;
  cout << "long    : " << sizeof(long) << " bytes" << endl;
  cout << "void    : " << sizeof(void) << " bytes" << endl;//особый тип, пустой
  cout << '\n';

  //0-false 1..255-true
  bool lYes{true}, lNo{false};
  cout.setf(ios::boolalpha);
  cout << "<BOOL> logical от " << lYes << " до " << lNo << endl;
  printf("<BOOL> decimal/hexadecimal от %X до %X\n",lYes,lNo);
  cout << "<BOOL> binary от " << (int)lYes << " до " << (int)lNo << endl;
  cout << "\n";

  //встроенные константы для типов -128 до 127
  char cMin{CHAR_MIN};
  char cMax{CHAR_MAX};
  cout << "<CHAR> decimal от " << (int)cMin << " до " << (int)cMax << endl;
  printf("<CHAR> hexadecimal от %X до %X\n",cMin,cMax);//FFFFFF80-cMin 7F-cMax
  //указываем размер шаблона 8 бит и указываем число для создаваемого объекта
  bitset<sizeof(char)*8> bCharMin((int)cMin);
  bitset<sizeof(char)*8> bCharMax((int)cMax);
  cout << "<CHAR> binary от " << bCharMin << " до " << bCharMax << endl;
  cout << "\n";

  //встроенные константы 255
  unsigned char ucMax{UCHAR_MAX};
  cout << "<UNSIGNED CHAR> decimal от " << 0 << " до " << (int)ucMax << endl;
  printf("<UNSIGNED CHAR> hexadecimal от %X до %X\n",0,cMax);
  bitset<sizeof(char)*8> uChar((int)ucMax);
  cout << "<UNSIGNED CHAR> binary от " << 0 << " до " << uChar << endl;
  cout << "\n";

  //встроенные константы -32768 32767
  int iMin{SHRT_MIN};
  int iMax{SHRT_MAX};//аналогичен int
  cout << "<INT> decimal от " << iMin << " до " << iMax << endl;
  printf("<INT> hexadecimal от %X до %X\n",iMin,iMax);//
  bitset<sizeof(int)*8> bIntMin((int)iMin);
  bitset<sizeof(int)*8> bIntMax((int)iMax);
  cout << "<INT> binary от " << bIntMin << " до " << bIntMax << endl;
  cout << "\n";

  //встроенные константы unsgined long long как самое большое данное, помоему
  unsigned long long ullMax{ULLONG_MAX};//18,446,744,073,709,551,615 (0xffffffffffffffff)
  cout << "<UNSIGNED LONG LONG> decimal от " << 0 << " до " << ullMax << endl;
  printf("<UNSIGNED LONG LONG> hexadecimal от %X до %X\n",0,ullMax);//
  bitset<sizeof(unsigned long long)*8> bullMax((unsigned long long)ullMax);
  cout << "<UNSIGNED LONG LONG> binary от " << 0 << " до " << bullMax << endl;
  cout << "\n";

#endif
  return 0;
}

