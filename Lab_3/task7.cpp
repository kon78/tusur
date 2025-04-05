#include"task7.h"

using namespace std;
const char* answ_yes="да";
int floor_build;
int mem_elevator(0);
int elev_where;

void MapBuild(){
  cout << "В здании " << build_size << " этажей.\n";
  cout << "Этаж " << zero_floor << "\t - парковка\n"
       << "Этаж " << one_floor << "\t - Перекресток (первый этаж)\n"
       << "Этаж " << two_floor << "\t - Бытовая техника (второй этаж)\n"
       << "Этаж " << three_floor << "\t - ДНС (третий)\n"
       << "Этаж " << four_floor << "\t - Буквоед (четвертый)\n"
       << "Этаж " << five_floor << "\t - Би-би (пятый)\n"
       << "Этаж " << six_floor << "\t - Домовой (шестой)\n"
       << "Этаж " << seven_flor << "\t - Макдональдс (седьмой)\n";
}

void InfoElev(level target_floor){
  switch(target_floor){
    case(zero_floor):
    cout << " парковка\n";
    break;

  case(one_floor):
    cout << " Перекресток (первый этаж)\n";
    break;

  case(two_floor):
    cout << " Бытовая техника (второй этаж)\n";
    break;

  case(three_floor):
    cout << " ДНС (третий)\n";
    break;

  case(four_floor):
    cout << " Буквоед (четвертый)\n";
    break;

  case(five_floor):
    cout << " Би-би (пятый)\n";
    break;

  case(six_floor):
    cout << " Домовой (шестой)\n";
    break;

  case(seven_flor):
    cout << " Макдональдс (седьмой)\n";
    break;


  default:
    cout << "Wrong nomber floor!\n";
    break;
  }
}

int MoveElevator(int target_floor){
  elev_where = mem_elevator - target_floor;
  if(elev_where == 0){
    cout << "Лифт уже на " << target_floor << endl;
    InfoElev((level)target_floor);
  }else if(elev_where < 0){
    cout << "Едем вверх. ";
    mem_elevator = target_floor;
    elev_where = target_floor;
    InfoElev((level)target_floor);
  }else if(elev_where > 0){
    cout << "Едем вниз. ";
    mem_elevator = target_floor;
    elev_where = target_floor;
    InfoElev((level)target_floor);
  }else{
    cout << "Error!\n";
  }
  return elev_where;
}

void Elevator(){
  do{

//проверяем ввод
    while(true){
      cout << "Лифт на " << mem_elevator << " этаже. \nВведите этаж: ";

#if 1
      cin >> floor_build;
      if(cin.good()){
        cin.ignore(32767,'\n');
        break;//если нет ошибок
      }

      cout << "Error! Wrong input data! Repeat enter!\n";

      cin.clear();
      cin.ignore(32767,'\n');
#endif

    }

    if((floor_build >= zero_floor && floor_build <= seven_flor)){
      cout << "Был выбран этаж " << floor_build << endl;
      MoveElevator(floor_build);
    cout << "Выйти из программы yes/no? ";

//в плане знаний забегаю вперед, массив символов размером 32 \
и метод getline() для вычитки введенного слова\

    char buff[32];
    cin.getline(buff,8);

//с русским "да" получается плохо \
немного "схитрил" использовал преобразование char[20] к типу (объекту string)\

    if((string)buff == "yes")
      break;
    else
      cout << "Продолжаем кататься дальше.\n";

    }else{
      cout << "Неправильный номер этажа! Повторите ввод!\n";
    }
  }while(true);
}
