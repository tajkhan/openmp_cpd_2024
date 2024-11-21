#include <stdio.h>
// #include <unistd.h>
#include <stdlib.h>

int main() {
  int k;
  int n=10000000;

  double pi_approx;

  double factor = 1.0;
  double sum=0.0;

  for(k=0; k<n; k++) {
    if (k%2 == 0)
      factor = 1.0;
    else
      factor = -1.0;
    sum += factor/(2*k+1);
  }

  pi_approx = 4.0 * sum;

  printf("\nPI: %.20f\n", pi_approx);

  exit(EXIT_SUCCESS);
}
