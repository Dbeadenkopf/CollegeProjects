#include "Node.h"
#include <stdlib.h>

Node::Node(){
  m_next = NULL;
}

Node::Node(long coeff, unsigned int deg){
  m_coefficient = coeff;
  m_degree = deg;
  m_next = NULL;
}
