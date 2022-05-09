#include <stdio.h>
#include <stdlib.h>


// [TASK]: Verificati daca un arbore binar este un arbore binar de cautare.


typedef struct node
{
    int key;
    struct node* left;
    struct node* right;
} node;


typedef struct tree
{
    node* root;
} tree;


node* getNode(int k)
{
    node* nod = (node*)malloc(sizeof(node));
    nod->key = k;
    nod->left = NULL;
    nod->right = NULL;

    return nod;
}


void Insert(node* (*root), int k)
{
    node* nod = getNode(k);

    if ((*root) == NULL) (*root) = nod;

    else
    {
        if (k <= (*root)->key) Insert((&(*root)->left), k);
        else Insert((&(*root)->right), k);
    }
}


void insert(tree* a, int k)
{
    Insert(&(a->root), k);
}


void Check(node* root)
{

    if (root != NULL)
    {
        Check(root->left);
        Check(root->right);

        if (root->left != NULL)
        {
            if (root->key < root->left->key)
            {
                printf("NU");
            }
        }

        else if (root->right != NULL)
        {
            if (root->key > root->right->key)
            {
                printf("NU");

            }
        }
    }
}


void check_tree(tree a) {
    Check(a.root);
}

void swap(node* a, node* b)
{
    node c = *a;
    *a = *b;
    *b = c;
}


tree a;
int main() {

    int i = 0, x;
    while (i < 6) {
        scanf("%d", &x);
        i++;
        insert(&a, x);
    }
    swap(a.root->left, a.root->right);
    check_tree(a);
    printf("\n");

}