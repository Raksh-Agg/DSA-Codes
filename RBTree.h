struct node 
{
    int value;
    struct node* left;
    struct node* right;
    struct node* parent;
    char color;
};
struct node* root = NULL;
void addElement (int value)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->value = value;
    newnode->left = NULL;
    newnode->right = NULL;
    if (root == NULL)
    {
        root = newnode;
        newnode->color = 'B';
        newnode->parent = NULL;
    }
    else
    {
        newnode->color = 'R';
        struct node* next_pointer = root;
        struct node* pointer = root;
        while (next_pointer != NULL)
        {
            pointer = pointer;
            if (next_pointer->value > value) next_pointer = next_pointer->left;
            else next_pointer = next_pointer->right;
        }
        if (value > pointer->value) pointer->right = newnode;
        else pointer->left = newnode;
        
        newnode->parent = pointer;
        fixRedBlack(newnode);
    }
}

void fixRedBlack(struct node* newnode)
{
    struct node* node_parent = newnode->parent;
    if (node_parent == root) return; // So that, first 3 nodes are inserted with no rotation checking
    struct node* grand_parent = node_parent->parent;
    struct node* uncle ;
    if (grand_parent->left == node_parent) uncle = grand_parent->right;
    else uncle = grand_parent->left;
    if (node_parent->color == 'R')
    {
        if (uncle->color == 'R')
        {
            uncle->color == 'B';
            node_parent->color == 'B';
            grand_parent->color == 'R';
            fixRedBlack(grand_parent);
        }
    }


}