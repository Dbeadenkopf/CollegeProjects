#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class test
{
public:
  test(){
    count++;
  }
  int invokeCount() {
    return count++;
  }
  void report() const{
    cout << "Number times constructor has been called" << count << endl;
  }
private:
  int count;
};

class tester : public test{
public:
  tester(){
    //empty
  }

};


int main(){
  test *obj2;
  obj2 = new test;
  obj2->invokeCount();
  obj2->invokeCount();
  obj2->report();
  return 0;
}
