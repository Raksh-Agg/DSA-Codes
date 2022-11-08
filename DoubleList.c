#include <stdio.h>
#include <stdlib.h>
#include <time.h>
clock_t microtime;
struct node
{
	struct node* next;
	int val;
	struct node * prev;
};
struct node* head = NULL;
void insertAll ()
{
	microtime = clock();
	FILE* CSVPointer;
	do
	{
		printf("Please input name of CSV File to take input from\n");
		char File_Name[33000] ;
		scanf("%s", File_Name);
		CSVPointer = fopen(File_Name, "r");
		if(CSVPointer == NULL)
		printf("File doesn't exist, please enter valid File name, existing in current directory\n");
	}while (CSVPointer == NULL);


	int value;
	fscanf(CSVPointer, "%d", &value);
	struct node* first = (struct node*)malloc(sizeof(struct node*));
	first ->val = value;
	first -> prev = &head;
	head = first;
	first->next = NULL;

	while (fscanf(CSVPointer, "%d", &value) != EOF)
	{
		struct node* pointer = head;
		struct node* prev_pointer = head;
		struct node* newnode = (struct node*)malloc(sizeof(struct node*));
		newnode->val = value;
		while(pointer!= NULL)	
		{
			if(value > pointer ->val)
			{
				prev_pointer = pointer;
				pointer = pointer->next;
			}
			else
			break;
		}
		
		if (pointer == NULL)
		{
			newnode->next = pointer;
			newnode -> prev = prev_pointer;
			prev_pointer->next = newnode;
		}
		else if (pointer == head)
		{	
			newnode->next = pointer;
			newnode ->prev = &head;
			pointer -> prev = newnode;
			head = newnode;
		}
		else
		{
			newnode->next = pointer;
			pointer->prev = newnode;
			newnode -> prev = prev_pointer;
			prev_pointer->next = newnode;
		}
	}
	printf("Sorted List is initialized, please do not choose this option oce again.\n");
	microtime = clock() - microtime; 
	printf("Time taken by Function = %ld microseconds\n", microtime);
}
void insertFromUser ()
{
	microtime = clock();
	printf ("Please input integer to insert\n");
	int value;
	scanf("%d", &value);
	struct node * newnode = (struct node*)malloc(sizeof(struct node*));
	newnode -> val = value;
	if (head == NULL)
	{
		head = newnode;
		newnode->next = NULL;
		newnode ->prev = &head;
	}
	else
	{
		struct node* pointer = head;
		struct node* prev_pointer = head;
		while(pointer!= NULL)	
		{
			if(value > pointer ->val)
			{
				prev_pointer = pointer;
				pointer = pointer->next;
			}
			else
			break;
		}
		if (pointer == NULL)
		{
			newnode->next = pointer;
			newnode -> prev = prev_pointer;
			prev_pointer->next = newnode;
		}
		else if (pointer == head)
		{	
			newnode->next = pointer;
			newnode ->prev = &head;
			head->prev = newnode;
			head = newnode;
		}
		else
		{
			newnode->next = pointer;
			newnode->prev = prev_pointer;
			pointer->prev = newnode;
			prev_pointer->next = newnode;
		}

	}
	printf("Element with value = %d has been added to the sorted list\n", value);
	microtime = clock() - microtime; 
	printf("Time taken by Function = %ld microseconds\n", microtime);
}

void delete()
{
	microtime = clock();
	if (head == NULL)
	{
		printf("List is empty, no element to delete\n");
	}
	else
	{
		int value ;
		printf("Please enter integer to be deleted\n");
		scanf("%d", &value);

		struct node* pointer = head;
		struct node* prev_pointer = pointer;
		while(pointer!= NULL)	
		{
			if(value > pointer ->val)
			{
				prev_pointer = pointer;
				pointer = pointer->next;
			}
			else
			break;
		}

		if (value == pointer->val)
		{
			prev_pointer ->next = pointer->next;
			pointer->next = NULL;
			pointer ->prev = NULL;
			free(pointer);
			printf("Element containing value of %d is now deleted\n", value);
		}
		else
		{
			printf("Element = %d NOT found in list, hence cannot be removed\n", value);
		}
	}
	microtime = clock() - microtime; 
	printf("Time taken by Function = %ld microseconds\n", microtime);
}
void printAll()
{
	microtime = clock();
	struct node* pointer = head;
	while (pointer != NULL)
	{
		for (int i = 0 ; i < 5 ; i++)
		{
			if (pointer != NULL)
			{
				printf("%5d\t", pointer->val);
				pointer = pointer -> next;
			}
			else
			break;
		}
		printf("\n");
	}
	printf("\n");
	microtime = clock() - microtime; 
	printf("Time taken by Function = %ld microseconds\n", microtime);
}
void printDecreasingFromNumber()
{
	microtime = clock();
	printf("Please enter number from which list has to be printed\n");
	int value;
	scanf("%d", &value);
	struct node*  pointer = head;
	while (pointer != NULL)
	{
		if (value > pointer ->val)
		pointer = pointer->next;
		else
		break;
	}
	if (pointer == NULL)
	printf("Given value could not be found in List\n");
	else if (value == pointer->val)
	{
		while (pointer != &head)
		{
			for (int i = 0 ; i < 5 ; i++)
			{
				if (pointer != &head)
				{
					printf("%5d\t", pointer->val);
					pointer = pointer -> prev;
				}
				else
				break;
			}
			printf("\n");
		}
		printf("\n");
	}
	else
	printf("Given value could not be found in List\n");
	microtime = clock() - microtime;
	printf("Time taken by Function = %ld microseconds\n", microtime);
}

int main()
{
	int choice ;
	printf("Please input integer for what you want to do in Queue\n");
	printf("1. To initialize list\n");
	printf("2. To insert Element with value given by You\n");
	printf("3. To Delete element with value you input\n");
	printf("4. To Print the whole sorted list\n");
	printf("5. To Print the whole list in decreasing order from element given by you\n");
	printf("6. To Exit\n");

	do
	{
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			insertAll();
			break;
		case 2:
			insertFromUser();
			break;
		case 3:
			delete();
			break;
		case 4:
			printAll();
			break;
		case 5:
			printDecreasingFromNumber();
			break;
		case 6:
			printf("Thank You\n");
			break;
		default:
			printf("Please input value within given range\n");
			break;
		}
	} while (choice - 6);
	return 0;
}
