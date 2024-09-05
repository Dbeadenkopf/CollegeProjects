#ifndef UTILITIES_H
#define UTILITIES_H

#include <stdio.h>
#include <math.h>

#ifdef PARALLEL
#include "mpi.h"
#endif

#include "main.h"
#include "memory.h"

double dot_prod_global (double *l_x, double *l_y, long l_n, int id, int np);
double serial_dot (double *x, double *y, long n);
double vec_norm_two_global (double *l_x, long l_n, int id, int np);

#endif

