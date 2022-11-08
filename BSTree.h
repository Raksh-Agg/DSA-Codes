struct node
{
	struct node* left;
	int val;
	struct node* right;
};
struct node* root = NULL;
void addElement (int value)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node*));
	struct node* pointer = root;
	newnode->right = NULL;
	newnode->left = NULL;
	newnode->val = value;
	int right_or_left = 2; // if only root is added, right_or_left is at 2
	if (root != NULL)
	{
		struct node* parent_pointer = pointer;
		while ( pointer != NULL)
		{
			parent_pointer = pointer;
			if (value > pointer -> val)
			pointer = pointer->right;
			else
			pointer = pointer->left;
		}
		if (value > parent_pointer->val)
		{
			parent_pointer->right = newnode;
			right_or_left = 1;
		}
		else
		{
			parent_pointer->left = newnode;
			right_or_left = 0;
		}
	}
	else
	{
		root = newnode;
	}

	//Begin AVL
	
}

void insertFromFile()
{
	
	FILE* CSVPointer;
	do
	{
		printf("Please input name of CSV File to take input from\n");
		char File_Name[100] ;
		scanf("%s", File_Name);
		CSVPointer = fopen(File_Name, "r");
		if(CSVPointer == NULL)
		printf("File doesn't exist, please enter valid File name, existing in current directory\n");
	}while (CSVPointer == NULL);
	int value;
	while (fscanf(CSVPointer, "%d", &value) != EOF)
		addElement(value);
	printf("All integers have been inserted in tree.\n");
}
void insertSingleElement ()
{
	printf("Please enter value to be inserted\n");
	int value ;
	scanf("%d", &value);
	addElement(value);

}
void toReplaceLeftOrRightChild (int right_or_left, struct node * parent_pointer, struct node * pointer_thing)
{
	if(right_or_left)
	parent_pointer->left = pointer_thing;
	else
	parent_pointer->right = pointer_thing;
}
void deleteNode()
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
		if (parent_pointer == pointer)
		{
			free(pointer);
			printf("Now the Tree is Empty\n");
			root = NULL;
		}
		else
		{
			toReplaceLeftOrRightChild(right_or_left, parent_pointer, NULL);
			free(pointer);
		}
	}
	else if (pointer ->left == NULL)
	{
		if (parent_pointer == pointer)
		{
			root = pointer->right;
			free(pointer);
		}
		else
		{
		
			toReplaceLeftOrRightChild(right_or_left, parent_pointer, pointer->right);

			pointer->right = NULL;
			free(pointer);
		}
	}
	else if (pointer -> right == NULL)
	{
		if (parent_pointer == pointer)
		{
			root = pointer->left;
			free(pointer);
		}
		else
		{
			toReplaceLeftOrRightChild(right_or_left, parent_pointer, pointer->left);

			pointer->left = NULL;
			free(pointer);
		}
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
		if (parent_pointer->right == pointer)
        {
			if (pointer->right == NULL)
			{
				parent_pointer->right = NULL;
				free(pointer);
			}
			else
			{
				parent_pointer->right = pointer->right;
				pointer->right = NULL;
				free(pointer);
			}
		}
		else
		{
			if (pointer->right == NULL)
			{
				parent_pointer->left = NULL;
				free(pointer);
			}
			else
			{
				parent_pointer->left = pointer->right;
				pointer->right = NULL;
				free(pointer);
			}

		}
	}

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