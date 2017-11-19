#include <stdlib.h>
#include <time.h>

#include "random.h"

#define MY_RAND_MAX 100

void initializeRandom()
{
    srand(time(NULL));
}

int getRandomValue(int max_value)
{
    return rand() % max_value;
}

int *getRandomArray(unsigned int array_size)
{
    int *array=malloc(array_size * sizeof(int));
    for(unsigned int i=0; i<array_size; i++)
    {
        array[i]=getRandomValue(MY_RAND_MAX);
    }
    return array;
}