#ifndef NODESUSED_H
#define NODESUSED_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "getcpuid.h"

#ifdef _OPENMP
#include <omp.h>
#include <sched.h>
#endif

#ifdef PARALLEL
#include <mpi.h>
#endif

void nodesused (void);
int sched_getcpu();

#endif

