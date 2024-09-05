#include <stdio.h>
#include <stdlib.h> // library call to use exit
#include <omp.h>
#include <math.h>
#include <list>
// a function that is used to determine wether
// a value from 0 - 10,000,000 is prime



int isPrime(unsigned int n){
  unsigned int m = sqrt(n);
  for (unsigned int k=2 ; k <= m ; k++){
    if (n % k == 0) return 0;
  }
  return 1;
}




int main(){
  bool bothPrime;
  std::list<int> L1;
  std::list<int> L2;
  //int primes = 0;
  std::list<int>::const_iterator iterator1; // to iterate over list 1
  std::list<int>::const_iterator iterator2; // to iteratre over list 2
  int counter1;
  int counter2;
  //  int primei; // varible to hold prime
  //int primeiplustwo; // varible to hold prime two
  // long int holdPrimes;
  int start; // varible
  int stop;

  start = 10000;
  stop = 20000;
  // using a default compiler directive here
#pragma omp parallel shared(start,stop, counter1, counter2, bothPrime)
  {
    #pragma omp single
    {  // only one thread has to do this
      {  // only one thread has to do this
	omp_set_num_threads(4); // set the amount of threads to 4
	printf("Number of threads = %d\n", omp_get_num_threads()); // us omp function to get threads and display
      }
    }
      // using reduction clause to call the +operator function on primes, that way the values will not change
#pragma omp for schedule(static,5) reduction(||:bothPrime)
      for (unsigned int i = start; i < stop; i++){
	bothPrime = (bothPrime || (isPrime(i) && isPrime(i+2)));
	if (bothPrime == true){
	  #pragma omp critical
	  {
	    L1.push_front(i);
	    L2.push_front(i+2);
	  } 
	}
	// end of parallel region
      }
    
  }
  if (bothPrime == true){
    printf("yes there are twin primes between %ld and %1d\n", start, stop); // print out the summed items within the array
    for (iterator1 = L1.begin(); iterator1 != L1.end(); ++iterator1) {
      for (iterator2 = L2.begin(); iterator2 != L2.end(); ++iterator2)
	printf("%1d , %1d\n", *iterator1, *iterator2);
      }
    }
  else
    {
      printf("No, there are no twin primes between %1d and %1d\n", start, stop);
    }


  return 0;
}
