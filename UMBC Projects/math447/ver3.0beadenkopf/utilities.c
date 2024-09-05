#include "utilities.h"

/* 09/12/02-10/10/02, updated 02/21/08 by Matthias K. Gobbert */

double dot_prod_global (double *l_x, double *l_y, long l_n, int id, int np)
{
  double d, l_d;

  l_d = serial_dot (l_x, l_y, l_n);

#ifdef PARALLEL
  MPI_Allreduce (&l_d, &d, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
#else
  d = l_d;
#endif
  
  return d;
}

double serial_dot (double *x, double *y, long n)
{
  double d;
  long i;

  d = 0.0;
  for(i = 0; i < n; i++)
    d += x[i] * y[i];

  return d;
}

double vec_norm_two_global (double *l_x, long l_n, int id, int np)
{
  double d;

  d = sqrt (dot_prod_global (l_x, l_x, l_n, id, np));
 
  return d;
}

