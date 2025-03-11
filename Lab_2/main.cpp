/*
* Лабораторная работа No2
* Исследование ввода-вывода типов данных стандартной библиотеки С++
* Типы данных
* Developer: Половян КА 318OOP/C++
* git ветка lab2, слить с веткой master!!!!
*/
#include <iostream>// подключаем библиотеку ввода/вывода

#if 1//Задание 1.“Калькулятор для расчета идеального веса“.
#define size 80
using namespace  std;
int main(int argc, char *argv[])
{
//используемые переменные camelCase

int patOldYears;//возвраст пациента (0-115)
int patMass;//вес пациента (1-125)
int patMassAlg;//вес пациента по расчету
bool patSex;//пол пациента (0-1)
int patHigh;//рост пациента (50-250)
char algProg;//выбор варианта расчета
float index;//индекс массы тела
float normMass1, normMass2;//нормы весов
float indPatHigh;//рост пациента в метрах
bool errPatData;//неверные данные, не подходят для условий задачи, патологии
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
       << "массы тела с учетом вораста\n";

  cin.clear();  cin >> algProg;

/* проверка введенных данных
 * тут конечно все относительно
 * возраст 46, вес 35, рост 184 - либо патология либо узник Дахау и т.д.
 * возраст 15, вес 150, рост 165 - явное заболевание щетовидной к примеру
 * возраст 45, вес 40, рост 110 - карлик, либо инвалид (без ног)
 * поэтому за основу взял таблицу из задания
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

//расчеты
  if(algProg == 'a'){
//    algProgText = "формула Брока";
    const int brokConst = 100;
    const float brokMaleCoef = 0.9;
    const float brokFemaleCoef = 0.89;

/*
 * формула Брока
 * мужчины вес = (рост см - 100) * 0.9
 * женщины вес = (рост см - 100) * 0.85
*/
    if(patSex == true){//male
      if(patHigh > 50 && patHigh <= 250)//ограничения на рост 50-250 см
        patMassAlg = (patHigh - brokConst) * brokMaleCoef;
      else{
        cout << "Указанный рост вне допустимого диапазона 50 - 250 см!";
        exit(1);//выходим из программы с сообщением в систему
      }
    }else if(patSex == false){
      patMassAlg = (patHigh - brokConst) * brokFemaleCoef;
    }

  }else if(algProg == 'b'){
/*
 * вес по индексу массы тела
 * индекс = вес, кг/(рост, м)2
 * вес,кг = индекс * рост,м2
*/
    if(patHigh != 0){
//      float indPatHigh;//рост пациента в метрах
      indPatHigh = (float)patHigh / 100;
      index = (float)patMass / (indPatHigh * indPatHigh);
//      cout << indPatHigh << "\n";
    }else{
      cout << "Рост пациента не может быть 0 сантиметров!";
      exit(1);
    }

  }else if(algProg == 'c'){
/*
 * вес по индексу массы тела и возрасту
*/
    if(patOldYears <=19 || patOldYears >=24){
        ((patSex)?indexOldYears = 21.4:indexOldYears = 19.5);
      }else if(patOldYears <=25 || patOldYears >=34){
        ((patSex)?indexOldYears = 21.6:indexOldYears = 23.2);
      }else if(patOldYears <=35 || patOldYears >=44){
        ((patSex)?indexOldYears = 22.9:indexOldYears = 23.4);
      }else if(patOldYears <=45 || patOldYears >=54){
        ((patSex)?indexOldYears = 25.8:indexOldYears = 25.2);
      }else if(patOldYears > 55){
        ((patSex)?indexOldYears = 26.6:indexOldYears = 27.3);
      }
  }else{
    cout << "\nБыло введено значение отличное от a, b, c!!!\n";


  //вывод результатов
  cout << "\nБыли введены следующие данные:\n";
  cout << "Пациент: " << ((patSex)?" Мужчина ":" Женщина ")
       << " возраст " << patOldYears << " лет "
       << " вес пациента " << patMass << " килограмм "
       << " рост пациента " << patHigh << " сантиметров\n";

  //вывод результатов формула Брока
  if(algProg == 'a'){
    cout << "Вариант расчета " << "формула Брока " << "вес " << patMassAlg << " килограмм.\n";
    if(patMassAlg < patMass){
      cout << "Вес необходимо сбросить на " << (patMass - patMassAlg) << " килограмм\n";
    }else if(patMass < patMassAlg){
      cout << "Вес необходимо набрать на " << (patMassAlg - patMass) << " килограмм \n" ;
    }

  //вывод результатов по индексу массы тела
  }else if(algProg == 'b'){
    cout << "индекс массы тела " << index << "\n";
    //пороги индекса массы тела
    if(index < 16){
      cout << "\nВыраженный дифицит массы тела.";
    }else if(index > 16 && index < 18.5){
      cout << "\nНедостаточная (дефицит) масса тела.";
    }else if(index > 18.5 && index < 25){
      cout << "\nНорма.";
    }else if(index > 25 && index < 30){
      cout << "\nИзбыточная масса тела (предожирение).";
    }else if(index > 30 && index < 35){
      cout << "\nОжирение первой степени";
    }else if(index > 35 && index < 40){
      cout << "\nОжирение второй степени";
    }else if(index > 40){
      cout << "\nОжирение третьей степени (морбидное)";
    }
  cout << "\nВариант расчета " << "по индексу массы тела (индекс массы тела " << index
       << ") вес " << patMass << " килограмм.\n";
  //вывод результатов по индексу массы тела и возрасту
  //18.5 <--> 25 норма
  const float indexNorm1 = 18.5;
  const float indexNorm2 = 25;
  normMass1 = indexNorm1 * (indPatHigh * indPatHigh);
  normMass2 = indexNorm2 * (indPatHigh * indPatHigh);

  //набрать вес
  if(index < 18.5){
    cout << "Вес необходимо набрать на " << (normMass1 - patMass) << " килограмм.";
  }else if(index > 25){
  //сбросить вес
    cout << "Вес необходимо сбросить на " << (patMass - normMass2) << " килограмм.";
  }else{
    cout << "Вес пациента в пределах нормы!\n";
  }
  }else if(algProg == 'c'){
    cout << "индекс массы тела " << index << " возраст пациента " << patOldYears
         << " пол пациента " << ((patSex)?" Мужчина ":" Женщина ") << end;

    if(patOldYears <=19 || patOldYears >=24){
        if(patSex){
          indexOldYears
        }else if(!patSex){

        }
      }else if(patOldYears <=25 || patOldYears >=34){

      }else if(patOldYears <=35 || patOldYears >=44){

      }else if(patOldYears <=45 || patOldYears >=54){

      }else if(patOldYears > 55){

      }


  }
  return 0;
}
#endif 1
