#include"task4.h"

using namespace std;

void getAnimalName(Animal name_animal){
  switch(name_animal){
    case(pig):
      cout << "animal pig " << pig << " count legs is ";
      printNumberOfLegs(pig);
    break;

  case(chicken):
      cout << "animal chicken " << chicken << " count legs is ";
      printNumberOfLegs(chicken);
    break;

  case(goat):
      cout << "animal goat " << goat << " count legs is ";
      printNumberOfLegs(goat);
    break;

  case(cat):
      cout << "animal cat " << cat << " count legs is ";
      printNumberOfLegs(cat);
    break;

  case(dog):
      cout << "animal dog " << dog << " count legs is ";
      printNumberOfLegs(dog);
    break;

  default:
    cout << "Wrong name animal!\n";
    break;
  }
}

void printNumberOfLegs(Animal name_animal){
  switch(name_animal){
    case(pig):
      cout << "4\n";
    break;

  case(chicken):
      cout << "2\n";
    break;

  case(goat):
      cout << "4\n";
    break;

  case(cat):
      cout << "4\n";
    break;

  case(dog):
      cout << "4\n";
    break;

  default:
    cout << "Wrong legs animal!\n";
    break;
  }

}
