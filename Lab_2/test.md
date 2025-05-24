# Тестовые задания.

### 1. Найдите в программе ошибки, представьте ниже рабочий вариант программы.

> [!WARNING]
> а) Неправильный код

```cpp
nt main() {  //<-- int
short a;     //<-- модификатор без типа
a(65599);    //<-- слишком большое число, -32768 до 32767
int 5 = 4;   //<-- 5 = 4, нет имени переменной
int л = 4;   //<-- русский символ
char ch;
ch{5};//ошибка в одну строку
float f;
f = 3,2;     //<-- , в дробном числе, может и не быть (региональные стандарты)
}}           //<-- нет парной скобки стеймена (лишняя)
```

>[!Tip]
>исправленный код

```cpp
#include<iostream>
int main() {
short a(659);  
int b = 4;
int c = 4;
char ch{5};
float f;
f = 3.2;
return 0;
}         
```

### 2. Какие значения выводит эта программа?
### а) Почему z выводит неожиданные значения?

```cpp
#include <iostream>
int main() { 
int x = 5;
x = x - 2;
//a
std::cout << x << std::endl; // #a x=3
int y = x;
//b
std::cout << y << std::endl; // #b y=3
//c
std::cout << x + y << std::endl; // #c 6
//d
std::cout << x << std::endl; // #d 3
int z;//неявная инициализация 
//e
std::cout << z << std::endl; // #e z объявлена, но не инициализирована, любое значение
}
```
>Вывод на экран
```bash
3
3
6
3
0//переменная со статическим временем существоавания инициализируется 0
```

### b)

```cpp
#include <iostream>
int main() {
int x = 1;
x = x++; //<-- 2 постфиксный инкремент, в x будет 1

std::cout << x << std::endl;// #x 1
}
```
>Вывод на экран
```bash
1
```

### c)

```cpp
#include <iostream>
int main(){
int x = 1;
std::cout << ++x << "\n"; //<-- префиксный инкремент, в x будет 2
}
```
> Вывод на экран
```bash
2
```

### 3. Найдите в программе ошибки, можно только что-то добавлять убирать нельзя, и выведите результат.
### a)

> [!WARNING]
> Неправильный код

```cpp
const int option_1 = 0;
const int option_2 = 1;
const int option_3 = 2;
const int option_4 = 3;
const int option_5 = 4;
const int option_6 = 5;
const int option_7 = 6;
const int option_8{7};
int main( { //<-- ) парная скобка
bitset<8> bits(0x4);
bits.set(option_1);
bits.flip(option_3);
bits.reset(option_7);
cin << "Bit 1 has value: " << bits.test(option_1) << '/n';
cin << Bit 3 has value: " << bits.test() << '\n';
cin << "Bit 7 has value: " << bits.test() < '\n';
cin<< "All the bits: " << bits << '\n;
}
```

>[!Tip]
>исправленный код

```cpp
#include<iostream>
#include<bitset>
using namespace std;

enum{SIZE_BYTE=8};
const int option_1 = 0;
const int option_2 = 1;
const int option_3 = 2;
const int option_4 = 3;
const int option_5 = 4;
const int option_6 = 5;
const int option_7 = 6;
const int option_8{7};

int main(){
bitset<SIZE_BYTE> bits(0x04);
bits.set(option_1);
bits.flip(option_3);
bits.reset(option_7);

//cin >> "Bit 1 has value: " << bits.test(option_1) << '\n';
//cin << "Bit 3 has value: " << bits.test(option_3) << '\n';
//cin << "Bit 7 has value: " << bits.test(option_7) << '\n';
//cin << "All the bits: " << bits << '\n';

cout << "Bit 1 has value: " << bits.test(option_1) << '\n';
cout << "Bit 3 has value: " << bits.test(option_3) << '\n';
cout << "Bit 7 has value: " << bits.test(option_7) << '\n';
cout << "All the bits: " << bits << '\n';
}
```
>_Вывод на экран_
```bash
Bit 1 has value: 1
Bit 3 has value: 0
Bit 7 has value: 0
All the bits: 00000001
```

### b)

> [!WARNING]
> Неправильный код

```cpp
int main()//нет парных скобок {}
uint8_t a(1), uint8_t b(1), c(3
a = a < 1;
printf("a: \n", a)
b <<= 1;
printf("b: \n", b);
c |= 1;
print("c: \n", );
```

> [!Tip]
> исправленный код

```cpp
#include<iostream>
#include<cstdint>
int main(){
std::uint8_t a(1); std::uint8_t b(1), c(3);
a = a < 1; //логическая операция a<1 --> 1<1 --> a=false(0)
printf("a:%d\n", a);
b <<= 1; //сдвиг с записью результата в b b=2
printf("b:%d\n", b);
c |= 1;//логическая операция | (or) с записью в результата c=3
printf("c:%d\n", c);
}
```
>_Вывод на экран_
```bash
a:0
b:2
c:3
```

### c)

> [!WARNING]
> Неправильный код

```cpp
int main() {
int x (08);// 0x8
std::cout << "x: " << x < endl;//оператор std::
int y = 0x5;
std::cout << "y: " < y << stdendl;// оператор ::
int bin(0);
bin = 0b101// окончание ;
out << "bin 0b101: " << bin << std::endl// cout
}
```

> [!Tip]
> исправленный код

```cpp
#include<iostream>
int main(){
int x (0x8);
std::cout << "x: " << x << std::endl;//8hex=8dec
int y = 0x5;
std::cout << "y: " << y << std::endl;//5hex=5dec
int bin(0);
bin = 0b101;//0b101 = 5dec
std::cout << "bin 0b101: " << bin << std::endl;
}
```
>_Вывод на экран_
```bash
x: 8
y: 5
bin 0b101: 5
```

### d)

> [!WARNING]
> Неправильный код

```cpp
int main() {
int x{8};
std::cout << "hex: " << h << x << ndl;//std::endl hex
std::cout << "oct: " << o<< x << std::endl;
out << "dec: " << dec << x << std::endl;
}
```

> [!Tip]
> исправленный код

```cpp
#include<iostream>
int main(){
int x{8};
std::cout.unsetf(std::ios::dec);//снимаем флаг dec
std::cout << "hex: " << std::hex << x << std::endl;//8dec=8hex
std::cout << "oct: " << std::oct << x << std::endl;//8dec=10oct
std::cout << "dec: " << std::dec << x << std::endl;//8dec
}
```

>_Вывод на экран_

```bash
hex: 8
oct: 10
dec: 8
```

### 4 Вычислите следующие выражения:

### a)

_(true или false):_

```bash
# (true && true) || false --> true
# (false && true) || true --> true

# (false && true) || false || true --> true
# (5 > 6 || 4 > 3) && (7 > 8) --> false
# !(7 > 6 || 3 > 4) --> false
```

> b) Какой результат 0110 >> 2 в двоичной системе счисления? 1 (6/2 3/2 --> 1)

> c) Какой результат 5 & 12 в десятичной системе счисления?

```bash
#  5 - 0101 
#      &(and)
# 12 - 1100
#  4   0100
```

> d) Какой результат 5 ^ 12 в десятичной системе счисления?

```bash
#  5 - 0101
#  ^(xor)
# 12 - 1100
#  9   1001
```

### 5 Конвертируйте двоичное число 0100 1101 в десятичную систему счисления.

```bash
0*2^7 + 1*2^6 + 0*2^5 + 0*2^4 + 1*2^3 + 1*2^2 + 0*2^1 + 1*2^0
0     + 64    + 0     + 0     + 8     + 4     + 0     + 1     --> 77
```