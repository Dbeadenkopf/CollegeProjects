//
// TrainCar.cpp
// 
// CMSC 202 Project file
//
// COMPLETE THE IMPLEMENTATION AS INSTRUCTED
//
#include <iostream>
using namespace std;

#include "TrainCar.h"

TrainCar::TrainCar() : m_type( NoType ), m_next( NULL ) 
{ /* empty constructor body */ }

TrainCar::TrainCar( TrainCar::cType car ) : m_type( car ), m_next( NULL ) 
{ /* empty constructor body */ }

void TrainCar::setType( TrainCar::cType car ) {
  m_type = car;
}

TrainCar::cType TrainCar::getType() const {
  return m_type;
}

//
// IMPLEMENT THE OVERLOADED INSERTION OPERATOR
//
