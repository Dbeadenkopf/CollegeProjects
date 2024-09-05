//
// TrainCar.cpp
// 
// CMSC 202 Project file
//
// COMPLETE THE IMPLEMENTATION AS INSTRUCTED
//

#include <iostream>
#include "TrainCar.h"
#include "Time.h"
using namespace std;

// default Constructor
TrainCar::TrainCar(){ 
  m_type = NoType;
  m_next = NULL; 
}
// alternate constructor which sets type of car and a pointer to 
// the next cart node
TrainCar::TrainCar( TrainCar::cType car ){
  m_type = car;
  m_next = NULL; 
}
// setter to set the cart type
void TrainCar::setType( TrainCar::cType car ) {
  m_type = car;
}
// getter to get the car type
TrainCar::cType TrainCar::getType() const {
  return m_type;
}
// overloaded ostream operator to allow for main to cout objects 
std::ostream& operator<< (std::ostream& outStream, const TrainCar& car){
  switch (car.getType()){// putting each car type through a switch
  case 0:// case for each cart
    outStream << "// Locomotive ]]";
    break;
  case 1:
    outStream << "[ oo Coach oo ]";
    break;
  case 2:
    outStream << "[ Businesss ]";
    break;
  case 3:
    outStream << "[ -  Dining - |";
    break;
  case 4:
    outStream << "[ -- Snack -- ]";
    break;
  case 5:
    outStream << "[ o Sleeper o ]";
    break;
  case 6:
    outStream << "Invalid Cart";
    break;
  }
  return outStream;
}
