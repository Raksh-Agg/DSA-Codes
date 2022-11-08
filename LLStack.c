#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

struct node
{
	struct node* prev;
	int val;
	struct node* next;
};

struct node* head = NULL;
int size = 0;

void isEmpty()
{
	if (size)
	printf("Stack is NOT empty\n");
	else
	printf("Stack is empty\n");
}
void giveSize()
{
	printf("Size of Stack is = %d\n", size);
}
void top()
{
	if (size)
	printf("Element at top of Stack is = %d\n", head->val);
	else
	printf("Stack is empty, No element at top\n");
}
void pop()
{
	if (head == NULL)
	printf("Stack is Empty, no element to delete\n");
	else
	{
		printf("Element = %d is popped from Stack\n", head->val);
		struct node* DataToFree = head;
		head = head->next;
		free(DataToFree);
	}
}

void push(int value)
{
	struct node* newnode = (struct node* )malloc(sizeof(struct node*)); 
	newnode->val = value;
	newnode->prev = &head;
	if (head == NULL)
	{
		newnode->next = NULL;
	}
	else
	{
		head->prev = newnode;
		newnode->next = head;
	}
	head = newnode;
	printf("Element = %d is pushed in Stack\n", head->val);
	size++;
}
void display()
{
	if(size)
	{
		struct node* pointer= head;
		while(pointer != NULL)
		{
			printf("%d ", pointer->val );
			pointer = pointer->next;
		}
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
			{	fscanf(CSVPointer, "%d", &value);
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