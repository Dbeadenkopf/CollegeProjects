//#ifndef COMMODITYSTORE_CPP_
//#define COMMODITYSTORE_CPP_

#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include "CommodityStore.h"
using namespace std;

CommodityStore::~CommodityStore(){

}


void CommodityStore::loadCommodities(string filename){
  fstream commFile;
  commFile.open(filename.c_str());
  string holdCommodity;
  //string formakeCom;
  string holdColor;
  //Commodity *makeCommodity;
  while(true){
    commFile >> holdCommodity;
    commFile >> holdColor;
    Commodity *makeCommodity;
    if (holdColor == "Purple"){
      makeCommodity = new Commodity(holdCommodity, Commodity::PURPLE);
      m_store.insert(pair<string, Commodity*>(holdCommodity, makeCommodity));
    }
    else if(holdColor == "Red"){
      makeCommodity = new Commodity(holdCommodity, Commodity::RED);
      m_store.insert(pair<string, Commodity*>(holdCommodity, makeCommodity));
    }
    else if(holdColor == "Orange"){
      makeCommodity = new Commodity(holdCommodity, Commodity::ORANGE);
      m_store.insert(pair<string, Commodity*>(holdCommodity, makeCommodity));
    }
    else if(holdColor == "Black"){
      makeCommodity = new Commodity(holdCommodity, Commodity::BLACK);
      m_store.insert(pair<string, Commodity*>(holdCommodity, makeCommodity));
    }
    else if(holdColor == "Green"){
      makeCommodity = new Commodity(holdCommodity, Commodity::GREEN);
      m_store.insert(pair<string, Commodity*>(holdCommodity, makeCommodity));
    }
    else if(holdColor == "Brown"){
      makeCommodity = new Commodity(holdCommodity, Commodity::BROWN);
      m_store.insert(pair<string, Commodity*>(holdCommodity, makeCommodity));
    }
    else{
      makeCommodity = new Commodity(holdCommodity, Commodity::COLORLESS);
      m_store.insert(pair<string, Commodity*>(holdCommodity, makeCommodity));
    }
    if(commFile.eof()){
      break;
    }
  }

  
  commFile.close();
}

Commodity* CommodityStore::getCommodity(string name){
  return m_store[name];
}



//#endif
