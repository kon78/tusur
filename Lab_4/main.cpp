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
        cout << "Задание 1.\n";
        const int size_arr = 10;
        int arr_int[size_arr] = {0};
        // cout << "size array is " << (sizeof(arr_int)/sizeof(int)) << endl;
        if((sizeof(arr_int)/sizeof(int))){
            unsigned value = size_arr + (size_arr / 2);
            // Порождаем и выводим 20 чисел, используя число 18 как зерно
            for (int i = 0; i < size_arr; ++i)
            {
                // Итеративно вычисляем новое значение value.
                value = (value * 73129 + 95121) % 100000;
                // std::cout << value << std::endl;
                arr_int[i] = value;
            }
            //смотрим что получилось
            for(auto i = 0; i < size_arr; ++i){
                cout << arr_int[i] << " ";
            }
            cout << endl;
            //сортируем buble-sort(пузырьковая)

        }else{
            cout << "Error! Array not equal " << size_arr << endl;
        }
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
