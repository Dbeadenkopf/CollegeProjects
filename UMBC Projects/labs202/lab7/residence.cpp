#include <iostream>
#include <cstring>
#include "residence.h"
#include <ostream>
using namespace std;
Residence::Residence(){
  n_roomS = 0;
  n_ewallS = 0;
  isWasher = false;
}
Residence::Residence(int rS, int eW, bool wash){
  n_roomS = rS;
  n_ewallS = eW;
  isWasher = wash;
} 
bool Residence::HasWasher() const{
  return true;
}
double Residence::PropertyValue()const{
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(1);
  double calc;
  calc = (n_roomS*10000);
  return calc;
}
int Residence::NumWindows()const{
  return(n_ewallS*2);
}
int Residence::getRooms()const{
  return n_roomS;
}
int Residence::getWalls()const{
  return n_ewallS;
}
std::ostream& operator<<(std::ostream& sout, const Residence& obj){
  sout << "Number of Rooms: " << obj.getRooms() << endl;
  sout << "Number of Walls: " << obj.getWalls() << endl;
  if (obj.HasWasher() == 1){
    sout << "Washer: " << "true" << endl;
  }
  else{
    sout << "Washer: " << "false" << endl;
  }
  sout << "Number of Windows: " << obj.NumWindows() << endl;
  sout << "Property Value: " << obj.PropertyValue() << endl;
  return sout;
}
