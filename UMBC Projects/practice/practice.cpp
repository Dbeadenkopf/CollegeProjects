// we are gonna practce a little polymorphism

#include <iostream>

using namespace std;


class B{
public:
  virtual void S() = 0; //pure virtual function
  
};

// below we made a class D and are
// deriving from the base class B
class D: public B {
public :
  void S(){
    cout << "Virtual function in the Derived class\n";
  }

};



int main(){
  B *b;
  D dobj;
  b = &dobj;
  b->S();// using the object pointer b to invoke
  // the function within b

  

  return 0;
}
