#ifndef COMPWALLET_H_
#define COMPWALLET_H_
#include "wager.h"

class compWallet : public Wager
{
 public:
  compWallet();
  compWallet(double cAmount);

  void outPut(const compWallet& obj);



 private:
  double compAmount;
};

#endif
