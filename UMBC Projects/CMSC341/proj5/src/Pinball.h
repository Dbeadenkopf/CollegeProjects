// The header file that holds the interface for the
// cuccohashing scheme / pinball hashing. The pinball hashing
// will make use of a hash table and using what can be
// known as primary slots and auxilary slots. The primary slots
// are each index of the array which each index will have 
// the auxilary slots(degree given + 1) ( in my case degree = 5)
// so each primary slot will have auxilary slots 6. The way
// the Pinball hashing works is that strings will be inserted
// into the hashtable using a hashing function which each string 
// that is to be inserted will be put into the hash function
// which is mod(N) where N = capacity of the array. The function
// will then spit out the random primary slot that the inserted string
// will go to and that string will be inserted in one of the auxilary
// slots of that primary slot. WorstCase( some spots may already
// be occupied and so an empty auxilary spot will need to be found)
// if all auxilary spots are occupied, begin ejecting, if ejection
// limit is reached, that inserted word can be flagged as not found
// ejection = (take out string, put in string, hold original string
// put that string into auxilary spot, eject that string, and when 
// ejection limit is reached, flag that string as not found)



#ifndef _PINBALL_H_
#define _PINBALL_H_

#include <string>
#include <stdexcept>
#include <stdlib.h> // allows for the usage of free and malloc
//#include "words.h"
using namespace std;

// The inline exception function that will 
// throw an exception if a word is marked as not
// found which implies that the ejection limit (in my case 8)
// has been reached
class PinballHashFull : public std::out_of_range {

 public:
 PinballHashFull(const string& what) : std::out_of_range(what) { }
};


class Pinball
{

 public:
  

  //  Pinball();

  // the constructor that if no value
  // is given, then the size of the 
  // hash table n is prime, space must 
  // be allocated for the H array and it 
  // needs to be initilized
  Pinball(int n=1019);   

  // the destructor that will act as a memory manager
  // for this object, strings in the 
  // H array must be deallocated using free()
  ~Pinball();
  
  // the function that will insert 
  // a copy of the C-str into the hash table
  // if the hash table is full or the maximum number
  // of ejections was exceeded, then insert() should
  // throw an PINBALLHASHFULLEXCEPTION
  void insert(const char *str);

  // the find function looks for str in the hash table
  // if str is found, the index of str is returned
  // if str is not found, the function will
  // return -1. The location(INDEX) returned by 
  // find is only valid until the next call to insert()
  // or to remove() can hold the value until
  // insert() or remove is called
  int find(const char *str);

  // the at() function returns a pointer to the string
  // stored at the index slot of the hash table. If the index is
  // less than 0 or greater than or equal to m_capacity, then at()
  // should throw an out_of_range exception
  // the pointer returned has type const* char which
  // means it will prevent the string being stored in the
  // hash table from being changed which helps with just looking
  // at the string in the hash table, the calling function
  // can make a copy if desired
  const char * at(int index);


  // The remove function will remove the string
  // from the hash table and returns the pointer
  // of the string which cannot be copied(if desired 
  // need to use calling function). else if string
  // is not in the hash table, remove() will return NULL
  // !!!** code should deallocate the string that is
  // returned using free() **!!!
  char * remove(const char *str);

  // fucntion that will print out some 
  // statistics about the hash table
  // the statistics are
  // 1. The randomness level( mine is not so random option 3)
  // 2. Capacity of hash table
  // 3. size of hash table
  // 4. degree of hash table
  // 5. the ejection limit
  // 6. The number of primary slots
  // 7. The average hits to primary slots
  // 8. The maximum hits to primary slots
  // 9. The total number of ejections
  // 10. The maximum number of ejections in a single insertion
  void printStats();

  // A getter function that returns 
  // the size(number of items stored in
  // the hash table) 
  int size() { return m_size ; }

  // add public data members and 
  // public member functions as needed

  bool isEmpty(); //  function that returns true if the hashtable is empty
  // ** may need a member function to 
  // compute the average hits to prrimary slots
 
  // ** may need member function to computer
  // the maxium hits to primary slot
  // could use that macro defined maximum function

  // ** may need a member function to compute the total number of
  // ejections
  
  bool ejectlimitReached(); // function that returns the ejection limit that 
  // has been reached

  void setPrimary(int Primary); // function that sets the primary count

  unsigned int getPrimary(); // function that gets the current 
  // number of primary slots


  unsigned int primaryslotCount(); // function that increments each time
  // a primary slot is generated

  unsigned int generateOffsets(unsigned int Primary); // function that takes in
  // the primary slot generated by the hashcode and creates the offsets of that primary
  // slots

  // ** may need member function to compute the maximum number of ejections
  // iun a single insertion

  // need a member helper function
  // to generate random off sets (maybe?)

 private:
 
  char ** H;        // the actual hash table (allows for the initilization)
  int m_size;       // number of items stored in H
  int m_capacity;   // number slots allocated in H
  
  int m_degree;     // use degree assigned to you
  int m_ejectLimit; // use ejection limit assigned to you
  int countEjects; // varible that will count the number of ejections
  string randomnessLvl; // string to hold the random-ness level
  unsigned int m_primarySlots; // member varible to hold the #of primary slots
  unsigned int holdHashvalue; // member varbile that will hold the hash value
  int m_totalEjects; // member varible to hold the total number of ejections
  int m_maxEjects; // member varible to hold the maximum number of ejections
  
  unsigned int offset1;
  unsigned int offset2;
  unsigned int offset3;
  unsigned int offset4;


  // Made inline definition of hashCode() so everyone uses
  // the same function.
  //  ** I think this function will generate a hash value?
  unsigned int hashCode(const char *str) {

    unsigned int val = 0 ; 
    const unsigned int thirtyThree = 33 ;  // magic number from textbook

    int i = 0 ;
    while (str[i]!= '\0') { // a C-string ends in \0 
      val = (val * thirtyThree + str[i])%m_capacity; // now will keep within bounds of hash table
      i++ ;
    }
    return val ; // return hash value
  }


  // add private data members and 
  // private member functions as needed

};


#endif
