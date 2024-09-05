#include <iostream>
#include <cstring>
#include "Pinball.h"
#include <time.h>
#include "words.h"
using namespace std;

int main(){
  const char * inWords[10] = {
    "cauterising",
    "bursar",
    "outbursts",
    "glider",
    "intercity",
    "cartographers",
    "reggae",
    "chivvy",
    "merchantability",
   "felicitation"
  } ;





  //char *tester;
  srand(time(NULL));
  Pinball test(13);
  test.printStats();
  test.insert(inWords[0]);
  
 
 
  /*int offset1 = rand() % 9999 + 1;
  int offset2 = rand() % 9999 + 2;
  int offset3 = rand() % 9999 + 3;
  int offset4 = rand() % 9999 + 4;*/

 
  
  
  return 0;
}
