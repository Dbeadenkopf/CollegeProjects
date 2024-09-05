#ifndef COUNTRY_H_
#define COUNTRY_H_
#include <iostream>
#include <cstring>
using namespace std;
// this file contains the base class country which will replicate 
// a country of a continant, the country should have a name, population,
// litteracy rate, Primary completion of both male and female, education of GDP spent, and youth literacy rate of both male and female 
class Country
{
 public:
  // Default constructor
  Country();


  Country(string N, long P, float LR, float PCF, float PCM, float PCT, float edGPD, float yLRF, float yLRM);
  
  // getter to grab the name of country
  string getName() const;

  // setter to set the Name of the Country
  void setName(string N);

  // getter to grab population number of Country
  long getPop() const;

  // setter to set the population of the Country
  void setPop(long P);

  // getter to grab the literacy rate of the Country 
  float getLit() const;

  // setter to set the literacy Rate
  void setLit(float L); 
  
  // getter tp grab the Primary completion rate female
  float getPcf() const;

  // setter to set the primary completion rate female
  void setPcf(float PCF);

  // getter to get the primary completion rate male
  float getPcm() const;

  // setter to set the primary completion rate male
  void setPcm(float PCM);
  
  // getter to get the primary completion rate total
  float getPct() const;

  // setter to set the primary completion rate total
  void setPct(float PCT);

  // getter to get the gross demestic product
  // spent of education
  float geteduGDPspent() const;
  
  // setter tp set the gross demestic product
  // spent of education
  void seteduGDPspent(float eduGDP);

  // getter to get the literacy rate of females
  float getlitr_F () const;
  
  // setter to set the literacy rate of females
  void setlitr_F(float litF);

  // getter to get the literacy rate of males
  float getlitr_M () const;
  
  // setter to set the literacy rate of males
  void setlitr_M(float litM);
  

 private:
  string name; // string varible to store name of country as a string
  long population; // long int varible to store population of country
  float literacyRate; // floating point integer varible to store literacy rate;
  float primaryCompletionFemale; // floating point to store Pri. completion rate of Fem.
  float primaryCompletionMale; // floating point to store Pri. completion rate of Male
  float primaryCompletionTotal; // floating point to store Pri. completion rate Total
  float educationGDPSpent; // floating point to store GDP spent on education
  float youthLitRateFem; // floating point to store Y. literacy rate of Fem.
  float youthLitRateMale; // floating point to store Y. literacy rate of Male.
};



#endif
