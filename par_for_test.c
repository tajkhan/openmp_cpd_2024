#include <stdio.h>
#include <omp.h>              // include omp.h

#define N 16
int main() {

  int i=0;
  int sum = 0;
#pragma omp parallel for shared(sum) num_threads(4)     // OpenMP pragma to parallelize
  for(i=0; i<N; i++) {
#pragma omp critical
    sum += i;
    printf("i = %d, sum = %d, thread_id = %d\n", i, sum, omp_get_thread_num());
  }

  return 0;
}

/****************************************************
 * Don't forget to compile with -fopenmp option     *
 * on command line !!!                              * 
 ****************************************************/


