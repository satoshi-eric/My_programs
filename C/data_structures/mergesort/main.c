#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int array[], int begin, int mid, int end)
{
    int left_length = mid-begin;
    int right_length = end-mid;

    int left_array[left_length];
    int right_array[right_length];

    // Copiando o array original nos 2 novos arrays
    for (int i=0; i<left_length; i++)
        left_array[i] = array[begin + i];

    for (int i=0; i<right_length; i++)
        right_array[i] = array[left_length + i + 1];

    // Variáveis para vontrolar o topo das arrays
    int left_top = 0;
    int right_top = 0;

    for (int i=begin; i<end; i++)
    {
        // Verificando se uma das arrays já foi totalmente preenchida
        if (left_top >= left_length)
            array[i] = right_array[right_top++];
        else if (right_top >= right_length)
            array[i] = left_array[left_top++];
        else if (left_array[left_top] < right_array[right_top])
            array[i] = left_array[left_top++];
        else if (left_array[left_top] >= right_array[right_top])
            array[i] = right_array[right_top++];
    }
    
}

void mergesort(int array[], int begin, int end)
{
	if (end - begin > 1)
	{
		int mid = (begin + end)/2;
        mergesort(array, begin, mid);
        mergesort(array, mid, end);
        merge(array, begin, mid, end);
	}	
}    

int main(int argc, char *argv[])
{
    int length = 3;
    int array[] = {3, 2, 1};

    for (int i=0; i<length; i++)
        printf("%d ", array[i]);

    mergesort(array, 0, 9);
    printf("\n");


}