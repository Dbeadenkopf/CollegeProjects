#include <iostream>
#include <string>
#include "businessCardOcr.h"

using namespace std;

int main(){
  BusinessParser getContact;
  ContactInfo holdContact;
  holdContact = getContact.getContactInfo("example4.txt");
  
  cout << "Name: " << holdContact.getName() << endl;
  cout << "Phone: " << holdContact.getPhoneNumber() << endl;
  cout << "Email: "  << holdContact.getEmail() << endl;
  
  return 0;
}
