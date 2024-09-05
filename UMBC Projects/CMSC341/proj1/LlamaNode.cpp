#ifndef _LLAMANODE_CPP_
#define _LLAMANODE_CPP_
// not guarding yet because we are not templeting the class
// yet

/* File: LlamaNode.cpp

   UMBC CMSC 341 Fall 2016 Project 1

   This file has the implementations of the LlamaNode class
   for Project 1. See project description for details.

   This file should not be modified in ANY way.

   When your program is graded, it will be compiled with the original 
   version of this file. Your program must work with the original. 

*/


#include <iostream>
#include "LlamaNode.h"
using namespace std ;


// Static variables


// counts how many times the constructor is called
template <class T, int LN_SIZE>
int LlamaNode<T,LN_SIZE>::newCount = 0;


// counts how many times the destructor is called
template <class T, int LN_SIZE>
int LlamaNode<T,LN_SIZE>::deleteCount = 0 ;


// default constructor 
// sets m_next to NULL and increments the new Count
// which incrementing the newCount is incrementing
// based on each time it is called
template <class T, int LN_SIZE>
LlamaNode<T,LN_SIZE>::LlamaNode() {
  m_next = NULL ; 
  newCount++ ; 
}


// destructor, the destructor 
// sets m_next to null, and acounts for
// any dealocated memory of this class,
// also counts the amount of time
// the destructor is called my incrementing
//                     What is the significance of 
//                     LN_SIZE
template <class T, int LN_SIZE>
LlamaNode<T,LN_SIZE>::~LlamaNode(){ 
  m_next = NULL ; 
  deleteCount++ ; 
}


// report member function that just displays the amount
// of times the constructor was called and destructor was called
// which then simulatedd the amount of nodes created using the constructors increment 
// process and the # of nodes destroyed using its increment of the deleteCount varible process
template <class T, int LN_SIZE>
void LlamaNode<T,LN_SIZE>::report() {

  cerr << "# of nodes created = " << LlamaNode<T,LN_SIZE>::newCount << endl ;
  cerr << "# of nodes destroyed = " << LlamaNode<T,LN_SIZE>::deleteCount << endl ;

}


#endif
