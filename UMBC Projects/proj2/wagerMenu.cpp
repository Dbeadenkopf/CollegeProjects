#include <iostream>
#include <cstring>
#include "wagerMenu.h"
#include "wager.h"
using namespace std;

Menu::Menu(){
  u_Num = 0;
}

Menu::Menu(int num){
  u_Num = num;
}

Menu::Menu(char choice){
  takechoicE = choice;
}

int Menu::getNum(){
  return u_Num;
}

char Menu::getChoice(){
  return takechoicE;
}

void Menu::setNum(int setNum){
  u_Num = setNum;
}

void Menu::setSymbol(char S){
  symboL = S;
}

char Menu::Symbol() const{
  return symboL;
}

// needs to then lead into this menu
void Menu::outPut(const Menu& newMenu) const{

  cout << "--------------------------------------------------" << endl;
  cout << "| (1)      (2)       (3)      (4)       (5)      |" << endl;

  // to be displayed before every number
  // based of the user selection
  cout << "|" << newMenu.symboL <<"10   " << "   " <<        newMenu.symboL <<      "100    " << newMenu.symboL  << "1,000     Check     \
 Fold     |" << endl;
  cout << "|________________________________________________|" << endl;
 

}


// for the set symbol, an outStream statement will need to go
// before each number but for now just testing //
std::ostream& operator<<(std::ostream& outStream, Menu& fMenu){
  // logic needs to occur here for it to work
  if (fMenu.getChoice() == 'y'){
    fMenu.setSymbol('?');
    outStream << "------------------------------" << endl;
    outStream << "| (1)      (2)       (3)      |" << endl;
    
    outStream << "|" << fMenu.Symbol() <<"10   " << "   " <<        fMenu.Symbol() <<      "100    " << fMenu.Symbol()  << "1,000      |" << endl;
    outStream << "|_____________________________|" << endl;
    return outStream;
  }
  return outStream;
}


