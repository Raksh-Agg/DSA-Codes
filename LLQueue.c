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
struct node* tail = NULL;
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
void front()
{
	if (size)
	printf("Element at front of Queue is = %d\n", head->val);
	else
	printf("Queue is empty, no element at front\n");
}
void back()
{
	if(size)
	printf("Element at back of Queue is = %d\n", tail->val);
	else
	printf("Queue is empty, no element at back\n");
}
void pop()
{
	if (head == NULL)
	printf("Queue is Empty, no element to delete\n");
	else
	{
		printf("Value deleted is = %d\n", head->val);
		struct node* DataToFree = head;
		head = head->next;
		free(DataToFree);
		size--;
	}
	
}
void push(int value)
{
	struct node* newnode = (struct node* )malloc(sizeof(struct node*)); 
	newnode -> next = NULL;
	newnode-> val = value;
	size++;
	if (head == NULL)
	{
		head = newnode;
		newnode->prev = &head;
		tail = newnode;
	}
	else
	{
		tail->next = newnode;
		newnode ->prev = tail;
		tail = newnode;
	}
	printf("Element of value = %d is added in the Queue\n", value);
}
void display()
{
	if(size)
	{
		struct node* pointer= head;
		while (pointer != NULL)
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
			if (size != MAXSIZE)
			{	fscanf(CSVPointer, "%d", &value);
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
