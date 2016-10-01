
#include <stdio.h>

static long num_steps = 1000000000;
double step;

void main () { 
 int i;
 double pi;
 double x;
 double sum = 0.0;

 step = 1.0/(double) num_steps;

 for (i=0; i< num_steps; i++){
   x = (i+0.5)*step;
   sum = sum + 4.0/(1.0+x*x);
 }
 pi = step * sum;

 printf("Pi es %3.20f, calculado con %ld pasos\n", pi,num_steps);
}
