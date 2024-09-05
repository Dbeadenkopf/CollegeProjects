#include <iostream>
#include <string>
#include <exception>
#include "iterator_ex.h"
#include "sorted2.h"
using namespace std;
sorted2::sorted2(){
  m_size = 0;
}

sorted2::~sorted2(){
  //for (unsigned int i = 0; i < m_size; i++){
  delete m_data;
  m_data[0] = NULL;
}

sorted2::sorted2(int* data, int len){ 
  // if data array is too long, throw range_error exception  
  if ( len > MAX_SIZE ){
    forexC = "exceeds size";
    throw iterator_ex(forexC);
  }
  for (int i = 0; i < len; i++){
    m_data[i] = data[i];
  }
  m_size = len;
}
int sorted2::capacity() const{
  return sizeof(m_data);
}
int sorted2::size() const{
  return m_size;
}

int* sorted2::getStorageArray() const{
  const int ptr[MAX_SIZE];
  ptr = &m_data;
  
  return ptr;
}



