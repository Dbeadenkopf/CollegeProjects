#ifndef SORTED2_H
#define SORTED2_H
#include "iterator_ex.h"
using namespace std;
class sorted2 {
 public:

  // Size of sorted array.  Maximum number of ints that can be
  // stored in a sorted array object
  static const int MAX_SIZE = 10;
  
  //Default constructor
  sorted2();

  // Non-default constructor copies data from array to sorted
  //     T* -> changed to int for testing
  sorted2(int* data, int len);

  // Copy constructor
  //                 <T> was here changed to int for testing
  sorted2( const sorted2& srtd );

  // Destructor
  ~sorted2();

  // Overloaded assignment operator
  // sorted<T> was here      <T> was here
  sorted2& operator=(const sorted2& srtd);

  // Return the capacity of the storage array
  int capacity() const;

  // Return number of items stored
  int size() const;

  // Return the address of the storage array;
  // for use in grading programs
  // T* was here changed for testing
  int* getStorageArray() const;

 private:
  int m_size;
  int m_data[MAX_SIZE];
  const char* forexC;
};


#endif
