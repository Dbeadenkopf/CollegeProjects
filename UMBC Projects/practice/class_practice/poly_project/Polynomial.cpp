#include "Polynomial.h"


Polynomial::Polynomial(){
  m_head = new Node(0,0);
}


// oour
Polynomial::Polynomial(const Polynomial& p){
  m_head = nullptr;
  Node **last = &m_head;

    for ( Node *current = p.m_head; current; current = current->next )
    {
        *last = new Node( current->m_coefficient, current->m_degree );
        ( *last )->m_next = nullptr;
        last = &( *last )->m_next;
    }
}


Polynomial::~Polynomial(){
  Node *current, *next;

  current = m_head;
  while(current!= NULL){
    next = current->m_next;
    delete current;
    current = next;
  }
}


void Polynomial::insertMonomial(long coeff, unsigned int deg){
  

}
