#include <string>
#include <iostream>
#include "wager.h"
#include "pokerhand.h"
#include "card.h"
using namespace std;
Wager::Wager(){
  amount = 100.00;
  symboL = '$';
  counter = 0;
}
Wager::Wager(double aM){
  amount = aM;
}
void Wager::setAmount(double u_Amount){
  amount = u_Amount;
}
void Wager::setSymbol(char S){
  symboL = S;
}
double Wager::getAmount() const{
  return amount;
}
int Wager::returnCount() const{
  return counter;
}
char Wager::Symbol() const{
  return symboL;
}
void Wager::outPut(){
  cout << "                      *" << "*****" << "*" << "***" << "**" << "********" << endl;
  cout << "                      * " << symboL << "" << amount << " " << "Current wager" << " *" << endl;
  cout << "                      *" << "*****" << "*" << "***" << "**" << "********" << endl;
}
