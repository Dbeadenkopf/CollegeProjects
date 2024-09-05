#include "MyPokemon.h"

MyPokemon::MyPokemon(){
  m_Num = 0;
  m_Name = "ted";
  m_CP = 0; 
  m_HP = 0; 
  m_Rarity = 0; 
}

MyPokemon::MyPokemon(int num, string name, int cp, int hp, int rarity){
  m_Num = num;
  m_Name =  name;
  m_CP = cp;
  m_HP = hp;
  m_Rarity = rarity;
}


int MyPokemon::GetCP(){
  return m_CP;
} // getter to get my Pokemons combat points                                                                                                                          
int MyPokemon::GetHP(){
  return m_HP;
} // getter to get my Pokemons HP                                                                                                                                     
int MyPokemon::GetRarity(){
  return m_Rarity;
} // getter to get the Rarity of my pokemon (scale 1-5)                                                                                                           
string MyPokemon::GetName(){
  return m_Name;
} // getter to get the Name of my pokemon                                                                                                                        
int MyPokemon::GetNum(){
  return m_Num;
} // getter to get the number of my pokemon                                                                                                                          

//Mutators                                                                                                                                                                       
void MyPokemon::SetRarity(int newRarity){
  m_Rarity = newRarity;
} // setter to set the Rarity of my pokemon (so rarity can develop/ a pokemon can become more rare)                                                 
void MyPokemon::SetName(string newName){
  m_Name = newName;
} // setter to set the name of my Pokemon(for example "STINKER" I choose you)                                                                        
void MyPokemon::SetCP(int newCP){
  m_CP = newCP;
} // setter to set the combat points of my pokemon                                                                                                          
void MyPokemon::SetHP(int newHP){
  m_HP = newHP;
} // setter to set the Hit Points of my Pokemon ( im assuming I could use these when battling occurs?) -> maybe                                             

//Member Functions                                                                                                                                                               
// prototype of the function that allows for training                                                                                                                            
// simply adds 10 CP to the Pokemon. Updates the CP of                                                                                                                           
// the Pokemon that was trained and what thier new CP is                                                                                                                         
void MyPokemon::Train(){
  int addnew;
  addnew = m_CP + 10; // adding new cp to pokemon
  this->SetCP(addnew); // invoking the cp to set it
}
