#include <stdio.h>
// #include <unistd.h>
#include <stdlib.h>
#include <omp.h>

#define NUM_THREADS 4

int main() {
  int k;
  int n=10000000;

  double pi_approx;

  double factor = 1.0;
  double sum=0.0;
#pragma omp parallel for num_threads(NUM_THREADS) //private(factor) reduction(+: sum)
  for(k=0; k<n; k++) {
    sum += factor/(2*k+1);
    factor = -factor;
  }

  pi_approx = 4.0 * sum;

  printf("\nPI: %.20f\n", pi_approx);

  exit(EXIT_SUCCESS);
}
