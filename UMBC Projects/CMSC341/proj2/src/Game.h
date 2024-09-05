#ifndef GAME_H_
#define GAME_H_
#include <vector>
#include <stack>
#include <fstream>
#include "Card.h"
#include "Player.h"
using namespace std;

class Game{
 public:
  // runs through the simulations of playing the game using the
  // given strategy with the given number of players
  void runSimulation(int players, Player::STRATEGY strategy);

  //prints the current state(meaning, the pile has not been 
  // altered yet in anyway) of the drawPile to a given output stream
  // GOING TO READ FROM THE CARD.TXT FILE
  void printDrawPile(ofstream& fileStream);


  // prints the results of the simulation
  // to the given output stream
  // this function is only reading from a file
  void printResults(ofstream& fileStream);

 private:
  // The data structure to be used to store the deck of cards
  stack<Card*> m_drawPile;

  // The data structure to be used to store the list of players
  vector<Player*> m_players;


};

#endif
