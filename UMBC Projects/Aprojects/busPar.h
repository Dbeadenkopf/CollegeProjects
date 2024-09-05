#ifndef BUSPAR_H_
#define BUSPAR_H_
#line 1 "ERROR->"
#include <string>
#include "OCR.h"
using namespace std;


class BusinessCarParser : public ContactInfo
{
 public:
  BusinessCarParser();

  // this function should
  // return the entire parced information
  // from the document and therefore displaying
  // all employees contact info
  ContactInfo getContactInfo(string document);

  

 

 private:
  string doC;
};


#endif
