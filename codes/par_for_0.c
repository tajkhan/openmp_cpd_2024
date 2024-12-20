#include <stdio.h>
#include <omp.h>              // include omp.h

#define N 1000
int main() {

  int i=0;
  int sum = 0;
#pragma omp parallel for num_threads(4)     // OpenMP pragma to parallelize
  for(i=0; i<N; i++)

#pragma omp critical
    sum = sum + i;

  printf("Sum = %d\n", sum);
}

/****************************************************
 * Don't forget to compile with -fopenmp option     *
 * on command line !!!                              * 
 ****************************************************/

