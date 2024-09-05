#include <iostream>
#include <fstream>
#include <vector>
using namespace std;





int main(){
  char array[10];
  int num  = 4;
  vector<int *> ptr;
 
  ptr = &num;
  cout << "ptr = " << ptr << endl;
  
  

  return 0;
}
