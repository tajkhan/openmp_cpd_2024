#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>              // include omp.h

#define N 100000000
#define NUM_THREADS 16

int* init_array(int len) {
  int *a = malloc(len * sizeof(int));
  if (a==NULL) {
    exit(-1);
  }

  srand(time(NULL));
  for(int i=0; i<len; i++) {
    a[i] = rand()%10;
  }

  return a;
}

void dest_array(int* a) {
  free(a);
}

int array_sum_serial(int *a, int len) {
  int sum = 0;
  for(int i=0; i<len; i++) {
    sum += a[i];
  }

  return sum;
}

int array_sum_omp(int *a, int len) {
  int sum = 0;
#pragma omp parallel for reduction(+:sum)
  for(int i=0; i<len; i++) {
    sum += a[i];
  }

  return sum;
}

int main() {

  int *arr = init_array(N);
  omp_set_num_threads(NUM_THREADS);

  double start = omp_get_wtime();
  int ssum = array_sum_serial(arr, N);
  double end = omp_get_wtime();
  printf("serail sum = %d, time taken = %f seconds\n", ssum, end-start);

  start = omp_get_wtime();
  ssum = array_sum_serial(arr, N);
  end = omp_get_wtime();
  printf("serail sum = %d, time taken = %f seconds\n", ssum, end-start);

  start = omp_get_wtime();
  int psum = array_sum_omp(arr, N);
  end = omp_get_wtime();
  printf("OpenMP sum = %d, time taken = %f seconds\n", psum, end-start);

  start = omp_get_wtime();
  ssum = array_sum_serial(arr, N);
  end = omp_get_wtime();
  printf("serail sum = %d, time taken = %f seconds\n", ssum, end-start);


  dest_array(arr);
  return 0;
}

/****************************************************
 * Don't forget to compile with -fopenmp option     *
 * on command line !!!                              * 
 ****************************************************/


