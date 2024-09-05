#include "Pokemon.h"


using namespace std;

Pokemon::Pokemon(){
  m_Num = 0; // varible to hold pokemon`s number
  m_Name = "pixelGuy"; // varible to hold pokemons string name
  m_MinCP = 0; // varible to hold pokemons Min CP
  m_MaxCP = 0; // varible to hold pokemons Max CP
  m_Rarity = 0;
}

Pokemon::Pokemon(int num, string name, int cpMin, int cpMax, int rarity){
  m_Num = num; // varible to hold pokemon`s number
  m_Name = name; // varible to hold pokemons string name
  m_MinCP = cpMin; // varible to hold pokemons Min CP
  m_MaxCP = cpMax; // varible to hold pokemons Max CP
  m_Rarity = rarity;
}


int Pokemon::GetCPMin(){
  return m_MinCP;
}

int Pokemon::GetCPMax(){
  return m_MaxCP;
} 

int Pokemon::GetRarity(){
  return m_Rarity;
}
 
string Pokemon::GetName(){
  return m_Name;
}

int Pokemon::GetNum(){
  return m_Num;
}

int Pokemon::GetNewCP(){
  return m_newCP;
}
 
//Setters, take in new values
// and update member varibles
void Pokemon::SetRarity(int newRarity){
  m_Rarity = newRarity;
} // sets the rarity of the pokemon
void Pokemon::SetName(string newName){
  m_Name = newName;
} // sets the name of the pokemon

void Pokemon::SetCP(int newCP){
  m_newCP = newCP;
} // sets t

void Pokemon::dump() const{
  cout << "Pokemon number = " <<   m_Num  << endl;; // varible to hold pokemon`s number
  cout << "Pokemon name = " << m_Name << endl; // varible to hold pokemons string name
  cout << "Pokemon minumimum cp =  " << m_MinCP << endl; // varible to hold pokemons Min CP
  cout << "Pokemon maximum cp = " << m_MaxCP << endl; // varible to hold pokemons Max CP
  cout << "Pokemon rarity = " << m_Rarity  << endl;
}

