#ifndef _OPERATOR_TEST_H
#define _OPERATOR_TEST_H
#include <iostream>
#include <stdexcept>
#include "node.h"
template <class T>
class Operator
{
  T& operator[](unsigned int i) ;
  void addFront(const T& moreData);
  void print() ;




};
#include "operator_test.cpp"
#endif
