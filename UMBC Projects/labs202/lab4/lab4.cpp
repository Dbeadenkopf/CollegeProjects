#include <iostream>
#include "Fraction.h"

using namespace std;

int main()
{
  // Create 3 fractions:
  int nuM, deN;
  cout << "Select a numerator: ";
  cin >> nuM;
  cout << "Select a denominator: ";
  cin >> deN;
  int i = 0;
  while (deN == 0){
    cout << "Error! no 0 in the denominator; please enter again\n" << endl;
    cout << "Select a denominator: ";
    cin >> deN;
    i++;
  }

  Fraction frac(nuM, deN);
  frac.getNum();
  frac.getDen();
  frac.Reciprocal(frac);
  cout << "The Reciprocal" << endl;
  frac.outPut();
  
  Fraction frac2;
  cout << "Default Fraction" << endl;
  frac2.outPut();

  Fraction frac3(2,3);
  cout << "Non-input Fraction" << endl;
  frac3.outPut();
  
  //  - Read the first fraction from the keyboard using cin.
  //    Find the reciprocal of this fraction and print it to the screen.
  //  - The second fraction will be created with default values. You
  //    should also print this to the screen.
  //  - Attempt to create a fraction with a denominator of zero, which 
  //    should print an error

  return 0;  
}
