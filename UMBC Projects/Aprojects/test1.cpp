#include <iostream>
#include "OCR.h"
#include "busPar.h"
#include <string>
using namespace std;

int main(){
  
  string hold;
  ContactInfo getContact;

  BusinessCarParser obj;
  getContact = obj.getContactInfo("example1.txt");
  hold = getContact.ToString();
  cout << "testing example1" << endl;
  cout << hold << endl;
  

  getContact = obj.getContactInfo("example2.txt");
  hold =  getContact.ToString();
  cout << "testing example2" << endl;
  cout << hold << endl;

  cout << "testing example3" << endl;
  getContact = obj.getContactInfo("example3.txt");
  hold = getContact.ToString();
  cout << hold;
 
 
  



  return 0;
}
