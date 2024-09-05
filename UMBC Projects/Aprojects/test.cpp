#include <iostream>
#include <string>
#include <cstring>
#include <fstream> // file input and output
#include <vector>
#include "OCR.h"
#define SPACE 80
using namespace std;
// this is the company projects that was ask to be adminerstered by joe 
// 
int main(){
  string take;
  char copy[SPACE];
  char copy2[SPACE];
  char copy3[SPACE];
  char copy4[SPACE];
  char copy5[SPACE];
  char discard[SPACE];
  string walk;
  // using this vector to
  // concateinate the string
  // for convient output
  vector <string> add;
  add.resize(SPACE);
  string line;

  string through;
  string firstName, lastName;
  fstream inputStream;
  string phone;
  string number;
  string email;
  int counter = 0;
  string fileName;
  cout << "what is the doc name?: ";
  cin >> fileName;
  inputStream.open(fileName.c_str());
  if(fileName == "example2.txt"){
    while(getline (inputStream, line) ){
      counter++;
      ContactInfo u_namE;
      
      inputStream >> walk >> through;
      inputStream >> firstName >> lastName;
      cout << "Name: " << firstName << " " << lastName << endl;
      take = firstName + " " + lastName;// concatinating the name
      u_namE.getName();
      line = u_namE.getName();
      line = take;
      
      inputStream >> walk >> through >> walk;
      inputStream >> walk >> through >> walk;
      inputStream >> phone >> number;
      strncpy(copy2, number.c_str(), sizeof(copy2));
      for (int i = 0; i < SPACE; i++){
        // getting rid of any extra characters
        // in the number
        if (copy2[i] == '(' || copy2[i] == ')' || copy2[i] == '-'){
          copy2[i] = discard[i];
        }
        if (copy2[i] >= 48 && copy2[i] <= 57){
          counter++;
        }
	
       
	number = copy2[i];
	// they might all have to be of the same
	// object to be relevent when using the 
	// getter contact info in business card class
	ContactInfo e_num;
	phone = e_num.getPhoneNumber();
	phone = number;
       
      }
      
      cout << "[" << phone << "]" << "need this" << endl;
      // <<  copy2[0] << copy2[1] << copy2[2] << copy2[3] << copy2[4] << copy2[5] << copy2[6] << copy2[7]  << copy2[8] << copy2[9] << copy2[10] << copy2[11] << copy2[12] << endl;
      inputStream >> walk >> through;
      inputStream >> email;
      
      cout << "Email: " << email << endl;
      break;
    }
   
  }
  if(fileName == "example1.txt"){
    while(getline (inputStream, line) ){
      inputStream >> firstName >> lastName;
       cout << "Name: " << firstName << " " << lastName << endl;
      inputStream >> walk >> through >> walk;
      inputStream >> number;     
      strncpy(copy, number.c_str(), sizeof(copy));
     
     
      for (int i = 0; i < SPACE; i++){
	// getting rid of any extra characters 
	// in the number
	if (copy[i] == '(' || copy[i] == ')' || copy[i] == '-'){
	  copy[i] = discard[i];
	}
	if (copy[i] >= 48 && copy[i] <= 57){
	  counter++;
	}
	
      }

     
     
     
   
      
      cout << "Phone: " << copy[1] << copy[2] << copy[3] << copy[5] << copy[6] << copy[7] <<  copy[9] << copy[10] << copy[11] << copy[12] << endl;
      
      inputStream >> email;
      cout << "Email: " << email << endl;
      break;
    }
    
  }
  if(fileName == "example3.txt"){
    while( inputStream.is_open() ){
      inputStream >> firstName >> lastName;
      cout << "Name: " << firstName << " " << lastName << endl;
      inputStream >> walk >> through;
      inputStream >> walk >> through >> walk >> through;
      inputStream >> walk >> through;
      inputStream >> walk >> through >> walk >> through;
      inputStream >> walk >> through;
      inputStream >> walk >> through >> walk;
      inputStream >> walk >> phone >> through >> number;
      strncpy(copy4, through.c_str(), sizeof(copy4));
      strncpy(copy5, phone.c_str(), sizeof(copy5));
      strncpy(copy3, number.c_str(), sizeof(copy3));
      for (int i = 0; i < SPACE; i++){
        // getting rid of any extra characters
        // in the number
        if (copy3[i] == '(' || copy3[i] == ')' || copy3[i] == '-' || copy3[i] == '+'){
          copy3[i] = discard[i];
        }
	if (copy4[i] == '(' || copy4[i] == ')' || copy4[i] == '-' || copy4[i] == '+'){
          copy4[i] = discard[i];
        }
	if (copy5[i] == '(' || copy5[i] == ')' || copy5[i] == '-' || copy5[i] == '+'){
          copy5[i] = discard[i];
        }
        if (copy3[i] >= 48 && copy3[i] <= 57){
          counter++;
        }
	if (copy4[i] >= 48 && copy4[i] <= 57){
          counter++;
        }
	if (copy5[i] >= 48 && copy5[i] <= 57){
          counter++;
        }
	
      }
      
      cout << "Phone: " << copy5[1] << copy4[1] << copy4[2] << copy4[3] << copy3[0] << copy3[1] << copy3[2] << copy3[3] << copy3[4] << copy3[5] << copy3[6] << copy3[7] <<  copy3[8] << copy3[9] << copy3[10] << copy3[11] << copy3[12] << endl;
      // add[10] add[11]
      
      
    
      inputStream >> walk >> phone >> through >> number;
      inputStream >> email;
      cout << "Email: " << email << endl;
      break;
      
    }

  }
  inputStream.close();
  return 0;
}
