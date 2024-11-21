#include <stdio.h>
// #include <unistd.h>
#include <stdlib.h>
#include <omp.h>

#define NUM_THREADS 4000

int thread_function(void);

int main() {
  int res;
  long totalSum = 0;

#pragma omp parallel num_threads(NUM_THREADS)
  {
#pragma omp critical    // ??
    totalSum += thread_function();
  }

  printf("\nTotal sum: %ld\n", totalSum);
  exit(EXIT_SUCCESS);
}


int thread_function(void) {
  int my_number = omp_get_thread_num();
  int totalThreads = omp_get_num_threads();

  int startAt = my_number*100;

  int sum = 0;
  for (int i=startAt; i <= (startAt+99); i++)
    sum += i;

  printf("\n\tBye from %d\n", my_number);

  return sum;
}
