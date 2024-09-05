#ifndef DOG_CPP_
#define DOG_CPP_
#include <iostream>
#include "human.h"
using namespace std;



 // default contructor for human class                                         
Human::Human(){
  Human_Name = "None";
  Human_Age = 0;
  Human_Birthmonth = "None";
  Human_Birthyear = 0000;
  Human_BirthDay = 0;
}
  // default decontrustor for free and delete                                   
Human::~Human(){
  
}

  // getter that returns Human_name                                             
string Human::GetHumanName(){
  return Human_Name;
}

  // setter that sets the Human_name                                            
void Human::SetHumanName(string name){
  Human_Name = name;
}

  // getter that gets the human age                                             
int Human::GetHumanAge(){
  return Human_Age;
}

  // setter that sets the human age                                             
void Human::SetHumanAge(int age){
  Human_Age = age;
}

  // getter to get the humans birth year                                        
string Human::getBirthMonth(){
  return Human_Birthmonth;
}

  // setter to set the humans birth year                                        
void Human::SetBirthMonth(string month){
  Human_Birthmonth = month;
}

long int Human::getBirthYear(){
  return Human_Birthyear;
}

  // setter to set the birth year                                               
void Human::SetBirthYear(long int year){
  Human_Birthyear = year;
}


  // getter to get the birth day                                                
int Human::getBirthDay(){
  return Human_BirthDay;
}


  // setter to set the birth day                                                
void Human::setBirthDay(int day){
  Human_BirthDay = day;
}


void Human::Output(){
  cout << "The Name of this Human is: " << GetHumanName() << endl;
  cout << "The Age of this Human is: " << GetHumanAge()  << endl;
  cout << "The Birth year of this Human is " << getBirthYear() << endl;
  cout << "The Birth month of this Human is "  << getBirthMonth() << endl;
  cout << "The Birth Day of this Human is " << getBirthDay() << endl;
}



#endif
