#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"
#include "array.h"

/**
 * Ordenação do array por mergesort
 * @param array Ponteiro para o array de inteiros
 * @param begin Índice do começo do array
 * @param end Índice do final do array
 */ 
void mergesort(int *array, int begin, int end)
{
    // Verifica se o tamanho do array é maior que 1
    if (end - begin > 1)
    {
        // Definindo o meio do array
        int middle = (begin + end)/2;

        mergesort(array, begin, middle);
        mergesort(array, middle, end);

        merge(array, begin, middle, end);
    }
}

/**
 * Junção das array do mergesort
 * @param array ponteiro para array de inteiros a ser separado
 * @param begin Índice do começo do array
 * @param middle Índice do meio do array
 * @param end Índice do final do array
 */ 
void merge(int *array, int begin, int middle, int end)
{
    // Definindo os tamanho dos 2 arrays
    int left_length = middle - begin + 1;
    int right_length = end -middle;

    // Fatiando a array pela metade
    int *left_array = slice_array(array, begin, middle-begin);
    int *right_array = slice_array(array, middle, end-middle);

    // variáveis para os topos de cada uma das arrays
    int left_top = 0;
    int right_top = 0;

    for (int i=begin; i<end; i++)
    {
        // Verificando se os arrays já foram totalmente percorridos
        if (left_top >= left_length)
        {
            array[i] = right_array[right_top];
            right_top++;
        }

        if (right_top >= right_length)
        {
            array[i] = left_array[left_top];
            left_top++;
        }

        // Verificando o maior topo de cada uma das matrizes
        if (left_array[left_top] < right_array[right_top])
        {
            array[i] = left_array[left_top];
            left_top++;
        }
        else
        {
            array[i] = right_array[right_top];
            right_top++;
        }
        
    }
}