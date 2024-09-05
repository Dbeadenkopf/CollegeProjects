// The .cpp file for commodities, the file containes
// the implementation from the commodity headerfile

#include <iostream>
#include <cstring>
#include <string>
#include "Commodity.h"
using namespace std;

// the Default constructor 
// that sets the varibles
// to thier default value
Commodity::Commodity(){
  m_sName = "none";
  m_eColor = COLORLESS;
}

Commodity::~Commodity(){
  // empty atm until I know
  // what will be destroyed
  //delete m_sName;
  //delete m_eColor;
  //delete pointer;
}


// the Constructor that takes in a string name
// and a color which the passed in color will
// be linked to the enumeration, the constructor
// will then set the private member varibles
// to the passed in arguements
Commodity::Commodity(string Name, COLOR color){
  m_sName = Name;
  m_eColor = color;
}

// getter which returns the name of
// a commodity as a string
string Commodity::getName() const{
  return m_sName;
}

// getter to return the color of type COLOR
// which is the type name given to the enumeration
Commodity::COLOR Commodity::getColor(){
  return m_eColor;
}

