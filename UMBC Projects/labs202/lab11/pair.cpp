#ifndef PAIR_CPP_
#define PAIR_CPP_
#include <iostream>
#include <cstring>
#include "pair.h"
using namespace std;
template <class T>
Pair<T>::Pair(){
  S = 0;
  F = 0;
}
template <class T>
Pair<T>::Pair(T first,T second){
  F = first;
  S = second;
}
template <class T>
T Pair<T>::first(){
  return S;
}
template <class T>
T Pair<T>::second(){
  return F;
}
template <class T>
bool Pair<T>::operator==(const Pair<T>& obj) const{
  if (obj.F == F && obj.S == S){
    return true;
  }
  if (obj.F == S  && obj.S == F){
    return true;
  }
  else{
    return false;
  }
  return 0;
}

#endif
