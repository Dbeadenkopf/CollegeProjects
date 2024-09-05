// File: example1.cpp
// the file of a simple paralell program that sums the elements
// of an array
#include <stdio.h>
#include <omp.h>



int main(){
  
  int reps = 10000;
  long int A[reps] ; // integer arrray of ints
  long int sum = 0 ; // 
  
  for (long int i=0; i < reps ; i++) {
    A[i] = i ; // initlizing the array
  }

  // using a default compiler directive here  
#pragma omp parallel shared(A,sum,reps)
  {
    #pragma omp single
    {  // only one thread has to do this
      omp_set_num_threads(4); // set the amount of threads to 4
      printf("Number of threads = %d\n", omp_get_num_threads() ) ; // us omp function to get threads and display 
    }
    
#pragma omp for schedule(static,5)
    for (long int i=0; i < reps; i++) {
      sum += A[i] ;// some all the elements that are within the array
    }

  } // end of parallel region

  printf("sum = %ld\n", sum) ; // print out the summed items within the array


  return 0 ;
}
