#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <stack>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Commodity.h"
#include "Objective.h"
#include "Player.h"
#include "Game.h"
#include "CommodityStore.h"
using namespace std;
void printGreating();

int main(int argc, char ** argv){
  cout << "argc " << argc << endl;
  for(size_t i = 0; i < argc; i++){
    cout << "argv[" << i << "]" << argv[i] << endl;
  }
  //  printGreating();
  stack<string> deck;
  fstream inputStream;
  fstream commFile;
  ofstream cardFile;
  string holdCommodity;
  //string holdColor;
  // int fileColor;
  // how will we link the color to the 
  inputStream.open("cards.txt");
  //cardFile.open("cards.txt");
  //commFile.open("commodities.txt");
  string allCards;
  Game tester;
  tester.printDrawPile(cardFile);
  //Commodity::COLOR fileColor;
  // the commodity class works
  // Commodity *makeCommodity;
  //  cout << obj.getName() << endl;
  //cout << obj.getColor() << endl;
  int counter = 0;
  //while(true){
    //commFile >> holdCommodity;
    //commFile >> holdColor;
  while(true){
    inputStream >> allCards;
    deck.push(allCards);
    counter++;
    if(inputStream.eof()){
      break;
    }
  }
  holdCommodity = "commodities.txt";
  CommodityStore readFile;
  //Commodity *ptr;
  
  readFile.loadCommodities(holdCommodity);
  for (int i = 0; i < counter; i++){
    cout << deck.top() << endl;
    readFile.getCommodity(deck.top());
    deck.pop();
  }

 
  //Commodity *p;
  //readFile.getCommodity("Bauxite");

  //cout << *ptr << endl;
 
  
  // this top to pop is the way of looking
  // at the card.txt items in a realistic stack
  // implementation, this may be the way they
  // will need to be passed in to the card class
  // or perhaps to be read and passed in all together
  //for (int i = 0; i < counter;i++){
    // cout << deck.top() << endl;
    //deck.pop();
  // }
  printGreating();  


  inputStream.close();
  //commFile.close();
  return 0;
}

void printGreating(){
  ofstream inStream;
  inStream.open("results.txt");
  while(true){
    inStream << "David Beadenkopf" << endl;
    inStream << "section: Chang 10:00 am Tu-Thu" << endl;
    break;
  }
  inStream.close();
}
