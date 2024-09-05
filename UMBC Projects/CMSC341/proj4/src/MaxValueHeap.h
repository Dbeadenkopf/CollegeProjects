// The header file for the implementation
// of a MAX count heap, which is a single
// instance of a max heap that uses the maximum
// values of a comparable (< == >) to prioritize
// items. The root node of this heap will always
// have the largest value. The trick to this class
// is that it will utilize pinHit, because it relies
// on the pinHit with the most hits, the class will
// inherit from the Heap


#ifndef MAXVALUEHEAP_H_
#define MAXVALUEHEAP_H_
#include <iostream>
#include "Heap.h"






template<class T, int m_size>
  class MaxValueHeap : public Heap<T, m_size>  // deriving from heap
{

 public:
  // the default constructor for
  // the Min Heap class, sets values to
  // there default value
  MaxValueHeap();

  // copy contructor for the MinHeap
  MaxValueHeap(const Heap<T, m_size>& other);


  // takes element from root of heap
  // and then return that element
  // also will shuffle things in heap
  // perculate up and down are vital
  // when doing that part
  T& Remove();


  // function to insert within the array
  // basically insert at bottom
  // then bubble up
  void Insert(T& insertable);

  // Basically bubbling up method
  // will be used to keep the
  // shuffle method and the heap
  // in order in terms of insert
  void PercolateUp(int index);



  // Basically the bubbling down
  // method, will be used to keep
  // the shuffle method and the heap
  // in order in terms of remove
  void PercolateDown(int index);

};

#include "MaxValueHeap.cpp"
#endif

