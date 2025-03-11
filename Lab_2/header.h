#ifndef HEADER_H
#define HEADER_H
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
bool errPatData;//неверные данные, не подходят для условий задачи, патологии
float indexOldYears;

//расчет по формуле Брока \
  чем больше скобок, тем лучше, \
  по-моему такое правило для функций в виде макроса именно в с++ \
  сейчас не вспомню где такое читал правило скобки помогают более правильно \
  раскрыть компилятору запись, но есть и предупреждение, что такие записи могут \
  приводить к непредсказуемым последствиям, вроде Р.Лафоре \
                           int       const       float
#define patMassBroke() (((patHigh) - (100)) * (brokCoef))
#define viewBroke() (cout<<"масса пациента "<<patMass<<" масса по Броку "<<patMassAlg<<endl)
  //вывод результатов
#define answer() \
  do { \
    cout << "\nБыли введены следующие данные:\n"; \
    cout << "Пациент: " << ((patSex)?" Мужчина ":" Женщина ") \
         << " возраст " << patOldYears << " лет " \
         << " вес пациента " << patMass << " килограмм " \
         << " рост пациента " << patHigh << " сантиметров\n"; \
  }while(0)
#define answerBroke(patMassAlg, patMass) \
  do { \
    cout << "Вариант расчета формула Брока вес " << patMassAlg << " килограмм.\n"; \
    if((patMassAlg) < (patMass)){ \
      cout << "Вес необходимо сбросить на " << ((patMass) - (patMassAlg)) << " килограмм\n"; \
    }else if((patMass) < (patMassAlg)){ \
      cout << "Вес необходимо набрать на " << ((patMassAlg) - (patMass)) << " килограмм \n"; \
    } }while(0)

#define answerIndMass(index) \
  do { \
  cout << "Вариант расчета индекс массы тела " << index << "\n"; \
  if(index < 16){ \
    cout << "\nВыраженный дифицит массы тела."; \
  }else if(index > 16 && index < 18.5){ \
    cout << "\nНедостаточная (дефицит) масса тела."; \
  }else if(index > 18.5 && index < 25){ \
    cout << "\nНорма."; \
  }else if(index > 25 && index < 30){ \
    cout << "\nИзбыточная масса тела (предожирение)."; \
  }else if(index > 30 && index < 35){ \
    cout << "\nОжирение первой степени"; \
  }else if(index > 35 && index < 40){ \
    cout << "\nОжирение второй степени"; \
  }else if(index > 40){ \
    cout << "\nОжирение третьей степени (морбидное)"; \
  } \
cout << "\nВариант расчета " << "по индексу массы тела (индекс массы тела " << index \
     << ") вес " << patMass << " килограмм.\n"; \
const float indexNorm1 = 18.5; \
const float indexNorm2 = 25; \
normMass1 = indexNorm1 * (indPatHigh * indPatHigh); \
normMass2 = indexNorm2 * (indPatHigh * indPatHigh); \
if(index < 18.5){ \
  cout << "Вес необходимо набрать на " << (normMass1 - patMass) << " килограмм."; \
}else if(index > 25){ \
  cout << "Вес необходимо сбросить на " << (patMass - normMass2) << " килограмм."; \
}else{ \
  cout << "Вес пациента в пределах нормы!\n"; \
} \
  }while(0)

#define answerIndMass(index) \
  do { \
    cout << "Вариант расчета индекс массы тела " << index << " возраст пациента "  << patOldYears << "\n"; \
}while(0)

#define selYears(patSex,patOldYears) \
  do { \
  cout << "years " << patOldYears << ((patSex)?" Мужчина ":" Женщина "); \
  if(patOldYears >= 19 && patOldYears <= 24){ \
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
  indPatHigh = (float)patHigh / 100; \
    normMass1 = indexOldYears * (indPatHigh * indPatHigh); \
  } \
  while(0)

#endif // HEADER_H
