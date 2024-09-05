#ifndef CONTINENT_H_
#define CONTINENT_H_
#include <iostream>
#include <cstring>
#include <ostream>
#include <vector>
#include <algorithm>
#include "Country.h"

using namespace std;
// This file will repilicate a continent and will hold 
// each continents countries information such as the highest popultation
// highest gross domestic product spent and highest literacy rate
class Continent : public Country
{

 public:
  Continent();
 
  Continent(string N, vector<Country> obj, string C);

  // getter to get the countries of Continent
  vector<Country> getCC() const;
  
  // setter to set the countries of Continent
  void setCC(vector<Country> & CC);
  

  // getter to get the Highest population of Country
  Country getHighPop() const;
  
  // setter to set highest population of Country
  void setHighPop(Country HP);


  // getter to get Gross Domstic product Spent
  Country getGDPspent() const;

  // setter to set Gross Demestic Product Spent
  void setHDPspent(Country GPD);
  

  // getter to get literacy rate of Country
  Country geth_LitRate() const;

  // setter to set literacy Rate of Country
  void seth_LitRate(Country LR);


 private:
  string name;
  string conT;
  vector <Country> countriesinContinent; // vector of type Country, holds the countries within Continent
 
  Country highestPopulation; // highestPop object of type Country
  Country highestGDPSpent; // highestGDP Spent object of type Country 
  Country highestLiteracyRate; // highest Literacty Rate object of type Country
};


// overloaded ostream cout to display the Continent with rank and
// highest population. Then, display the country with heighest literacy rate
// as well as the Continent`s country along with that coutries population. Then,
// display heighest GDP spent on education along with that countries population 
// and literacy rate. Finnally, display country of Continent with highest population
// (name, pop# and literacy rate);
std::ostream & operator<<(std::ostream& outStream, const Continent& obj);



#endif
