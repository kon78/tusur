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

//выполняемя задача TASK_1,2,3...N
#define TASK_1
//подключаем библиотеки
//для калькулятора
#include <string>
#include <sstream>

#include <iostream>
#include <bitset>//для вывода в бинарной форме

using namespace  std;
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

#define answerIndMass(index) \
  do { \
  cout << "Вариант расчета индекс массы тела " << (index) << "\n"; \
  if((index) < 16){ \
    cout << "\nВыраженный дифицит массы тела."; \
  }else if(((index) > 16) && ((index) < 18.5)){ \
    cout << "\nНедостаточная (дефицит) масса тела."; \
  }else if(((index) > 18.5) && ((index) < 25)){ \
    cout << "\nНорма."; \
  }else if(((index) > 25) && ((index) < 30)){ \
    cout << "\nИзбыточная масса тела (предожирение)."; \
  }else if(((index) > 30) && ((index) < 35)){ \
    cout << "\nОжирение первой степени"; \
  }else if(((index) > 35) && ((index) < 40)){ \
    cout << "\nОжирение второй степени"; \
  }else if((index) > 40){ \
    cout << "\nОжирение третьей степени (морбидное)"; \
  } \
cout << "\nВариант расчета " << "по индексу массы тела (индекс массы тела " << (index) \
     << ") вес " << (patMass) << " килограмм.\n"; \
const float indexNorm1 = 18.5; \
const float indexNorm2 = 25; \
normMass1 = (indexNorm1 * ((indPatHigh) * (indPatHigh))); \
normMass2 = (indexNorm2 * ((indPatHigh) * (indPatHigh))); \
if((index) < 18.5){ \
  cout << "Вес необходимо набрать на " << ((normMass1) - (patMass)) << " килограмм."; \
}else if((index) > 25){ \
  cout << "Вес необходимо сбросить на " << ((patMass) - (normMass2)) << " килограмм."; \
}else{ \
  cout << "Вес пациента в пределах нормы!\n"; \
} \
  }while(0)

#define answerIndMass(index) \
  do { \
    cout << "Вариант расчета индекс массы тела " << (index) << " возраст пациента "  << (patOldYears) << "\n"; \
}while(0)

#define selYears(patSex,patOldYears) \
  do { \
  cout << "years " << (patOldYears) << ((patSex)?" Мужчина ":" Женщина "); \
  if(((patOldYears) >= 19) && ((patOldYears) <= 24)){ \
      ((patSex)?indexOldYears = 21.4:indexOldYears = 19.5); \
    }else if(patOldYears >= 25 && patOldYears <= 34){ \
      ((patSex)?indexOldYears = 21.6:indexOldYears = 23.2); \
    }else if(patOldYears >=35 && patOldYears <=44){ \
      ((patSex)?indexOldYears = 22.9:indexOldYears = 23.4); \
    }else if(patOldYears >=45 && patOldYears <=54){ \
      ((patSex)?indexOldYears = 25.8:indexOldYears = 25.2); \
    }else if(patOldYears > 55){ \
      ((patSex)?indexOldYears = 26.6:indexOldYears = 27.3); \
    } \
  }while(0)

#define answerIndMassOldYear(indexOldYears) \
  do { \
  indPatHigh = ((float)(patHigh) / 100); \
    normMass1 = (indexOldYears * ((indPatHigh) * (indPatHigh))); \
  } \
  while(0)

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
       << "массы тела с учетом вораста\nВыберите вариант расчета:";

  cin.clear();  cin >> algProg;

