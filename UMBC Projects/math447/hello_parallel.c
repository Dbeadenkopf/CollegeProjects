#include <mpi.h>
#include <stdio.h>





int main(){
  // so we are going to initilize the mpi enviroment
  MPI_Init(NULL, NULL);


  // now to get the number of processors
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  // get the ramk of the processors
  // usually starts at 9=0
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);


  // getting the name of the processors

  char processor_name[MPI_MAX_PROCESSOR_NAME];
  int name_length;
  MPI_Get_processor_name(processor_name, &name_len);

  // now we can print out our hhello world mesage
  printf("Hello world from processor &s, rank %d out of %d proccessors \n", processor_name,
	 world_rank, world_size);

  MPI_Finalize();

}
