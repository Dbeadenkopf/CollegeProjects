#ifndef CRUNOREVERSE_H
#define CRUNOREVERSE_H
#include "game.h"
class CrunoRev : public Game{
 public:
  CrunoRev();
  // I choose to use the playGame function because it handles the players turns
  // using the playGame function, I was hoping to reverse play whenever this
  // created action gets dealt to a player
  void playGame();



};



#endif
