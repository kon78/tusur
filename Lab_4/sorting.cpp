#include"sorting.h"

void bubbleSort(int array[], int size)
{
    bool b = true;
    while (b)
    {
        b = false;
        for (int i = 0; i < size - 1; i++)
        {
            if (array[i] < array[i + 1])
            {
//стандартная библиотека swap
#if 0
                std::swap(array[i], array[i+1]);//меняем элементы местами
#endif

//swap вручную, нужна дополнительная переменная
#if 1
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
#endif

                b = true;
            }
        }
    }
}
