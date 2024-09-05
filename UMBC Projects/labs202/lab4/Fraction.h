#include <iostream>
#include <string>
#ifndef FRACTION_H
#define FRACTION_H
using namespace std;
class Fraction
{

 public:
  Fraction();
  Fraction(int newNum, int newDum);
  void setFraction(int newNum, int newDen);
  void outPut();
  void Reciprocal(Fraction& newData);
  int getNum();
  int getDen();
 private:
  int num;
  int den;
};

#endif
