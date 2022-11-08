#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BSTree.h"
#include "RBTree.h"
void executeBST();
int main()
{
    int choice_for_data_structure;
    printf("Enter choice for which data structure is to be followed\n");
    printf("1. Heap Array\n");
    printf("2. Heap Tree\n");
    printf("3. Binary Search Tree\n");
    printf("4. Binary Search Tree (Red-Black)\n");
    printf("5. Linked List\n");
    printf("6. Queue Linked List\n");
    printf("7. Stack Linked List\n");
    printf("8. Stack Array\n");
    printf("9. Queue Array\n");
    scanf("%d", &choice_for_data_structure);
    switch (choice_for_data_structure)
    {
	case 4:
    case 3:
        executeBST();
        break;
    }
}

void executeBST()
{
    clock_t mytime = clock();
    int choice;
	printf("Please input integer for what you want to do in Queue\n");
	printf("1. To insert all elements in Tree from a CSV File.\n");
	printf("2. To insert single element in Tree.\n");
	printf("3. To print Tree in Pre-Order way\n");
	printf("4. To print Tree in In-Order way\n");
	printf("5. To print Tree in Post-Order way\n");
	printf("6. To delete element from tree\n");
	printf("7. To exit\n");
	do
	{
		scanf ("%d", &choice);
		switch (choice)
		{
		case 1:
			insertFromFile();
			break;
		case 2:
			insertSingleElement();
			break;
		case 3:
			printPreOrder(root);
			printf("\n");

			break;
		case 4:
			printInOrder(root);
			printf("\n");

			break;
		case 5:
			printPostOrder(root);
			printf("\n");
			break;
		case 6:
			deleteNode();			
			break;
		case 7:
			printf("Thank You\n");
			break;
		default:
			printf("Please print integer within given range\n");
			break;
		}
		printf("Process took time = %ld microseconds\n", clock()-mytime);
	} while (choice - 7);
	return;
}
