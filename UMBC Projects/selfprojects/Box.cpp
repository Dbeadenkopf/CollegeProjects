// File: Box.cpp
// Implementation of Box class.

#include <iostream>
#include "Box.h"

using namespace std ;


// Initialiize static members 
//
int Box::count = 0 ;
int Box::sequence = 0 ;


// Default constructor
//
Box::Box() {

  length = 1.0 ;
  height = 2.0 ;
  width = 3.0 ;
  count++ ;
  sequence++ ;
  serial_number = sequence ;

#ifndef NDEBUG
  cerr << "Default Box constructor, Serial Number = " << serial_number << endl ;
#endif 

}


// Alternate constructor with parameters for box dimensions
//
Box::Box(float len, float ht, float wd) 

  :   length(len), height(ht), width(wd)  // member initializers

{    
  count++ ;
  sequence++ ;
  serial_number = sequence ;

#ifndef NDEBUG
  cerr << "Alternate Box constructor, Serial Number = " << serial_number << endl ;
#endif 
}


// Destructor
//
Box::~Box() {

#ifndef NDEBUG
  cerr << "Box destructor, Serial Number = " << serial_number << endl ;
#endif
   
  count-- ;
}


// Print out vital stats
//
void Box::identify() {
   
  if (length == 0.0 || height == 0.0  || width == 0.0) {
    cout << "I am an invisible box.  " ;
  } else {
    cout << "I am a box with length="  << length 
	 << ", height=" << height
	 << " and width=" << width << ".  " ;
  }
   
  cout << "Serial Number = " << serial_number << endl ;
}


// Print out static members
//
void Box::report() {
  cout << "\n=== Report:" << endl ;
  cout << "There are " << count << " boxes in existence." << endl ;
  cout << "A total of " << sequence << " boxes have been made." << endl ;
  cout << "===\n" << endl ;
}


// Compute box volume
//
float Box::volume() {
  return length * height * width ;
}


// Double each dimension
//
void Box::grow() {
  length = length * 2 ;
  height = height * 2 ;
  width  = width  * 2 ;
}


// Halve each dimension
//
void Box::shrink() {
  length = length / 2 ;
  height = height / 2 ;
  width  = width  / 2 ;
}


// Friend function 
//
int compare(Box& A, Box& B) {
  if (A.length < B.length && A.height < B.height && A.width < B.width) {
    return -1 ;
  }
  if (A.length > B.length && A.height > B.height && A.width > B.width) {
    return 1 ;
  }
  return 0 ;
}
