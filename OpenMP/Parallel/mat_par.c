#include "matriz.h"
#include <omp.h>
#include <stdio.h>

int main()
{
    int i,j,k;
    register int result;

	
	#pragma omp parallel for default(none) private(result,j,k) shared(mat1,mat2,matR)
    for (i=0; i<M1; i++) {
        for (j=0; j<N2; j++) {
            result = 0;
            for (k=0; k<N1; k++)
                result += mat1[i][k] * mat2[k][j];
            matR[i][j] = result;
        }
    }

    for (i=0; i<M1; i++) {
        for (j=0; j<N2; j++) {
            printf("%d ", matR[i][j]);
        }
        printf("\n");
    }

    return(0);

}

