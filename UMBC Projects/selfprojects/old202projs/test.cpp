#include <iostream>
#include "Node.h"
#include "polynomial.h"

using namespace std;


int main(){
  Polynomial create_Mon;
  long int test = 4;
  create_Mon.insertMonomial(test, 4);
  create_Mon.insertMonomial(test, 3);
  create_Mon.insertMonomial(test, 2);
  create_Mon.insertMonomial(test, 1);
  create_Mon.insertMonomial(test, 1);


  cout << create_Mon << endl;



  return 0;
}
