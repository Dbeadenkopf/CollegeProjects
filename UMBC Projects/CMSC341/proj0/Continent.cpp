#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include "Coninent.h"
using namespace std;


// this is the file that displays the results of the continent calculations
// just getters and setters mostly 
Continent::Continent(){
  //
}

Continent::Continent(string N, vector<Country> obj, string C){
  name = N;
  countriesinContinent = obj;
  conT = C;
  if(name == "NORTH-AMERICA" && name == " "){
    cout << "***" << endl;
    cout << "*  *" << endl;
    cout << name << endl;
    cout << "*  *" << endl;
    cout << "***" << endl;
  }
  else{
    cout << name << endl;
  }
  for (unsigned int i = 0; i < countriesinContinent.size(); i++){
    cout << countriesinContinent[i].getName() << endl;
  }
}


vector<Country> Continent::getCC() const{
   return countriesinContinent;
}

// setter to set the countries Continent
void Continent::setCC(vector<Country> & CC){
  countriesinContinent = CC;
}

// getter to get the Highest population
Country Continent::getHighPop() const{
  return highestPopulation;
}

// setter to set highest population
void Continent::setHighPop(Country HP){
  highestPopulation = HP; // varible that is of type country gets the passed in parmeter of type country
}

// getter to get Gross Domstic product Spent
Country Continent::getGDPspent() const{
  return highestGDPSpent;
}

// setter to set Gross Demostic Product Spent
void Continent::setHDPspent(Country GPD){
  highestGDPSpent = GPD;
}


// getter to get literacy rate
Country Continent::geth_LitRate() const{
  return highestLiteracyRate;
}

// setter to set literacy Rate
void Continent::seth_LitRate(Country LR){
  highestLiteracyRate = LR;
}

std::ostream & operator<<(std::ostream& outStream, const Continent& obj){
  // design can go here outStream << Continet.get
  
  outStream << obj.getName() << endl;
  outStream << "Population: " << obj.getPop() << endl;
  outStream << "Country with highest literacy rate: " << obj.getName() << " with a populations of " << obj.getPop() << "and a literacy rate of " << obj.getLit() << endl;
  outStream << "country with highest GPD expenditure on education: " << obj.getName() << " with a populations of " << obj.getPop() << "and a literacy rate o\
f " << obj.getLit() << endl;

  outStream << "country with highest population: " << obj.getName() << " with a populations of " << obj.getPop() << "and a literacy rate o\
f " << obj.getLit() << endl;
;
  return outStream;
}
