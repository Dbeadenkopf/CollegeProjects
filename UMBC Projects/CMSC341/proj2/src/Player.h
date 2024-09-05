// the headerfile that will create a single 
// player instance


#ifndef PLAYER_H_
#define PLAYER_H_
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include "Card.h"
#include "Objective.h"
using namespace std;

class Player{
 public:
  // the enumertation that houses all the players strategies
  // bascially acts as the brain of the player
  enum STRATEGY {BESTPAYOFF, FIRST_ALPHA_DESTINATION, COLOR_PURPLE, COLOR_RED, COLOR_ORANGE, COLOR_BLACK, COLOR_GREEN, COLOR_BROWN};

  // the prototype of the function
  // that should return the string of a 
  // name in the player format "Player #"
  string getName() const;



  //  should return the score received by the player after
  // running the simulations,defaults to zero
  int getScore() const;

  // adds a given card to the players hand 
  void addCard(Card* card);

  // processes the players hand using the given strategy, storing the resulting
  // objectives selected in m_objectives and the resulting score in an internal variable of
  // your choosing. This function should be able to be run on the player’s hand multiple
  // times each time the selected objective should be reset before processing the hand
  int calculateScore(Player::STRATEGY strategy);



  //  prints the resulting objectives selected by the player from each card and
  // the player’s final score
  void printResult(ofstream& fileStream);



 private:
  string m_sName; // The players name to be printed in the output file
  // format "Player #"

  // the data structure for holding the cards in the players hand in the order the cards were dealt to the player 
  queue<Card*> m_cards;  

  // the data structure for holding the selected objectives for each card in the players hand during the simulation in the order the cards were dealt to the player 
  queue<Objective*> m_objectives;
  

};






#endif
