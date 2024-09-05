#ifndef CRUNODRAW2_H
#define CRUNODRAW2_H
#include "card.h"
#include "newCrunoGame.h"
class Draw2 : public Card{
 public:
  Draw2(unsigned int suit, unsigned int points);
  void playCard(Game *gptr, Player *pptr);





};

#endif
