#include <iostream>
#include <cstring>
#include "businessCardOcr.h"
using namespace std;

// acts as our name grabber from parced info
string ContactInfo::getName(){
  return name;
}


void ContactInfo::setName(string client_name){
  name = client_name;
}

// acts as our phone number grabber from parced info
string ContactInfo::getPhoneNumber(){
  return phonENumber;
}


void ContactInfo::setPhoneNumber(string client_number){
  phonENumber = client_number; // setting the parameter to the varible 
}


// acts as our email grabber from parced info
string ContactInfo::getEmail(){
  return emaiL;
}

void ContactInfo::setEmail(string client_email){
  emaiL = client_email;
}


// could possibley have in here where, we give each 
// line in the file its own string, if the file is longer 
// than expected , we alloctate a new string or new identifier
// to hold an item from the file(ex. ptr->new string tim;)
// This acts as our parcer
ContactInfo BusinessParser::getContactInfo(string document)
{
  int counter = 0; // the counter will make the size universal
  ContactInfo obj;
  fstream openFile;

  fstream humanNames;
  string holder;
  string Names;
  //string firstName;
  string lastName;
  char discard[counter]; 
  openFile.open(document.c_str());
  humanNames.open("listofCommonNames.txt");
  while(true){
    humanNames >> Names;
    popNames.push_back(Names); // putting into vector to use through other parts of program
    if(humanNames.eof()){
      break;
    }
  }
  int i = 0;
  while(true){
    openFile >> holder;
    for (unsigned int p = 0; p < popNames.size(); p++){
      if (holder == popNames[p]){
	openFile >> lastName;
	Names = holder + " " + lastName; // concatinates name and last name
	obj.setName(Names);
	break;
      }
      // else{
      //	popNames.push_back(holder); // accounting for if the word is not 
	// in the vector of names
      //}
    }
    if (holder[i] >= 45  && holder[i] <= 57){ // if there
      for (unsigned int increment = 0; increment < holder.size() ; increment++){ // any of the if statments characters
	if (holder[increment] == '+' || holder[increment] == '(' || holder[increment] == ')' || holder[increment] == ' ' || holder[increment] == '-' || holder[increment] == '\''){ // go through entire ascii table
	  holder[increment]  = discard[increment];
	  counter++;
	  obj.setPhoneNumber(holder);
	}
      }      
      if((holder[i] >= 97 && holder[i] <= 122) || (holder[i] == 46 && holder[i] == 64)){ // wont grab the email for some
	obj.setEmail(holder);
      }
    }
    i++;
    if (openFile.eof()){
      break;
    }
  }
  if (islower(holder[i])){
    obj.setEmail(holder);
  }
  openFile.close();
  humanNames.close();
  return obj;
}




