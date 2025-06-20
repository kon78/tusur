# Тестовые задания.

### 1. Что выводят программы, если есть ошибки исправьте их:

> [!WARNING]
> а) Неправильный код

```cpp
int return 5(){
return 5
}
int return8(){
return;
}
int main( {
std::cout << return5() + return8() << ;
return 0
}
```

>[!Tip]
>исправленный код

```cpp
#include<iostream>

int return5(){
return 5;
}

int return8(){
return 8;
}

int main() {
std::cout << (return5() + return8()) << std::endl;
return 0;
}
```

```bash
13
```

> [!WARNING]
> б) Неправильный код

```cpp
int return() {
return 5;
int return()
{
int k = 3 ;
k{3};
return k;
}
}
int main(){
std::cout << return() <<
std::cout << return() <<
}
```

>[!Tip]
>исправленный код

```cpp
#include <iostream>
int return1(){
return 5;
}

int return2(){
int k = 3 ;
return k;
}

int main(){
std::cout << return1() << std::endl;
std::cout << return2() << std::endl;

return 0;
}
```

```bash
5
3
```

> [!WARNING]
> c) Неправильный код

```cpp
void prints
()
{
std::cout << 'O_o' << ;
}
int main ()
{
std::cout << prints() <<
return 0;
}
```

>[!Tip]
>исправленный код

```cpp
#include<iostream>

void prints(){
std::cout << "O_o" << std::endl;
}

int main(){
prints();
return 0;
}
```

```bash
O_o
```

> [!WARNING]
> d) Неправильный код

```cpp
int getNumbers()
{
return 6;
return;
}
int main()
{
std::cout << getNumbers(
std::cout << getNumbers)
std::cout << getNumbers
return 0;
}
```

>[!Tip]
>исправленный код

```cpp
#include<iostream>

int getNumbers(){
return 6;
}

int main()
{
std::cout << getNumbers() << std::endl;
return 0;
}
```

```bash
6
```

> [!WARNING]
> e) Неправильный код

```cpp
int main()
{
std::cout << multiply(7, 8)

return 0;
}
void multiply(int a)
{
return a * b
}
int main() {
int x;
std::cin >> x;
constexpr y(x);
std::cout << y << std::endl;
return 0;
}
```

>[!Tip]
>исправленный код

```cpp
#include<iostream>
auto multiply(int a, int b)->int{
return a * b;
}

int main() {
int x;
std::cin >> x;//при условии ввода целого числа (INT_MIN INT_MAX)
constexpr int y(8);
std::cout << y << std::endl;
std::cout << multiply(7, 8) << std::endl;
return 0;
}
```

```bash
7 <--cin #любое другое целое число 
8
56
```

> [!WARNING]
> f) Неправильный код

```cpp
#define VALUE
int main() {
#if (VALUE == 0)
std::cout << VALUE <<"\n";
#elif (VALUE == 1)
std::cout << VALUE <<"\n";
#
elif
std::cout << VALUE <<"\n";
}
```

>[!Tip]
>исправленный код

```cpp
#include<iostream>
#ifndef VALUE
#define VALUE 1
int main(){
#if (VALUE == 0)
std::cout << VALUE <<"\n";
#elif (VALUE == 1)
std::cout << VALUE <<"\n";
#endif
#endif
return 0;
}
```

```bash
1
```
> [!WARNING]
> g) Неправильный код

```cpp
namespace Mix {
enum class Fruits {
LEMON,
APPLE
}
enum class Colors {
RED,
BLACK
}
};
int main() {
Fruits fruit = Fruits::LEMON;
std::cout << "MIX\n";
return 1;
}
```

>[!Tip]
>исправленный код

```cpp
#include<iostream>

namespace Mix {
enum class Fruits {
LEMON,
APPLE
};

enum class Colors {
RED,
BLACK
};
}

using namespace Mix;

int main() {
Fruits fruit = Fruits::LEMON;
std::cout << "MIX\n";
std::cout << (int)fruit << '\n';
std::cout << (int)Mix::Fruits::APPLE << '\n';
return 1;//можно и 1, 0 - нет ошибок
}
```

```bash
MIX
0
1
```

> [!WARNING]
> h) Неправильный код

```cpp
namespace DoMath
{
int subtract(int x, int y)
{
return x , y;
}
namespace DoMath
{
int add(int x, int y)
{
return x | y;
}
}
}
auto main()
{
std::cout << DoMath::add(5, 4) << '\n';

std::cout << ::subtract(5, 4) << '\n';
return 0;
}
```

>[!Tip]
>исправленный код

```cpp
#include <iostream>

namespace DoMath{
int subtract(int x, int y)
{
return x - y;//,
}

int add(int x, int y)
{
return x + y;//|
}

}

using namespace std;
using namespace DoMath;
auto main()->int
{
std::cout << add(5, 4) << '\n';

//std::cout << std::subtract(5, 4) << '\n';//если убрать запись using namespace DoMath;
std::cout << subtract(5, 4) << '\n';
return 0;
}
```

```bash
#+
9
1
#|
5
1
```

### 3.2 Чтобы программа cкомпилировалась нужно что-то добавить, нельзя удалять или комментировать программный код:

> [!WARNING]
> Неправильный код

```cpp
int tmp 1;
int main() {
tmp 3;
std::cout << "Чтобы программа скомпилилась нужно что-то добавить а нельзя удалять
здесь пустые строки или
комментировать
<< std::endl;
return;
int getNumbers( {
int tmp = 1;
return;
}
```

>[!Tip]
>исправленный код

```cpp
#include<iostream>
static int tmp(1);
int main() {
std::cout << "Глобальная переменная tmp: " << tmp << '\n';
int tmp(3);
std::cout << "Локальная переменная tmp: " << tmp << '\n';
std::cout << "zzz " << '"' << ":)" << '"' << " Чтобы программа скомпилилась нужно что-то добавить а нельзя удалять\n"
          << "\nздесь пустые строки или\n"
          << "\nкомментировать\n"
<< std::endl;
return 0;
}

int getNumbers(){
int tmp = 1;
return tmp;
}
```

```bash
Глобальная переменная tmp: 1
Локальная переменная tmp: 3
zzz ":)" Чтобы программа скомпилилась нужно что-то добавить а нельзя удалять

здесь пустые строки или

комментировать!
```
