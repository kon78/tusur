/*
* Лабораторная работа No2
* Исследование ввода-вывода типов данных стандартной библиотеки С++
* Типы данных
* Developer: Половян КА 318OOP/C++
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

  }else if(algProg == 'c'){

  }else{
    cout << "\nБыло введено значение отличное от a, b, c!!!\n";
  }

  cout << "\nБыли введены следующие данные:\n";
  cout << "Пациент: " << ((patSex)?" Мужчина ":" Женщина ")
       << " возраст " << patOldYears << " лет "
       << " вес пациента " << patMass << " килограмм "
       << " рост пациента " << patHigh << " сантиметров\n";
  if(algProg == 'a'){
    cout << "Вариант расчета " << "формула Брока " << "вес " << patMassAlg << " килограмм.\n";
    if(patMassAlg < patMass){
      cout << "Вес необходимо сбросить на " << (patMass - patMassAlg) << " килограмм\n";
    }else if(patMass < patMassAlg){
      cout << "Вес необходимо набрать на " << (patMassAlg - patMass) << " килограмм \n" ;
    }
  }else if(algProg == 'b'){

  }else if(algProg == 'c'){

  }
  return 0;
}
#endif 1
