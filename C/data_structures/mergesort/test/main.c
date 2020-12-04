#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "mergesort.h"

int main(int argc, char **argv)
{
    int length = 8;
    int *array = generate_random_array(length);
    print_array(array, length, NULL);
    mergesort(array, 0, length);
    print_array(array, length, NULL);
}