#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union numero
{
    int int_num;
    float float_num;
}numero;


typedef struct vetor
{
    int tamanho_membro;
    char tipo_membro;
    numero *vetor_membro;
    void (*printar)(struct vetor vet_param);
}vetor;

/* função para printar o vetor */
void printar_vetor(vetor vet_param)
{
    /* printa o vetor de int */
    if(vet_param.tipo_membro == 'i')
    {
        for(int i = 0; i< vet_param.tamanho_membro; i++)
        {
            printf("%i\n", vet_param.vetor_membro[i].int_num);
        }
    }     
    /* printa o vetor de float */
    else if(vet_param.tipo_membro == 'f')
    {
        for(int i = 0; i< vet_param.tamanho_membro; i++)
        {
            printf("%f\n", vet_param.vetor_membro[i].float_num);
        }
    } 
}

vetor criar_vetor(int tamanho_param, char tipo, void *vetor_param)
{
    vetor vetor_instancia;
    vetor_instancia.tamanho_membro = tamanho_param; /* atribuindo o tamanhp do vetor */
    vetor_instancia.vetor_membro = (numero*)malloc(vetor_instancia.tamanho_membro * sizeof(numero)); /* alocando memória para o vetor */
    vetor_instancia.tipo_membro = tipo; /* atribuindo o tipo do vetor: int ou float */
    
    vetor_instancia.printar = printar_vetor;

    /*
     * se o vetor for do tipo float, 
     */ 
    if(tipo == 'f')
    {
        for(int i = 0; i < vetor_instancia.tamanho_membro; i++)
        {
            vetor_instancia.vetor_membro[i].float_num = *((float*) vetor_param + i);
        }
    }
    else if(tipo == 'i')
    {
        for(int i = 0; i < vetor_instancia.tamanho_membro; i++)
        {
            vetor_instancia.vetor_membro[i].int_num = *((int*) vetor_param + i);
        }
    }
    else
    {
        free(vetor_instancia.vetor_membro);
        return vetor_instancia;
    }
    
    return vetor_instancia;
}

int main()
{
    int vetor_int[] = {1, 2, 3};
    vetor v1 = criar_vetor(3, 'i', vetor_int);
    v1.printar(v1);
}