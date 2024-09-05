#ifndef MAXVALUEHEAP_CPP_
#define MAXVALUEHEAP_CPP_
#include <iostream>
#include "MaxValueHeap.h"

using namespace std;


template <class T, int m_size>
MaxValueHeap<T, m_size>::MaxValueHeap(){
  //empty default constructor
  this->m_array = new T[m_size];
  this->keepTrackEnd = 0;
}


template <class T, int m_size>
MaxValueHeap<T, m_size>::MaxValueHeap(const Heap<T, m_size>& other){
  // empty atm
  this->m_array = new T[m_size]; // ?
  for (int i = 0; i < m_size; i++){
    // copy elemenets from other array to
    // my new allocated array
    this->m_array[i] = this->other.m_array[i];
  }
  this->keepTrackEnd = this->other.keepTrackEnd;
}


template <class T, int m_size>
void MaxValueHeap<T, m_size>::Insert(T& insertable){
  this->m_array[this->keepTrackEnd] = insertable;
  this->keepTrackEnd++;
}



template <class T,int m_size>
T& MaxValueHeap<T, m_size>::Remove(){
  // put the first element acting as the root
  // in the zeroth element for storage
  this->m_array[0] = this->m_array[1];
  this->PercolateDown(0);
  this->keepTrackEnd--;
  return this->m_array[0]; // return the item in the place holder
}





template <class T, int m_size>
void MaxValueHeap<T, m_size>::PercolateUp(int index){
  T temp;
  while(true){
    if (this->m_array[index/2].CompareTo(this->m_array[(index/2)+1]) == 1){
      if (this->m_array[index].CompareTo(this->m_array[index/2]) == 1){
	return;
      }
      else
        { // perform swap with nodes
          temp = this->m_array[index];
          this->m_array[index] = this->m_array[index/2];
          this->m_array[index/2] = temp;
          index = index/2; // continue to swap
        }
    }
    else
      {
        if (this->m_array[index].CompareTo(this->m_array[(index/2)+1]) == 1){ // have to change logic
          return;
        }
        else{
          temp = this->m_array[index];
          this->m_array[index] = this->m_array[(index/2)+1];
          this->m_array[(index/2)+1] = temp;
          index = (index/2)+1; // continue to swap
        }
      }
  }
}

template <class T, int m_size>
void MaxValueHeap<T, m_size>::PercolateDown(int index){
  //T obj; // whatever type T is, you can make something
  // to compare to
  T temp;
  while(index < this->keepTrackEnd){
    if (this->m_array[2*index].CompareTo(this->m_array[2*index+1]) == 1){

      if (this->m_array[index].CompareTo(this->m_array[2*index]) == 1){
        return;
      }
      else
        { // perform swap with nodes
	  temp = this->m_array[index];
	  this->m_array[index] = this->m_array[2*index];
	  this->m_array[2*index] = temp;
	  index = 2*index; // continue to swap
        }
    }
    else
      {
        if (this->m_array[index].CompareTo(this->m_array[2*index+1]) == 1){
          return;
        }
        else{
          temp = this->m_array[index];
          this->m_array[index] = this->m_array[2*index+1];
          this->m_array[2*index+1] = temp;
          index = 2*index+1; // continue to swap
        }
      }
  }

}





#include "MinValueHeap.h"
#endif
