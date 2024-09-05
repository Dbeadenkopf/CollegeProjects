#include <iostream>
#include <fstream>



using namespace std;


int main(){
  ofstream myfile;
  myfile.open("account.txt");
  myfile << "David Beadenkopf.\n";
  myfile.close();


  return 0;
}
