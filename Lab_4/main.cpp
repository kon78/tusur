/*
* Лабораторная работа No4
* “Исследование массивов, указателей, ссылок.”
*
* Developer: Половян КА 318OOP/C++
* OS: Windows 10
* locale (кодировка): UTF-8
*/

enum class ProgrEnum {Task_1, Task_2, Task_3/*, Task_4,...*/};
const ProgrEnum progrEnum = ProgrEnum::Task_1;

#include <iostream>
using namespace std;

int main(int* argc, char* argv[])
{
    if constexpr (progrEnum== ProgrEnum::Task_1) {
        // task 1
    }
    else if constexpr (progrEnum == ProgrEnum::Task_2) {
        // task 2
    }
    else if constexpr (progrEnum == ProgrEnum::Task_3) {
        // task 3
    }
    else {
        // ...
    }
return 0;
}
