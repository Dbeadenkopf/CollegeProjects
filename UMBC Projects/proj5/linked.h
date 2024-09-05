#ifndef _LINKED_H_
#define _LINKED_H_
#include <iostream>
#include <stdexcept>
#include "node.h"
template <class T>
class LinkedList
{
 public:
  LinkedList();
  LinkedList(const LinkedList<T>& otherList) ;
  ~LinkedList() ;// should loop thorugh the linked list explicetly and deallicate each node in the linked list. Do not destroy sequence of nodes
  void addFront(const T& moreData) ;// adds new node to the beggning of the linked list with given data
  T deleteFront() ; // removes first node of linked list and returns the value stored in that node
  // if list is empty
  // throw range_error()
  // throw range_error("deleteFront() on empty list");
  bool remove(const T& searchData); // looks for node with a given valie and removes from linked list, if found
  // if 
  unsigned int size() const ;
  T& operator[](unsigned int i) ;
  const LinkedList<T>& operator=(const LinkedList<T>& otherList) ;
  void print() ;
 private:
  Node<T> *m_head;
  Node<T> *casher_Ptr;  // pointer to the actual node in the linked list that is based of the ith_holder
  unsigned int ith_Holder;// holds address of some node in the list,
  bool are_Synced; // indicates that I have found the ith element in the list
  unsigned int sizeIs;
  


  
};
#include "linked.cpp"
#endif
