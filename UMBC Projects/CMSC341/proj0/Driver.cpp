#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <iterator>
#include "Coninent.h"
#include "Country.h"
// this main driver file will do most of 
// file I/O manipulation and use the functions of both 
// the continent class and Country class to grab or set
// peices of infromation with both text files
using namespace std;
// this function will read from both txt files given
// both the file that contains the continents 
// and each Continent`s countries data
void readFromFiles(string, string);

// so basically what he wants me to do is create a data structre linking the continent vector to a country vector and then for each country
// we can look at the continent it belongs to and if it doesnt belong to that continent, we get rid of it or dont worry about itX & operator=(X rhs){

class sumofNum : public Country{
public:
  string sumofNums(){
    return this->getName();
  }

};

int main(){
 
  vector<Continent> world;
  vector<Country> v_ofCountries;
  vector<string> Continents;
  readFromFiles("ContinentsCountries.txt","2013WorldBankEducationCensusData.txt"); 
  fstream ccFile;
  fstream worldfilE;
  string line1, line2;
  string oneLine;
  string str1, str2, str3, str4, str5, str6, str7, str8, str9;
  string str10, str11;
  long int population;
  float litRate, gdpSpent, pcR, pcrM, pcrF, literf, literM;
  ccFile.open("CountriesContinents.txt");
  worldfilE.open("2013WorldBankEducationCensusData.txt");
  // int countCont = 0;
  Continent *ptr;  
  Continent obj, hold;
  //  getline(worldfilE, oneLine);
  while(true) {
    getline(worldfilE, oneLine) ;
    
      // cout << oneLine << endl ;
    
      // if ( ifile.eof() ) break ;
    if ( worldfilE.fail() ) break ;
    // -- prob use this for 
    // -- getting the pokemon attributes
    istringstream istrm(oneLine) ;   // new one each loop!
    // holds country
    istrm >> str1 ;
   
    // str2 holds population
    istrm >> str2 ;
    // str3 holds literacy rate
    istrm >> str3 ;
    // str4 holds GdP Spent on Education
    istrm >> str4 ;
    // str 5 holds Primary Completion Rate
    istrm >> str5 ;
    // str 6 holds Primary Completion Rate Male
    istrm >> str6 ;
    // str 7 holds Primary Completion rate female
    istrm >> str7 ;
    // str 8 holds youth literacy rate female
    istrm >> str8 ;
    // str 9 holds youth literacy rate Male
    istrm >> str9 ;
    istrm >> str10 ;
    istrm >> str11 ;
    
    // this line is cout twice
    // cout << "country = '" << str1 << "'   " ;
    // converting population to float here
    // names.push_back(str1); // putting in vector of strings
    Continent obj;
    ptr = new Continent;
    ptr->setName(str1);
    //v_ofCountries.push_back(*ptr);

    population = atol(str2.c_str());
    
    obj.setPop(population);
    v_ofCountries.push_back(*ptr);
    //   cout << "population = " << population << "   ";*/
    if ( str3 == "N/A" ){
      litRate = -1.0 ;
      obj.setLit(litRate);
    } else {
      litRate = atof(str3.c_str()) ;
      obj.setLit(litRate);
     
    }
    if ( str4 == "N/A" ) {
      gdpSpent = -1.0 ;
      obj.seteduGDPspent(gdpSpent);
     
    } else {
      gdpSpent = atof(str4.c_str()) ;
      obj.seteduGDPspent(gdpSpent);
     
    }
    if ( str5 == "N/A" ) {
      pcR = -1.0 ;
      obj.setPct(pcR);
     
    } else {
      pcR = atof(str5.c_str()) ;
      obj.setPct(pcR);
     
    }
    
    if ( str6 == "N/A" ){
      pcrM = -1.0 ;
      obj.setPcm(pcrM);
     
    } else {
      pcrM = atof(str6.c_str()) ;
      obj.setPcm(pcrM);
     
    }
    
    if ( str7 == "N/A" ){
      pcrF = -1.0 ;
      obj.setPcf(pcrF);
    
    }else{
      pcrF = atof(str7.c_str());
      obj.setPcf(pcrF);
    
    }
    if ( str8 == "N/A" ) {
      literf = -1.0 ;
      obj.setlitr_F(literf);
    
    } else {
      literf= atof(str8.c_str()) ;
      obj.setlitr_F(literf);
    
    }
    if ( str9 == "N/A" ) {
      literM = -1.0 ;
      obj.setlitr_M(literM);
     
    } else {
      literM = atof(str9.c_str());
      obj.setlitr_M(literM);      
    }
    //  obj = Country hold(obj.getName(), obj.getPop(), obj.getLit(), obj.getPcf(), obj.getPcm(), obj.getPct(), obj.geteduGDPspent(), obj.getlitr_F(), obj.getlitr_M());
    v_ofCountries.push_back(obj);
  }
  /*cout << "Str 4 check " << str4 << endl;
    cout << "literacy rate = " << litRate << endl ;*/
    
  
    /* v_ofCountriesData.push_back(str2) ;
    v_ofCountriesData.push_back(str3);
    v_ofCountriesData.push_back(str4);
    v_ofCountriesData.push_back(str5);
    v_ofCountriesData.push_back(str6);
    v_ofCountriesData.push_back(str7);
    v_ofCountriesData.push_back(str8);
    v_ofCountriesData.push_back(str9);*/

    /*cout << "str2 = '" << str2 << "'\n" ;
    cout << "str3 = '" << str3 << "'\n" ;
    cout << "str4 = '" << str4 << "'\n" ;
    cout << "str5 = '" << str5 << "'\n" ;
    cout << "str6 = '" << str6 << "'\n" ;
    cout << "str7 = '" << str7 << "'\n" ;
    cout << "str8 = '" << str8 << "'\n" ;
    cout << "str9 = '" << str9 << "'\n" ;
      cout << str10 << endl;
      cout << str11 << endl;*/
   
  
  
  
  string temp;
  string Counter;
  string eachContinent;
  int index;
  vector<Country> inContinent;
  long unsigned iterations;
  while(!ccFile.eof()){
    getline(ccFile,line1);
    if (line1.find("--") != -1){
      // this is code that finds the string index
      // of the number in the CC file; ex: AFRICA -- 51
      // index now holds 51
      index = line1.find("--");
      // counter a string that holds that number 
      // after we have found it
      Counter = line1.substr(index + 3);
      // iterations a long int that converts
      // that number found into a long integer
      iterations = atoi(Counter.c_str());
      // string each cont
      // holds the contiennts
      eachContinent = line1;
     
      //   cout << eachContinent << endl;
      /*ptr = new Continent;
      ptr->setName(line1);
      world.push_back(*ptr);*/
    }
    else{
      for (int i = 0 ; i < v_ofCountries.size(); i++){
	if (v_ofCountries[i].getName() == line1){
	  // cout << line1 << endl;
	  inContinent.push_back(v_ofCountries[i]);
	  iterations--;
	}
      }
      if (iterations == 0){
	//hold.setName(eachContinent);
	
	hold = Continent(eachContinent, inContinent, eachContinent);
	world.push_back(hold);
	inContinent.clear();
      }
    }
  }
  
  //  int n = v_ofCountries.size();
  /*for (int i = 0 ; i < n; i++){
    cout << world[i].getPop() << endl;
    }*/
 

  cout << obj << endl;

  

 
  
 
 
   
  
 
  
  
  
  
  

  

  


 
  worldfilE.close();
  ccFile.close();

  return 0;
}


void readFromFiles(string document1, string document2){
  

}
  




