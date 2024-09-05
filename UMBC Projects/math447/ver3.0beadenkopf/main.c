#include "main.h"

/* 09/12/02-10/10/02, updated 02/07/08 by Matthias K. Gobbert */

void setup_example (double *l_A, long n, long l_n, int id, int np)
{
  long i, j, l_j;

  /* example in global notation: A is n-by-n matrix with components
   * A(i,j)=1/(i+j-1) for i,j=1,...,n in 1-based mathematical counting or
   * A(i,j)=1/(i+j+1) for 0<=i,j<n in 0-based computer science counting
   */
  for (l_j = 0; l_j < l_n; l_j++)
    for (i = 0; i < n; i++)
    {
      j = l_j + id*l_n;
      l_A[i+l_j*n] = 1.0 / ((double) (i+j+1));
    }
  /* Note 1: loops ordered to access memory of l_A consecutively */
  /* Note 2: systematic choice of variable names and uses:
   * 0<=l_j<l_n is the index into the local l_A,
   * j is the mathematical index into the global A (not actually set up),
   * hence, j = l_j + id*l_n transforms l_j to j such that we get
   * id*l_n<=j<(id+1)*l_n on Process id.
   */
}

int main (int argc, char *argv[])
{
  int id, np, processor_name_len;
  char processor_name[MPI_MAX_PROCESSOR_NAME];
  char message[100];
  MPI_Status status;
  long n;
  double v;
  long l_n;
  long nln;
  double *l_A, *l_x, *l_y, *p_y, *y; 
  double tol;
  int itmax;
  double lambda, resnormabs, resnormrel;
  int it;
  double tstart, tend, timesec, tmin, tsec;
  int inthrs, intmin, intsec;
  long i, l_j;

  MPI_Init(&argc, &argv);

  /* Check processes: */
  MPI_Comm_size(MPI_COMM_WORLD, &np);
  MPI_Comm_rank(MPI_COMM_WORLD, &id);
  /*
  MPI_Get_processor_name(processor_name, &processor_name_len);
  sprintf(message, "Hello from %3d of %3d on %s", id, np, processor_name);
  if (id == 0) {
    printf("%s\n", message);
    for (i = 1; i < np; i++) {
      MPI_Recv(message, 100, MPI_CHAR, i, 0, MPI_COMM_WORLD, &status);
      printf("%s\n", message);
    }
  } else {
    MPI_Send(message, 1+strlen(message), MPI_CHAR, 0, 0, MPI_COMM_WORLD);
  }
  fflush(stdout);
  */

  /* test output of command-line: */
  /*
  if (id == 0) {
    printf("argc = %d\n", argc);
    for (i = 0; i < argc; i++) {
      printf("argv[%d] = %s\n", i, argv[i]);
    }
    printf("\n");
  }
  */

  /* process command-line inputs: */
  if (argc != 4)
  {
    if (id == 0)
    {
      printf ("Usage: \"./power n tol itmax\" \n");
      printf ("  with integer n, real tol, and integer itmax\n");
    }
    MPI_Abort (MPI_COMM_WORLD, 1);
  }
  n     = (long)atof(argv[1]);
  tol   =      atof(argv[2]);
  itmax =      atoi(argv[3]);
  v     =      atof(argv[1]);
  if (((double)n) != v)
  {
    if (id == 0)
      printf("Error: input must be integer! n = %ld, v = %f\n", n, v);
    MPI_Abort(MPI_COMM_WORLD, 1);
  }

  /* number of processes np must divide n: */
  if ( (n % np) != 0)
  {
    if (id == 0)
    {
      printf("Error: np must divide n!\n");
      printf("  n = %ld, np = %d, n%%np = %ld\n", n, np, (n%np));
    }
    MPI_Abort(MPI_COMM_WORLD, 1);
  }

  /* compute size of local blocks: */
  l_n = n / np;
  nln = n * l_n;
  if (id == 0)
  {
    printf("n =%6ld, np =%5d, l_n =%6ld, n*l_n =%12ld, nln =%12ld\n",
           n, np, l_n, (n*l_n), nln);
    printf("\n");
    fflush(stdout);
  }

  /* allocate storage: */
  l_A = allocate_double_vector((n*l_n)); /* l_A is n-by-l_n */
  l_x = allocate_double_vector(l_n);
  l_y = allocate_double_vector(l_n);
  p_y = allocate_double_vector(n);
  y   = allocate_double_vector(n);

  /* setup example: */
  setup_example(l_A, n, l_n, id, np);

  /* test printout for small examples: */
  if (n <= 4) {
    /* print_matrix_local  (l_A, n, n, l_n, id, np); */
    print_matrix_global (l_A, n, n, l_n, id, np);
  }

  /* set inputs to power method: */
  /* choose default initial guess: */
  for (l_j = 0; l_j < l_n; l_j++)
    l_x[l_j] = 1.0 / sqrt((double)n);

  /* run and time power method: */
  MPI_Barrier(MPI_COMM_WORLD);
  tstart = MPI_Wtime ();

  lambda = power_method(l_A, l_x, tol, itmax, n, l_n, id, np, &it,
                        l_y, p_y, y);

  MPI_Barrier(MPI_COMM_WORLD);
  tend = MPI_Wtime();
  timesec = tend - tstart;

  /* print out eigenvector approximation: */
  if (n < 25) {
    /* print_vector_local  (l_x, n, l_n, id, np); */
    print_vector_global (l_x, n, l_n, id, np);
  }

  /* compute residual y = A * x - lambda * x and its norm: */
  matrix_vector (l_y, l_A, l_x, n, l_n, id, np, p_y, y);
  for (l_j = 0; l_j < l_n; l_j++)
    l_y[l_j] = l_y[l_j] - lambda * l_x[l_j];
  resnormabs = vec_norm_two_global (l_y, l_n, id, np);
  resnormrel = resnormabs / lambda;

  /* final summary output: */
  if (id == 0)
  {
    printf("number of iterations allowed    itmax = %10d\n", itmax);
    printf("number of iterations taken         it = %10d\n", it);
    printf("relative tolerance chosen         tol = %24.16e\n", tol);
    printf("eigenvector approximation      lambda = %24.16e\n", lambda);
    printf("Euclidean norm of residual resnormabs = %24.16e\n", resnormabs);
    printf("Euclidean norm of residual resnormrel = %24.16e\n", resnormrel);
    printf("observed wall clock time in seconds   = %12.2f\n", timesec);
    diag_time(timesec);
/*  printf("elapsed time for power method timesec:\n");
    printf("  in seconds = %24.16e\n", timesec);
    inthrs = lround(timesec) / (60*60);
    intmin = (lround(timesec) - inthrs*60*60) / 60;
    intsec = lround(timesec) % 60;
    printf("  in HH:MM:SS = %5.2d:%2.2d:%2.2d\n", inthrs, intmin, intsec);
*/
    printf("\n");
  }

  /* Check memory usage */
  diag_memory();

  free_vector(l_A);
  free_vector(l_x);
  free_vector(l_y);
  free_vector(p_y);
  free_vector(y);

  MPI_Finalize();

  return 0;
}

