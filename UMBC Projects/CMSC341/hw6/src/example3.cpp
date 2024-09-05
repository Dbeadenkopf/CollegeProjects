// File: example3.cpp
//
#include <stdio.h>
#include <omp.h>

int main(){

  int reps = 10000;
  long int A[reps];
  long int B[reps];
  long int sumA = 0;
  long int sumB = 0;

  for (long int i=0; i < reps ; i++) {
    A[i] = i;
    B[i] = 2*i;
  }
  // the compiler directive default which is shared, so it tells the omp that these 
  // every thing in the body of this directive is shared and apart of omp paralell
#pragma omp parallel shared(A,B,sumA,sumB,reps)
  {
#pragma omp single // complier directive that allows for the compiler c++ routine cal
    // to occur
    {  // only one thread has to do this
      omp_set_num_threads(4); // compiler routine call to set the number of threads
      printf("Number of threads = %d\n", omp_get_num_threads() ) ; // print statement with a compiler routine call to get the number
      // of threads that were set and output them
    }

    // compiler directive to scheduele static 10 
    // two reduction clauses that call the +operator to sumA and sumB to prevent both of them    // from changing each time this program  
    for (long int i=0; i < reps; i++) {
      sumA += A[i] ;
      sumB += B[i] ;
    }
  } // end of parallel region
  printf("sumA = %ld\n", sumA) ;
  printf("sumB = %ld\n", sumB) ;
  return 0 ;
}
