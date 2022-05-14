#include <stdio.h>
#include <stdlib.h>


// [TASK]: Inserarea intr-un arbore binar de cautare a nodului, in asa fel incat sa se pastreze proprietatea de arbore binar.  


typedef struct node {
    int key;
    struct node* left;
    struct node* right;
    struct node* tati;
}node;

node* root;


typedef struct tree {
    node *root;
}tree;


node* getNode(int k)
{
    node* nod = (node*)malloc(sizeof(node));
    nod->key = k;
    nod->left = NULL;
    nod->right = NULL;
    nod->tati = NULL;

    return nod;
}


void insert(tree* a, int k)
{
    node* y = NULL;
    node* x = a;

    while (x)
    {
        y = x;
        if (k < x->key) x = x->left;
        else x = x->right;
    }

    node* z = getNode(k);
    z->tati = y;

    if (y == NULL) a->root = z;
    else if (z->key < y->key) y->left = z;
    else y->right = z;

}


tree a;

int main() {

    int i = 0, x;
    while (i < 5)
    {
        scanf("%d", &x);
        i++;
        insert(&a, x);
    }
}