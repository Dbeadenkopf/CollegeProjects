#include <iostream>
#include <cstring>
#include <stack>
#include <string>
#include <cstdlib>
#include <map>
#include <fstream>
// Excptions practice
using namespace std;
struct Commodity
{
  char name;
  int number;
};


int main(){
  fstream contactlist;
  contactlist.open("example1.txt");
  string holdinfo;
  while(true){
    contactlist >> holdinfo;
    cout << holdinfo << endl;
    if (contactlist.eof()){
      break;
    }
  }
  map<string,char> myMap;
  map<string,char>::iterator p;
  myMap.insert(pair<string, char>(holdinfo, '@')); // maps to char
  // the key here can be used as an identifer to identify
  // the type when reference, our key here is a string
  // so we give the keys a string
  if (myMap[holdinfo] == '@'){
    cout << "email: " << holdInfo << endl;
  }


  return 0;
}
