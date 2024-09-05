#ifndef _LLAMA_H_
#define _LLAMA_H_
//#define T string 
//#define LN_SIZE 4 // Length or size of the array 
#include <string>
/* File: Llama.h

   UMBC CMSC 341 Fall 2016 Project 1

   This file has the class declaration for the LlamaNode class
   for Project 1. See project description for details.

   You may add public and private data members to the Llama class.

   You may add public and private member functions to the Llama class.

*/


#include <stdexcept>
#include <string>
#include "LlamaNode.h"
   
using namespace std;

// The Llama Underflow will handle all 
// the exceptions, and throw for errors
// may or could use dynamic binding for the
// exceptions
class LlamaUnderflow : public std::out_of_range{

 public:
  // inline bracets thats why It works and is defined in the header file
 LlamaUnderflow(const string& what) : std::out_of_range(what) { }

};


template <class T, int LN_SIZE>
class Llama{
  
 public:
  // The default Constructor must create a LLama stack that holds one node
  // and sets our data members to default values
  Llama();
  
  // makes a copy a complete copy of the Llama Stack
  // given in the paremeter
  Llama(const Llama<T,LN_SIZE>& other);   // copy constructor

  // any dynamic allocated memory accociated with the host object
  // must be deallocated 
  ~Llama();

  // size() returns the number of items in the llama stack
  int size();

  // dump() used for debugging, prints out all relevent information 
  // regarding the host Llama stack to (cerr). including the number of
  // (Llamanodes) (means we can use the llamanode Class for this)
  // that have been created and destroyed. Additionally, it prints 
  // out the address of each node and whether there is currently an "extra " 
  // node in the data Structure
  void dump(); // prob can invoke LlamaNodes print function

  // what would T be then?
  // adds data to the top of the stack
  void push(const T& data);
 
  // Removes and returns the item at the top of the stack
  T pop();

  // dup() duplicates the top of the stack, may need
  // to use copy constructor or assignment operator
  // for this one
  void dup();    //  (top) A B C D -> A A B C D

  // swap() exchanges the top two items at the top of the stack
  void swap();   //  (top) A B C D -> B A C D
 
  // rot() - rot means rotates , must be three items in
  // the stack or else an exception is thrown
  // it will rearange the top three items in the stack
  void rot();    //  (top) A B C D -> C A B D

  // peek will return the value of an item in the stack
  // offset will determine which item is retrieved (peek(0) --> top)
  // peek(100) -- > end?
  T peek(int offset) const;


  // overloaded assignment operator
  // handles the case of self_assignment
  // dynamic allocated memory in the host object should
  // be deallocated beforehand
  const Llama<T,LN_SIZE>& operator=(const Llama<T,LN_SIZE>& rhs);


  //
  // Add your public member functions & public data mebers here:
  //


 private:
  static int sizeofStack; // member varible to hold the # of items in the stack
  T topItem; // member varible to hold the top item in a stack
  T valueofItem; // member varible to hold the value of an item in the stack
  static int arrayoffset;
 
  bool extraNode; // true if there is an extra node in the linked list, else false
  LlamaNode<T,LN_SIZE> *m_head; // pointer to the next node
  bool isEmpty(); // a private member function that returns true if the stack is empty
  // Add your private member functions & private data mebers here:
  //
  
};


#include "Llama.cpp" 
#endif
