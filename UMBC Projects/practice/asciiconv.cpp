// THis program will converter a user defined character and
// converts that character to ascii
#include <iostream>
using namespace std;




int main(){
  int integer;
  cout << "Enter your integer here" << endl;
  cin >> integer;
  cout << "The Ascii = " << static_cast<char>(integer) << endl;


  return 0;
}
