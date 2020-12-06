#ifndef VETOR_H
#define VETOR_H

#include <stdio.h>
#include <stdlib.h>

struct vetor criar_vetor(int tamanho_param, char tipo_param, void *vetor_param);
void printar_vetor(struct vetor vet_param);
void redefinir_vetor(struct vetor *vetor_param, int novo_tamanho_param, char novo_tipo_param, void *novo_vetor_param);
void push(struct vetor *vet_param, union numero num);


union numero
{
    int int_num;
    float float_num;
}numero;

/* vetor */
struct vetor
{
    int tamanho_membro;
    char tipo_membro;
    union numero *vetor_membro;
    void (*printar_vetor)(struct vetor vet_param);
    void (*redefinir_vetor)(struct vetor *vetor_param, int novo_tamanho_param, char novo_tipo_param, void *novo_vetor_param);
    void (*push)(struct vetor *vet_param, union numero num);
};

/* cria um vetor 
 * - tamanho_param: tamanho do vetor
 * - tipo_param: o vetor pode ser de 2 tipos: float('f') ou int ('i')
 * - vetor_param: a função copia todos os valores desse vetor. 
*/ 
struct vetor criar_vetor(int tamanho_param, char tipo_param, void *vetor_param)
{
    struct vetor vetor_instancia;
    vetor_instancia.tamanho_membro = tamanho_param; /* atribuindo o tamanhp do vetor */
    vetor_instancia.vetor_membro = (union numero*)malloc(vetor_instancia.tamanho_membro * sizeof(numero)); /* alocando memória para o vetor */
    vetor_instancia.tipo_membro = tipo_param; /* atribuindo o tipo do vetor: int ou float */
    vetor_instancia.printar_vetor = printar_vetor; /* atribuindo a função printar_vetor */
    vetor_instancia.redefinir_vetor = redefinir_vetor; /* função para redefinir o vetor */
    vetor_instancia.push = push;

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
                printf("[%.2f, ", vet_param.vetor_membro[i].float_num);
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

/* 
 * A partir do vetor [vetor_param] redefine os membros do vetor
 * - vetor_param: vetor que será redefinido
 * - novo_tamanho_param: novo tamanho do vetor
 * - novo_tipo_param: caso tipo do vetor seja mudado
 * - novo_vetor_param: a função copia todos os valores desse vetor. O vetor precisa ser do tipo int ou float
 */
void redefinir_vetor(struct vetor *vetor_param, int novo_tamanho_param, char novo_tipo_param, void *novo_vetor_param)
{
    free(vetor_param->vetor_membro);
    vetor_param->tamanho_membro = novo_tamanho_param;
    vetor_param->vetor_membro = (union numero*)malloc(vetor_param->tamanho_membro*sizeof(numero));
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



/*
 * TODO:
 * conflito com a função redefinir_vetor
 * adicionar paâmetro nela para verificar se o vetor é do tipo float, int ou numero
 * função que adiciona novo elemento no ultimo valor do vetor
 * vet_param
 */ 
void push(struct vetor *vet_param, union numero num)
{
    int tamanho_vet = vet_param->tamanho_membro;
    struct vetor vetor_temp;
    redefinir_vetor(vet_param, vet_param->tamanho_membro+1, vet_param->tipo_membro, &vetor_temp.vetor_membro);

    if(vet_param->tipo_membro = 'f')
    {
        vet_param->vetor_membro[tamanho_vet].float_num = num.float_num;
    }
    else if(vet_param->tipo_membro = 'i')
    {
        vet_param->vetor_membro[tamanho_vet].int_num = num.int_num;
    }
    else
    {
        free(vet_param->vetor_membro);
    }
}

#endif