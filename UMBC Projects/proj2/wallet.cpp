#include <iostream>
#include <cstring>
#include "wallet.h"
using namespace std;
Wallet::Wallet(){
  // empty
}

Wallet::Wallet(double Amount){
  holdAmount = Amount;
}


void Wallet::outPut(const Wallet& obj){
  cout << "                      *" << "*****" << "*" << "***" << "**" << \
    "********" << endl;
  cout << "                      * " << obj.Symbol() << "" << holdAmount << " " << "\
 Player wallet" << " *" << endl;
  cout << "                      *" << "*****" << "*" << "***" << "**" << \
    "********" << endl;
  

}
