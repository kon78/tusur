# Тестовые задания.

### 1. Что выводят программы, если есть ошибки исправьте их:

> [!WARNING]
> а) Неправильный код

```cpp
void main( {
short array[]{1,3,5,7,9};
short *ptr = array;
ptr = 111;
for (int i = 0; i < sizeof(array); ++i)
std::cout << " Значение элемента " << i << ": " << array +i << '\n';
}
```

>[!Tip]
>исправленный код

```cpp
#include <iostream>

int main() {
short array[]{1,3,5,7,9};//5 элементов
short *ptr = array;//адрес массива
*ptr = 111;//0 элементу массива array[0] <-- 111
//чтобы не было лишних элемнтов при выводе на печать
for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
std::cout << " Значение элемента " << i << ": " << *(array +i) << '\n';    
return 0;
}
```

```bash
Значение элемента 0: 111
 Значение элемента 1: 3
 Значение элемента 2: 5
 Значение элемента 3: 7
 Значение элемента 4: 9
 ```

> [!WARNING]
> б) Неправильный код

```cpp
int main() {
int array[size]{1,3,5,7,9};
Func(&array, size);
}
void Func(int *ptr, int size) {
for (int i = 0; i < size; ++i)
std::cout << " Значение элемента " ББ<< ptr[i] << '\n';
std::cout << " Адрес элемента " << ptr[i << '\n';
}
```

>[!Tip]
>исправленный код

```cpp
#include <iostream>
constexpr int size{5};

void Func(int(&array)[size]) {
for (int i = 0; i < size; ++i){
std::cout << " Значение элемента " << array[i] << '\n';
std::cout << " Адрес элемента " << &array[i] << '\n';}
}

int main() {
int array[size]{1,3,5,7,9};
Func(array);
return 0;
}
```

```bash
Значение элемента 1
 Адрес элемента 0x7ffd01239990
 Значение элемента 3
 Адрес элемента 0x7ffd01239994
 Значение элемента 5
 Адрес элемента 0x7ffd01239998
 Значение элемента 7
 Адрес элемента 0x7ffd0123999c
 Значение элемента 9
 Адрес элемента 0x7ffd012399a0
 ```

> [!WARNING]
> c) Неправильный код

```cpp
#include <iostream>
int main() {
short value;

short *p;
p = value;
*p = value;
*p = &value;
*p = *&value;
}
```

>[!Tip]
>исправленный код

```cpp
#include <iostream>
int main(){
short value(3);

short* p = nullptr;//чтобы указывал на заглушку
p = &value;//передаем адрес value --> p
std::cout << *p << '\n';
*p = value+1;//можем поменять значение 
std::cout << *p << '\n';
// *p = &value;//передача адреса value в p как значения short != &value 
void *pV = &value;
std::cout << pV << '\n';//выводим адрес
*p = *(&value);//запись содержимого по адресу &value в указатель как значение

return 0;
}
```

```bash
3
4
0x7fff87611c0e
```

> [!WARNING]
> d) Неправильный код

```cpp
#include <iostream>
int main() {
char cvalue;
int ivalue;
short * ps;
char *pc;
void *pv {(int*)(cvalue)};
void *pv_1 {(char*)(&ivalue)};
std::cout << "pv->int" << *static_cast<int>(pv) << std::endl;
int *pi = {(int)(pv)};
std::cout << "pi=" << pv_1 << std::endl;
}
```

>[!Tip]
>исправленный код

```cpp
#include <iostream>
int main() {
char cvalue;
int ivalue{8};//для удобства
short* ps=nullptr;//не стоит оставлять неинициализированным
char *pc=nullptr;
void *pv {(int*)(&ivalue)};//приводим адрес ячейки ivalue к int*
void *pv_1 {(char*)(&cvalue)};
//void* к int* pv 
std::cout << "pv->int " << static_cast<int*>(pv) << " " << (int*)(&pv) << std::endl;
int *pi = {(int*)(&ivalue)};
std::cout << "pi=" << *pi << std::endl;
}
```

```bash
pv->int 0x7fff6c10cd28 0x7fff6c10cd20
pi=8
```

> [!WARNING]
> e) Неправильный код

```cpp
#include <iostream>
int main() {
short value, value1(3);
short &ref;
const short &ref1 = value;
const short &ref2 = 78;
ref1 = 3;
*&value = 4;
const *short const p3;
}
```

>[!Tip]
>исправленный код

```cpp
#include <iostream>
int main() {
short value, value1(3);
short &ref=value1;//reference должна на что-то указывать
const short &ref1 = value;
const short &ref2 = 78;//константная ссылка на константу
// ref1 = 3;//const не изменится
*&value = 4;//так изменится (*разыменовываем/меняем значение по адресу &valu )
const short* const p3 = nullptr;//константное значение и константный адрес nullptr
}
```

