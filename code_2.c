#include <stdio.h>
#include <omp.h>              // include omp.h

#define N 1000
int main() {

  int sum = 0;

  for(int i=0; i<N; i++)
    sum = sum + i;

  printf("Sum = %d\n", sum);
}

/****************************************************
 * Don't forget to compile with -fopenmp option     *
 * on command line !!!                              * 
 ****************************************************/

