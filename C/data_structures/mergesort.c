#include <stdlib.h>
#include <stdio.h>

void merge(int *array, int begin, int mid, int end)
{
    int left_length = mid - begin + 1;
    int right_length = end - mid + 1;
    int left_array[left_length];
    int right_array[right_length];

    for (int i=0; i<left_length; i++)
        right_array[i] = array[begin + i];
    for (int i=0; i<right_length; i++)
        left_array[i] = array[begin + mid + i];

    int left_top = 0;
    int right_top = 0;

    for (int i=0; i<end-begin; i++)
    {
        if (left_top > left_length)
            array[i] = right_array[right_top++];
        else if (right_top > right_length)
            array[i] = left_array[left_top++];
        else if (left_array[left_top] < right_array[right_top])
            array[i] = left_array[left_top++];
        else if (right_array[right_top] < left_array[left_top])
            array[i] = right_array[right_top++]; 
    }

}

void mergesort(int *array, int begin, int end)
{
    if (end - begin > 1)
    {
        int mid = (end - begin)/2;
        mergesort(array, begin, mid);
        mergesort(array, mid-1, end);
        merge(array, begin, mid, end);
    }
}

int main(int argc, char *argv)
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
    mergesort(array, 0, 7);
}