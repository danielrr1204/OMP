
#include <omp.h>
#include <stdio.h>

#define NUM_THREADS 4

    static long num_steps = 100000000; 
    double step;
void main () { 
    int i;
    int nthreads; 
    double pi;
    double x;
    double sum=0.0;

step = 1.0/(double) num_steps;
omp_set_num_threads(NUM_THREADS);

#pragma omp parallel for private(x) reduction(+:sum)
for (i=0;i< num_steps; i++) {
    x = (i+0.5)*step;
    sum += 4.0/(1.0+x*x);
}
pi = step * sum;
printf("Pi es %3.20f, calculado con %d pasos y %d threads\n", pi,num_steps,NUM_THREADS);
}
