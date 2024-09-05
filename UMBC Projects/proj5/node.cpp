#ifndef NODE_CPP
#define NODE_CPP
#include <iostream>
#include <cstring>
#include "node.h"
using namespace std;
template <class T>
Node<T>::Node(){
  m_next = NULL;
}
template <class T>
Node<T>::Node(T data){
  M_data = data;
  m_next = NULL;
}
#include "node.h"
#endif
