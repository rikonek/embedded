#include <stdio.h>
#include <stdlib.h>

#include "function.h"
#include "random.h"

void shellSortArray(int *array, unsigned int array_size)
{
    unsigned int pivot,i,j;
    int n;
    for(pivot=array_size/2; pivot>0; pivot=pivot/2)
    {
        for(i=pivot; i<array_size; i++)
        {
            for(j=i; j>=pivot && array[j-pivot]>array[j]; j=j-pivot)
            {
                n=array[j-pivot];
                array[j-pivot]=array[j];
                array[j]=n;
            }
        }
    }
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

    shellSortArray(array, array_size);

    printf("Ordered array:\n");
    displayArray(array, array_size);
    printf("\n");

    free(array);

    return 0;
}