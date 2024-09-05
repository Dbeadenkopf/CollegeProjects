#ifndef MATVEC_H
#define MATVEC_H

#include <stdio.h>

#ifdef PARALLEL
#include <mpi.h>
#endif

#include "memory.h"
#include "utilities.h"

void matrix_vector (double *l_y, double *l_A, double *l_x,
                    long n, long l_n, int id, int np,
                    double *p_y, double *y);

#endif

