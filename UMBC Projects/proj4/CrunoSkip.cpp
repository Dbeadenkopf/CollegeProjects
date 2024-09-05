#include <iostream>
#include <cstring>
#include "game.h"
#include "CrunoSkip.h"
#include "newCrunoGame.h"
using namespace std;
CrunoSkip::CrunoSkip(){
  // empty default ccnstructor
}
// using the playcard to access the CrunoGame to skip players
void CrunoSkip::playCard(Game *gptr, Player *pptr){
  newCrunoGame *cgptr; 
  cgptr = dynamic_cast<newCrunoGame*>(gptr);
  gptr->nextPlayer();
}


