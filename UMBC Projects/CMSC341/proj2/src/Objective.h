// this is the header file that will contain the 
// prototypes needed for the simulation of the
// three objectives of each card. The class
// will create an instance for each objective
// needed for the players to make thier decissions
// and each objective contains a destination, commodity
// and payoff

#ifndef OBJECTIVE_H_
#define OBJECTIVE_H_
#include <fstream>
#include "Commodity.h"

using namespace std;
class Objective
{ 

 public:

  Objective();

  Objective(string Dest, Commodity* Comm, int payOff); 


  // prototype that returns a copy of the name of
  // the destination by string type
  string getDestination() const;

  // prototype that returns a reference to the
  // commodity that was requested by this
  // objective from the commodity store
  Commodity* getCommodity() const;


  // prototype that returns an integer
  // which is a copy of the value recieved 
  // for delivering the commodity to its desination
  int getPayoff() const;
 
     // prototype for the function, that will read from
  // the results file, and prints the objective
  // as selected by the player(using his/her strategy)
  // in simulation to the given output stream.
  // ex. "<commodity> to <destination> for <payoff> " 
  void printObjectives(ofstream& fileStream);


 private:
  string m_sDestination; // varible that will hold the name of the 
  // destination that the commodity should be delivered
  
  Commodity* m_pCommodity; // pointer varible to the instance in
  // the commodity store of the commodity being requested in this objective
  // so each objective will look to the commodity store to see what its commodity
  // is for this instance of an objective

  int m_Payoff; // integer varible that will hold the amount the player will recieve for delivering this commodity to its destination, holds the number amount that is connected to the commmodity
  

};



#endif
