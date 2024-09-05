// File: Cube.cpp
//
// Implementation of the Cube derived class

#include <iostream>
#include "Cube.h"
using namespace std ;

// Default constructor
// Note: default constructor for Box is called already.
//
Cube::Cube() :
  Box(1.0, 1.0, 1.0)   //  invokes Box alternate constructor
{ 

#ifndef NDEBUG
  cerr << "Default Cube constructor, Serial Number = " << serial() << endl ;
#endif 
}


// create a cube with equal sides
//   Note: default constructor for Box is called already.

Cube::Cube(float side) :
  Box(side,side,side)   //  invokes Box alternate constructor
{
#ifndef NDEBUG
  cerr << "Alternate Cube constructor, Serial Number = " << serial() << endl ;
#endif
   
}


// Destructor
//
Cube::~Cube() {

#ifndef NDEBUG
  cerr << "Cube destructor, Serial Number = " << serial() << endl ;
#endif
   
  // Do nothing
}


// report vital stats for cubes
//
void Cube::identify() {
  cout << "I'm a cube. Each side has length=" << length
       << ". Serial number = " << serial() << endl ;
}
