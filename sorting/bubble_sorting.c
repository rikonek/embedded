#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "random.h"
#include "function.h"

void bubbleSortArray(int *array, unsigned int array_size)
{
    bool repeat_sort=false;
    int n;
    do
    {
        repeat_sort=false;
        for(unsigned int i=0; i<(array_size-1); i++)
        {
            if(array[i]>array[i+1])
            {
                repeat_sort=true;
                n=array[i+1];
                array[i+1]=array[i];
                array[i]=n;
            }
        }
    }
    while(repeat_sort==true);
}

int main(int argc, char *argv[])
{
    if(argc==1)
    {
        printf("Usage:\n");
        printf("\t%s array_size\n", argv[0]);
        exit(0);
    }

    initializeRandom();

    int array_size=atoi(argv[1]);
    int *array=getRandomArray(array_size);

    printf("Unordered array:\n");
    displayArray(array, array_size);
    printf("\n");

    bubbleSortArray(array, array_size);

    printf("Ordered array:\n");
    displayArray(array, array_size);
    printf("\n");

    free(array);

    return 0;
}