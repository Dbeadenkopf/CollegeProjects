// This file will implement the instance
// of a single pokemon in the pokemon game
// when they are encountered, basically 
// this header file acts as the train pokemon 
// class or the class that is used when the pokemon
// are caught, in battle, or for training them
//** the header file for a single instance of a my Pokemon ** 
// should be added to the mycollection.txt when the user decideds
// they dont want to play pokemon anymore

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <stdlib.h> // used in order to access the random functions
#include <time.h> // used this library include to use the random function generator


using namespace std;

class MyPokemon{
 public:
  // default constructor 
  // to give the varibles
  // their default values
  MyPokemon(); 
 
  // the nstructor to intilize
  // the parameter values to thier
  // mirrored varible name (or number,name, comb points, hit points, and rarity)
  MyPokemon(int num, string name, int cp, int hp, int rarity);

  //Accessors
  int GetCP(); // getter to get my Pokemons combat points
  int GetHP(); // getter to get my Pokemons HP
  int GetRarity(); // getter to get the Rarity of my pokemon (scale 1-5)
  string GetName(); // getter to get the Name of my pokemon
  int GetNum(); // getter to get the number of my pokemon

  //Mutators
  void SetRarity(int newRarity); // setter to set the Rarity of my pokemon (so rarity can develop/ a pokemon can become more rare)
  void SetName(string newName); // setter to set the name of my Pokemon(for example "STINKER" I choose you)
  void SetCP(int newCP); // setter to set the combat points of my pokemon
  void SetHP(int newHP); // setter to set the Hit Points of my Pokemon ( im assuming I could use these when battling occurs?) -> maybe

  //Member Functions
  // prototype of the function that allows for training
  // simply adds 10 CP to the Pokemon. Updates the CP of
  // the Pokemon that was trained and what thier new CP is
  void Train(); 

 private:
  int m_Num; // member varible to hold the number of the pokemon
  string m_Name; // member varible to hold the name of the pokemon
  int m_CP; // member varible to hold the CP(combat points) of the pokemon
  int m_HP; // member varible to hold the Hit points of the pokemon
  int m_Rarity; // member varible to hold the rarity of the pokemon
  //int newerCP; // member vrible to hold the new CP of the pokemon
};
