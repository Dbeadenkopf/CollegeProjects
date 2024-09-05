#ifndef CRUNO8_H
#define CRUNO8_H
#include "game.h"
#include "card.h"
#include "player.h"
#include "newCrunoGame.h"
#include "CrunoPlayer.h"
class Cruno8 : public Card{
 public:
  Cruno8();
  Cruno8(unsigned int suit, unsigned int point);
  unsigned int getPoints();
  unsigned int getSuits();
  void showPlayerToCard(Player *pptr);

};


#endif
