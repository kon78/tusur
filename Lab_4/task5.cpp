#include"task5.h"
using namespace  std;
//char-1, 2-short, 3-int, 4-float, 5-double
void InsertionSort(char array[], int size){
    for (int i = 1; i < size; i++)
    {
        int j = i;
        while (j > 0 && array[j - 1] < array[j])
        {
            std::swap(array[j - 1], array[j]);
            j--;
        }
    }
}

void InsertionSort(short array[], int size){
    for (int i = 1; i < size; i++)
    {
        int j = i;
        while (j > 0 && array[j - 1] < array[j])
        {
            std::swap(array[j - 1], array[j]);
            j--;
        }
    }
}

void InsertionSort(int array[], int size){
    for (int i = 1; i < size; i++)
    {
        int j = i;
        while (j > 0 && array[j - 1] < array[j])
        {
            std::swap(array[j - 1], array[j]);
            j--;
        }
    }
}

void InsertionSort(float array[], int size){
    for (int i = 1; i < size; i++)
    {
        int j = i;
        while (j > 0 && array[j - 1] < array[j])
        {
            std::swap(array[j - 1], array[j]);
            j--;
        }
    }
}

void InsertionSort(double array[], int size){
    for (int i = 1; i < size; i++)
    {
        int j = i;
        while (j > 0 && array[j - 1] < array[j])
        {
            std::swap(array[j - 1], array[j]);
            j--;
        }
    }
}

void MakeArray(unsigned int& dtype, unsigned int& sarr){
  enum{tpChar=1,tpshort,tpint,tpfloat, tpdouble};
  const char type_name[][10]{"int","short","int","float","double"};
  const unsigned int ssize(sarr);//объявляем размер
  switch(dtype){
    case (tpChar):
  {
    cout << "тип " << type_name[tpChar-1] << " размер " << ssize << endl;
    break;
  }

  case (tpshort):
{
  cout << "тип " << type_name[tpshort-1] << " размер " << ssize << endl;
  break;
}
  case (tpint):
{
  cout << "тип " << type_name[tpint-1] << " размер " << ssize << endl;
  break;
}
  case (tpfloat):
{
  cout << "тип " << type_name[tpfloat-1] << " размер " << ssize << endl;
  break;
}
  case (tpdouble):
{
  cout << "тип " << type_name[tpdouble-1] << " размер " << ssize << endl;
  break;
}

  default:{cout << "нет такого типа данного\n";break;}
  }

  //созданные массивы имеют элементы с разными данными
    if(dtype == 1){

      char chArrData[ssize];
      if( (sizeof(chArrData)/sizeof(char)) != ssize ){
        cout << "Error! Array size!\n";
      }else{
        cout << "size array is " << (sizeof(chArrData)/sizeof(char)) << endl;
        for(auto el : chArrData)
          cout << static_cast<int>(el) << "-" << el << " ";
        cout << endl;

        InsertionSort(chArrData,(sizeof(chArrData)/sizeof(char)) );

        cout << "after sorting\n";
        for(auto el : chArrData)
          cout << static_cast<int>(el) << "-" << el << " ";
        cout << endl;
      }

    }else if(dtype == 2){

      short shArrData[ssize];
      if( (sizeof(shArrData)/sizeof(short)) != ssize ){
        cout << "Error! Array size!\n";
      }else{
        cout << "size array is " << (sizeof(shArrData)/sizeof(short)) << endl;
        for(auto el : shArrData)
          cout << el << " ";
        cout << endl;

        InsertionSort(shArrData,(sizeof(shArrData)/sizeof(short)) );

        cout << "after sorting\n";
        for(auto el : shArrData)
          cout << el << " ";
        cout << endl;
      }

    }else if(dtype == 3){

      int iArrData[ssize];
      if( (sizeof(iArrData)/sizeof(int)) != ssize ){
        cout << "Error! Array size!\n";
      }else{
        cout << "size array is " << (sizeof(iArrData)/sizeof(int)) << endl;
        for(auto el : iArrData)
          cout << el << " ";
        cout << endl;

        InsertionSort(iArrData,(sizeof(iArrData)/sizeof(int)) );

        cout << "after sorting\n";
        for(auto el : iArrData)
          cout << el << " ";
        cout << endl;
      }

    }else if(dtype == 4){

      float fArrData[ssize];
      if( (sizeof(fArrData)/sizeof(float)) != ssize ){
        cout << "Error! Array size!\n";
      }else{
        cout << "size array is " << (sizeof(fArrData)/sizeof(float)) << endl;
        for(auto el : fArrData)
          cout << el << " ";
        cout << endl;

        InsertionSort(fArrData,(sizeof(fArrData)/sizeof(float)) );

        cout << "after sorting\n";
        for(auto el : fArrData)
          cout << el << " ";
        cout << endl;
      }

    }else if(dtype == 5){

      double dArrData[ssize];
      if( (sizeof(dArrData)/sizeof(double)) != ssize ){
        cout << "Error! Array size!\n";
      }else{
        cout << "size array is " << (sizeof(dArrData)/sizeof(double)) << endl;
        for(auto el : dArrData)
          cout << el << " ";
        cout << endl;

        InsertionSort(dArrData,(sizeof(dArrData)/sizeof(double)) );

        cout << "after sorting\n";
        for(auto el : dArrData)
          cout << el << " ";
        cout << endl;
      }

    }
}
