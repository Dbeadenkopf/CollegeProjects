#ifndef WAGERMENU_H_
#define WAGERMENU_H_
#include <ostream>
#include "wager.h"
using namespace std;

class Menu : Wager 
{
 public:
  Menu();
  Menu(int num);
  Menu(char choice);
  int getNum();
  char getChoice();
  void setNum(int setNum);
  void setSymbol(char S);
  char Symbol() const;
  void outPut(const Menu& newMenu) const ;
 private:
  int u_Num;
  char symboL;
  char takechoicE;
};

std::ostream& operator<< (std::ostream& outStream, Menu& fMenu);
// using second operator ostream to display other menu after 
// first menu




#endif
