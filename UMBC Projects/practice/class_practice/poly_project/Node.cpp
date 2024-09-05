#include "Node.h"



Node::Node(){
  m_next = null;
}


Node::Node(long coeff, unsigned int deg){
  m_coefficient = coeff;
  m_degree = deg;
  m_next = null;
}

