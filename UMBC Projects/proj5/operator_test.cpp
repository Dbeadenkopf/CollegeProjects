#ifndef _OPERATOR_TEST_CPP
#define _OPERATOR_TEST_CPP
#include <iostream>
#include <string>
#include <stdexcept>
#include "node.h"
#include "operator_test.h"
template <class T>
T& LinkedList<T>::operator[](unsigned int i){
  if (sizeIs<= i){
    throw range_error("index out of Range");// if i value is greater thant he size
  }
  // need to walk through the list
  Node<T> *ith_current;
  unsigned int current_Address;
  if ( i >= ith_Holder && are_Synced == true){// indicates that the (i) passed in is after the ith element in the list that was found
    ith_current = casher_Ptr; // idnicate starting point for cash pointer
    current_Address = ith_Holder; // for the address of the ith element
    
  }
  else {
    ith_current = m_head->m_next; // start at first node
    current_Address = 0; // the next node is the first element

  }
  while (current_Address < i){ // are we at the address and if so stop at the address
    ith_current = ith_current->m_next; 
    current_Address++; 
  }
  casher_Ptr = ith_current; // last time to find something from list
  ith_Holder = current_Address;
  return ith_current->M_data; // return the data that the casher pointer is holder to the user
}
template <class T>
void LinkedList<T>::addFront(const T& moreData){
  Node<T> *insert_Data = new Node<T>(moreData);
  insert_Data->m_next = m_head->m_next; // to insert to first node
  sizeIs++; // icnrement size becasue adding node to list
  m_head->m_next = insert_Data; // made insert data the new first node by telling where the second node is and telling data where the second node is
}
template <class T>
void LinkedList<T>::print(){
  // iteratre through the list and print out every peice of data
  Node<T> *ith_current;
  ith_current = m_head->m_next;
  while (ith_current!= NULL){
    cout << ith_current->M_data << endl; // display data
    ith_current = ith_current->m_next; // then go to next nodes data
    
  }

}

#endif
