#include <iostream>
#include <cstring>
#include <string>
#include "Fraction.h"
using namespace std;
Fraction::Fraction(){
  num = 1;
  den = 1;
}
Fraction::Fraction(int newNum, int newDen){
  num = newNum;
  den = newDen;
}
void Fraction::outPut(){
  cout << num << "/" << den << endl;
}
void Fraction::Reciprocal(Fraction& newData){
  int temp;
  temp = newData.num;
  newData.num = newData.den;
  newData.den = temp;
}
void Fraction::setFraction(int newNum, int newDen){
  num = newNum;
  den = newDen;
}
int Fraction::getNum(){
  return num;
} 
int Fraction::getDen(){
  return den;
}
