#ifndef PAIR_H
#define PAIR_H
template <class T>
class Pair
{
 public:
  Pair();
  Pair(T first,T second);
  T first();
  T second();
  bool operator==(const Pair<T>& obj)const;
 private:
  T S;
  T F;
};


#include "pair.cpp"
#endif
