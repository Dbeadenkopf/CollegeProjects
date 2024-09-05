//  File: Cube.h
//
//  Declare a class Cube that is derived from Box


#ifndef CUBE_H
#define CUBE_H

#include "Box.h"

class Cube : public Box { // public derivation of class Box

 public:   
  Cube() ;             // default constructor
  Cube(float) ;        // another constructor
  ~Cube() ;            // destructor
   
  void identify() ;    // identify redefined
} ;


#endif
