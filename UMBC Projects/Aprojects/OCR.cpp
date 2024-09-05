#include <iostream>
#include <sstream>
#include "OCR.h"
#include "busPar.h"
#include <string>
using namespace std;

ContactInfo::ContactInfo(){
  name = "none";
  phoneNum = "none";
  emaiL = "none";
}

ContactInfo::ContactInfo(string N, string P, string E){
  name = N;
  phoneNum = P;
  emaiL = E;
}

string ContactInfo::getName(){
  return name;
}


string ContactInfo::getPhoneNumber(){
  return phoneNum; 
}


string ContactInfo::getEmailAddress(){
  return emaiL;
}

string ContactInfo::ToString() const{
  stringstream ss;
  ss << "Name: " << name << endl;
  ss << "Phone: " << phoneNum  << endl;
  ss << "Email: " << emaiL << endl;
  return ss.str();
}



