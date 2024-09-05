#ifndef _LLAMA_CPP_
#define _LLAMA_CPP_
#include <iostream>
#include <string>
#include <cstring>
#include "Llama.h"
#include "LlamaNode.h"
#include <exception>
#include <assert.h>
using namespace std;
// The default constructor
// gives two member varibles
// sizeofstack and extraNode thier
// default values. Also, creates a new
// LlamaNode
template <class T,int LN_SIZE>
Llama<T,LN_SIZE>::Llama(){
  sizeofStack = 0;
  extraNode = false;
  m_head = new LlamaNode<T, LN_SIZE>; 
}

// this copy constructor, makes a full
// copy of the host object being passed in
template <class T, int LN_SIZE>
Llama<T,LN_SIZE>::Llama(const Llama<T,LN_SIZE>& other){
  sizeofStack = other.sizeofStack;
  topItem = other.topItem;
  valueofItem = other.valueofItem;
  extraNode = other.extraNode;
}

// Llama destructor, destroys all things 
// that portains to the host object and
// LlamaNode nodes 
template <class T, int LN_SIZE>
Llama<T,LN_SIZE>::~Llama(){
  LlamaNode<T,LN_SIZE> *current, *next;
  current = m_head;
  while (current!= NULL){
    next = current->m_next; 
    delete current;
    current = next;         
  }
}


// private member function empty
// that returns true if the stack is empty
// and false if it is not empty
template <class T, int LN_SIZE>
bool Llama<T,LN_SIZE>::isEmpty(){
  if(size() <= 0){
    return true;
  }
  return false;
}


// returns the size of the stack
// or the amount of items within each array of 
// each node
template <class T, int LN_SIZE>
int Llama<T,LN_SIZE>::size(){
  return sizeofStack;
}


// member function that will duplucate the
// top element of the stack, if the stack is empty
// it will check if it is and throw an exception if true
template <class T, int LN_SIZE>
void Llama<T,LN_SIZE>::dup(){
  Llama *checkif;
  LlamaNode<T,LN_SIZE> *current;
  current = m_head;
  try{
    if(checkif->isEmpty() == true){
      throw LlamaUnderflow("The stack is empty");
    }
  }
  catch(LlamaUnderflow& zde){
    cerr << zde.what() << endl;// handling excemption
  }
  while(current!= NULL){
    topItem = current->arr[arrayoffset-1];
    current = current->m_next;
    arrayoffset++;
  }
}


// the swap function will swap the top two items
// in the stack also checks for at least 2 items within
// the stack else throws an LlamaUnderflow exception


template <class T, int LN_SIZE>
void Llama<T,LN_SIZE>::swap(){
  LlamaNode<T,LN_SIZE> *current;
  current = m_head;
  try{
    if(size() < 2){
      throw LlamaUnderflow("The stack does not have at least 3 items");
    }
  }
  catch(LlamaUnderflow& zde){
    cerr << zde.what() << endl;// handling excemption
  }

  while(current!= NULL){
    topItem = current->arr[arrayoffset-2];
    current->arr[arrayoffset-2] = current->arr[arrayoffset-1];
    current->arr[arrayoffset-1] = topItem;
    current = current->m_next;
  }
}




// rotate function that rotates the top three elements
// of the stack, if there are not at least three items in the stack
// it will throw a LlamaUnderflow exception
template <class T, int LN_SIZE>
void Llama<T,LN_SIZE>::rot(){
  LlamaNode<T,LN_SIZE> *current;
  current = m_head;
  try{
    if(size() < 3){
      throw LlamaUnderflow("The stack does not have at least 3 items");
    }
  }
  catch(LlamaUnderflow& zde){
    cerr << zde.what() << endl;// handling excemption
  }
  while(current!= NULL){
    topItem = current->arr[arrayoffset-3];
    current->arr[arrayoffset-3] = current->arr[arrayoffset-2];
    current->arr[arrayoffset-2] = current->arr[arrayoffset-1];
    current->arr[arrayoffset-1] = topItem;
    current = current->m_next;
  }
}


