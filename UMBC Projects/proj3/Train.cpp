//
// Train.cpp
// 
// CMSC 202 Project File
//
// TWO CONSTRUCTORS ARE GIVEN.  IMPLEMENT THE REMAINDER OF
// THE CLASS AND THE OVERLOADED INSERTION OPERATOR
//

#include <iostream>
#include "TrainCar.h"
#include "Train.h"
#include "Time.h"
#include <ostream>
using namespace std;

// Default constructor.  Initialize variables and create dummy node.
Train::Train(){
  m_number = 0;
  m_departs = Time();
  m_destination = "";
  m_hasSnackCar = false;
  m_numCoachClass = 0; 
  m_numBusinessClass = 0; 
  m_numSleepingCar = 0; 
  m_head = new TrainCar(); // dummy node
}

void addCar( TrainCar::cType car){
  TrainCar* current;
  TrainCar* newCar;
  //current = current->m_next;
  newCar = new TrainCar(car);
  // this switch statement works
  // perfect I just have to account
  // for all the Trains now
  // to get it to work
  // trying to switch with an enum type
  switch(car){
  case 0:
    while(current->m_next!= NULL){
      current = current->m_next;// trains also have to be in
    }                           // a certain postition
    current->m_next = newCar;
    break;
  case 1:
    while(current->m_next!= NULL){
      current = current->m_next;
    }
    current->m_next = newCar;
    break;
  case 2:
    while(current->m_next!= NULL){
      current = current->m_next;
    }
    current->m_next = newCar;
    break;
  case 3:
    while(current->m_next!= NULL){
      current = current->m_next;
    }
    current->m_next = newCar;
    break;
  case 4:
    while(current->m_next!= NULL){
      current = current->m_next;
    }
    current->m_next = newCar;
    break;
  case 5:
    while(current->m_next!= NULL){
      current = current->m_next;
    }
    current->m_next = newCar;
    break;
  case 6:
    while(current->m_next!= NULL){
      current = current->m_next;
    }
    current->m_next = newCar;
    break;
  }
  // we are now inserting a car into the zero posistion this is 
  // absolutly correct and we can absoluty finish this :)

}

//} // used comment brackets here
// Non-default constructor.  Initialize variables and create dummy node.
Train::Train( int num, Time dep, string dest){
  m_number = num; // can take in a number from the main
  m_departs = dep; // can take in a dep time for the train,
  m_destination = dest; // can get a destination
  m_hasSnackCar = false;
  m_numCoachClass = 0; 
  m_numBusinessClass = 0;
  m_numSleepingCar = 0; 
  m_head = new TrainCar(); // dummy node
}
// destructure for memory management 
Train::~Train(){
  TrainCar *derail, *nextT;
  derail = m_head;
  while(derail != NULL){
    nextT = derail->m_next;
    delete derail;
    derail = nextT;
  }
}
//void addCar( TrainCar::cType car);
// gettter to get number of train
int Train::getNumber() const{
  return m_number;
}
// setter to set a number to train
void Train::setNumber(int num){
  m_number = num;
}
// gettter for getting current departure time
Time Train::getDepartureTime() const{
  return m_departs;
}
// setter for setting departer times
void Train::setDepartureTime( const Time& t ){
  m_departs = t.getHour();
  m_departs = t.getMin();
}
// gettter to get the current despination of train
string Train::getDestination() const{
  return m_destination; 
}
// setter to set destination of Train
void Train::setDestination( string dest ){
  m_destination = dest;
}
// gives full display of train once it has beem structured
// also gives departure time, destination, and number of each train
std::ostream& operator<<(std::ostream& outStream, const Train& t){  
  outStream << "#" << t.getNumber() << "to " << t.getDestination() << "departs at " << t.getDepartureTime() << endl;
  return outStream; // this operator ostream is not workig
}
// my intention here ^^^^^ was to have a graphical display of the departure time, description, and number of the train
// but with the error, I attempted to solve it but could not

//
// IMPLEMENT THE REMAINDER OF THE CLASS AND THE OVERLOADED
// INSERTION OPERATOR
//
