#include <stdio.h>
#include <openacc.h>
#include <stdlib.h>

int main() 
{
    int num = 10;
    int *vetor = (int*) malloc(num * sizeof(int));

    #pragma acc parallel loop
    for (int i=0; i<num; i++)
    {
        vetor[i] = 0;
        printf("%i\n", vetor[i]);
    }
}