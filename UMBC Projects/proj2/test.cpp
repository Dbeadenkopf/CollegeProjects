#include <iostream>
#include <ostream>
#include "wagerMenu.h"
using namespace std;
int main(){
  Menu obj;
  int userAmount;
  cout << obj << endl;
  cout << "Make Decision" << endl;
  cin >> userAmount;
  obj.setNum(userAmount);

  return 0;
}
