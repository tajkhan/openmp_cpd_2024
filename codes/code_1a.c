#include <stdio.h>
#include <omp.h>              // include omp.h

int main() {

#pragma omp parallel  num_threads(4)        // OpenMP pragma to parallelize
  printf("hello, world!\n");

}

/****************************************************
 * Don't forget to compile with -fopenmp option     *
 * on command line !!!                              * 
 ****************************************************/
