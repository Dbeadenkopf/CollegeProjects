#ifndef NODE_H_
#define NODE_H_
#include <iostream>
using namespace std;


class Node {

 public:
  // Node() is the default constructor , that initilizes m_next to Null
  Node();

  // the constructor initlizeds m_coefficient to coeff
  Node(long coeff, unsigned int deg);

  long m_coefficient;
  unsigned int m_degree;
  Node *m_next;

};





#endif
