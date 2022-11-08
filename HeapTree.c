#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct node 
{
    struct node* left;
    int val;
    struct node* right;
    struct node* parent;
};
struct node* root = NULL;
struct node* newnode = NULL;
struct node* end_ptr = NULL;
int size = 0;

void swap(struct node* x, struct node* y)
{
    int swapval = x->val;
    x->val = y->val;
    y->val = swapval;
}
void SwapTillHeap(struct node* pointer)
{
    if (pointer->parent == NULL)
    return;
    else
    {
        if (pointer->val > pointer->parent->val)
        {
            swap(pointer, pointer->parent);
            SwapTillHeap(pointer->parent);
        }
        else
        return;
    }
}

void AddEleInHeap(int value)
{
    if (size)
    {   
        newnode = (struct node* )malloc(sizeof(struct node));
        newnode->val = value;
        newnode->right = NULL;
        newnode->left = NULL;
        struct node* pointer = root;
        int leftind = 1, rightind = 1;
        size++;
        int level = 1;
        while (!(size >= leftind && size <= rightind))
        {
            leftind = 2*leftind;
            rightind = 2*rightind+1;
            level++;
        }
        level = level -2;
        for (int i = 0 ; i < level ; i ++)
        {    
            int mid = leftind + rightind;
            mid = mid/2;
            if (size <= mid)
            {
                pointer = pointer->left;
                rightind = mid;
            }
            else
            {
                pointer = pointer->right;
                leftind = mid+1;
            }
        }
        if (size%2)
        pointer->right = newnode;
        else
        pointer->left = newnode;

        newnode->parent = pointer;

        end_ptr = pointer;
        SwapTillHeap(newnode);
    }
    else
    {
        root = (struct node* )malloc(sizeof(struct node));
        root->val = value;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        size++;
        end_ptr = root;
    }
    

}

void CreateHeapFromFile()
{
    char filename[500];
    printf("Enter name of CSV data file you want to open\n");
    scanf("%s", filename);
    FILE* CSVPointer = fopen(filename, "r");
	int value;
    while (fscanf(CSVPointer, "%d", &value) != EOF)
    AddEleInHeap(value);
    printf("Heap has now been initialized from given CSV File\n");
}
void InsertInTree ()
{
    printf("Insert element to be aded in tree\n");
    int value ;
    scanf ("%d", &value);
    AddEleInHeap(value);
    printf("Element of value = %6d is now added\n", value);
}
void pop()
{
    if (size == 0)
    {
        printf("Heap is empty, no element to pop\n");
        return;
    }
    else if (size == 1)
    {
        printf("Element at top with value %6d is now deleted, and now, Heap is empty\n", root->val);
        free(root);
        root  = NULL;
        size--;
        return;
    }
    printf("Element at top with value %6d is now deleted\n", root->val);
    if (size%2)
    {
        swap(root, end_ptr->right);
        free(end_ptr->right);
        end_ptr->right = NULL;
    }
    else
    {
        root->val = end_ptr->left->val;
        free(end_ptr->left);
        end_ptr->left = NULL;
    }
    size--;
    
    int leftind = 1, rightind = 1;
    int level = 1;
    end_ptr = root;
    while (!(size >= leftind && size <= rightind))
    {
        leftind = 2*leftind;
        rightind = 2*rightind+1;
        level++;
    }
    level = level -2;
    for (int i = 0 ; i < level ; i ++)
    {    
        int mid = leftind + rightind;
        mid = mid/2;
        if (size <= mid)
        {
            end_ptr = end_ptr->left;
            rightind = mid;
        }
        else
        {
            end_ptr = end_ptr->right;
            leftind = mid+1;
        }
    }
    

    struct node* pointer = root;
    struct node* pointer_to_child = root;
    while(1)
    {    
        if (pointer->left == NULL)
        break;
        else if (pointer->right == NULL)
        {
            pointer_to_child = pointer->left;
            if (pointer->val < pointer_to_child->val)
            swap(pointer,pointer_to_child);
            else
            break;
        }
        else
        {
            if (pointer->left->val > pointer->right->val)
            pointer_to_child = pointer->left;
            else
            pointer_to_child = pointer->right;

            if (pointer->val < pointer_to_child->val)
            swap(pointer,pointer_to_child);
            else
            break;
        }
        pointer = pointer_to_child;
    }
}
void printDecreasingOrder()
{
    while (1)
    {    
        if (size == 0)
        {
            printf("\nHeap is now empty\n");
            return;
        }
        else if (size == 1)
        {
            printf("%6d\t", root->val);
            free(root);
            root  = NULL;
            size--;
            continue;
        }
        printf("%6d\t", root->val);
        if (size%2)
        {
            swap(root, end_ptr->right);
            free(end_ptr->right);
            end_ptr->right = NULL;
        }
        else
        {
            root->val = end_ptr->left->val;
            free(end_ptr->left);
            end_ptr->left = NULL;
        }
        size--;
        
        int leftind = 1, rightind = 1;
        int level = 1;
        end_ptr = root;
        while (!(size >= leftind && size <= rightind))
        {
            leftind = 2*leftind;
            rightind = 2*rightind+1;
            level++;
        }
        level = level -2;
        for (int i = 0 ; i < level ; i ++)
        {    
            int mid = leftind + rightind;
            mid = mid/2;
            if (size <= mid)
            {
                end_ptr = end_ptr->left;
                rightind = mid;
            }
            else
            {
                end_ptr = end_ptr->right;
                leftind = mid+1;
            }
        }
        

        struct node* pointer = root;
        struct node* pointer_to_child = root;
        while(1)
        {    
            if (pointer->left == NULL)
            break;
            else if (pointer->right == NULL)
            {
                pointer_to_child = pointer->left;
                if (pointer->val < pointer_to_child->val)
                swap(pointer,pointer_to_child);
                else
                break;
            }
            else
            {
                if (pointer->left->val > pointer->right->val)
                pointer_to_child = pointer->left;
                else
                pointer_to_child = pointer->right;

                if (pointer->val < pointer_to_child->val)
                swap(pointer,pointer_to_child);
                else
                break;
            }
            pointer = pointer_to_child;
        }
    }
    printf("\n");

}
int main()
{
    clock_t time_var = clock();
    int choice ;

	do
	{
        printf("\t\t\t\t\t\t\t\t\tPlease input integer for what you want to do in Heap Tree\n");
        printf("\t\t\t\t\t\t\t\t\t1. To create Heap Tree from File\n");
        printf("\t\t\t\t\t\t\t\t\t2. To insert Element with value given by You\n");
        printf("\t\t\t\t\t\t\t\t\t3. To Pop top element from Heap Tree\n");
        printf("\t\t\t\t\t\t\t\t\t4. To Print Heap Tree in Sorted form\n");
        printf("\t\t\t\t\t\t\t\t\t5. To Exit\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
            CreateHeapFromFile();
			break;
		case 2:
            InsertInTree();
			break;
		case 3:
            pop();
			break;
		case 4:
            printDecreasingOrder();
			break;
		case 5:
			printf("Thank You\n");
			break;
		default:
			printf("Please input value within given range\n");
			break;
		}
        printf("\t\t\t\t\t\t\t\t\tTime taken by Function is %7ld microseconds\n\n\n", clock() - time_var);
	} while (choice - 5);
	return 0;
}
