// this is a simple progtram to find the sum of perfect sqaures in an array


#include <iostream>
#include <math.h>


using namespace std;


int isPerfectSqaure(int number){
  int iVar;
  float fVar;

  fVar = sqrt((double)number); // type cast here
  iVar = fVar;
  if (iVar == fVar){
    return number;
  }
  else{
    return 0;
  }
  
}



int main(){
  int n;
  //  cout << "Select a number: ";
  cin >> n;
  int sum = 0;
  int Arr[n];
  for (int i = 0; i < n; i++){
    cin >> Arr[i];
  }
  //  cout << "testing " << endl;
  for (int i = 0; i < n; i++){
    sum = sum +  isPerfectSqaure(Arr[i]);
  }
  //cout << "testing " << endl;
  cout << sum << endl;
  return 0;
}
