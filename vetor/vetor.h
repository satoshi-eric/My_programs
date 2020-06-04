#ifndef VETOR_H
#define VETOR_H

#include <stdio.h>
#include <stdlib.h>

typedef union numero
{
    int int_num;
    float float_num;
}numero;

/* vetor */
struct vetor
{
    int tamanho_membro;
    char tipo_membro;
    numero *vetor_membro;
    void (*printar)(struct vetor vet_param);
    void (*redefinir_vetor)(struct vetor *vetor_param, int novo_tamanho_param, char novo_tipo_param, void *novo_vetor_param);
};

/* função para printar o vetor */
void printar_vetor(struct vetor vet_param)
{
    /* printa o vetor de int */
    if(vet_param.tipo_membro == 'i')
    {
        for(int i = 0; i< vet_param.tamanho_membro; i++)
        {
            if(i == 0)
            {
                printf("[%i, ", vet_param.vetor_membro[i].int_num);
            }
            else if(i == vet_param.tamanho_membro-1)
            {
                printf("%i]\n", vet_param.vetor_membro[i].int_num);
            }
            else
            {
                printf("%i, ", vet_param.vetor_membro[i].int_num);
            }
        }
    }     
    /* printa o vetor de float */
    else if(vet_param.tipo_membro == 'f')
    {
        for(int i = 0; i< vet_param.tamanho_membro; i++)
        {
            if(i == 0)
            {
                printf("[%f, ", vet_param.vetor_membro[i].float_num);
            }
            else if(i == vet_param.tamanho_membro-1)
            {
                printf("%f]\n", vet_param.vetor_membro[i].float_num);
            }
            else
            {
                printf("%f, ", vet_param.vetor_membro[i].float_num);
            }
        }
    } 
}

/* A partir de um vetor já criado pela função  */
void redefinir_vetor(struct vetor *vetor_param, int novo_tamanho_param, char novo_tipo_param, void *novo_vetor_param)
{
    free(vetor_param->vetor_membro);
    vetor_param->tamanho_membro = novo_tamanho_param;
    vetor_param->vetor_membro = (numero*)malloc(vetor_param->tamanho_membro*sizeof(numero));
    vetor_param->tipo_membro = novo_tipo_param;

    if(novo_tipo_param == 'f')
    {
        /* atribuindo os valores float ao vetor */
        for(int i = 0; i < vetor_param->tamanho_membro; i++)
        {
            vetor_param->vetor_membro[i].float_num = *((float*) novo_vetor_param + i);
        }
    }
    /* se o vetor for do tipo int */
    else if(novo_tipo_param == 'i')
    {
        /* atribuindo valores int ao vetor */
        for(int i = 0; i < vetor_param->tamanho_membro; i++)
        {
            vetor_param->vetor_membro[i].int_num = *((int*) novo_vetor_param + i);
        }
    }
    /* a memória alocada para o vetor é liberada */
    else
    {
        free(vetor_param->vetor_membro);
    }
}

/* cria um vetor de tamanho [tamanho_param]  de tipo [tipo] podendo ser int('i') ou float('f') atribuindo os valores do vetor [vetor_param] à esse vetor */ 
struct vetor criar_vetor(int tamanho_param, char tipo_param, void *vetor_param)
{
    struct vetor vetor_instancia;
    vetor_instancia.tamanho_membro = tamanho_param; /* atribuindo o tamanhp do vetor */
    vetor_instancia.vetor_membro = (numero*)malloc(vetor_instancia.tamanho_membro * sizeof(numero)); /* alocando memória para o vetor */
    vetor_instancia.tipo_membro = tipo_param; /* atribuindo o tipo do vetor: int ou float */
    vetor_instancia.printar = printar_vetor; /* atribuindo a função printar_vetor */
    vetor_instancia.redefinir_vetor = redefinir_vetor; /* função para redefinir o vetor */

    /* se o vetor for do tipo float */ 
    if(tipo_param == 'f')
    {
        /* atribuindo os valores float ao vetor */
        for(int i = 0; i < vetor_instancia.tamanho_membro; i++)
        {
            vetor_instancia.vetor_membro[i].float_num = *((float*) vetor_param + i);
        }
    }
    /* se o vetor for do tipo int */
    else if(tipo_param == 'i')
    {
        /* atribuindo valores int ao vetor */
        for(int i = 0; i < vetor_instancia.tamanho_membro; i++)
        {
            vetor_instancia.vetor_membro[i].int_num = *((int*) vetor_param + i);
        }
    }
    /* a memória alocada para o vetor é liberada */
    else
    {
        free(vetor_instancia.vetor_membro);
        return vetor_instancia;
    }
    
    return vetor_instancia;
}

#endif