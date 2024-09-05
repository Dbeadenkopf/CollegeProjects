#include <iostream>
#include "human.h"

using namespace std;








int main(){
  Human Obj1;
  string testname = "David";
  int age = 25;
  Obj1.SetHumanName(testname);
  Obj1.SetHumanAge(age);
  Obj1.SetBirthMonth("May");
  Obj1.SetBirthYear(1993);
  Obj1.setBirthDay(20);
  Obj1.Output();


  return 0;
}
