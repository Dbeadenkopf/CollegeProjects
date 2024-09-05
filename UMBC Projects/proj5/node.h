#ifndef NODE_H
#define NODE_H
#include <cstring>
using namespace std;
template <class T>
class Node {
 public:
  Node();
  Node(T data);
  

  T M_data;// class data
  Node<T> *m_next;// pointer to another node or null 




};
#include "node.cpp"
#endif
