/*
* Лабораторная работа No2
* Исследование ввода-вывода типов данных стандартной библиотеки С++
*
* Developer: Половян КА 318OOP/C++
* OS: Windows 10
* locale (кодировка): UTF-8
*/

//выполняемя задача TASK_1,2,3...11
#define TASK_0
//подключаем библиотеки
//для калькулятора
#include <string>
#include <sstream>

#include <iostream>
#include <bitset>//для вывода в бинарной форме
#include <math.h>

#if defined TASK_6
#define func (cout << "hello\n");

#define print_value(n) \
  do { \
    printf(#n"=",n); \
    cout.setf(ios::boolalpha); \
    cout \
      << ( (n==true)?true:false) << " "; \
  }while(0)

#define print_val_numb(n) \
  do { \
    printf(#n"=%d ",n); \
  }while(0)

//enum{NO=false,YES=true};
//const bool bLogicA = NO; const bool bLogicB = YES;
//const bool bLogicC = NO; const bool bLogicD = NO;
//const bool bLogicE = NO;
#endif

using namespace std;

int main(int argc, char *argv[])
{
//Задание 1.“Калькулятор для расчета идеального веса“.
#if defined TASK_1
  //используемые переменные camelCase
  int patOldYears;//возвраст пациента
  int patMass;//вес пациента
  int patMassAlg;//вес пациента по расчету
  bool patSex;//пол пациента
  int patHigh;//рост пациента
  char algProg;//выбор варианта расчета
  float index;//индекс массы тела
  float normMass1, normMass2;//нормы весов
  float indPatHigh;//рост пациента в метрах
  float brokCoef;
  float indexOldYears;
  enum{HighConst=100};

#define patMassBroke() (((patHigh) - (HighConst)) * (brokCoef))
#define viewBroke() (cout<<"масса пациента "<<(patMass)<<" масса по Броку "<<(patMassAlg)<<endl)
  //вывод результатов
#define answer() \
  do { \
    cout << "\nБыли введены следующие данные:\n"; \
    cout << "Пациент: " << ((patSex)?" Мужчина ":" Женщина ") \
         << " возраст " << (patOldYears) << " лет " \
         << " вес пациента " << (patMass) << " килограмм " \
         << " рост пациента " << (patHigh) << " сантиметров\n"; \
  }while(0)
#define answerBroke(patMassAlg, patMass) \
  do { \
    cout << "Вариант расчета формула Брока вес " << (patMassAlg) << " килограмм.\n"; \
    if((patMassAlg) < (patMass)){ \
      cout << "Вес необходимо сбросить на " << ((patMass) - (patMassAlg)) << " килограмм\n"; \
    }else if((patMass) < (patMassAlg)){ \
      cout << "Вес необходимо набрать на " << ((patMassAlg) - (patMass)) << " килограмм \n"; \
    } }while(0)

enum{indMass16=16,indMass25=25,indMass30=30,indMass35=35,indMass40=40};
//const float indMass18_5=18.5;
#define answerIndMass(index) \
  do { \
  const float indexNorm1 = 18.5; \
  const float indexNorm2 = 25; \
  cout << "Вариант расчета индекс массы тела " << (index) << "\n"; \
  if((index) < indMass16){ \
    cout << "\nВыраженный дифицит массы тела."; \
  }else if(((index) > indMass16) && ((index) < indexNorm1)){ \
    cout << "\nНедостаточная (дефицит) масса тела."; \
  }else if(((index) > indexNorm1) && ((index) < indexNorm2)){ \
    cout << "\nНорма."; \
  }else if(((index) > indexNorm2) && ((index) < indMass30)){ \
    cout << "\nИзбыточная масса тела (предожирение)."; \
  }else if(((index) > indMass30) && ((index) < indMass35)){ \
    cout << "\nОжирение первой степени"; \
  }else if(((index) > indMass35) && ((index) < indMass40)){ \
    cout << "\nОжирение второй степени"; \
  }else if((index) > indMass40){ \
    cout << "\nОжирение третьей степени (морбидное)"; \
  } \
cout << "\nВариант расчета " << "по индексу массы тела (индекс массы тела " << (index) \
     << ") вес " << (patMass) << " килограмм.\n"; \
normMass1 = (indexNorm1 * ((indPatHigh) * (indPatHigh))); \
normMass2 = (indexNorm2 * ((indPatHigh) * (indPatHigh))); \
if((index) < 18.5){ \
  cout << "Вес необходимо набрать на " << ((normMass1) - (patMass)) << " килограмм.\n"; \
}else if((index) > 25){ \
  cout << "Вес необходимо сбросить на " << ((patMass) - (normMass2)) << " килограмм.\n"; \
}else{ \
  cout << "Вес пациента в пределах нормы!\n"; \
} \
  }while(0)

enum{patYr19=19,patYr24=24,patYr25=25,patYr34=34,patYr35=35,patYr44=44,patYr45=45,patYr54=54,patYr55=55};
const float indYr21_4=21.4,indYr19_5=19.5,//коэффициенты в зависимости от возраста и пола пациента
            indYr21_6=21.6,indYr23_2=23.2,
            indYr22_9=22.9, indYr23_4=23.4,
            indYr25_8=25.8, indYr25_2=25.2,
            indYr26_6=26.6, indYr27_3=27.3;
#define selYears(patSex,patOldYears) \
  do { \
  cout << "Возраст " << (patOldYears)  << " лет " << ((patSex)?" Мужчина ":" Женщина "); \
  if(((patOldYears) >= patYr19) && ((patOldYears) <= patYr24)){ \
      ((patSex)?indexOldYears = indYr21_4:indexOldYears = indYr19_5); \
    }else if(patOldYears >= patYr25 && patOldYears <= patYr34){ \
      ((patSex)?indexOldYears = indYr21_6:indexOldYears = indYr23_2); \
    }else if(patOldYears >=patYr35 && patOldYears <=patYr44){ \
      ((patSex)?indexOldYears = indYr22_9:indexOldYears = indYr23_4); \
    }else if(patOldYears >=patYr45 && patOldYears <=patYr54){ \
      ((patSex)?indexOldYears = indYr25_8:indexOldYears = indYr25_2); \
    }else if(patOldYears > patYr55){ \
      ((patSex)?indexOldYears = indYr26_6:indexOldYears = indYr27_3); \
    } \
  }while(0)

#define answerIndMassOldYear(indexOldYears) \
  do { \
  indPatHigh = ((float)(patHigh) / HighConst); \
    normMass1 = (indexOldYears * ((indPatHigh) * (indPatHigh))); \
  } \
  while(0)

//основной код
  cout << "Программа Калькулятор для расчета идеального веса.\n";

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
       << "массы тела с учетом вораста\nВыберите вариант расчета: ";

  cin.clear();  cin >> algProg;
//ограничения по вводимым данным
enum{patYearsMin=19,patYearsMax=100,patMassMin=45,patMassMax=125,patHighMin=140,patHighMax=215};
//проверка введенных данных
  if(
     (patOldYears <= patYearsMin || patOldYears > patYearsMax) || //от 19 до 100 лет - норма
     (patMass < patMassMin || patMass > patMassMax) || //от 45 до 125 килограмм - норма
     (patHigh < patHighMin || patHigh > patHighMax) //от 140 до 215 сантиметров - норма
     ){
//    errPatData = true;
    cout << "Были введены неверные данные:\n";
    if(patOldYears <= patYearsMin || patOldYears > patYearsMax)
      cout << "Неверный возраст пациента -->" << patOldYears << endl;

    if(patMass < patMassMin || patMass > patMassMax)
      cout << "Неверный вес пациента -->" << patMass << endl;

    if(patHigh < patHighMin || patHigh > patHighMax)
      cout << "Неверный рост пациента -->" << patHigh << endl;
    exit(1);
  }

  /*
   * формула Брока
   * мужчины вес = (рост см - 100) * 0.9
   * женщины вес = (рост см - 100) * 0.85
  */
//enum{coefMaleBrok=0.9,coefFemaleBrok=0.89};
const float coefMaleBrok=0.9, coefFemaleBrok=0.89;
//расчеты общий расчет по имеющимся данным

  cout.setf(ios::fixed);cout.precision(1);//точность до 1 знаков после запятой

  if(algProg == 'a'){
    ((patSex)?brokCoef = coefMaleBrok:brokCoef = coefFemaleBrok);//male female
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
      indPatHigh = (float)patHigh / HighConst;//перевод в метры
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
                                 //в переменную indexOldYears
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
#if defined TASK_2
  enum{BYTE_SIZE=8};
//type:____bytes
  cout << "bool    : " << sizeof(bool) << " byte" << endl;
  cout << "int     : " << sizeof(int) << " bytes" << endl;
  cout << "char    : " << sizeof(char) << " bytes" << endl;
  cout << "wchar_t : " << sizeof(wchar_t) << " bytes" << endl;
  cout << "double  : " << sizeof(double) << " bytes" << endl;
  cout << "float   : " << sizeof(float) << " bytes" << endl;
  cout << "long    : " << sizeof(long) << " bytes" << endl;
  cout << "void    : " << sizeof(void) << " bytes" << endl;//особый тип, пустой
  cout << '\n';

  //модификатор unsigned/signed; short/long/long long
  //unsigned int:____bytes;
  cout << "unsigned char          : " << sizeof(unsigned char) << " bytes " << endl;
  cout << "signed char            : " << sizeof(signed char) << " bytes " << endl;

  cout << "int                    : " << sizeof(int) << " bytes " << endl;
  cout << "signed int             : " << sizeof(signed int)  << " bytes " << endl;
  cout << "unsigned int           : " << sizeof(unsigned int)  << " bytes " << endl;

  cout << "short int              : " << sizeof(short int) << " bytes " << endl;
  cout << "signed short int       : " << sizeof(signed short int)  << " bytes " << endl;
  cout << "unsigned short int     : " << sizeof(unsigned short int)  << " bytes " << endl;

  cout << "long int               : " << sizeof(long int) << " bytes " << endl;
  cout << "signed long int        : " << sizeof(signed short int)  << " bytes " << endl;
  cout << "unsigned long int      : " << sizeof(unsigned short int)  << " bytes " << endl;
  cout << "signed long long int   : " << sizeof(signed long long int)  << " bytes " << endl;
  cout << "unsigned long long int : " << sizeof(unsigned long long int)  << " bytes " << endl;

  cout << "long double            : " << sizeof(long double) << " bytes " << endl;

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
  bitset<sizeof(char)*BYTE_SIZE> bCharMin((int)cMin);
  bitset<sizeof(char)*BYTE_SIZE> bCharMax((int)cMax);
  cout << "<CHAR> binary от " << bCharMin << " до " << bCharMax << endl;
  cout << "\n";

  //встроенные константы 255
  unsigned char ucMax{UCHAR_MAX};
  cout << "<UNSIGNED CHAR> decimal от " << 0 << " до " << (int)ucMax << endl;
  printf("<UNSIGNED CHAR> hexadecimal от %X до %X\n",0,cMax);
  bitset<sizeof(char)*BYTE_SIZE> uChar((int)ucMax);
  cout << "<UNSIGNED CHAR> binary от " << 0 << " до " << uChar << endl;
  cout << "\n";

  //встроенные константы -32768 32767
  int iMin{SHRT_MIN};
  int iMax{SHRT_MAX};//аналогичен int
  cout << "<INT> decimal от " << iMin << " до " << iMax << endl;
  printf("<INT> hexadecimal от %X до %X\n",iMin,iMax);//
  bitset<sizeof(int)*BYTE_SIZE> bIntMin((int)iMin);
  bitset<sizeof(int)*BYTE_SIZE> bIntMax((int)iMax);
  cout << "<INT> binary от " << bIntMin << " до " << bIntMax << endl;
  cout << "\n";

  //встроенные константы unsgined long long как самое большое данное, помоему
  unsigned long long ullMax{ULLONG_MAX};//18,446,744,073,709,551,615 (0xffffffffffffffff)
  cout << "<UNSIGNED LONG LONG> decimal от " << 0 << " до " << ullMax << endl;
  printf("<UNSIGNED LONG LONG> hexadecimal от %X до %X\n",0,ullMax);//
  bitset<sizeof(unsigned long long)*BYTE_SIZE> bullMax((unsigned long long)ullMax);
  cout << "<UNSIGNED LONG LONG> binary от " << 0 << " до " << bullMax << endl;
  cout << "\n";

#endif

//Задание 3. Среднее арифметическое из введенных 10 чисел.
#if defined TASK_3
  //используемые переменные
  float fnumbFloat;
  float fnumbCin;
  enum{COUNT=10};
  bool errCin=false;//флаг ошибки ввода
  //в цикле for вводим числа
  for(int i=0; i < COUNT; i++){

       cout << "Введите (десятичное) число " << i+1 << " : ";
      cin >> fnumbCin;
      if(cin.fail()){
          errCin=true;
          break;
      }

      fnumbFloat += fnumbCin; //суммируем
      cin.clear();//очищаем буфер
  }

  if(!errCin)
   cout << "Сумма введенных чисел равна " << fnumbFloat << endl;
  else
      cout << "Was Error CIN!!!";

#endif

//Задание 4. Экспоненциальная запись числа.
#if defined TASK_4
  cout << "Число 34.50 " << " экспоненциальная запись 3.450e1" << " 4 значащих числа" << endl;
  cout << "Запись средствами С++ " << uppercase << scientific << 34.50 << endl;

  cout << "Число 0.004000 " << " экспоненциальная запись 4.000e-3 " << "4 значащих числа" << endl;
  cout << "Запись средствами С++ " << uppercase << scientific << 0.004000 << endl;

  cout << "Число 123.005 " << " экспоненциальная запись 1.23005e2" << " 6 значащих чисел" << endl;
  cout << "Запись средствами С++ " << uppercase << scientific << 123.005 << endl;

  cout << "Число 146000 " << " экспоненциальная запись 1.46e5" << " 3 значащих числа" << endl;
  cout << "Запись средствами С++ " << uppercase << scientific << 146000 << endl;
  return 0;

#endif

//Задание5.1. Логические выражения.
#if defined TASK_5
  // (true && true) || false
  // (true && true) = true
  // true || false = true
  cout << "Логическое выражение (true && true) || false --> " << (((true && true) || false)?"true":"false") << endl;

  // (false && true) || true
  // (false && true) = false
  // false || true = true
  cout << "Логическое выражение (false && true) || true --> " << (((false && true) || true)?"true":"false") << endl;

  // (false && true) || false || true
  // (false && true) = false
  // (false || false || true) = true
  cout << "Логическое выражение (false && true) || false || true --> " << (((false && true) || false || true)?"true":"false") << endl;

  // (5 > 6 || 4 > 3) && (7 > 8)
  // (5 > 6 || 4 > 3) --> (false || true) = true
  // (7 > 8) --> false
  // (false || true) && false --> false
  cout << "Логическое выражение (5 > 6 || 4 > 3) && (7 > 8) --> " << (((5 > 6 || 4 > 3) && (7 > 8))?"true":"false") << endl;

  // !(7 > 6 || 3 > 4)
  // 7 > 6 --> true
  // 3 > 4 --> false
  // !(7 > 6 || 3 > 4) --> !(true || false) --> !(true) --> false
  cout << "Логическое выражение !(7 > 6 || 3 > 4) --> " << ((!(7 > 6 || 3 > 4))?"true":"false") << endl;

#endif

//Задание 5.2. Логические выражения.
#if defined TASK_6
  enum{NO=false,YES=true};
  const bool bLogicA(NO); const bool bLogicB(YES);//исрользуем один раз
  const bool bLogicC(NO); const bool bLogicD(YES);
  const bool bLogicE(NO); const bool bLogicF(NO);

cout << "Заданные переменные:" << endl;
print_value(bLogicA);print_value(bLogicB);print_value(bLogicC);print_value(bLogicD);print_value(bLogicE);
//( (_&&_) || (!_) && (_||_) ) --> ((bLogicA && bLogicB) || (!bLogicC) && (bLogicD || bLogicE)) -->
//                                 ( (false && true) || (!false) && (false || false) ) -->
//                                 (      (false)    ||  (true)  && (false) ) --> false
cout << "\nЛогическое выражение: ((bLogicA && bLogicB) || (!bLogicC) && (bLogicD || bLogicE))\n"
     << "Результат: ";
cout.setf(std::ios::boolalpha);
bool bAnsLogic = (
                  ( (!bLogicC) && (bLogicD || bLogicE) ) ||
                  (bLogicA && bLogicB)
                                                         );
  cout << ((bool)(bAnsLogic)?"true\n":"false\n");

cout << "\nЗаданные переменные:" << endl;
print_value(bLogicA);print_value(bLogicB);print_value(bLogicC);print_value(bLogicD);print_value(bLogicE);
//((_ &&_ ) || (_&&_) || (!_)) --> ( (bLogicA && bLogicB) || (bLogicC && bLogicD) || (!bLogicE) ) -->
//                                 ( (false && true) || (false && true) || (!false)) -->
//                                 ( false || false || true ) --> true
cout << "\nЛогическое выражение: ((bLogicA && bLogicB) || (bLogicC && bLogicD) || (!bLogicE))\n"
     << "Результат: ";
cout.setf(std::ios::boolalpha);
bAnsLogic = (
             (bLogicC && bLogicD) || (!bLogicE) ||
             (bLogicA && bLogicB)
      );
cout << ((bool)(bAnsLogic)?"true\n":"false\n");

cout << "\nЗаданные переменные:" << endl;
print_value(bLogicA);print_value(bLogicB);print_value(bLogicC);print_value(bLogicD);print_value(bLogicE);
print_value(bLogicF);

//((_ || _) && (_ || _) && (_||_)) --> ( (bLogicA || bLogicB) && (bLogicC || bLogicD) && (bLogicE || bLogicF) ) -->
//                                     ( (false || true) && (false || true) && (false || false) ) -->
//                                     ( (true && true && false)) --> false
cout << "\nЛогическое выражение: ((bLogicA || bLogicB) && (bLogicC || bLogicD) && (bLogicE || bLogicF))\n"
     << "Результат: ";
cout.setf(std::ios::boolalpha);
bAnsLogic = (
             (bLogicA || bLogicB) && (bLogicC || bLogicD) && (bLogicE || bLogicF)
            );
cout << ((bool)(bAnsLogic)?"true\n":"false\n");

enum{numb1=2,numb2=4,numb3=1,numb4=-3,numb5=7,numb6=0};
const int numConstA=numb1; const int numConstB=numb2; const int numConstC=numb3;
const int numConstD=numb4; const int numConstE=numb5; const int numConstF=numb6;
cout << "\nЗаданные переменные:" << endl;
print_val_numb(numConstA);print_val_numb(numConstB);print_val_numb(numConstC);
print_val_numb(numConstD);print_val_numb(numConstE);print_val_numb(numConstF);
//((_ >_) && (_<_) && (_!=_)) --> ( (numConstA > numConstB) && (numConstC < numConstD) && ( numConstE != numConstF)) -->
//                                     ( 2     >      4 )   && (    1     <     3    ) && (      7    !=     0    ) -->
//                                     ( false ) && (false ) && ( true ) --> false
cout << "\nЛогико-арифметическое выражение: (numConstA > numConstB) && (numConstC < numConstD) && ( numConstE != numConstF)\n"
     << "Результат: ";
cout.setf(std::ios::boolalpha);
bAnsLogic = (
             (numConstA > numConstB) && (numConstC < numConstD) && ( numConstE != numConstF)
            );
cout << ((bool)(bAnsLogic)?"true\n":"false\n");
#endif


//Задание 5.3. Законы де Моргана.
#if defined TASK_7
  // правильность законов де Моргана
  // не (a и b) = (не a) или (не b)
  // !(logicA && logicB) == (!logicA) || (!logicB)
  // используемые переменные
  bool logicA, logicB;
  cout.setf(std::ios::boolalpha);

  // !(F /\ F)==!F \/ !F --> T==T\/T --> T == T
  logicA = false; logicB = false;
  cout<<"!("<<logicA<<"&&"<<logicB<<")==(!"<<logicA<<")||(!"<<logicB<<") --> "
       << (!(logicA && logicB)?"true":"false") << " == "
       << ((!logicA) || (!logicB)?"true":"false");
  cout << "\n";

  // !(T /\ F)==!T \/ !F --> T==F\/T --> T == T
  logicA = true; logicB = false;
  cout<<"!("<<logicA<<"&&"<<logicB<<")==(!"<<logicA<<")||(!"<<logicB<<") --> "
       << (!(logicA && logicB)?"true":"false") << " == "
       << ((!logicA) || (!logicB)?"true":"false");
  cout << "\n";

  // !(F /\ T)==!F \/ !T --> T==T\/F --> T == T
  logicA = false; logicB = true;
  cout<<"!("<<logicA<<"&&"<<logicB<<")==(!"<<logicA<<")||(!"<<logicB<<") --> "
       << (!(logicA && logicB)?"true":"false") << " == "
       << ((!logicA) || (!logicB)?"true":"false");
  cout << "\n";

  // !(T /\ T)==!T \/ !T --> F==F\/F --> F == F
  logicA = true; logicB = true;
  cout<<"!("<<logicA<<"&&"<<logicB<<")==(!"<<logicA<<")||(!"<<logicB<<") --> "
       << (!(logicA && logicB)?"true":"false") << " == "
       << ((!logicA) || (!logicB)?"true":"false");
  cout << "\n";

  cout << "-------------------------------------------------------------------------\n";
  // не (a или b) = (не a) и (не b)
  // !(logicA || logicB) == (!logicA) && (!logicB)
  // !(F \/ F)==!F /\ !F --> T==T/\T --> T == T
  logicA = false; logicB = false;
  cout<<"!("<<logicA<<"||"<<logicB<<")==(!"<<logicA<<")&&(!"<<logicB<<") --> "
       << (!(logicA || logicB)?"true":"false") << " == "
       << ((!logicA) && (!logicB)?"true":"false");
  cout << "\n";

  // !(T \/ F)==!T /\ !F --> F==F/\T --> F == F
  logicA = true; logicB = false;
  cout<<"!("<<logicA<<"||"<<logicB<<")==(!"<<logicA<<")&&(!"<<logicB<<") --> "
       << (!(logicA || logicB)?"true":"false") << " == "
       << ((!logicA) && (!logicB)?"true":"false");
  cout << "\n";

  // !(F \/ T)==!F /\ !T --> F==T/\F --> F == F
  logicA = false; logicB = true;
  cout<<"!("<<logicA<<"||"<<logicB<<")==(!"<<logicA<<")&&(!"<<logicB<<") --> "
       << (!(logicA || logicB)?"true":"false") << " == "
       << ((!logicA) && (!logicB)?"true":"false");
  cout << "\n";

  // !(T \/ T)==!T /\ !T --> F==F/\F --> F == F
  logicA = true; logicB = true;
  cout<<"!("<<logicA<<"||"<<logicB<<")==(!"<<logicA<<")&&(!"<<logicB<<") --> "
       << (!(logicA || logicB)?"true":"false") << " == "
       << ((!logicA) && (!logicB)?"true":"false");
  cout << "\n";

#endif

//Задание 5.4. Логико-арифметические выражения.
#if defined TASK_8
  int x,y,z,v;
  bool logicValue;
  cout << "Введите числа x y z v: ";
  cin >> x >> y >> z >> v;
  cout << "Были введены следующие числа x=" << x << " y=" << y << " z=" << z << " v=" << v << endl;

/*
 * ранее введенное значение в x "стирается" оператором присваивания "=" x = 12
*/
  x = 3 + 4 + 5;
  cout << "Результат:\nx=" << x << " y=" << y << " z=" << z << " v=" << v << endl;

/*
 * значение введенное в z присваивается переменным y и x
*/
  x = y = z;
  cout << "Результат:\nx=" << x << " y=" << y << " z=" << z << " v=" << v << endl;

  z *= ++y + 5;//умножение содержимого z на инкремент y+1 + 5
  cout << "Результат:\nx=" << x << " y=" << y << " z=" << z << " v=" << v << endl;

  //в данном случае при введенных значениях 3 4 27 4 \
  x=3(0011) y=4(0100) z=27(11011) v=4(0100) logicValue=1(true) \
  x=2(0010) y=2(0010) z=2(0010) v=2(0010) logicValue=1(true) \
  то есть при любых значениях отличного от нуля будет происходить преобразование компилятором \
  [ячейка]=1,2,3,...n --> true, и если [ячейка]=0 --> false \
  Приоритет логических операций 1.действия в скобках 2.инверсия 3.конъюнкция/\ 4.дизъюнкция\/. \
  x || y && z || v = 0, когда все 0 \

  logicValue = x || y && z || v;
  cout.setf(std::ios::boolalpha);
  cout << "Результат:\nx=" << x << " y=" << y << " z=" << z << " v=" << v
       << " logicValue=" << logicValue <<  endl;


//  logicValue = 2 || 0 && 0 || 9;
//  cout << "logicValue=" << logicValue << endl;

//  logicValue = 0 || (2 && 3) || 0;
//  cout << "logicValue=" << logicValue << endl;

//  logicValue = (2 || 0) && (0 || 9);
//  cout << "logicValue=" << logicValue << endl;

//  logicValue = 0 || 0 && 0 || 0;
//  cout << "logicValue=" << logicValue << endl;

#endif

//Задание 5.5.Сдвиг числа влево.
#if defined TASK_9
  enum{BYTE_SIZE=8};
  unsigned int numbCin, numbShift, resultNumb;
  cout << "Введите целое число от 0 до " << (pow(2,4)) << ":";
  cin
      >> numbCin;

  cout << "Введите целое число на которое необходимо сдвинуть " << numbCin << " влево:";
  cin
      >> numbShift;

  if(numbCin != 0 && numbCin <= 16 && !cin.fail()){
    cout << "Число " << numbCin << " сдвиг влево на " << numbShift << endl;
    resultNumb = (numbCin << numbShift);
    cout << "Dec   : " << resultNumb << endl;
    bitset<sizeof(unsigned int)*BYTE_SIZE> binNumb(resultNumb);
    cout << "Binary: " << binNumb << endl;
    cout.unsetf(ios::dec);cout.setf(ios::hex);
    cout << "Hex   : " << resultNumb << endl;
    cout.unsetf(ios::hex);cout.setf(ios::oct);
    cout << "Oct   : " << resultNumb << endl;
}
  else{
    cout << "Не выполняется условие от 0 до 16 или ошибка ввода!\n";
    exit(0);
  }

#endif

//Задание  6.Приоритет выражений и ассоциатовности.
/*
 * Приоритет выражений возведение в степень ^ здесь выжны скобки!
 * умножение *
 * деление /
 * сложение +
 * вычитание -
 * int res = a | b >> 1;
 * int res = a /b* k;
*/
#if defined TASK_10
  enum{BYTE_SIZE=8};
  // --> a + ((b * 1) - (128/5)) --> (a + (b * 1)) - (128/5));
  int a,b,res,leftRes,rightRes,randNumbA,randNumbB;

    int beg = 1000000; int end = 0;
    int count = 0;
    bool ind;
  while(true){//count != 128 count <= 128
    randNumbA = rand() % (beg - end + 1) + end;//случайное в пределах от 0 до 1000000
    randNumbB = rand() % (beg - end + 1) + end;
    res = randNumbA + randNumbB * 1 - 128 / 5;
    leftRes = randNumbA + ((randNumbB * 1) - (128/5));
    rightRes = (randNumbA + (randNumbB * 1)) - (128/5);
    if((res == leftRes) && (res == rightRes) && (leftRes == rightRes)){
      ind = true;
      ++count;
    }else{
      ind = false;
    }
    if(count > 1000000 || !ind)break;
  }
  cout << "count=" << count << endl;

//  res = a + b * 1 - 128 / 5;
//  leftRes = a + ((b * 1) - (128/5));
//  rightRes = (a + (b * 1)) - (128/5);
  if(count == 1000001 && ind){
    cout << "Запись выражений одинакова\n";
  }else{
    cout << "Запись выражений не одинакова\n";
  }

//int res = a | b >> 1; у операций << >> больший приоритет
  a=4; b=6;//signed
  unsigned int newA = static_cast<unsigned int>(a);cout << "a=" << newA << endl;
  unsigned int newB = static_cast<unsigned int>(b);cout << "b=" << newB << endl;
  unsigned int newRes = static_cast<unsigned int>(res);cout << "res=" << newRes << endl;
  unsigned int newleftRes = static_cast<unsigned int>(leftRes);
  unsigned int newrightRes = static_cast<unsigned int>(rightRes);

  //b=0000110 6 \
    a=0000100 4 \
    b >> 1 --> 00001100 3 \
    a | b --> \
    b 00000011 \
    a 00000100 \
  res 00000111 7 \

  bitset<sizeof(unsigned int)*BYTE_SIZE> binNumA(newA);
  cout << "bin a=" << binNumA << endl;

  bitset<sizeof(unsigned int)*BYTE_SIZE> binNumB(newB);
  cout << "bin b=" << binNumB << endl;

  bitset<sizeof(unsigned int)*BYTE_SIZE> binNumC(newA | (newB >> 1));
  cout << " op | " << binNumC << endl;

  newRes = newA | newB >> 1;//тут компилятор считает без скобок
  newleftRes = (newA | newB) >> 1;//тут мы указываем как считать
  newrightRes = newA | (newB >> 1);//более правильная запись

  //записи newA | newB >> 1    и    newA | (newB >> 1) --> одинаковы
  //(newA | newB) >> 1 --> отлична от приведенных выше, с ошибкой

  cout << "res=" << newRes << " leftRes=" << newleftRes << " rightRes=" << newrightRes << endl;

  unsigned int k = 2;
  a = 8; b = 4;
  //int res = a / b * k; \
                    (8/4)*2              8/(4*2)             8/4*2 \
  приоритет деление затем умножение      ошибка              компилятор \

  cout << "res=" << ((a/b)*k) << " " << (a/(b*k)) << " " << (a/b*k) << endl;
#endif

#if defined TASK_11
//в самом простом виде
  cout << "Программа Калькулятор.\nВыполняемые оперции + - * /\n"
       << "Пример использования: 2+2 далее необходимо ввести ввод!\n"
       << "Останов программы <число>s пример: 0s ввод\n";

  //используемые переменные
  string buffer;
  char operation;
  double a, b;
  double answ;
  bool err = true;
  bool _calc = true;

  while(_calc){//пока не будет команда s
      cout << "Введите выражение:";
      cin >> buffer;
      stringstream(buffer) >> a >> operation >> b;//читаем переменные со строки

      if((operation == '/' || operation == '*' || operation == '+' || operation == '-' || operation == 's')){
          switch(operation){
          case '/':{
              if(b != 0){
                  err = false;
                  answ = a / b;
              }else{
                  cout << "error! operand b=0!" << '\n';
                  err = true;
              }
              break;
          }
          case '*':{
              err = false;
              answ = a * b;
              break;
          }
          case '+':{
              err = false;
              answ = a + b;
              break;
          }
          case '-':{
              err = false;
              answ = a - b;
              break;
          }
          case 's':{
              err = true;
              _calc = false;
              cout << "Program stop!\n";
              break;
          }
          default:cout << "No operation!" << '\n';
          }//switch
      }else{
          cout << "Wrong expression!";
      }

      if(!err){
          cout << "answer: ";
          cout << a << operation << b << '=' << answ << '\n';}
  }

#endif

  return 0;
}
