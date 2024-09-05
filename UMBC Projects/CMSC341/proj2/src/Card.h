// This is the header file that will contain
// the prototypes that will build an instance
// of a card that players can use and base thier strategy
// off of, the card will need 3 objectives which each objective
// contains a Destination, Commodity, and Payoff

#ifndef CARD_H_
#define CARD_H_

#include <iostream>
#include <cstring>
#include <vector>
#include "Objective.h"
#include "Commodity.h"

class Card
{
  // The prototype for the member function 
  // which will insert a single objective 
  // into the card
  void addObjective(Objective* objective);

  // The prototype for the member function
  // that will return a pointer to the objective that
  // has the best payoff, which allows the players
  // to utilize thier payoff strategy easier
  Objective* getBestPayoff();

  // returns a pointer to the objective that
  // has the first alphabetic destination name
  // which makes it easier for the player to look
  // at because it will compare destinations
  // and return a pointer to the destination
  // that has the first alphabet in comparison
  Objective* getFirstAlphaDestination();

  
  // prototype of the member function that returns a 
  // pointer to the objective with a commodity whose color
  // matches the requested color.(One of the color strategies
  // that the player may choose) If more than one objective has
  // that color, returns the color that was requested who has
  // the highest payoff. If no commodities on the card have 
  // the color requested, return the objective with the
  // highest payoff
  Objective* getByColor(Commodity::COLOR color);

  // The prototype of the member function that 
  // prints the card with it objectives in the order they
  // were read in from the file to the given output
  // ex. (--------CARD-------)
  // <commodity_name> to <destination> for <payoff>
  // same scheme
  // same scheme
  // what file does it read from?
  void printCard(ofstream& fileStream);



 private:
  vector<Objective*> m_objectives; // the vector that holds all the 
  // objectives available on a single card in the order they appear
  // on the card aka (order they are read in from the file)
  
};




#endif
