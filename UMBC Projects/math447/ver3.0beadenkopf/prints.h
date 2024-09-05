#ifndef PRINTS_H
#define PRINTS_H

#include <stdio.h>
#include "mpi.h"
#include "memory.h"

void print_vector_local (double *local_x, long local_n, int id, int np);
void print_matrix_local (double *local_A, long m, long local_n, int id, int np);
void print_vector_global (double *local_x, long n, long local_n, int id, int np);
void print_matrix_global
     (double *local_A, long m, long n, long local_n, int id, int np);

#endif

