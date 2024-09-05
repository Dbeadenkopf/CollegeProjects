#include <iostream>
#include <string>
#include "Time.h"
#include "TrainCar.h"
#include "Train.h"
using namespace std;
// default constructor that sets hours and minutes to 0
Time::Time(){
  hours = 0;
  minutes = 0;
}
// alternate constructor allos values to be passed from main
Time::Time(int h, int m){
  hours = h;
  minutes = m;
}
// accessor to allow for a single integer to be added to minutes
Time::Time(int m_Min){
  minutes = m_Min;
}
// getter to get hours
int Time::getHour()const {
  return hours;
}
// getter to get mins
int Time::getMin()const {
  return minutes;
}
// basically jus ttrying to get times to  (14:30) nice times
// need to account for larger times and ones that dont need 00
std::ostream& operator<<(std::ostream &outStream,const Time& t){ // maybe two objs ? will fix our integer probelm
  int withinMin = t.getMin(); 
  int withinHour = t.getHour();// error is that when an integer gets added to the obj it creates a huge integer number 
  int increaseHour = 0;
  // while value holding the minutes is greater that 60
  // (-) by 60 and increment the counter 
  while (withinMin >= 60){
    increaseHour++;
    withinMin = withinMin - 60;
    withinHour = withinHour + increaseHour;// add counter to integer value to inc
  }
  if (withinHour < 10 && withinMin < 10){
    outStream << "0" << withinHour << ":" << "0" << withinMin << endl;
  }
  if (withinHour > 10 && withinMin > 10){
    outStream << withinHour << ":" << withinMin << endl;
  }
  if (withinHour < 10 && withinMin > 10){
    outStream << "0" << withinHour << ":" << withinMin << endl;
  }
  if (withinHour > 10 && withinMin < 10){
    outStream << withinHour << ":" << "0" << withinMin << endl;
  }
  return outStream;
}
// overloaded adding operator to add hours and mins objects
const Time Time::operator+( const Time& addT){
  return Time(addT.getHour() + hours, addT.getMin() + minutes);
}
// overloaded comparison to compare two objects of time in main
bool operator<(const Time& obj1, const Time& obj2){
  return (obj1.getHour() < obj2.getHour());
}
