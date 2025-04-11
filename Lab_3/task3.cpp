#include "task3.h"
using namespace std;

#define Init 4
//auto trailing-синтаксис
auto Initialization()->int{
  int param;//здесь будет мусор
  cout << "function Initialization() ";
  PRINT_INT(param); cout << '\n';
#if Init == 1
  cout << "Нотация присваивания ";
//  int iValue, bool bValue, char cValue, long lValue;
  int iValue = 8;//в ячейки _Value[XY] нотация присваивания/копирующая (assignment notation/copy-initial.)
  bool bValue = false;
  char cValue = 'A';
  long lValue = 271828;
#if 0
//так приводим к типу вручную без trailng и возвращаем в main \
  тогда из объявления функции и реализации убираем auto -> записи\

  param = static_cast<int>(cValue);
  return param;
#endif

//return будет включаться в каждом из блоков
#if 1
  return cValue;//приводим тип char к int и возвращаем в main() 65 'A'
#endif
#elif Init == 2
int iValue(8);//функциональная нотация/прямая инициализация (functional notation/direct initial.)
bool bValue(true);
char cValue('B');
long lValue(31415);
return cValue;//возвращаем в main() 66 'B'
#elif Init == 3
  int iValue{42};//braced initialization/list-initialization/uniform-initialization
  bool bValue(true);
  char cValue('C');
  long lValue(137);

#if 0
  struct BracedInit{
    int iValue;//braced initialization/list-initialization/uniform-initialization
    bool bValue;
    char cValue;
    long lValue;
  };
  BracedInit bi{0};//напомнило, что так можно обнулять поля струтктуры C++98 (borland c++ 5.5 подстрочник)
#endif
  return cValue;//возвращаем в main() 67 'C'

#elif Init == 4
auto iValue = 37;//37 int
auto cValue = static_cast<char>(iValue);//37 to char %
auto bValue = true;
auto lValue = 293847;
return cValue;
#endif
}
