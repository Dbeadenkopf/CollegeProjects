#ifndef CRUNOPLAYER_H
#define CRUNOPLAYER_H
#include "player.h"
#include "card.h"
#include "Cruno8.h"
#include "newCrunoGame.h"
class CrunoPlayer : public Player
{
 public:
  // not sure why we would need this
  CrunoPlayer(Game *gptr,unsigned int numCards);
  Card *playOneCard(bool &lastCard, bool &oneCardLeft);
  unsigned int pickSuit();
  void takeCard(Card *cptr);
  void showCardToPlayer(const Card *cptr, unsigned int player, bool oneCardLeft);


};


#endif
