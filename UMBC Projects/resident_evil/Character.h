#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <iostream>

using namespace std;

class Character{


 public:
  Character();

  virtual ~Character();

  virtual void encounter(Character *ptr) = 0;
  
  virtual void biteMe(Character *ptr) = 0;
  

  virtual void hitMe() = 0;

  virtual void cureMe() = 0;

  virtual Character *morph() = 0;
  
  virtual bool migrates();

  virtual string identify() = 0;

  unsigned int getID();

  bool isDead();

 protected:
  bool m_isDead;


 private:
  unsigned int m_id;
  static unsigned int m_counter;

};



#endif 
