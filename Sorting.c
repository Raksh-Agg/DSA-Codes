#include <stdio.h>
#include <time.h>
int arr[100];
int arrsize;
void swapVal (int index1, int index2);
void selectionSort();
void bubbleSort();
void insertionSort();
void countingSort();
void radixSort();
void bucketSort();
void shellSort();
int main()
{
    return 0;
}

selectionSort ()
{
    for(int i = 0 ; i < arrsize ; i++)
    {
        int minval = 10000;
        int minindex;
        for(int j = i ; j < arrsize ; j++)
        {
            if (minval > arr[j])
            {
                minval = arr[j];
                minindex = j
            }
        }
        swapVal(minindex, i);
    }
}
bubbleSort()
{
    for(int i = 0 ; i < arrsize ; i++)
    {
        for (int j = i ; i < arrsize-1 ; i++)
        {
            if (arr[j] > arr[j+1])
            swapVal(j,j+1);
        }
    }
}
insertionSort ()
{
FILE CSV_Pointer = fopen (
}

countingSort()
{
    int findmax = 0;
    for (int i = 0 ; i < arrsize ; i++)
    if (findmax < arr[i])
    findmax = arr[i];

    int indexarr[findmax+1] = {0};
    for (int i = 0 ; i < arrsize ; i++)
    indexarr[arr[i]]++;
    int finalarr[arrsize];
    for (int i = arrsize-1 ; i >= 0 ; i--)
    finalarr[indexarr[arr[i]]] = arr[i];
}
radixSort()
{
    int ten = 1;
    for (int i = 0 ; i < arrsize; i++)
    {

    }
}