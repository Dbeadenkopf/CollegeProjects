#include "List.h"
#include <iostream>
#include <stdlib.h>

using namespace std;


Node::Node(int data)
  : m_data(data) 
{
  m_next = NULL;
}

// the default constrocter makes the dummy node
List::List()
    : m_head(new Node(0))
{ /* No code */ }


List::~List() {
  Node *current, *next;

  current = m_head;
  while (current != NULL) {
    next = current->m_next;	// Save this away while we still have "curr"
    delete current;             // delete the node here
    current = next;		// Now, move on to next item
  }
}


void List::AddToEnd(int data){
  Node* current = m_head;
  Node* newData;
  newData = new Node(data);// passing data into new node
  // traverse linked list to end
  while(current->m_next != NULL){
    current = current->m_next;
  }

  // Now, "current" points to last Node on list--add new Node after that
  //  (Note: you must allocate a new Node object from the heap to hold
  //   the new data)
  // Before:   [CURRENT] -> NULL
  // After: [CURRENT] -> [NEW NODE] -> NULL

  // PUT CODE HERE:
  current->m_next = newData;
  while(current->m_next != NULL){
    current = current->m_next;
  }



 


  return;
}

int List::RemoveFromStart(){
  // First, check that there is something in the list;
  // IMPORTANT: Don't forget the dummy 0 at the head of the list!
  Node *current = m_head;
  //  Node *temp;
  if (m_head == NULL || m_head->m_next == NULL){
    cout << "Trying to remove from an empty list--existing!!\n";
    exit(1);
  }
  
  //m_head->m_next = delete m_;
  // Now, remove the first item on the list.  Note that m_head points
  // to a dummy "0" Node, so we don't remove that: we remove the one
  // AFTER that.
  // Don't forget that you need to delete the removed Node, but
  // also don't forget that you have to extract and save any needed
  // data members of the Node first, because it is illegal to access
  // anything inside an object once you delete it!!
  //
  // Before:  m_head -> [DUMMY 0 NODE] -> [FIRST_NODE] -> <REST OF NODES>
  // After:   m_head -> [DUMMY 0 NODE] -> <REST OF NODES>
  // Return: data from FIRST_NODE

  // PUT CODE HERE:
  while(current!= NULL){
    int value;
    value = current->m_data;
    delete current;
    return value;
  }
  return 0;
}


void List::Print() const {
  Node* current = m_head->m_next;  // Skip over dummy 0 Node

  while(current != NULL) {
    cout << current->m_data << ' ';
    current = current->m_next;
  }

}


unsigned int List::Size() const {
    // Skip over dummy 0 Node
  int counter = 0;
  Node* current = m_head->m_next;  // Skip over dummy 0 Node
  while(current != NULL) {
    current = current->m_next;
    counter++;
  }
  return counter;
}
  // traverse linked list with a while loop and count the number of
  // elements.  Don't forget about dummy 0 node at head of list!

  // PUT CODE HERE:








//  return VALUE_TO_RETURN;  // Replace VALUE_TO_RETURN with actual value
//}
