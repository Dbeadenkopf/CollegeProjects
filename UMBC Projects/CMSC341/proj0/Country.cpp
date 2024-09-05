#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "Country.h"
using namespace std;

Country::Country(){
  name = "None"; 
  population = 0;
  literacyRate = 0.0;
  primaryCompletionFemale = 0.0;
  primaryCompletionMale = 0.0; 
  primaryCompletionTotal = 0.0;
  educationGDPSpent = 0.0; 
  youthLitRateFem = 0.0; 
  youthLitRateMale = 0.0; 
}

Country::Country(string N, long P, float LR, float PCF, float PCM, float PCT, float edGPD, float yLRF, float yLRM){
  name = N; // string varible to store name of country as a string
  population = P; // long int varible to store population of country
  literacyRate = LR; // floating point integer varible to store literacy \rate;
  primaryCompletionFemale = PCF; // floating point to store Pri. completio\n rate of Fem.
  primaryCompletionMale = PCM; // floating point to store Pri. completion \rate of Male
  primaryCompletionTotal = PCT; // floating point to store Pri. completion\rate Total
  educationGDPSpent = edGPD; // floating point to store GDP spent on educati\on
  youthLitRateFem = yLRF; // floating point to store Y. literacy rate of Fe\m.
  youthLitRateMale = yLRM; // f
}


// getter to grab the name of country
string Country::getName() const{
  return name;
}

// setter to set the Name of the Country
void Country::setName(string N){
  name = N;
}

// getter to grab population number of Country
long Country::getPop() const{
  return population;
}

// setter to set the population of the Country
void Country::setPop(long P){
  population = P;
}

// getter to grab the literacy rate of the Country
float Country::getLit() const{
  return literacyRate;
}

// setter to set the literacy Rate
void Country::setLit(float L){
  literacyRate = L;
}

// getter tp grab the Primary completion rate female
float Country::getPcf() const{
  return primaryCompletionFemale;
}

// setter to set the primary completion rate female
void Country::setPcf(float PCF){
  primaryCompletionFemale = PCF;
}

// getter to get the primary completion rate male
float Country::getPcm() const{
  return primaryCompletionMale; 
}

// setter to set the primary completion rate male
void Country::setPcm(float PCM){
  primaryCompletionMale = PCM; 
}

// getter to get the primary completion rate total
float Country::getPct() const{
  return primaryCompletionTotal; 
}

// setter to set the primary completion rate total
void Country::setPct(float PCT){
  primaryCompletionTotal = PCT;
}

// getter to get the gross demestic product
// spent of education
float Country::geteduGDPspent() const{
  return educationGDPSpent;
}

// setter tp set the gross demestic product
// spent of education
void Country::seteduGDPspent(float eduGDP){
  educationGDPSpent = eduGDP;
}

// getter to get the literacy rate of females
float Country::getlitr_F () const{
  return youthLitRateFem;
}

// setter to set the literacy rate of females
void Country::setlitr_F(float litF){
  youthLitRateFem = litF;
}

// getter to get the literacy rate of males
float Country::getlitr_M () const{
  return youthLitRateMale;
}

// setter to set the literacy rate of males
void Country::setlitr_M(float litM){
  youthLitRateMale = litM;
}



