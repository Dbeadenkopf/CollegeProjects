#ifndef _LINKED_CPP
#define _LINKED_CPP
#include <iostream>
#include <cstring>
#include <stdexcept>
#include <string>
#include "linked.h"
#include "node.h"
using namespace std;
template <class T>
LinkedList<T>::LinkedList(){
  m_head = new Node<T>; // allocating new node of type T so that whatever is passed in will be the starting node
  sizeIs = 0;
}
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& otherList){// go through other nodes in the other lsit and make copies of them
  // take another list object and makes a copy of that list
  m_head = new Node<T>; // setting any type of dummy node for starting node
  casher_Ptr = NULL;
  are_Synced = false;
  Node<T> *ith_current, *other_Ptr;
  ith_current = m_head; 
  other_Ptr = otherList.m_head->m_next; // access other list first node
  //  isSize = otherList.isSize;//(What was I getting at this isSize?) store other list size, checking other list size
  while (other_Ptr!= NULL){
    Node<T> *new_Node = new Node<T>(other_Ptr->M_data);
    ith_current->m_next = new_Node; // attatching the new Node to the end
    ith_current = ith_current->m_next; // go to the next node in the list
  }
  // evertme you acces head node you store a pointer to it 
}
template <class T>// (Must me a nonstatic member function is the error!)
const LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& otherList){
  Node<T> *ith_current, *ith_next;
  ith_current = m_head;
  while(ith_current!= NULL){
    ith_next = ith_current->m_next;
    delete ith_current; // deleting every other node
    ith_current = ith_next;// keep nexgt node while we still can
  }
  m_head = new Node<T>; // setting any type of dummy node for starting node
  casher_Ptr = NULL;
  are_Synced = false;
  Node<T>  *other_Ptr;
  ith_current = m_head; 
  other_Ptr = otherList.m_head->m_next; // access other list first node
  //isSize = otherList.isSize;//
  while (other_Ptr!= NULL){
    Node<T> *new_Node = new Node<T>(other_Ptr->M_data);
    ith_current->m_next = new_Node; // attatching the new Node to the end
    ith_current = ith_current->m_next; // go to the next node in the list
  }
  return *this;
}
template <class T>
unsigned int LinkedList<T>::size() const{
  return sizeIs; // retunring the size of the list

}
template <class T>
LinkedList<T>::~LinkedList(){
  Node<T> *ith_current, *ith_next;
  ith_current = m_head;
  while (ith_current!= NULL){
    ith_next = ith_current->m_next;
    delete ith_current; // deleting every other node
    ith_current = ith_next;// keep nexgt node while we still can 
  }
}
template <class T>
void LinkedList<T>::addFront(const T& moreData){
  Node<T> *insert_Data = new Node<T>(moreData);
  insert_Data->m_next = m_head->m_next; // to insert to first node
  sizeIs++; // icnrement size becasue adding node to list
  m_head->m_next = insert_Data; //  made insert data the new first node by telling where the second node is and telling data where the second node is
}
template <class T>
T LinkedList<T>::deleteFront(){
  if ((m_head->m_next = NULL)){ // condition if the first node is NULL
    throw range_error("deleteFront() on empty list"); // throw error if so
  }
  else{
    Node<T> *delete_Node = m_head->m_next;// store first node in pointer
    m_head->m_next = delete_Node->m_next; // asking where the second node. Telling m_head that this is the first node
    T delete_Data = delete_Node->M_data; // store first node in data 
    delete delete_Node; // delete 
    sizeIs--; // deincrement size becasue I took a node out of list
    return delete_Data; // returning the data that was deleted
  } 

}
template <class T>
bool LinkedList<T>::remove(const T& searchData){
  Node<T> *ith_current, *ith_next = m_head->m_next;
  if ((m_head->m_next = NULL)){
    throw range_error("deleteFront() on empty list");
  }
  ith_current = m_head;
  while(ith_next!= NULL){
    if (ith_next->M_data == searchData){ // if the next node data is equal to the data they passed in 
      ith_current->m_next = ith_next->m_next; // current is pointing to next node and that is poitning to the head and thats pointing to the next node
      delete ith_next;
      sizeIs--; 
      return true; // found node, returning indication
      // ith_next = ith_next->m_next;
      //  ith_current = ith_current->m_next;
    }
    else if (ith_next->m_next == NULL){
       ith_next = ith_next->m_next;
    }// NULL test cases  and the after a
    
    
   
  }
  return 0;
}
template <class T>
T& LinkedList<T>::operator[](unsigned int i){
  if (sizeIs <= i){
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
