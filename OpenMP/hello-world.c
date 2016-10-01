#include <stdio.h>
#include <omp.h>


void main () 
{ 
 omp_set_num_threads(4);

#pragma omp parallel
 {
   int id = omp_get_thread_num();
   printf("hello world from %d\n", id);
 } 

 printf("all done\n");
}
