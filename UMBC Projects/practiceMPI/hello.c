#include <mpi.h>
#include <stdio.h>


int main(int argc, char** argv){
  // ok so we are going to Initialize the MPI enviroment
  MPI_Init(NULL, NULL);

  // then getting the number of processes
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  

  // Get the rank of the process
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_size);

  // Get the name of the processor
  char processor_name[MPI_MAX_PROCESSOR_NAME);
  int name_len;
  MPI_Get_processor_name(processor_name, &name_len);


  // Now that we have intilized the MPI enviroment, got the number of processor, getting the rank of that process, and then getting the name of the processor
  // we cam print off the hello world message
  printf("Hello world from processor %s, rank %d out of %d processors\n", processor_name, world_rank, world_size);

  
  MPI_Finalize();
}
