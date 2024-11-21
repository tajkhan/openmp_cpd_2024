#include <stdio.h>
//#include <unistd.h>
#include <stdlib.h>
#include <omp.h>

#define NUM_THREADS 4

void A_function(void);

int main() {
  int res;

#pragma omp parallel num_threads(NUM_THREADS)
  A_function();

  printf("All done\n");
  exit(EXIT_SUCCESS);
}


void A_function(void) {
  int my_number = omp_get_thread_num();
  int totalThreads = omp_get_num_threads();

  for (int i=0; i<5; i++)
    fprintf(stderr, "\tthread_function %d, %d\n", my_number, i);

  printf("\tBye from %d\n", my_number);
}
