#include <string>
#include <iostream>
#include "TrainCar.h"
#include "Train.h"
#include "Time.h"
using namespace std;
int main(){
  TrainCar obj(TrainCar::Locomotive);
  TrainCar obj2(TrainCar::SnackCar);
  TrainCar obj3(TrainCar::SnackCar);
  TrainCar obj4(TrainCar::NoType);
  cout << obj << obj2 << obj3 << obj4 << endl;
  cout << "Testing noType" << endl;
  cout << obj4 << endl;
  Time test(3 , 4);
  cout << test;
  Time t0(13,55);
  Time t1(14, 00);
  bool b = (t0 < t1);
  bool c = ((t1) < t0); 
  cout << "Result (C) = " << c << endl;
  cout << "Result (B) = " << b << endl;
  // Train obj4(0);
  return 0;
}