//проверка введенных данных
//  errPatData = false;
  if(
     (patOldYears <= 19 || patOldYears > 100) || //от 19 до 100 лет - норма
     (patMass < 45 || patMass > 125) || //от 45 до 125 килограмм - норма
     (patHigh < 140 || patHigh > 215) //от 140 до 215 сантиметров - норма
     ){
//    errPatData = true;
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

#if 0
  enum{BYTE_SIZE=8};//енумератор для переменной
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

#if 0
  //используемые переменные
  float fnumbFloat;
  float fnumbCin;
  enum{COUNT=10};
  bool errCin=false;//флаг ошибки ввода
  //в цикле for вводим числа
  for(int i=0; i < COUNT; i++){

      //FIX:русские символы в консоли???
       cout << "Введите (десятичное) число " << i+1 << " : ";
//      cout << "Vvedite (desyatichnoe) chislo " << i+1 << " : ";
      cin >> fnumbCin;
      if(cin.fail()){
          errCin=true;
          break;
      }

      fnumbFloat += fnumbCin; //суммируем
      cin.clear();//очищаем буфер
      //TODO:проверка ввода?
  }

  if(!errCin)
   cout << "Сумма введенных чисел равна " << fnumbFloat << endl;
//      cout << "Summa vvedennih chisel " << fnumbFloat << endl;
  else
      cout << "Was Error CIN!!!";

#endif

#if 0
  float fNumb = 34.50;
  cout << "Число " << fNumb << " экспоненциальная запись " << 3.45e1 << endl;

  fNumb = 0.004000;
  cout << "Число " << fNumb << " экспоненциальная запись " << 4.0e-3 << endl;

  fNumb = 123.005;
  cout << "Число " << fNumb << " экспоненциальная запись " << 123.005e0 << " или " << 123005e-3 << endl;

  int iNumb = 146000;
  cout << "Число " << iNumb << " экспоненциальная запись " << 146e3 << endl;
  return 0;

#endif

#if 0
  // (true && true) || false
  // (true && true) = true
  // true || false = true
  // true
  cout << "Логическое выражение (true && true) || false --> " << (((true && true) || false)?"true":"false") << endl;

  // (false && true) || true
  // (false && true) = false
  // false || true = true
  //ios::boolalpha
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

#if 0
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

#if 0
  int x,y,z,v;
  bool logicValue;
  cout << "Введите числа x y z v: ";
  //cin >> x >> y >> z >> v;
  cout << "Были введены следующие числа x=" << x << " y=" << y << " z=" << z << " v=" << v << endl;

  cout << "Введите числа x y z v: ";
  //cin >> x >> y >> z >> v;
  cout << "Были введены следующие числа x=" << x << " y=" << y << " z=" << z << " v=" << v << endl;
  x = 3 + 4 + 5;//ранее введенное значение в x "стирается" оператором присваивания "=" \
  x = 12
  cout << "Результат:\nx=" << x << " y=" << y << " z=" << z << " v=" << v << endl;

  cout << "Введите числа x y z v: ";
  //cin >> x >> y >> z >> v;
  cout << "Были введены следующие числа x=" << x << " y=" << y << " z=" << z << " v=" << v << endl;
  x = y = z;//значение введенное в z присваивается переменным y и z \
  x=54 y=54 z=54 (54 как пример)
  cout << "Результат:\nx=" << x << " y=" << y << " z=" << z << " v=" << v << endl;

  cout << "Введите числа x y z v: ";
  //cin >> x >> y >> z >> v;
  cout << "Были введены следующие числа x=" << x << " y=" << y << " z=" << z << " v=" << v << endl;
  z *= ++y + 5;//умножение содержимого z на инкремент y+1 + 5
  cout << "Результат:\nx=" << x << " y=" << y << " z=" << z << " v=" << v << endl;

  cout << "Введите числа x y z v: ";
  cin >> x >> y >> z >> v;
  cout << "Были введены следующие числа x=" << x << " y=" << y << " z=" << z << " v=" << v << endl;
  //в данном случае при введенных значениях 3 4 27 4 \
  x=3(0011) y=4(0100) z=27(11011) v=4(0100) logicValue=1(true) \
  x=2(0010) y=2(0010) z=2(0010) v=2(0010) logicValue=1(true) \
  то есть при любых значениях отличного от нуля будет происходить преобразование компилятором \
  [ячейка]=1,2,3,...n --> true, и если [ячейка]=0 --> false \


  logicValue = x || y && z || v;
  cout << "Результат:\nx=" << x << " y=" << y << " z=" << z << " v=" << v
       << " logicValue=" << logicValue <<  endl;

#endif

#if 0
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

