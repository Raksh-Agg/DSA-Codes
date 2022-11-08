#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

int MyQueue[1000];
int size = 0;
int MyFront = 0;

void isEmpty()
{
	if (size)
	printf("Queue is NOT empty\n");
	else
	printf("Queue is empty\n");
}
void giveSize()
{
	printf("Size of Queue is = %d\n", size);
}
void front()
{
	if (size)
	printf("Element at front of Queue is = %d\n", MyQueue[MyFront]);
	else
	printf("Queue is empty, no element at front\n");
}
void back()
{
	if (size)
	printf("Element at back of Queue is = %d\n", MyQueue[size-1]);
	else
	printf("Queue is empty, no element at back\n");

}
void pop()
{
	if (size)
	{
		printf("Value deleted from front is = %d\n", MyQueue[MyFront]);
		MyFront++;
	}
	else
	printf("Q is Empty, No element to be popped\n");
}
void push(int value)
{
	MyQueue[size] = value;
	size ++;
	printf("Element of value = %d is added in the Queue\n", value);
}
void display()
{
	if (size)
	{
		for(int i = MyFront ; i < size ; i ++)
		printf("%d ", MyQueue[i]);
		printf("\n");
	}
	else
	printf("Queue is Empty\n");
}
int main()
{
	FILE* CSVPointer = fopen("datainp.csv", "r");
	int value;
	int choice;
	printf("Please input integer for what you want to do in Queue\n");
	printf("1. To check if Queue is Empty\n");
	printf("2. To print Size of Queue\n");
	printf("3. To print element at Front of Queue\n");
	printf("4. To print element at Back of Queue\n");
	printf("5. To pop first element in Queue\n");
	printf("6. To push element in Queue\n");
	printf("7. To Display whole Queue\n");
	printf("8. To exit\n");
	do
	{
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			isEmpty();
			break;
		case 2:
			giveSize();
			break;
		case 3:
			front();
			break;
		case 4:
			back();
			break;
		case 5:
			pop();
			break;
		case 6:
			if(size != MAXSIZE)
			{
				fscanf(CSVPointer, "%d", &value);
				push(value);
			}
			else
			printf("You have filled the Queue to Max Size capacity, There are no more values in CSV File\n");
			break;
		case 7:
			display();
			break;
		case 8:
			break;
		default:
			printf("Please print an integer within given range\n");
		}
		
	} while (choice-8);
	printf("Thank You\n");
	return 0;
}
