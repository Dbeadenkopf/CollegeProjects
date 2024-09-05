#ifndef HEAP_CPP_
#define HEAP_CPP_
#include "Heap.h"

#include <iostream>
 

using  namespace std;

// THe heap or the default constructor 
template<class T, int m_size>
Heap<T, m_size>::Heap(){
  //m_size = 0;
  keepTrackEnd = 0; // this value needs to be incremented 
  // each time 
  // m_array[0] = NULL;
}

template<class T, int m_size>
Heap<T, m_size>::Heap(const Heap<T, m_size>& origHeap){

}

template<class T, int m_size>
bool Heap<T, m_size>::Contains(const T& needle) return{
  return false;
}


template<class T, int m_size>
const T* Heap<T, m_size>::Find(const T& needle) const{

}

template<class T, int m_size>
T& Heap<T, m_size>::Remove(){
  // not doing anything within the heap
  return m_array[0];
}


template<class T, int m_size>
void Heap<T, m_size>::Insert(T& insertable){
  //if (isEmpty() == true){
  //  m_array[m_size] = insertable;
  //}
  // could use compare to here to begin to compare the key values
  // then we have to keep the heap order property intak
}


template<class T, int m_size>
// so one could add the index in the peramiter 
// and it will go +1 from that index
void Heap<T, m_size>::PercolateUp(int index){
  // maybe we can perculate further
  // 
}

template<class T, int m_size>
// im not sure if this is how perculate up is suppose to be implemeneted
void Heap<T, m_size>::PercolateDown(int index){
  //m_array[index-1];
}


template<class T, int m_size>
void Heap<T, m_size>::dump(){
  for (int i = 0; i < m_size; i++){
    cout << m_array[i] << endl;
  }
}



template <class T, int m_size>
bool Heap<T, m_size>::isEmpty(){
  if (m_array[1] == NULL){
    return true;
  }
 
  return false;
}








#endif /* HEAP_CPP_ */



// basically what I was intially trying to do was to check if the array is already
// empty (BECAUSE IF IT IS) I could just perculate all the way up to the first index
// from adding the item in att the end of the array, I dont think insert can be directly tested
// but I think i can still try and test it
