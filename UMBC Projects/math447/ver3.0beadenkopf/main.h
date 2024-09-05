#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#ifdef PARALLEL
#include "mpi.h"
#endif

#include "memory.h"
#include "utilities.h"
#include "matvec.h"
#include "powermethod.h"
#include "prints.h"
#include "nodesused.h"
#include "diag_time.h"
#include "check_memory.h"

void setup_example (double *l_A, long n, long l_n, int id, int np);

#endif

