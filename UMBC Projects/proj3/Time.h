#ifndef TIME_H
#define TIME_H
#include <iostream>
using namespace std;
// class Time which will hold the prototypes 
class Time {
 public:
  // default constructor
  Time();
  // alternate constructor
  Time(int h, int m);
  // accesor
  Time(int m_Min);
  // overloaded plus operator for two objs of class Time
  const Time operator+( const Time& addT);
  // getter to get the hour integer
  int getHour()const;
  // getter to get the min integer
  int getMin() const;
 private:
  // data members hours and minutes both
  // of type int
  int hours;
  int minutes;
};
// ostream overloaded operator to output times
std::ostream& operator<<(std::ostream &outStream,const Time& t);
// comparison overloaded operator
bool operator<(const Time& obj1, const Time& obj2);

#endif
