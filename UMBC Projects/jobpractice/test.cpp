#include <iostream>
#include <fstream>
#include <sstream>
#include <ctype.h>
//#define MAX_NUMS 60
//#define CAL_BRATE 12
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

bool isNumber(const string& s){
  for (char const &c: s) {
    if(std::isdigit(c) == 0){
      return false;
    }
  }
  return true;
}





// with this code we are trying to figure out
// how to user the users exustubg account balance and
// add the amount they are requesting to deposit
// into thier already made acount 
int main(){
  //vector<string> Account_info;
  //long int num;
  string user_info;
  int user_number;
  int test_v;
  //int num1,num2;
  //cout << "Lets find your account: ";
  //cin >> test_v;
  //int n = user_info.length();
  //char char_arrary[n+1];
  ifstream readFile("useraccountfile.txt");
  //  int sum = 5;
  while(readFile >> user_info){

    if(isNumber(user_info)){
      cout << user_info ;
      
    }
  }
  


  
 
  readFile.close();
}
  // SetNum = grabChecking + CAL_BRATE;
  //cout << SetNum << endl;
  // string Username = "Dave";
  //string Amount = "67";
  //int size = Account_info.size();
  
  // int size = sizeof(Account_info);

 


      
