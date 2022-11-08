#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

int MyStack[1000];
int size = 0;


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
void top()
{
	if (size)
	printf("Element at top of Stack is = %d\n", MyStack[1000-size]);
	else
	printf("Stack is empty, No element at top\n");
}
void pop()
{
	if (size)
	{
		size--;
		printf("Element = %d is popped from Stack\n",MyStack[999-size]);
	}
	else
	printf("Stack is Empty, No element to be popped\n");
}
void push(int value)
{
	MyStack[999-size] = value;
	printf("Element = %d is pushed in Stack\n", MyStack[999-size]);
	size ++;
}
void display()
{
	if (size)
	{
		for (int i = 1000-size ; i < 1000 ; i ++ )
		printf("%d ", MyStack[i]);
		printf("\n");
	}
	else
	printf("Stack is Empty\n");
}


int main()
{
	FILE* CSVPointer = fopen("datainp.csv", "r");
	int value;
	int choice;
	printf("Please input integer for what you want to do in Stack\n");
	printf("1. To check if Stack is Empty\n");
	printf("2. To print Size of Stack\n");
	printf("3. To print element at Top of Stack\n");
	printf("4. To pop first element in Stack\n");
	printf("5. To push element in Stack\n");
	printf("6. To display all of the Stack\n");
	printf("7. To exit\n");
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
			top();
			break;
		case 4:
			pop();
			break;
		case 5:
			if (size != MAXSIZE)
			{
				fscanf(CSVPointer, "%d", &value);
				push(value);
			}
			else
			printf("You have filled the Stack to Max Size capacity, There are no more values in CSV File\n");

			break;
		case 6:
			display();
			break;
		case 7:
			break;
		default:
			printf("Please print an integer within given range\n");
		}
		
	} while (choice-7);
	printf("Thank You\n");
	return 0;
}