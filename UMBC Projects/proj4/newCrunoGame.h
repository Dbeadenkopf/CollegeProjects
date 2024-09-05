#ifndef NEWCRUNOGAME_H
#define NEWCRUNOGAME_H
#include "game.h"
#include "Cruno8.h"
#include "card.h"
#include "CrunoPlayer.h"
#include "CrunoSkip.h"
#include "CrunoDraw2.h"
class newCrunoGame : public Game
{
 public:
  newCrunoGame();
  // using or inheriting this function to
  // add the (crazy 8 card) to the deck
  void initialize(int numPlayer);
  unsigned int getNumCards();
  void addPlayer(Player *pptr);
  void startGame(unsigned int seed) ;
  void playGame();
  unsigned int nextPlayer();
  unsigned int playerAfter(unsigned int thisPlayer);
  Card * dealOneCard();
  
};

#endif
