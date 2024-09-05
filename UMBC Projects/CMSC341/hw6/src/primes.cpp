// Name: David Beadenkopf
// Section: Chang 10:00 am - 11:15 am
// objective: to program a small omp parallel program that will
// count up the number of prime numbers up until 10000000
//
// Assignment: the for loop should be parallel and use reduction clause
// for the prime sums , output the ending values at the end
// 
#include <stdio.h>
#include <omp.h>
#include <math.h>
// a function that is used to determine wether 
// a value from 0 - 10,000,000 is prime
int isPrime (unsigned int n) {
  unsigned int m = sqrt(n) ;
  for (unsigned int k=2 ; k <= m ; k++) {
    if (n % k == 0) return 0 ; 
  }
  return 1; 
}


int main(){
  long int holdPrimes;
  unsigned int primes = 0;
 // using a default compiler directive here
#pragma omp parallel shared(holdPrimes)
  {
    #pragma omp single
    {  // only one thread has to do this
      omp_set_num_threads(4); // set the amount of threads to 4 
      printf("Number of threads = %d\n", omp_get_num_threads()); // us omp function to get threads and display
    }
    // using reduction clause to call the +operator function on primes, that way the values will not change
#pragma omp for schedule(static,5) reduction(+:primes)
    for (unsigned int i=0; i < 10000000; i++){
      holdPrimes = isPrime(i);
      if (holdPrimes == 0){
	primes+= i;
      }
    }
  } // end of parallel region
  printf("primes = %ld\n", primes) ; // print out the summed items within the array
  return 0;
}
