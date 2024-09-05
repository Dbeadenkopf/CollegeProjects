
#ifndef _HUMAN_H_
#define _HUMAN_H_

#include <iostream>

using namespace std;




class Human{

 public:
  // default contructor for human class
  Human();
  // default decontrustor for free and delete
  ~Human();

  // getter that returns Human_name
  string GetHumanName();

  // setter that sets the Human_name 
  void SetHumanName(string name);
  
  // getter that gets the human age
  int GetHumanAge();

  // setter that sets the human age
  void SetHumanAge(int age);

  // getter to get the humans birth year
  string getBirthMonth();
  
  // setter to set the humans birth year
  void SetBirthMonth(string month);


  // getter to get the birth year
  long int getBirthYear();

  // setter to set the birth year
  void SetBirthYear(long int year);

  
  // getter to get the birth day
  int getBirthDay();


  // setter to set the birth day
  void setBirthDay(int day);

  // output member function to output results
  void Output();


  
 private:
  string Human_Name;
  int Human_Age;
  string Human_Birthmonth;
  long int Human_Birthyear;
  int Human_BirthDay;
};








#endif
