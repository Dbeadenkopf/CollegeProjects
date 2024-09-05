#ifndef _WAGER_H_
#define _WAGER_H_
// also could add a member function that subtracts when they loose, maybe
#include "card.h"
#include "pokerhand.h"
class Wager
{
 public:
  Wager();
  Wager(double aM);
  void setAmount(double u_Amount);
  void setSymbol(char S);
  double getAmount() const;
  // make this virtual now it can be invoked by a pointer of the wager class
  virtual int returnCount() const;
  void outPut();
  virtual char Symbol() const;
 private:
  int counter;
  char symboL;
  double amount;
};


#endif
