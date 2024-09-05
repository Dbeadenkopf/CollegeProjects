#include <cstring>
#include <string>
#include <iostream>
#include "game.h"
#include "card.h"
#include "player.h"
#include "Cruno8.h"
#include "newCrunoGame.h"
using namespace std;
Cruno8::Cruno8(){
  // empty constructor body
}
Cruno8::Cruno8(unsigned int suit, unsigned int point) : Card( suit, point){
  // empty constructor body
}
unsigned int Cruno8::getPoints(){
  return m_points;
}

unsigned int Cruno8::getSuits(){
  return m_suit;
}
void Cruno8::showPlayerToCard(Player *pptr){
  unsigned int holder;
  //unsigned int countH = 0;
  //unsigned int countC = 0;
  //unsigned int countD = 0;
  //unsigned int countS = 0;
  //unsigned int countI = 0;
  pptr->pickSuit();
  holder = pptr->pickSuit();
  switch(holder){
  case Clubs :
    cout << "Suit picked" << " clubs!";
    break;
  case Diamonds :
    cout << " Suit picked " << "Diamonds!" << endl;;
    break ;
  case Hearts :
    cout << " Suit picked " << "Heats!" << endl;
    break; 
  case Spades :
    cout << " Suit picked "  << "Spades!" << endl;
    break;
  default:
    cout << "of INVALID SUIT\n" ;
  }
  
}
