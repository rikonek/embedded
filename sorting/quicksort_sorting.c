#include <stdio.h>
#include <stdlib.h>

#include "function.h"
#include "random.h"

void quickSortArray(int *array, unsigned int indexL, unsigned int indexR)
{
    if(indexL>=indexR) return;

    int pivot=array[(indexL+indexR)/2];
    int i=indexL;
    int j=indexR;
    int n;
    do
    {
        while(array[i]<pivot) i++;
        while(array[j]>pivot) j--;
        if(i<=j)
        {
            n=array[j];
            array[j]=array[i];
            array[i]=n;
            i++;
            j--;
        }
    }
    while(i<=j);
    if(j>indexL) quickSortArray(array,indexL,j);
    if(i<indexR) quickSortArray(array,i,indexR);
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

    quickSortArray(array, 0, array_size-1);

    printf("Ordered array:\n");
    displayArray(array, array_size);
    printf("\n");

    free(array);

    return 0;
}