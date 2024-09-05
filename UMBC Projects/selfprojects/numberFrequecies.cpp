#include <cstring>
#include <iostream>
using namespace std;
// idea i initilty had was to then take these counters and some how throw them in a member fuction 
// then i need to figure out how i want to get the user input to the class so that when it takes user input, but then i need an object call to the class
int main(){
  int counter1(0), counter2(0), counter3(0), counter4(0), counter5(0), counter6(0), counter7(0), counter8(0);
  int num1;
  for (int i = 0; num1!= 0; i++){
    cout << "what number? or choose 0 if done ";
    cin >> num1;
    Number number(num1);
    number.Useroutput();
    switch (num1){
    case 1:
      counter1++;
      break;
    case 2:
      counter2++;
      break;
    case 3:
      counter3++;
      break;
    case 4:
      counter4++;
      break;
    case 5:
      counter5++;
      break;
    case 6:
      counter6++;
      break;
    case 7:
      counter7++;
      break;
    case 8:
      counter8++;
      break;
    }
    // if (num1 == 0){
    // cout << 1 << " : " << (counter1) << " " << "\n";
    // cout << 2 << " : " << (counter2) << " " << "\n";
    // cout << 3 << " : " << (counter3) << " " << "\n";
    // cout << 4 << " : " << (counter4) << " " << "\n";
    // cout << 5 << " : " << (counter5) << " " << "\n";
    // cout << 6 << " : " << (counter6) << " " << "\n";
    // cout << 7 << " : " << (counter7) << " " << "\n";
    // cout << 8 << " : " << (counter8) << " " << "\n";
  }
  return 0; 
}


class Number
{
public:
  Number(){
    num = 1;
  }
  Number(int number){ // dont know what this does 
    num = number;
  }
  void Useroutput(){
    if (num == 0){
      cout << 1 << " : " << (counter1) << " " << "\n";
      cout << 2 << " : " << (counter2) << " " << "\n";
      cout << 3 << " : " << (counter3) << " " << "\n";
      cout << 4 << " : " << (counter4) << " " << "\n";
      cout << 5 << " : " << (counter5) << " " << "\n";
      cout << 6 << " : " << (counter6) << " " << "\n";
      cout << 7 << " : " << (counter7) << " " << "\n";
      cout << 8 << " : " << (counter8) << " " << "\n";
    }
  }
private:
  int num;
};
