// The header file for the commodity store
// wich will replicate a storage place that 
// holds all the commodities and the 




#ifndef COMMODITYSTORE_H_
#define COMMODITYSTORE_H_
#include <iostream>
#include <cstring>
#include <map>
#include "Commodity.h"
#include <cstdlib>

using namespace std;

class CommodityStore : public Commodity
{
 public:

  ~CommodityStore();

  // function that takes commodities
  // that are being read in from a text file
  // commodities.txt and creates an instance
  // for each commodity and stores is in m_store
  void loadCommodities(string filename);

  // getter function that returns a commodity instance
  // given the commodity string name, so a string name
  // of the commodity will be passed in as a parameter
  // and the instance of that commodity will be returned
  // by  m_store
  Commodity* getCommodity(string name);





 private:
  map<string, Commodity*> m_store; // the data structure container that maps and instance of each commodity to it respective string name, the maps keys are of type string, and values are of type commodity pointer
  
  
};



#endif
