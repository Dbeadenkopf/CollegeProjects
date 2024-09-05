#include <iostream>
#include "IntArray.h"
//int IntArray::errorsFound.insert(1); // someting like this perhaps?
using namespace std;
int main()
{
  // Create IntArray objects and call methods here...
  IntArray ia(10);
  IntArray A(0);
  IntArray A2(3), T(-2);
  A+= A;
  for (int i = 0; i < 10; i++){
    A = A +i;
    A!= i;
  }
  A == ia;
  A == -2;
  A!= ia;
  A+= 10;
  A.Get(-1);
  A.Get(1);
  A.Get(384);
  A.Get(0);
  A.Remove(5);
  A.SetItem(-1, 2);
  A = A + ia;
  T.Insert(-2, 2);
  T.Clear();
  // Print out the number of errors/edge cases found
  cout << endl << endl << IntArray::GetProgress() << endl;
    
  return 0;
}
