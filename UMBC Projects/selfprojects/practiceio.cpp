#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;




int main(){
  ifstream myfile;
  string grab_text;
  myfile.open("nfl_2019_sch.txt");
  if (myfile.is_open()){
    while(getline(myfile, grab_text)){
      //if (grab_text == "Baltimore"){
	cout << grab_text << endl;
      }
    }



  myfile.close();

  



  return 0;
}
