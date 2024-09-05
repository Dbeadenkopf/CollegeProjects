#ifndef POWERMETHOD_H
#define POWERMETHOD_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "memory.h"
#include "utilities.h"
#include "matvec.h"
#include "prints.h"

double power_method (double *l_A, double *l_x, double tol, int itmax,
                     long n, long l_n, int id, int np, int *itout,
                     double *l_y, double *partial_y, double *y);

#endif

