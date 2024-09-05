#ifndef OCR_H_
#define OCR_H_
#line 1 "ERROR->"
#include <string>

using namespace std;



class ContactInfo
{
 public:
  // basic default constructor
  ContactInfo();
  
  ContactInfo(std::string N, std::string P, std::string E);
  // this function should return the name as a string
  string getName();
  // this function should return the number as a string
  string getPhoneNumber();
  // this function should return the email as a string
  string getEmailAddress();

  string ToString() const;



 private:
  string name;
  string phoneNum;
  string emaiL;
 
};
 



#endif
