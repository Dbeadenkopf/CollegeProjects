#ifndef SORTED_H_
#define SORTED_H_
using namespace std;
template <class T>
class sorted {
 public:
  // Size of sorted array.  Maximum number of ints that can be
  // stored in a sorted array object
  static const int MAX_SIZE = 10;
  
  // Forward declare iterator classe(s)
  class const_iterator;

  // Forward declare iterator classe(s)
  class rand_iterator;
  
  //Default constructor
  sorted();
  
  // Non-default constructor copies data from array to sorted
  //     T* -> changed to int for testing
  sorted(T* data, int len);
  
  // Copy constructor
  //                 <T> was here changed to int for testing
  sorted( const sorted<T>& srtd );
  
  // Destructor
  ~sorted();
  
  // Overloaded assignment operator
  // sorted<T> was here      <T> was here
  sorted<T>& operator=(const sorted<T>& srtd);
 
  // Return the capacity of the storage array
  int capacity() const;

  // Return number of items stored
  int size() const;

  // Return the address of the storage array;
  // for use in grading programs
  // T* was here changed for testing
  T* getStorageArray() const;

  // Insert an item in sorted; return iterator to inserted item
  //                    T was here changed for testing
  const_iterator insert(T data);
      
  // Remove an item from sorted; return iterator to next item
  // after the erased item
  const_iterator erase(const_iterator itr);
  
  // Get element at indx position 
 //    T change for testing       
  const T& at(int indx);
  
  // Starting iterator value for const_iterator
  const_iterator begin();

  // Ending iterator value for const_iterator; typically,
  // one element beyond the last valid element in the array.
  const_iterator end();

  // Starting iterator value for rand_iterator.  Should use constant
  // value or time(NULL) as seed value for srand().
  rand_iterator rndbegin();

  // Starting iterator value for rand_iterator with seed for
  // srand() specified.  Given a sorted<T> object x, repeated 
  // use of rndbegin( unsigned seed ) with the same seed value
  // must produce the same permutation of the elements of x.
  rand_iterator rndbegin( unsigned seed );

  // Ending iterator value for rand_iterator
  rand_iterator rndend();

  //sorted<T> myArr;
  

  class const_iterator{
  public:
    
    // Allows sorted to access const_iterator's private variables.
    // Used by sorted::erase().
    friend class sorted;

    // Default constructor
    const_iterator();

    // Non-default constructor sets value to given address
    //             T changed for testing
    const_iterator(T* addr);

    // Pre-increment, e.g. ++itr
    const_iterator operator++();

    // Post-increment, e.g. itr++
    const_iterator operator++(int);

    // operator!= needed for loop control, e.g. itr != x.end()
    bool operator!=(const const_iterator& itr);

    // Unary dereference operator; returns element currently pointed
    // to by the const_iterator
    //    T& was here changed for testing
    // this function can be particularly important for 
    // allowing the operator to notice in main that
    // we are trying to make a templated array to pass in and test
    // our data
    const T& operator*();
  private:
    T* m_current;
  };
  class rand_iterator{

    // Allows sorted to access rand_iterator's private variables.
    // Used by sorted::erase().
    friend class sorted;
    
    // Default constructor
    rand_iterator();

    // Non-default constructor; pointer to sorted<T> object passed 
    // as a parameter, which allows the rand_iterator to access 
    // variables of the associated sorted<T>> container
    //                    <T> was here changed for testing
    rand_iterator( sorted<T>* srtdPtr );

    // Non-default constructor; pointer to sorted<T> passed as in
    // previous constructor, but also passes seed for random number
    // generator
    //                   <T>* was here changed for testing
    rand_iterator( sorted<T>* srtdPtr, unsigned seed );
    
    // Copy constructor
    rand_iterator( const rand_iterator& itr );

    // Destructor
    ~rand_iterator();
    
    // pre-increment
    rand_iterator operator++();
    
    // post-increment
    rand_iterator operator++(int);

    // operator!= needed for loop control, e.g. itr != x.end()
    bool operator!=(const rand_iterator& itr);
  
    // Unary dereference operator
    //    T was here changed for testing
    const T& operator*();

    // Overloaded assignment operator
    rand_iterator operator=(const rand_iterator& itr);
  private:
    sorted<T> myArr;
    int* randomIndices;
    int currentIndex;
    T* m_current2;
    // althought this might need a psudeo random see pointer of some sort
    // maybe or maybe not 
  };
 private:
  int m_size;
  T m_data[MAX_SIZE];
};

#include "sorted.cpp"
#endif
