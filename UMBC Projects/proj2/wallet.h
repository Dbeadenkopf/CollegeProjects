#ifndef WALLET_H_
#define WALLET_H_
#include "wager.h"

class Wallet : public Wager
{
 public:
  Wallet();
  Wallet(double Amount);
 
  void outPut(const Wallet& obj);



 private:
  double holdAmount;
};

#endif
