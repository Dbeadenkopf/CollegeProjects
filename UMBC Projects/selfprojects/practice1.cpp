#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <stdlib.h>// for rand
using namespace std;

int main(){
  srand(10);

  int random_sixty = rand() % 151 + 1*.65;
  cout << random_sixty << endl;


  return 0;
}
