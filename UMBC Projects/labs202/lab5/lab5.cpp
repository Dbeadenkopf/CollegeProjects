#include <iostream>
#include <string>
#include "Complex.h"
using namespace std;
int main(){
  // To test your code, you must
  // - create at least three Complex numbers using
  //   the non-default constructor.
  double num1, num2;
  int counter = 1;
  cout << "Please enter your first number: ";
  cin >> num1;
  cout << "Please choose second number: ";
  cin >> num2;
  while(counter <= 3){
    Complex calc(num1,num2);
    string grabString = calc.ToString();
    cout << "Default Constructed Complex number " << counter << "\n";
    cout << grabString << endl << "\n";
    cout << "Please enter another first number: ";
    cin >> num1;
    cout << "please enter another second number: ";
    cin >> num2;
    counter++;
    if (counter == 3){
      string grabString2 = calc.ToString();
      cout << "Default Constructed Complex number " << counter << "\n";
      cout << grabString2 << endl << "\n";
      break;
    }
  }
  Complex mult(4,5);
  mult.Multiply(mult);
  string grabString3 = mult.ToString();
  cout << "The multiplied Fraction " << endl;
  cout << grabString3 << endl;
  double choice;
  cout << "Give me a double: ";
  cin >> choice;
  Complex mult2(2.3,choice);
  string grabNew = mult2.ToString();
  mult2.Multiply(mult);
  cout << "The multipled Function with a double" << endl;
  cout << grabNew << endl;
  // - Use the Multiply() function to compute the
  //   product of two Complex numbers; output the
  //   product using the ToString() function.
  // - Use the Multiply function to compute the
  //   product of a Complex number and a double;
  //   output the product using the ToString()
  //   function.

  return 0;
}
  
