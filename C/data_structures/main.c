#include <stdio.h>
#include <stdlib.h>


/**
 * Função para juntar os elementos durante o mergesort
 *
 * @param array array de inteiros que será juntado pelo mergesort 
 * @param inicio índice do início do array
 * @param meio índice do meio do array
 * @param fim índice do fim do array 
 *
 */ 
void merge( int array[], int inicio, int meio, int fim )
{v
	// Dividindo o array em 2
	
	int esq_tam = meio - inicio;
	int dir_tam = fim - meio;

	int esq_array[esq_tam]; // Inicializando array da esquerda
	int dir_array[dir_tam]; // Inicializando array da direita

	// Copiando elementos do array original para os 2 novos arrays
	// Copiando para o array da esquerda
	for ( int i=0; i<esq_tam; i++ )
		esq_array[i] = array[inicio + i]; //  Precisamos adicionar o início pois queremos um array do inicio ao meio
	// Copiando para o array da direita
	for ( int i=0; i<dir_tam; i++ )
		dir_array[i] = array[inicio + meio + i]; // Precisamos adicionar meio pois o inicio do array à direita começa do meio

	int esq_top = 0; // Índice do topo da array esquerda
	int dir_top = 0; // Índice do topo da array direita

	for ( int i=inicio; i<fim; i++ )
	{
		// Precisamos verificar se todos os lementos de cada uma das subarrays não possuir todos os valores menores que a outra array. Isso porque, ao incrementar o topo de uma das array até o final, não será mais possível fazer a comparação visto que não é possível acessar o elemento em um indice maior que o tamanho da array
		if ( esq_top >= esq_tam )
			array[i] = dir_array[dir_top++];
		if ( dir_top >= dir_tam )
			array[i] = esq_array[esq_top++];

		// Verificando o topo de cada uma das arrays.
		if ( esq_array[esq_top] < dir_array[dir_top] )

			// Colocando o topo da array direita no array original
			array[i] = esq_array[esq_top++]; // Precisamos incrementar esq_top para que ele vá para o próximo valor da array esquerda
			
		else 
			// Colocando o topo da array direita no array original
			array[i] = dir_array[dir_top++]; // Precisamos incrementar dir_top para que ele vá para o próximo valor da array direita

	}	
	

}

/**
 * Função de ordenação por mergesort
 *
 * @param array array de inteiros
 * @param inicio indice do inicio do array
 * @param fim indice do fim do array
 *
 */ 
void mergesort( int array[], int inicio, int fim )
{
	// Verificando se o número de elementos do array é maior que 1
	if ( fim - inicio > 1)
	{
		// definindo o indic do meio do array
		// Adivisão precisa ser inteira para o caso de ter um número de elementos ímpar. Ex: 9/2 = 4
		int meio = (fim + inicio)/2;

		// Agora, precisamos chamar recursivamente o mergesort para ele dividir o array em 2
		
		mergesort(array, inicio, meio); // Chamamos o mergesort para ele ordenar do inicio até o meio do array
		mergesort(array, meio, fim); // Chamamos o mergesort para ele ordenar do meio até o fim do array

		merge(array, inicio, meio, fim);

	}

}

int main(int argc, char **argv)
{
	int array[] = {5,3,65,12,43};
	mergesort(array, 0, 5);
	print_array(array, 5);
}
