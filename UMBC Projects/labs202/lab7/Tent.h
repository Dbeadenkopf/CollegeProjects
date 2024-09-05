#ifndef TENT_H_
#define TENT_H_
#include "residence.h"
using namespace std;
class Tent : public Residence{
 public:
  Tent();
  double PropertyValue()const;
  int NumWindows()const;
  



};

#endif
