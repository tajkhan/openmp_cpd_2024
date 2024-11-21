#include <stdio.h>
// #include <unistd.h>
#include <stdlib.h>
#include <omp.h>

#define NUM_THREADS 4000


int main() {
  int res;
  long totalSum = 0;

#pragma omp parallel for reduction(+: totalSum) num_threads(NUM_THREADS)
  for(int i=0; i<NUM_THREADS*100; i++)
  {
    totalSum += i;
  }

  printf("\nTotal sum: %ld\n", totalSum);
  exit(EXIT_SUCCESS);
}
