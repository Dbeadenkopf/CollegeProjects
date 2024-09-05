// File: example2.cpp
//
#include <stdio.h>
#include <omp.h>

int main() {

  int reps = 10000;
  long int A[reps];
  long int sum = 0;

  for (long int i=0; i < reps ; i++) {
    A[i] = i ;
  }

#pragma omp parallel shared(A,sum,reps)
  {
      #pragma omp single
    {  // only one thread has to do this
      omp_set_num_threads(4); // seting 4 threads again
      printf("Number of threads = %d\n", omp_get_num_threads() ) ; // printing 
      // those threads out
    }

#pragma omp for schedule(static,5) reduction(+:sum)// here is the reduction clause, allows for the sum varible to not be updated each time the program
    // the shedualed compiler directive allows for the body of code. The reduction sd 
    //just generates the +operator to add up the sum at the end of the for loop, this way it does not execute like the 
    // prevous program
    for (long int i=0; i < reps; i++) {
      sum += A[i] ;
    }
  } // end of parallel region

  printf("sum = %ld\n", sum) ;


  return 0 ;
}
