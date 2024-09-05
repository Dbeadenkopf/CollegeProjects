#include <iostream>
#include "Train.h"
#include "TrainCar.h"
#include <string>
#include "Time.h"
using namespace std;
int main(){
  Train obj;
  obj.addCar(TrainCar::Locomotive);
  return 0;
}
