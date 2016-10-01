
#include <stdio.h>

int main()
{
    int i,j,k;
    int acum=0;

    int a[1000], b[1000];


#ifdef _OPENMP
    omp_set_num_threads(4);
#endif

#pragma omp parallel for lastprivate(i) schedule(static)
    for (i=0; i<1000; i++)
        a[i] = b[i] + b[i+1];


printf("i: %d\n", i);

#pragma omp parallel for reduction(+:acum) schedule(static)
    for (i=0; i<1000; i++)
        acum += i;


printf("acum: %d\n", acum);

    return(0);

}

