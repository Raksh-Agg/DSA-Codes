#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#define MAX_SIZE 2000
int heap_array[2000] = {0};
int size = 0;
bool is_heap;
void swap(int index1, int index2)
{
    int swapval = heap_array[index1];
    heap_array[index1] = heap_array[index2];
    heap_array[index2] = swapval;
}
void createArrayFromFile ();
void addElementToArray();
void heapifyArray();
void pop();
void addElementToHeapArray();
void sortHeapArray ();
void printArray();
int main()
{
    clock_t time_var = clock();
    int choice ;
	printf("Please input integer for what you want to do in Heap Array\n");
	printf("1. To create Array from File\n");
	printf("2. To insert Element with value given by You\n");
	printf("3. To Heapify Array\n");
	printf("4. To Pop top element from Heap Array\n");
	printf("5. To Print Array\n");
	printf("6. To Print Array in Sorted form\n");
	printf("7. To Exit\n");

	do
	{
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
            createArrayFromFile();
			break;
		case 2:
            addElementToArray();
			break;
		case 3:
            heapifyArray();
			break;
		case 4:
            pop();
			break;
		case 5:
            printArray();
			break;
		case 6:
            sortHeapArray();
			break;
		case 7:
			printf("Thank You\n");
			break;
		default:
			printf("Please input value within given range\n");
			break;
		}
        printf("Time taken by Function is %ld microseconds\n", clock() - time_var);
	} while (choice - 7);
	return 0;
}

void createArrayFromFile ()
{
    char filename[500];
    printf("Enter name of CSV data file you want to open\n");
    scanf("%s", filename);
    FILE* CSVPointer = fopen(filename, "r");
	int value;
    is_heap = false;
    while (fscanf(CSVPointer, "%d", &value) != EOF)
    {
        if (size == MAX_SIZE)
        {
            printf("You have exceeded max size of array, you cannot insert anymore elements in heap now\n");
            return ;
        }
        else
        {
            size ++;
            heap_array[size] = value;
        }
    }
    printf("Array has been initialized\n");
}
void addElementToArray()
{
    printf("Please enter value you want to add to array\n");
    int val;
    scanf("%d", &val);
    size++;
    heap_array[size] = val;
    is_heap = false;
    printf("Element with value %d is now added to array\n", heap_array[size]);
}

void heapifyArray()
{
    if (is_heap)
    {
        printf("Array is already in heap form\n");
        return;
    }
    else
    {
        int iterator = size/2;
        if (size%2)
        {
            if (heap_array[iterator] < heap_array[iterator*2])
            swap(iterator, iterator*2);
            iterator--;
        }
        else
        {
            if (heap_array[2*iterator] > heap_array[2*iterator + 1])
            {
                if (heap_array[iterator] < heap_array[2*iterator])
                swap(iterator,2*iterator);
                iterator--;
            }
            else
            {
                if (heap_array[iterator] < heap_array[2*iterator+1])
                swap(iterator,2*iterator+1);
                iterator--;
            }
        }
        int valiter ;
        while (iterator)
        {
            if (iterator == size/2 && size%2 == 0)
            valiter = size;
            else
            valiter = 2*iterator + !(heap_array[2*iterator] > heap_array[2*iterator + 1]);
            while (heap_array[iterator] < heap_array[valiter])
            {
                swap(iterator, valiter);

                iterator = valiter;
                if (2*iterator > size)
                break;
                
                if (iterator == size/2 && size%2 == 0)
                valiter = size;
                else
                valiter = 2*iterator + !(heap_array[2*iterator] > heap_array[2*iterator + 1]);

                
            }
            iterator--;
        }
        is_heap = true;
        printf("Array is now heapified\n");
    }
    // one case left, for starting or end element
}
    

void pop()
{
    if (!is_heap)
    heapifyArray();
    if (!size)
    {
        printf("Array is empty, cannot pop\n");
        return;
    }
    printf("Max element in given heap is %d, is now deleted", heap_array[1]);
    heap_array[1] = heap_array[size];
    size--;
    int iterator  = 1;
    int valiter= 2*iterator + !(heap_array[2*iterator] > heap_array[2*iterator + 1]);
    do
    {
        if (heap_array[iterator] < heap_array[valiter])
        swap(iterator, valiter);
        else
        break;
        iterator = valiter;
        if (2*iterator + 1 > size)
        break;      
        valiter = 2*iterator + !(heap_array[2*iterator] > heap_array[2*iterator + 1]);          
    } while (heap_array[iterator] < heap_array[valiter]);
    
}
void printArray()
{
    for (int m = 0 ; m < size/10; m++)
    {    
        for (int i = 1 ; i <= 10 ; i ++)
        printf("%6d\t", heap_array[m*10 + i]);

        printf("\n");
    }
    for (int m = 10*(size/10) + 1 ; m <= size; m++ )
    printf("%6d\t", heap_array[m]);
    printf("\n");
}
void sortHeapArray ()
{
    if (!is_heap)
    heapifyArray();

    int size_to_print = size;
    while (size_to_print > 0)
    {   
        printf("%6d\t", heap_array[1]);
        swap(1,size_to_print);
        size_to_print--;
        if ((size - size_to_print)%10 == 0)
        printf("\n");
        int iterator  = 1;
        if (2*iterator> size_to_print)
        {
            printf("%6d\n", heap_array[1]);
            break;
        }
        int valiter;
        if (iterator == size_to_print/2 && size_to_print%2 == 0)
        valiter = size_to_print;
        else
        valiter = 2*iterator + !(heap_array[2*iterator] > heap_array[2*iterator + 1]);

        do
        {
            if (heap_array[iterator] < heap_array[valiter])
            swap(iterator, valiter);
            else
            break;
            iterator = valiter;
            if (2*iterator + 1 > size_to_print)
            break;      
            valiter = 2*iterator + !(heap_array[2*iterator] > heap_array[2*iterator + 1]);          
        } while (heap_array[iterator] < heap_array[valiter]);
    }


}
