// this file we are going to practice pure vurtual functions 
#include <iostream>


using namespace std;

class InterFace{
public:
  virtual void method() =0;
};


class Derived : public Interface{
public:
  void method();
}
