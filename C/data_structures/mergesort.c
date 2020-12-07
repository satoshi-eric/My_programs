#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mergesort(int *array, int begin, int end);
void merge(int *array, int begin, int mid, int end);
void print_array(int *array, int length);

int main(int argc, char **argv)
{
    // Criando uma array de inteiros
    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int length = (int) (sizeof(array)/sizeof(*array));
    print_array(array, length);
    mergesort(array, 0, length);
    print_array(array, length);
}

void mergesort(int *array, int begin, int end)
{
    if (end - begin > 1)
    {
        int mid = floor((begin + end)/2);
        mergesort(array, begin, mid);
        mergesort(array, mid, end);
        merge(array, begin, mid, end);

    }
}

void merge(int *array, int begin, int mid, int end)
{
    int left_array[mid-begin];
    int right_array[end-mid];

    for (int i=0; i<mid-begin; i++)
        left_array[i] = array[i];
    for (int i=0; i<end-mid; i++)
        right_array[i] = array[mid + i];

    printf("Left array: ");
    print_array(left_array, mid-begin);
    printf("Right array: ");
    print_array(right_array, end-mid);
    printf("\n");

    int left_top = 0;
    int right_top = 0;

    for (int i=begin; i<end; i++)
    {
        if (left_top >= mid-begin)
            array[i] = right_array[right_top++];
        else if (right_top >= end-mid)
            array[i] = left_array[left_top++];
        else if (left_array[left_top] <= right_array[right_top])
            array[i] = left_array[left_top++];
        else if (right_array[right_top] <= left_array[left_top])
            array[i] = right_array[right_top++];
    }
}

void print_array(int *array, int length)
{
    fprintf(stdout, "[");
    for (int i=0; i<length-1; i++)
        fprintf(stdout, "%d, ", array[i]);
    fprintf(stdout, "%d]\n", array[length-1]);
}