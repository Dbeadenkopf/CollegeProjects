#include <iostream>
#include <cstring>
#include "compWallet.h"
using namespace std;
compWallet::compWallet(){
  // empty amount
}

// precondition: takes in an integer 
// postcondition: gives the parameter to
// wallets constructor which sets the amount
compWallet::compWallet(double cAmount){
  compAmount = cAmount;
}

void compWallet::outPut(const compWallet& obj){
  cout << "                      *" << "*****" << "*" << "***" << "**" << \
    "********" << endl;
  cout << "                      * " << obj.Symbol() << "" << compAmount << " "\
       << "\
 Comp wallet" << " *" << endl;
  cout << "                      *" << "*****" << "*" << "***" << "**" << \
    "********" << endl;


}
