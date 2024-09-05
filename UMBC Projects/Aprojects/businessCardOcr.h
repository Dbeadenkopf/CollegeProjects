// Canident: David Beadenkopf
// Breifing: I am highlt aware of the challenge 
// that was given to me. {Engineering Design Process}
// what are my requirements? 
// answer: Must make software that will parce
// peoples information and store that infomation 
// into the context of three sections [Name.Phone.Email];
// OK what do I know?
// I know a /////// continue write up


// there needs to be multiple scope resuluton to perform the classes

#ifndef BUSINESSCARDOCR_H_
#define  BUSINESSCARDOCR_H_
#include <cstring>
#include <string>  // allows for the use of size() size_t
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <stdio.h>
#include <vector> // data structure to hold the names from the text file
using namespace std;


class ContactInfo 
{
 public:

  // the function that will return the name
  // of the parsed information
  string getName();


  // the function that will set the 
  // name of the parsed information 
  void setName(string client_name);


  // the function that will return a string
  // number but as a sequence of digits
  string getPhoneNumber();
 

  //  the function that will set the
  // phone number of the parsed information
  void setPhoneNumber(string client_number);

  // the function that will return a string
  // email that has been parced from the
  // given information
  string getEmail();

  // the function that will set a string
  // email that has been parced from the
  // given information
  void setEmail(string client_email);


  private:
  string name; // the string varible that will hold the name
  string phonENumber;// the string varible that will hold the number
  string emaiL;  // the string varible that will hold the email
};



// The business Card parcer software
class BusinessParser : public ContactInfo
{

 public:


  // the function that will accepts the passed in information
  // parce the information and allow the getters to return the
  // information based on thier desigination function
  ContactInfo getContactInfo(string document);
  

 private:
  vector<string> popNames; // a vector that holds a list of populer names
  


};




#endif