// pops off the element off the
// top of the stack and returns the item
// pop does not delete that item afterwards
// I was going to call delete topItem or delete
// current->arr[arrayoffset-1] to attempt to get rid of it
// in the node, also it does not pop of the next top item
template <class T, int LN_SIZE>
T Llama<T,LN_SIZE>::pop(){
  LlamaNode<T,LN_SIZE> *current;
  current = m_head;
  try{
    if(isEmpty() == true){
      throw LlamaUnderflow("The stack is empty");
    }
  }
  catch(LlamaUnderflow& zde){
    cerr << zde.what() << endl;// handling excemption
  }
  cout << "here" << endl;
  cout << arrayoffset << endl;
  while(current!= NULL){
    topItem = current->arr[arrayoffset-1];
    current = current->m_next;
  }
  
  return topItem;
}


// peek will give the value of the item
// that was passed in the paremeter which
// offset takes and finds that item in the stack
// and returns it
template <class T, int LN_SIZE>
T Llama<T,LN_SIZE>::peek(int offset) const{
  LlamaNode<T, LN_SIZE> *current;
  current = m_head;
  try{
    if(offset > sizeofStack){
      throw LlamaUnderflow("The offset is too large");
    }
  }
  catch(LlamaUnderflow& zde){
    cerr << zde.what() << endl;// handling excemption
  }
  int stackCounter = 0;
  while(current!= NULL){
    for (int i = 0; i < LN_SIZE; i++){
      if (stackCounter == offset){
	return current->arr[i];
      }
      else{
	stackCounter++;
      }
    }
    // return current->arr[stackCounter];
    current = current->m_next;
  }
  return 0;
}
  





// static varible sizeofstack
// that keeps track of the amount of 
// items added to the stack
template <class T, int LN_SIZE>
int Llama<T,LN_SIZE>::sizeofStack = 0;

// arrayoffset varible that keeps
// track of the index postition within the 
// array
template <class T, int LN_SIZE>
int Llama<T,LN_SIZE>::arrayoffset = 0;

// The memeber function push that pushes
// items on the top of the stack
template <class T, int LN_SIZE>
void Llama<T,LN_SIZE>::push(const T& data){
  LlamaNode<T,LN_SIZE> *current;
  LlamaNode<T,LN_SIZE> *newNode;
  current = m_head;
  if(arrayoffset > LN_SIZE-1){
    newNode = new LlamaNode<T, LN_SIZE>;
    // newNode is not templated yet, thats why 
    // we are doing parenthesis first
    arrayoffset = 0;
    while(current->m_next!= NULL){    
      current = current->m_next;
      //sizeofStack++;
    }
    current->m_next = newNode;
    current->m_next->arr[arrayoffset] = data;
    arrayoffset++;
    sizeofStack++;
  }
  else{
    while(current->m_next!= NULL){
      current = current->m_next;
    }
    current->arr[arrayoffset] = data;
    arrayoffset++;
    sizeofStack++;
  }
}


template <class T, int LN_SIZE>
const Llama<T,LN_SIZE>& Llama<T,LN_SIZE>::operator=(const Llama<T,LN_SIZE>& rhs){
  sizeofStack = rhs.sizeofStack;
  topItem = rhs.topItem;
  valueofItem = rhs.valueofItem;
  extraNode = rhs.extraNode;
}


// my dump function does not display
// the stack as an actual bottom to top stack
// it displays the array indexes instead
template <class T, int LN_SIZE>
void Llama<T,LN_SIZE>::dump(){
  cout << "*****  " << "Llama Stack Dump" << "  *****" << endl;
  LlamaNode<T,LN_SIZE> *current;
  LlamaNode<T,LN_SIZE> *check;
  int countNodes = 0;
  int balanceNodes = 0;
  current = m_head;
  while(current!= NULL && current->m_next != NULL){
    current = current->m_next;
    countNodes++;
    balanceNodes++;
    if (countNodes > LlamaNode<T,LN_SIZE>::newCount){// this maybe too simplistic
      extraNode = true; // this may be acounting for the physical count
      break;
    }
  }
  cout << "LN_SIZE = " << LN_SIZE << endl;
  cout << "# of items in the stack = " << size() << endl;
  check->report();
  if (extraNode == true){
    cout << " " << endl;
    cout << "This stack does have an extra node" << endl;
  }
  else{
    cout << "This stack does not have an extra node" << endl;
  }
  cout << " " << endl;
  cout << "Stack Contents, top to bottom" << endl;
  //current = m_head;
  while(current!= NULL){
    cout << "----- " << (current) << " -----" << endl;
    for (int i = 0; i < LN_SIZE; i++){
      cerr << current->arr[i] << i << endl;
    }
    current = current->m_next;
  }
}

#include "Llama.h"
#include "LlamaNode.h"
#endif
