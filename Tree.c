#include <stdio.h>
#include <stdlib.h>
struct node
{
	struct node* left;
	int val;
	struct node* right;
};
struct node* root = NULL;
void insertAll()
{
	root = (struct node* )malloc(sizeof(struct node*));
	root -> left = NULL;
	root-> right = NULL;
	FILE* CSVPointer = fopen("datainp.csv", "r");
	int value;
	fscanf(CSVPointer, "%d", &value);
	root->val = value;
	while (fscanf(CSVPointer, "%d", &value) != EOF)
	{
		struct node* Pointer = root;
		struct node* NodePointer = Pointer;
		struct node* newnode = (struct node*)malloc(sizeof(struct node*));
		newnode->right = NULL;
		newnode->left = NULL;
		newnode->val = value;
		while ( Pointer != NULL)
		{
			NodePointer = Pointer;

			if (value > Pointer -> val)
			Pointer = Pointer->right;
			else
			Pointer = Pointer->left;
		}
		if (value > NodePointer->val)
		NodePointer->right = newnode;
		else
		NodePointer->left = newnode;
	}
	printf("All integers have been inserted in tree. Please do not attempt this operation again\n");


}
void deleteNode(struct node* pointer)
{
	printf("Please enter value of node to be deleted\n");
	int value;
	scanf("%d", &value);
	struct node* pointer = root;
	struct node* parent_pointer = root;
	int right_or_left;
	// Search for node
	while(pointer != NULL)
	{
		if (value == pointer->val)
		break;
		else if (value > pointer->val)
		{
			if (pointer -> right == NULL)
			{
				printf("Element not found\n");
				return;
			}
			parent_pointer = pointer;
			pointer = pointer->right;
			right_or_left = 0;
		}
		else
		{
			if (pointer -> left == NULL)
			{
				printf("Element not found\n");
				return;
			}
			parent_pointer = pointer;
			pointer = pointer->left;
			right_or_left = 1;
		}
	}
	if (pointer->left == NULL && pointer -> right == NULL)
	{
		if (right_or_left)
		parent_pointer->left = NULL;
		else
		parent_pointer->right = NULL;
		free(pointer);
	}
	else if (pointer ->left == NULL)
	{
		if(right_or_left)
		parent_pointer->left = pointer->right;
		else
		parent_pointer->right = pointer->right;

		pointer->right = NULL;
		free(pointer);
	}
	else if (pointer -> right == NULL)
	{
		if(right_or_left)
		parent_pointer->left = pointer->left;
		else
		parent_pointer->right = pointer->left;

		pointer->right = NULL;
		free(pointer);
	}
	else
	{
		struct node* to_delete = pointer;
		parent_pointer = pointer;
		pointer = pointer -> right;
		while (pointer->left != NULL)
		{
			parent_pointer = pointer;
			pointer = pointer ->left;
		}
		to_delete->val = pointer->val;
		deleteNode(pointer);
	}
	return;

}
void printPreOrder( struct node * sub_root)
{
	if (sub_root == NULL)
	{
		printf("Tree is empty, nothing to print\n");
		return;
	}
	printf("%5d\t", sub_root->val);
	struct node* pointer_for_left = sub_root;
	if (pointer_for_left->left != NULL)
	{
		pointer_for_left = pointer_for_left -> left;
		printPreOrder(pointer_for_left);
	}
	struct node* pointer_for_right = sub_root;
	if (pointer_for_right->right != NULL)
	{
		pointer_for_right = pointer_for_right -> right;
		printPreOrder(pointer_for_right);
	}
}
void printInOrder( struct node * sub_root)
{
	if (sub_root == NULL)
	{
		printf("Tree is empty, nothing to print\n");
		return;
	}
	struct node* pointer_for_left = sub_root;
	if (pointer_for_left->left != NULL)
	{
		pointer_for_left = pointer_for_left -> left;
		printInOrder(pointer_for_left);
	}
	printf("%5d\t", sub_root->val);

	struct node* pointer_for_right = sub_root;
	if (pointer_for_right->right != NULL)
	{
		pointer_for_right = pointer_for_right -> right;
		printInOrder(pointer_for_right);
	}
}
void printPostOrder(struct node * sub_root)
{
	if (sub_root == NULL)
	{
		printf("Tree is empty, nothing to print\n");
		return;
	}
	struct node* pointer_for_left = sub_root;
	if (pointer_for_left->left != NULL)
	{
		pointer_for_left = pointer_for_left -> left;
		printPostOrder(pointer_for_left);
	}
	struct node* pointer_for_right = sub_root;
	if (pointer_for_right->right != NULL)
	{
		pointer_for_right = pointer_for_right -> right;
		printPostOrder(pointer_for_right);
	}
	printf("%5d\t", sub_root->val);

}
int main ()
{
	int choice;
	printf("Please input integer for what you want to do in Queue\n");
	printf("1. To insert all elements in Tree.\n");
	printf("2. To print Tree in Pre-Order way\n");
	printf("3. To print Tree in In-Order way\n");
	printf("4. To print Tree in Post-Order way\n");
	printf("5. To exit\n");
	do
	{
		scanf ("%d", &choice);
		switch (choice)
		{
		case 1:
			insertAll();

			break;
		case 2:
			printPreOrder(root);
			break;
		case 3:
			printInOrder(root);
			break;
		case 4:
			printPostOrder(root);
			break;
		case 5:
			printf("Thank You\n");
			break;
		default:
			printf("Please print integer within given range\n");
			break;
		}
		printf("\n");
	} while (choice - 5);
	
	return 0;
}
