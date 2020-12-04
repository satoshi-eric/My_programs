#include <stdio.h>
#include <stdlib.h>
#include "array.h"

/**
 * Construtor de array de inteiros. Inicializa todos os elmentos com 0.
 * @param length Tamanho da array
 * @return Ponteiro para a array de inteiros	
 */ 
int *new_array(int length)
{
	int *ret_array = (int *) calloc(length, sizeof(int));
	return ret_array;
}

/**
 * Cria uma cópia da array.
 * @param array Array de inteiros a ser copiado
 * @param length Tamanho do array
 * @return Ponteiro para array copiado
 */ 
int *copy_array(int *array, int length)
{
	int *copied_array = new_array(length);
	for (int i=0; i<length; i++)
	{
		copied_array[i] = array[i];
	}
	return copied_array;
}

/**
 * Fatia a array entre begin e end.
 * @param array Ponteiro para array de inteiros
 * @param begin Índice do começo da fatia da array
 * @param length Quantidade de elementos a serem adicionados à array
 * @return Array fatiada de begin até end
 */ 
int *slice_array(int *array, int begin, int length)
{
    int *sliced_array = new_array(length);
    for (int i=0; i<length; i++)
    {
        sliced_array[i] = array[begin + i];
    }
    return sliced_array;
}

/**
 * Gera uma array de números inteiros aleatórios entre 0 e 10
 * @param length Tamanho da array de inteiros aleatórios
 * @return Ponteiro para array de inteiros aleatórios
 */ 
int *generate_random_array(int length)
{
	int *random_array = new_array(length);
	for (int i=0; i<length; i++)
		random_array[i] = rand()%length;
	return random_array;
}

/**
 * Printa array em um arquivo. Se o nome do arquivo for NULL, printa na saída padrão.
 * @param array Ponteiro para o array de inteiros
 * @param length Tamanho da array
 * @param filename Nome do arquivo
 */ 
void print_array(int *array, int length, char *filename)
{
	FILE *file;
	if (filename == NULL)
		file = stdout;
	else
		file = fopen(filename, "w");
	
	fprintf(file, "[");
	for (int i=0; i<length-1; i++)
	{
		fprintf(file, "%d, ", array[i]);
	}
	fprintf(file, "%d]\n", array[length-1]);
}

