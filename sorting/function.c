#include <stdio.h>

#include "function.h"

void displayArray(int *array, unsigned int array_size)
{
    for(unsigned int i=0; i<array_size; i++)
    {
        printf("%d ", array[i]);
    }
}