#include "powermethod.h"

/* 09/12/02-10/10/02 by Matthias K. Gobbert */

double power_method (double *l_A, double *l_x, double tol, int itmax,
                     long n, long l_n, int id, int np, int *itout,
                     double *l_y, double *partial_y, double *y)
{
  double err, lambda, lambdaold, ynorm;
  int it;
  long l_j;

  matrix_vector (l_y, l_A, l_x, n, l_n, id, np, partial_y, y);

  lambda = 0.0;
  it = 0;
  err = tol + 1.0;
  while ( (err > tol) && (it < itmax) )
  {
    it++;

    lambdaold = lambda;

    ynorm = vec_norm_two_global (l_y, l_n, id, np);
    for (l_j = 0; l_j < l_n; l_j++)
      l_x[l_j] = l_y[l_j] / ynorm;
    matrix_vector (l_y, l_A, l_x, n, l_n, id, np, partial_y, y);
    lambda = dot_prod_global (l_x, l_y, l_n, id, np);

    err = fabs ((lambda - lambdaold) / lambda);
  }

  *itout = it;

  if (it == itmax)
  {
    if (id == 0)
      printf ("Warning: itmax reached in power method!\n");
  }

  return lambda;
}

