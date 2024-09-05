#include <string>
#include <iostream>
#include <cstring>
#include "integerTrivia.h"
using namespace std;
int main(){
  cout << "Welcome to integer Trivia!: " << "\n";
  cout << "The objective of the game can be to guess " << endl;
  cout << "the position of where an integer is in an array of floats! " << endl << "\n";;
  Integer get;  
  char holder = get.Input(get);
  if (holder == 'y'){
    int n, user_N, j;
    float X[] = {1.2,2.3,4.2,2.3,2.0};
    int range = sizeof(X);
    cout << "guess the integer posistion in the range 0 to " << range << ":"; 
    cin >> user_N;
    while (user_N > range){
      cout << "out of range!" << endl;
      cout << "guess the integer position in the range 0 to " << range << ":";
      cin >> user_N;
      j++;
    }
    n = get.findInteger(X, 5);
    int i = 0;
    while(user_N!= n){
      cout << "Incorrect! " << "\n" << endl;
      cout << "guess the integer postition in the range 0 to " << range << ":";
      cin >> user_N;
      i++;
      if (user_N == n){
	char newHolder;
	cout << "Correct! ***********" << "\n" << endl;
	get.outPut(n);
	newHolder = get.Input(get);
	if (newHolder == 'y'){
	  cout << "guess the integer position in the range 0 to " << range << ":";
	  cin >> user_N;
	}
	else{
	  cout << "Game Over" << endl;
	  break;
	}
      }
    }
  }
  return 0;
}
  


