#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
using namespace std;

int main(){
  fstream inputStream;
  inputStream.open("cards.txt");
  string allCards;
  int counter = 0;
  while(true){
    getline(inputStream , allCards);
    cout << allCards << endl;
    counter++;
    if(inputStream.eof()){
      cout << counter << endl;
      break;
    }
  }





  return 0;
}
