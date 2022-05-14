#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


// [TASK]: Dandu-se un nod dintr-un arbore binar de cautare, gasiti predecesorul si succesorul lui.


int maxi = INT_MIN;
int mini = INT_MAX;

typedef struct node {
    int key;
    struct node* left;
    struct node* right;
} node;


typedef struct tree {
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


int Predecesor(node* root, int val)
{
    if (root != NULL)
    {
        if (root->key > maxi && root->key < val) maxi = root->key;
        Predecesor(root->left, val);
        Predecesor(root->right, val);
    }

    return maxi;
}


int predecessor(tree a, int val)
{
    return Predecesor(a.root, val);
}


Succesor(node* root, int val)
{
    if (root != NULL)
    {
        if (root->key < mini && root->key > val) mini = root->key;
        Succesor(root->right, val);
        Succesor(root->left, val);
    }

    return mini;
}


int successor(tree a, int val)
{
    return Succesor(a.root, val);
}

tree a;

int main() {

    int i = 0, x;
    while (i < 8) {
        scanf("%d", &x);
        i++;
        insert(&a, x);
    }
    printf("%d\n", predecessor(a, 6));
    printf("%d\n", successor(a, 4));
    printf("%d\n", successor(a, 3));
    printf("%d\n", predecessor(a, 8));

    printf("\n");

}