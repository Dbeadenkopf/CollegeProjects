#include <iostream>
#include <string>
#include "integerTrivia.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

srand(time(NULL));
char Integer::Input(Integer& data){
  cout << "would you like to play? (y/n)";
  cin >> data.choice;
  char temp  = data.choice;
  return temp;
}
void Integer::outPut(int& data2){
  cout << "Found integer in array position " << data2 << endl;
}
int Integer::findInteger(float F[], int n){
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(1);
  Integer num;
  int temp = num.getInt();
  float temp2 = num.getFloat();
  for (int i = 0; i < n; i++){
    temp = F[i];
    temp2 = F[i] - temp;
    if (temp2 == 0.0){
      return i;
    }
  }
  return 0;
}
int Integer::getInt(){
  return holder;
}
float Integer::getFloat(){
  return holder2;  
}
