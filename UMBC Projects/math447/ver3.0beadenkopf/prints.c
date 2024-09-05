#include "prints.h"

/* 09/12/02-10/10/02 by Matthias K. Gobbert */

void print_vector_local (double *local_x, long local_n, int id, int np)
{
  long j;

  for (j = 0; j < local_n; j++)
    printf ("%9.1f\n", local_x[j]);
}

void print_matrix_local
     (double *local_A, long m, long local_n, int id, int np)
{
  long i, j;

  for (i = 0; i < m; i++)
  {
    for (j = 0; j < local_n; j++)
      printf ("%9.1f ", local_A[i+j*m]);
    printf ("\n");
  }
}

void print_vector_global (double *local_x, long n, long local_n, int id, int np)
{
  long j;
  double *x;

  if (id == 0)
    x = allocate_double_vector (n); /* x is n vector */
  else
    x = NULL;
  MPI_Gather (local_x,local_n,MPI_DOUBLE, x,local_n,MPI_DOUBLE,
              0, MPI_COMM_WORLD);
  if (id == 0)
  {
    for (j = 0; j < n; j++)
      printf ("%24.15e\n", x[j]);
  }
  if (id == 0)
    free_vector (x);
}

void print_matrix_global
     (double *local_A, long m, long n, long local_n, int id, int np)
{
  long i, j;
  double *A;

  if (id == 0)
    A = allocate_double_vector ((m*n)); /* A is m x n matrix */
  else
    A = NULL;
  MPI_Gather (local_A,(m*local_n),MPI_DOUBLE, A,(m*local_n),MPI_DOUBLE,
              0, MPI_COMM_WORLD);
  if (id == 0)
  {
    for (i = 0; i < m; i++)
    {
      for (j = 0; j < n; j++)
        printf ("%12.4f ", A[i+j*m]);
      printf ("\n");
    }
  }
  if (id == 0)
    free_vector (A);
}

