// This header file contains the implementation
// for a instance of a Heap. The heap will act
// as a single heap that will perform the functions
// of a heap such as knowing when to bubble up and
// bubble down as well as find and insert
// both min and max heap types will rely
// on this heap instance class  


#ifndef HEAP_H_
#define HEAP_H_
#include "PinHit.h"
#include "fstream"




// m_size is a varible that simulates the amount
// of nodes in the array
template<class T, int m_size>
class Heap
{


  
 public:
  

  // required functions by UML
  // The default constructor for a Heap. 
  // can use any initilization for the default
  Heap();
  
  // Copy constructor, copies all the data 
  // members from the original heap and saves them in a new
  // heap
  Heap(const Heap<T, m_size>& origHeap);

  // The contains is a prototype of the function
  // that will return true if the needle
  // is found in the Heap
  bool Contains(const T& needle) const;

  // The Find is a prototype of the function
  // that will return an object pointer of type 
  // T if the needle is in the Heap
  // (runTime: O(n) Hint: uses PinHits operator==)
  const T* Find(const T& needle) const;

  // Removes and returns a T(by reference) from the heap
  // when remove is active, the heap is updated
  // to maintian heap order, so deleting node value
  // may require moving another exisiting value
  // from the heap to that position where the value was 
  // deleted(there is a method for this action)
  virtual T& Remove();

  // Given a T(type), insert will insert
  // the new object into the heap
  // percolate up will be used
  // in this class if needed
  virtual void Insert(T& insertable);

  // this is bubble up method for the heap
  // used internally on insert
  // runTime: 0(log n) -> binary search
  virtual void PercolateUp(int index);

  // PercolateDown = bubble down method
  // for the heap
  // used interanally on insert
  // runTime: 0(log n) -> binary search
  virtual void PercolateDown(int index);



  // prototype of the member
  // varible that acts as the debugger
  // of the class
  void dump();


  // prottype of member varible 
  // that checks if the array is empty
  bool isEmpty(); 
  


 protected:

  // UML-required member variables
  // the array of type T which
  // means the array can be populated 
  // by any value
  T* m_array;
  int keepTrackEnd; // varible that keeps track of the end of the array

};

#include "Heap.cpp"
#endif /* HEAP_H_ */

