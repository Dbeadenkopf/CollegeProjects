#include <iostream>
#include <sys/times.h>
#include <sys/resource.h>
#include <stdexcept>
#include <cstring>
#include <string>
using namespace std ;
#include "linked.h"

// call addFront reps many times
//
//cout << "test 5 with main" << endl;
void addFrontTest(unsigned int reps){
  LinkedList<double> dL ;
  
  struct rusage time1, time2 ;
  long int elapsed ;
  bool failed ;

  // record time before calls
  failed = getrusage(RUSAGE_SELF, &time1) ;
  if (failed) throw runtime_error("Could not get time") ;

  for (unsigned int i = 0 ; i < reps ; i++) {
    dL.addFront(i*i + 0.25) ;
  }

  // record time after calls
  failed = getrusage(RUSAGE_SELF, &time2) ;
  if (failed) throw runtime_error("Could not get time") ;

  // calculate elapsed time in microseconds
  elapsed = (time2.ru_utime.tv_sec - time1.ru_utime.tv_sec) * 1000000 ;
  elapsed += (time2.ru_utime.tv_usec - time1.ru_utime.tv_usec) ;

  cout << "Time for " << reps << " addFront() calls took " << elapsed << " microseconds elapsed\n" ;
}
//cout << "Testing main 7" << endl;
void sumEvenSquares(unsigned int reps) {

  LinkedList<long int> L ;

  struct rusage time1, time2 ;
  long int elapsed ;
  bool failed ;

  for (unsigned int i = 0 ; i < reps ; i++) {
    L.addFront(i*i) ;
  }

  // record time before calls
  failed = getrusage(RUSAGE_SELF, &time1) ;
  if (failed) throw runtime_error("Could not get time") ;

  long int sum = 0 ;

  // Loop in reverse
  //
  for (int i = reps - 1 ; i >= 0 ; i--) {
    if (L[i] % 2 == 0) {
      sum += L[i] ; 
    }
  }

  // record time after calls
  failed = getrusage(RUSAGE_SELF, &time2) ;
  if (failed) throw runtime_error("Could not get time") ;

  // calculate elapsed time in microseconds
  elapsed = (time2.ru_utime.tv_sec - time1.ru_utime.tv_sec) * 1000000 ;
  elapsed += (time2.ru_utime.tv_usec - time1.ru_utime.tv_usec) ;
   
   
  cout << "Time for " << reps << " sumEvenSquares() calls took " << elapsed << " microseconds elapsed\n" ;
}



int main () {
  
  int base = 1000000 ;    // change for your local machine speed

  // The elapsed time should roughly double each time
  addFrontTest(1*base) ;
  addFrontTest(2*base) ;
  addFrontTest(4*base) ;
  addFrontTest(8*base) ;

  cout << "Done!\n" ;

  unsigned int base2 = 10000 ;     // adjust for your machine speed.

  // Running times should roughly quadruple each time
  sumEvenSquares(1*base2);
  sumEvenSquares(2*base2);
  sumEvenSquares(4*base2);
  sumEvenSquares(8*base2);

  cout << "Done!\n" ;


  return 0 ;
}
