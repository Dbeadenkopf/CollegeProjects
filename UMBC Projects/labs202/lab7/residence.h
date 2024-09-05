#ifndef RESIDENCE_H
#define RESIDENCE_H
#include <iostream>
class Residence
{
 public:
  Residence();
  Residence(int rS, int eW, bool wash);
  double PropertyValue()const;// calculates property value based on number of rooms*10000
  int NumWindows()const;
  int getRooms()const;
  int getWalls()const;
  friend std::ostream& operator<<(std::ostream& sout,const Residence& obj);
 protected:
  bool HasWasher() const;// checks for residence washer, returns true if so, else false
 private:
  int n_roomS;
  int n_ewallS;
  bool isWasher;
};


#endif
