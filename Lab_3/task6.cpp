#include"task6.h"
using namespace std;
void Task6(){
int x; float y; double z; unsigned short k;
x=2; y=3.14f; z=2.71828; k=4;
  //преобразование типов \
  int i = (x+y)*z+k ; \
  int = (int + float) * double + unsigned short --> потеря точности float, double к int \
  static_cast \

#if 1
  int i = (x + static_cast<int>(y)) * static_cast<int>(z) + static_cast<int>(k); //-->14
  cout << i << "=(" << x << "+" << y << ")*" << z << "+" << k << '\n';
#endif

  //c-style cast \
  int i = (x+y)*z+k ; \

#if 0
  int i = (x + (int) y) * (int) z + (int) k; //-->14
  cout << i << "=(" << x << "+" << y << ")*" << z << "+" << k << '\n';
#endif
#if 0
//неявное преобразование
  int i = (x + y) * z + k;
  cout << i << "=(" << x << "+" << y << ")*" << z << "+" << k << '\n';//потеря точности 17
  cout << "(" << x << "+" << y << ")*" << z << "+" << k << "=";
  cout << fixed << setprecision(2) << ((x + y) * z + k) << '\n';//компилятор сам подберет необходимые типы 17.97
#endif

//k = x-y/z \
unsigned short = int - float / double --> может не учитываться знак\
static_cast \

#if 0
    if(z != 0){
    k = static_cast<unsigned short>(x) - static_cast<unsigned short>(y) / static_cast<unsigned short>(z);
    cout << k << "=" << x << "-" << y << "/" << z << '\n';
}else{
    cout << "Error! Devide 0!\n";
}
#endif

#if 0
//C-Style cast
  if(z != 0){
    k = (x) - (unsigned short) ( y / z );
    cout << k << "=" << x << "-" << y << "/" << z << '\n';
}else{
    cout << "Error! Devide 0!\n";
}
#endif

#if 0
//неявное преобразование
if(z != 0){
    k = x - (y / z);
    cout << k << "=" << x << "-" << "(" << y << "/" << z << ")\n";
    cout << x << "-" << y << "/" << z << "=" << (x - y / z) << '\n';
}else{
    cout << "Error! Devide 0!\n";
}
#endif

#if 0
//z = x*y+z/x; \
  double = int * float + double / int \
  static_cast \

  z = x * y + z / static_cast<double>(x); //z участвует как l-value и r-value
  cout << z << "=" << x << "*" << y << "+" << z << "/" << x << '\n';
#endif

#if 0
//C_style cast
  z = x * y + z / (double) x;
  cout << z << "=" << x << "*" << y << "+" << z << "/" << x << '\n';

#endif

#if 0
//неявное преобразование
  z = x * y + z / x;
  cout << z << "=" << x << "*" << y << "+" << z << "/" << x << '\n';
  z=2.71828;//иначе будет приплюсован предыдущий шаг
  cout << x << "*" << y << "+" << z << "/" << x << "=" << (x * y + z / x) << '\n';
#endif

//unsigned int ui = x/y+k; \
unsigned int = int / float + unsigned short \

#if 0
//static_cast
unsigned int ui = x / static_cast<unsigned int>(y) + k;
cout << ui << "=" << x << "/" << y << "+" << k << '\n';
#endif

#if 0
//C_Style cast
unsigned int ui = x / (unsigned int) y + k;
cout << ui << "=" << x << "/" << y << "+" << k << '\n';
#endif

#if 0
//неявное преобразование
unsigned int ui = x / y + k;//преобразует выражение к unsigned int
cout << ui << "=" << x << "/" << y << "+" << k << '\n';
cout << x << "/" << y << "+" << k << "=" << (x / y + k) << '\n';//комилятор подбирает тип сам
#endif

#if 0
//чтобы не поймать ошибку либо проверять, либо try \
при этих числах ошибка \

if((int)(x / (int)y) != 0){
  short s = x % static_cast<int>( x / static_cast<int>(y) );
  cout << s << "=" << x << "%(" << x << "/" << y << ")\n";
}else{
  cout << "Error! Division by zero!\n";
}
#endif
}
