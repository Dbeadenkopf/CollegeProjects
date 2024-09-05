#include "polynomial.h"
#include <stdlib.h>



Polynomial::Polynomial(){
  m_head = new Node(0,0);
}

Polynomial::Polynomial(const Polynomial& p)
{
  // must perform a deep copy
  // so need that operator first
  //  m_head = p.m_head;
}

void Polynomial::insertMonomial(long coeff, unsigned int deg){
  Node* current = m_head;
  Node* newMonomial;
  unsigned int holder;
  newMonomial = new Node(coeff, deg);// passing data into new node                                                                                                                           
  // traverse linked list to end                                                                                                                                        
  holder = newMonomial->m_degree;
 
  //(WE mUST figure out how to not add
  // how to not add an elementx)
  while(current->m_next!= NULL)
    {
      current = current->m_next;
      if (current->m_degree == holder){
	cout << "Duplice degree" << endl;
	//	delete newMonomial;
	//	free newMonomial;
      }
    }

  while(current->m_next!= NULL){
 
 
    current = current->m_next;
    //    current->m_next = newMonomial;
  }
  current->m_next = newMonomial;

  // Now, "current" points to last Node on list--add new Node after that                                                                                                           
  //  (Note: you must allocate a new Node object from the heap to hold                                                                                                             
  //   the new data)                                                                                                                                                               
  // Before:   [CURRENT] -> NULL                                                                                                                                                   
  // After: [CURRENT] -> [NEW NODE] -> NULL                                                                                                                                        

  // PUT CODE HERE:                                                                                                                                                     /*
 
  //current->m_next = newMonomial;

  // while(current->m_next!= NULL){
  //current = current->m_next;   
  //}
}



Polynomial::~Polynomial(){
  Node *current, *next;
  current = m_head;
  while (current != NULL){
    next = current->m_next;     // Save this away while we still have "curr"   
    delete current;
    current = next;             // Now, move on to next item                   
  }
}

unsigned int Polynomial::degree() const{
  return m_head->m_degree;
}


long Polynomial::evaluate(long x) const{
  m_head->m_coefficient = x;
  return m_head->m_coefficient;
}


// we could check for the duplicate degree here and throw 
// an error but checking the project requirments first
std::ostream& operator<<(std::ostream& sout, const Polynomial& p){
  Node* current = p.m_head;  // Skip over dummy 0 Node
  current = current->m_next;

  while(current!= NULL){
    sout << current->m_coefficient << " x" << "^" << current->m_degree << " + ";
    current = current->m_next;
    if (current == NULL){
      break;
    }
  }
  return sout;
}

// write the degree function then use it here
