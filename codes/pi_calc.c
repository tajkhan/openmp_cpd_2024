#include <stdio.h>
#include <math.h>
#include <time.h>
#include <omp.h>              // include omp.h

#define NUM_RECTS 100000000
#define NUM_THREADS 2


double pi_calc_serial(int rects) {
  double quadrant_area = 0.0;
  double width = 1.0/rects;
  for(int i=0; i<rects; i++) {
    double x = i*width;
    double height = sqrt(1.0 - x*x);
    double rect_area = height * width;
    quadrant_area += rect_area;
  }

  return 4*quadrant_area;
}

double pi_calc_omp(int rects) {
  double quadrant_area = 0.0;
  double width = 1.0/rects;
#pragma omp parallel for reduction(+:quadrant_area)
  for(int i=0; i<rects; i++) {
    double x = i*width;
    double height = sqrt(1.0 - x*x);
    double rect_area = height * width;
    quadrant_area += rect_area;
  }

  return 4*quadrant_area;
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

  omp_set_num_threads(NUM_THREADS);

  double start = omp_get_wtime();
  double pi = pi_calc_serial(NUM_RECTS);
  double end = omp_get_wtime();
  printf("serail pi = %f, time taken = %f seconds\n", pi, end-start);

  start = omp_get_wtime();
  pi = pi_calc_omp(NUM_RECTS);
  end = omp_get_wtime();
  printf("OpenMP pi = %f, time taken = %f seconds\n", pi, end-start);

  return 0;
}

/****************************************************
 * Don't forget to compile with -fopenmp option     *
 * on command line !!!                              * 
 *
 * Ref: http://hpcinside.blogspot.com/p/blog-page_29.html
 ****************************************************/



