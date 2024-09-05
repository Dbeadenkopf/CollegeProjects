/*****************************************
 ** File:    sorted.cpp
 ** Project: CMSC 202 Project 5, spring 2016
 ** Author:  David Beadenkopf
 ** Date:    05/05/2016
 ** Section: 01
 ** E-mail:  beadenk1@umbc.edu 
 **
 ** This file contains the implementation for the sorted class.
 ** 
 ***********************************************/

#ifndef SORTED_CPP_
#define SORTED_CPP_
#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>
#include "sorted.h"
#include "iterator_ex.h"
using namespace std;

template <class T>
// default constructor sets m_size to 0
sorted<T>::sorted(){
  m_size = 0;
}

// destructor that deletes m_data and 
// emphasizes that it is empty with NULL
template <class T>
sorted<T>::~sorted(){
  
  delete m_data;  
  //m_data[0] = NULL;
}

template <class T>
// non default constructor
sorted<T>::sorted(T* data, int len){
  // if data array is too long, throw range_error exception
  int holder;
  if ( len > MAX_SIZE ){
    cout << "just testing" << endl;
  }
    //throw iterator_ex("my_array(int* data, int len): len exceeds MAX_SIZE");
  // copy data to m_data
  //  int holder;
  for (int i = 0; i < len-1; i++){
    for (int j = 0; j < len-1;j++){
      if (data[j] > data[j+1]){
        holder = data[j];
	data[j] = data[j+1];
        data[j+1] = holder;
      }
      m_data[j] = data[j];
    }
  }
  m_size = len;
}

// copy- constructor 
template <class T>
sorted<T>::sorted(const sorted<T>& srtd){
  T *ptr;
  int *ptr2;
  ptr = new T;
  ptr2 = new int;
  *ptr = *srtd.m_data;
  *ptr2 = *srtd.m_size;
}
 
// getter that gets the capacity
template <class T>
int sorted<T>::capacity() const{
  return sizeof(sorted::m_data);
}

// getter that returns size
template <class T>
int sorted<T>::size() const{
  return (sorted::m_size);
}

// getter that returns address of m_data
template <class T>
T* sorted<T>::getStorageArray() const{
  return sorted<T>(m_data);
}


// assignment operator
template <class T>
sorted<T>& sorted<T>::operator=(const sorted<T>& srtd){
  return (sorted::m_size = srtd.sorted::size());
  return (sorted::m_data = srtd.sorted::size());
}


// insert function 
template <class T>
typename sorted<T>::const_iterator sorted<T>::insert(T data){
  
  //data = m_current;
  if ( m_size == MAX_SIZE ){
    throw iterator_ex("sorted::insert(): MAX_SIZE exceeded");
  }
  else{
    m_size++;
    m_data[m_size-1] = data;
    return const_iterator(&m_data[m_size-1]);
  }
  return 0;
}


// begin function
template <class T>
typename sorted<T>::const_iterator sorted<T>::begin(){
  return const_iterator(&m_data[0]);
}


// iterator end function
template <class T>
typename sorted<T>::const_iterator sorted<T>::end(){
  // return address of element one past the
  // end of the array
  return const_iterator(&m_data[m_size]);
}

// erase function
template <class T>
typename sorted<T>::const_iterator sorted<T>::erase(const_iterator itr){
  T* end = &m_data[MAX_SIZE];    // one past the end of data
  T* ptr = itr.m_current;        // element to erase
  // the itr object parameter is used to const_iterators m_current which
  // is a pointer to the current entry in the array
  
  // to erase element at ptr, shift elements from ptr+1 to
  // the end of the array down one position
  while ( ptr+1 != end ){
    *ptr = *(ptr+1);
    ptr++;
  }

  m_size--;
  // NEED to pay particular attention to this itr pointer when
  // m_size if resizing
  return itr;// imporant
}

// constiterator section
template <class T>
sorted<T>::const_iterator::const_iterator(){
  m_current = NULL;
}

template <class T>
sorted<T>::const_iterator::const_iterator(T* addr){
  m_current = addr;
}

template <class T>
typename sorted<T>::const_iterator sorted<T>::const_iterator::operator++() {
  ++m_current; return *this;
}

template <class T>
typename sorted<T>::const_iterator sorted<T>::const_iterator::operator++(int) {
  const_iterator result(*this);
  ++(*this);
  return result;
}

template <class T>
bool sorted<T>::const_iterator::operator!=(const const_iterator& itr){
  return m_current != itr.m_current;
}

template <class T>
const T& sorted<T>::const_iterator::operator*() { return *m_current; }

// rand_iterator section
template <class T>
sorted<T>::rand_iterator::rand_iterator(){
  m_current2 = NULL;
}
// overloaded incrementation operator that increments and returns value
template <class T>
typename sorted<T>::rand_iterator sorted<T>::rand_iterator::operator++() {
  ++m_current2; return *this;
}

// overloaded increment operator, increments the host object
template <class T>
typename sorted<T>::rand_iterator sorted<T>::rand_iterator::operator++(int) {
  rand_iterator result(*this);
  ++(*this);
  return result;
}
// the overloaded not equals operator
template <class T>
bool sorted<T>::rand_iterator::operator!=(const rand_iterator& itr){
  return m_current2 != itr.m_current2;
}
// the dreference operator
template <class T>
const T& sorted<T>::rand_iterator::operator*() { return *m_current2; }



#include "sorted.h"
#endif

// OTHER IMPLEMENTATION
// So I wassa gonna use rand() % seed + (some num) -> i beileve this would ahve given me a random number that would have put that number in between
// a certain range and the integer,

// The rand_iterator was suppose to randomly select songs to erase and go to that particular song or data item in a random item in the array kind of like a shuffling mechanism for a mp3 player

// i wasnt sure about the constructer that did (sorted<T>* stdpr) or some pointer object of sorted<t> , i new that it could grab and use the m_size and m_data but wasnt sure entirley about what they weere going to be used for  
