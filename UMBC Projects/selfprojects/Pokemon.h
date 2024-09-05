// This is the header file that will
// act as creating a single instance of a single
// pokemon basically bringing each pokemon to life
// that is in the text file pokedex.txt


#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <stdlib.h> // used in order to access the random functions
#include <time.h> // used this library include to use the random function generator


using namespace std;

class Pokemon{
 public:
  //default constructor to 
  // give the pokemon thier default values
  Pokemon();

  // The constructor to set the given parameter values to
  // thier mirrored member varibles
  Pokemon(int num, string name, int cpMin, int cpMax, int rarity); 
  
  //Getters, all return the 
  // corresponding member varible
  int GetCPMin(); // getter to get the minimum combat points (how well the pokemon will perform in battle) -> there is more to CP
  int GetCPMax(); // getter to get the maximum combat points (the maximum points that the pokemon will perform in battle) - >  there is more to CP
  int GetRarity(); // getter to get the rarrity of the pokemon( scale 1-5) 5 being the rarist
  string GetName(); // getter to get the name of the pokemon
  int GetNum(); // getter to get the number of the pokemon
  int GetNewCP(); // getter to get the pokemons new cp
  //Setters, take in new values
  // and update member varibles
  void SetRarity(int newRarity); // sets the rarity of the pokemon
  void SetName(string newName); // sets the name of the pokemon
  void SetCP(int newCP); // sets the CP of the pokemon (combat points)
  
  void dump() const; // acts as a debugger for the class

  
 private:
  int m_Num; // varible to hold pokemon`s number
  string m_Name; // varible to hold pokemons string name
  int m_MinCP; // varible to hold pokemons Min CP
  int m_MaxCP; // varible to hold pokemons Max CP
  int m_Rarity; // varible to hold the number that corresponds to the rareness
  // of pokemon ex(5 = mewtwo which is rare)
  int m_newCP; // varible to hold the new cp
};
