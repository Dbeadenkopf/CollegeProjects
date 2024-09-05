#include <iostream>
#include <cstring>
#include "pokerhand.h"
#include "card.h"
using namespace std;
int main(){
  Card obj1(Card::Diamonds, 10);
  Card obj2(Card::Spades, 14);
  Card obj3(Card::Clubs, 12);
  Card obj4(Card::Hearts, 11);
  Card obj5(Card::Spades, 13);
  //obj1 = Card(Card::Diamonds, 10);
  //obj2 = Card(Card::Spades, 14);
  //obj3 = Card(Card::Clubs, 12);
  //obj4 = Card(Card::Hearts, 11);// possibley short circuit evaluates
  //obj5 = Card(Card::Spades, 13);

  PokerHand hand, handofCards(obj1,obj2, obj3, obj4, obj5);
  hand.printRank();
  handofCards.printCards();
  if (handofCards.isRoyalFlush() == true){// could put result here for testing thenput it back into function
    cout << "Found royal flush" << endl;
  }



  return 0;
}
