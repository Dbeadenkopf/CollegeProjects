#ifndef DOG_CPP
#define DOG_CPP
#include <iostream>
#include "Dog.h"

using namespace std;

// default constructor for dog
Dog::Dog(){
  m_owner = "No owner yet";
  m_name = "No name yet";
  m_birthYear = 1;
  m_happiness = 1;
}

 // Returns the name of the owner                                         
string Dog::GetOwner(){
  return m_owner;
}

    // Gives the Dog a new owner                                             
void Dog::SetOwner(const string &owner){
  m_owner = owner;
}

    // Returns the name of the dog                                           
string Dog::GetName(){
  return m_name;
}

    // Gives the Dog a new name                                              
void Dog::SetName(const string &name){
  m_name = name;
}

    // Returns year the Dog was born                                         
int Dog::GetBirthYear(){
  return m_birthYear;
}

    // Gives the Dog a new year of birth                                     
void Dog::SetBirthYear(int birthYear){
  m_birthYear = birthYear;
}

    // Abuse the dog                                                         
void Dog::Scold(){
  m_happiness = m_happiness - 1;
}

void Dog::Reward(){
  m_happiness = m_happiness +1;
}

    // Returns the age of the dog at a given year                            
int Dog::GetAge(int current_year){
  return m_birthYear;
}

string Dog::GetHappiness(){
  if (m_happiness > 1){
    return "Good";
  }
  if (m_happiness < 1){
    return "Sad";
  }
  else{
    return "ok";
  }
}

void Dog::Talk(){
  cout << "Rough" << endl;
}


#endif
