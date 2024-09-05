#include <iostream>
#include <cstring>
#include <vector>
#include "Card.h"
//#include "Objective.h"

using namespace std;


void Card::addObjective(Objective* objective){
  m_objectives.push_back(objective);
}



// am i suppose to look for the objective in this 
Objective* Card::getBestPayoff(){
  // for (unsigned int i = 0; i < m_objectives.size(); i++){
  //if (m_objectives[i].getPayoff() > m_objectives[i+1].getPayoff()){
  //  return m_objectives[i];
  //}
  //} 
  return NULL;
}



Objective* Card::getFirstAlphaDestination(){
  return NULL;
}


Objective* Card::getByColor(Commodity::COLOR color){
  return NULL;
}



void Card::printCard(ofstream& fileStream){
  
}