> [!WARNING]
> f) Неправильный код

```cpp
int main() {
short value = 13;
short value_1 = 100;
short *ptr = &value;
std::cout << &value << '\n';
std::cout << (value +=1) << '\n';//нверное имелось ввиду ++value
ptr = 9;
std::cout << (value = value_1 + *ptr) << '\n';
std::cout << "Результат: " << value << '\n';
}
```

>[!Tip]
>исправленный код

```cpp
#include<iostream>
int main() {
short value = 13;
short value_1 = 100;
short *ptr = &value;
std::cout << &value << '\n';
std::cout << (++value) << '\n';
*ptr = 9;
std::cout << (value = value_1 + *ptr) << '\n';
std::cout << "Результат: " << value << '\n';
}
```

```bash
0x7ffc81c713ce
14
109
Результат: 109
```

> _Исправьте ошибки можно что-то добавлять а удалять нельзя._

> [!WARNING]
> g) Неправильный код

```cpp
int main() {
int value1 45;
int value 63;
int *ptr = &value;
*ptr = &value;
ptr = value;
std::cout << "Результат value1 + value2 : " << value1 + ptr << '\n';
}
```

>[!Tip]
>исправленный код

```cpp
#include<iostream>

int main() {
int value1(45);
int value(63);
int *ptr = &value;
//*ptr = &value;
// ptr = &value;
std::cout << "Результат value1 + value2 : " << (value1 + *ptr) << '\n';
}
```

```bash
Результат value1 + value2 : 108
```

> _Исправьте ошибки можно что-то добавлять а удалять нельзя. Что выведет программа:_

> [!WARNING]
> a) Неправильный код

```cpp
int main() {
std::cout << "Hi !\n";
exit;
std::cout << 3
}
```

>[!Tip]
>исправленный код

```cpp
#include <iostream>
int main() {
std::cout << "Hi !\n";
exit(0);//exit; - программа выполняется дальше
std::cout << 3;
}
```

```bash
Hi !
```

> [!WARNING]
> б) Неправильный код

```cpp
int main() {
switch (2) {
case 1
std::cout << 1 << '\n';
case 2
std::cout << 2 << '\n'
case
std::cout << 3 << '\n';
case 4
std::cout << 4 << '\n'
default:
std::cout << 5 << '\n';
```

>[!Tip]
>исправленный код

```cpp
#include <iostream>
int main() {
switch (2) {
case 1:{
    std::cout << 1 << '\n';
    break;}
case 2:{
    std::cout << 2 << '\n';
    break;}
case 3:{
    std::cout << 3 << '\n';
    break;}
case 4:{
    std::cout << 4 << '\n';
    break;}
default:{
    std::cout << 5 << '\n';
    break;}
}
    return 0;
}
```

```bash
2
```

> [!WARNING]
> в) Неправильный код

```cpp
#include <iostream>
const int size = 5;
void Func(int ptr, int size) {
for (int i = 0; i < size; ++i)
std::cout << ptr[i] << '\n'; // вывод элементов масива в цикле
ptr = 5; // первому элементу массива присваиваем значение 5
std::cout << '\n';
for (int i = 0; i < size; ++i)
std::cout << *ptr++ << '\n'; // вывод элементов масива в цикле
*ptr = 55; // первому элементу массива присваиваем значение 55
std::cout << '\n';
}
int main() {
int array[];
Func(array, size);
for (int i = 0; i < size; ++i)
std::cout << array[i] << '\n';
}
```

>[!Tip]
>исправленный код

```cpp
#include <iostream>
const int size = 5;

void Func(int* ptr, int size) {
if(ptr != nullptr){
for (int i = 0; i < size; ++i)
    std::cout << (ptr[i]) << '\n'; // вывод элементов масива в цикле
    
ptr[0] = 5; // первому элементу массива присваиваем значение 5

std::cout << '\n';

for (int i = 0; i < size; ++i)
    std::cout << *(ptr++) << '\n'; // вывод элементов масива в цикле
    
    ptr--;ptr--;ptr--;ptr--;ptr--;//сдвигаем указатель назад
ptr[0] = 55; // первому элементу массива присваиваем значение 55

std::cout << '\n';
    }
}

int main() {
int array[size]{2,3,2,4,7};
Func(array, size);
for (int i = 0; i < size; ++i)
    std::cout << array[i] << '\n';
}
```

```bash
2
3
2
4
7

5
3
2
4
7

55
3
2
4
7
```
