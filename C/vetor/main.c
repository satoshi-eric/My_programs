#include "vetor.h"

int main()
{
    int vet_int[1] = {2};
    struct vetor v1 = criar_vetor(1, 'i', vet_int);
    int vet_int2[2] = {2, 3};
    
    v1.printar_vetor(v1);
}