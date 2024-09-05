#include <iostream>
#include <cstring>
#include "card.h"
using namespace std;
int main(){
  // need to think of better way to get a suit in for on of the paremeters or this may be the
  //only means of doing s
  
  Card sel(Card::Clubs, 14);
  Card sel2(Card::Hearts, 13);
  if (sel.suit() == 1){
    cout << "THe returning suit function is working" << endl;
  }
  sel2.print();
  // probelbly will need some setters and getters because we cannot print out the value if they enter invalid values
  // ex user enters 0 but still use an boject call to print cannot happen





  return 0;
}
