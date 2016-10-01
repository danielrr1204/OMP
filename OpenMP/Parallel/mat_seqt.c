
#include "matriz.h"
#include <stdio.h>

int main()
{
    int i,j,k;
    register int result;

    for (i=0; i<M1; i++) {
	for (j=0; j<N2; j++) {
	    result = 0;
	    for (k=0; k<N1; k++) 
		result += mat1[i][k] * mat2[k][j];
	    matR[i][j] = result;
	}
    }
    
    return(0);

}
