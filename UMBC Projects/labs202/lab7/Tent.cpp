#include "Tent.h"
//#include "residence.h"
#include <iostream>
#include <cstring>
using namespace std;
Tent::Tent(): Residence(1,2,false){
  // inheriting from the residence class
}
double Tent::PropertyValue()const{
  return 0;
}
int Tent::NumWindows()const{
  return 0;
}
