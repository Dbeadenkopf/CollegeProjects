#ifndef _LLAMANODE_H_
#define _LLAMANODE_H_

// testing file with strings first
/* File: LlamaNode.h

   UMBC CMSC 341 Fall 2016 Project 1

   This file has the class declaration for the LlamaNode class
   for Project 1. See project description for details.

   This file should not be modified in ANY way.

   When your program is graded, it will be compiled with the original 
   version of this file. Your program must work with the original. 

*/


#include <iostream>
using namespace std;


template< class T, int LN_SIZE >   // forward class declaration
class Llama;


template <class T, int LN_SIZE>
class LlamaNode {
  // forward friending
  // now the Llama class has acces to all private
  // data members of LlamaNode
  friend class Llama<T,LN_SIZE>;

 public:

  LlamaNode()  ;
  ~LlamaNode() ;
  
  // function that gets out 
  // all of the calls to the destructor and constructor
  static void report(); 

 private:   

  static int newCount;      // # of times constructor was called
  static int deleteCount;   // # of times desctructor was called
  // this is the array that holds the items within the stack
  T arr[LN_SIZE];
  // pointer to the next stack in the linked list
  LlamaNode *m_next;   
  
};


#include "LlamaNode.cpp"

#endif
