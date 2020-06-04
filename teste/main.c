#include <stdio.h>

typedef union number
{
    int num_inteiro;
    float num_real;
}number;

typedef struct vetor
{
    int tamanho;
    number *vetor_num;
}vetor;

int soma(vetor vet)
{
    int res = 0;
    for(int i = 0; i < vet.tamanho; i++)
    {
        res += vet.vetor_num[i].num_inteiro;
    }
    return res;
}

int main()
{
    vetor v1;
}