// This is the header file that contains the 
// Commodity enitity, for each comodity 
// that is passed in from the .txt file
// it will be given a c++ entity here

#ifndef COMMODITY_H_
#define COMMODITY_H_
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Commodity{
 public:
  // an enumeration that holds the varibles PURPLE -  COLORLESS
  // the PURPLE = index 0 and COLORLESS = index 6
  // the enumeration is of type COLOR so that varibles or
  // instances can be made of type COLOR to then have 
  // access to the color indexes in the enumeration
  enum COLOR{ PURPLE, RED, ORANGE, BLACK, GREEN, BROWN, COLORLESS};

  // default constructor that 
  // gives the data members thier default values
  Commodity();

  // constructor that takes in passed string values
  // and a specific index of the enum type color
  Commodity(string Name, COLOR color);

  

  // the destructor that accounts for memmory 
  // management
  ~Commodity();

  // getter function to  return the string 
  // of the name of a commodity
  string getName() const; 

  // getter function to return the
  // COLOR of the enum index of a commodity color
  COLOR getColor();


 private:
  string m_sName; // varible to store the string name of a Commodity
  COLOR m_eColor;// varible of enum Type Color which will hold an index
  // of the COLOR enum and the color of a commodity
};




#endif





















