#include "matvec.h"

/* 09/12/02-10/10/02 by Matthias K. Gobbert */

void matrix_vector (double *l_y, double *l_A, double *l_x,
                    long n, long l_n, int id, int np,
                    double *partial_y, double *y)
{
  long i, l_j;

  for (i = 0; i < n; i++)
    partial_y[i] = 0.0;

  for (l_j = 0; l_j < l_n; l_j++) {
    for (i = 0; i < n; i++) {
      partial_y[i] += l_A[n*l_j+i] * l_x[l_j];
    }
  }

#ifdef PARALLEL
  MPI_Allreduce (partial_y, y, n, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
  for (l_j = 0; l_j < l_n; l_j++)
    l_y[l_j] = y[l_n*id+l_j];
  /*
  MPI_Reduce (partial_y, y, n, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
  MPI_Scatter(y,l_n,MPI_DOUBLE, l_y,l_n,MPI_DOUBLE, 0, MPI_COMM_WORLD);
  */
#else
  for (i = 0; i < n; i++)
    y[i] = partial_y[i];
  for (l_j = 0; l_j < l_n; l_j++)
    l_y[l_j] = y[l_j];
#endif

}

