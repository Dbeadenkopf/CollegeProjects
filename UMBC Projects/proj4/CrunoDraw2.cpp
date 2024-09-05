#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "game.h"
#include "player.h"
#include "card.h"
#include "CrunoDraw2.h"
using namespace std;
Draw2::Draw2(unsigned int suit, unsigned int points) : Card(suit, points){
  // empty body
}

void Draw2::playCard(Game *gptr, Player *pptr){
  newCrunoGame *cgptr;
  cgptr = dynamic_cast<newCrunoGame*>(gptr);
  gptr->dealOneCard();
  gptr->dealOneCard();
}
