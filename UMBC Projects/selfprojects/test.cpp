#include <iostream>
#include <cstring>
#include <time.h> // allows for the usage of the random number gen
#include "MyPokemon.h"
#include "Pokemon.h"
using namespace std;

int main(){
  
  Pokemon obj;
  ifstream getPokemon;
  string grabPokemon;
  getPokemon.open("pokeDex.txt");
  while (true){
    getPokemon >> grabPokemon;
    cout << grabPokemon << endl;
    if (getPokemon.eof()){
      break;
    }
  }
  MyPokemon test;
  
  
  obj.dump();
  getPokemon.close();


  return 0;
}
