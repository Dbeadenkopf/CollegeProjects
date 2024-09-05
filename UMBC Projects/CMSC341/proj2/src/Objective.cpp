#include <iostream>
#include <cstring>
#include <string>
#include "Objective.h"
using namespace std;

Objective::Objective(){
  m_sDestination =  "none";
  m_pCommodity  = NULL;
  m_Payoff = 0;
}


Objective::Objective(string Dest, Commodity* Comm, int payOff){
  m_sDestination = Dest;
  m_pCommodity = Comm;
  m_Payoff = payOff;
}


string Objective::getDestination()const{
  return m_sDestination;
}


Commodity* Objective::getCommodity() const{
  return m_pCommodity;
}

int Objective::getPayoff() const{
  return m_Payoff;
}

void Objective::printObjectives(ofstream& fileStream){
  // shall open the results file and read from it I suppose
  // thats the only real way it would seem to get the 
  // objective decided by the player
}

