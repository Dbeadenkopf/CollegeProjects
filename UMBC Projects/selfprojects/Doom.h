#ifndef DOOM_H_
#define DOOM_H_
// this is the interface for the game of doom /////
// *** ///////////////////////////////***////////
//***//////////D O O M//////\\////////////////
/***"''''''''''" "" "  "
| kills: 0    |  " "  "
| Monsters: 0 |||||||||
| The Undead:0 |
| savedLives: 0|
|//?//?//?//?//|
*/

class Doom {
  Doom();
  Doom( // just use the game class for cruno game here




 private:
  // counting number of players in the game
  unsigned int m_numPlayers;

  // counting the maximum number of players in a game
  unsigned int m_maxPlayers;

  // passage varible to allow you to go to the next stage
  unsigned int passage;
};


#endif
