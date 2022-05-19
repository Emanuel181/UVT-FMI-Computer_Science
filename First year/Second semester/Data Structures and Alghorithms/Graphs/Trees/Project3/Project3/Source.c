#include <stdio.h>
#include <stdlib.h>


// [TASK]: Implementati cautarea intr-un arbore binar de cautare.


typedef struct node {
    int key;
    struct node* left;
    struct node* right;
    struct node* p;
}node;


typedef struct tree {
    node* root;
}tree;


node* getNode(int k)
{
    node* nod = (node*)malloc(sizeof(node));
    nod->key = k;
    nod->left = NULL;
    nod->right = NULL;
    nod->p = NULL;

    return nod;
}


void insert(tree* a, int k)
{
    node* nod = getNode(k);

    node* y = NULL;
    node* x = a->root;

    while (x)
    {
        y = x;
        if (nod->key < x->key) x = x->left;
        else x = x->right;
    }
    nod->p = y;

    if (y == NULL) a->root = nod;
    else if (nod->key < y->key) y->left = nod;
    else y->right = nod;
}


node* search_val(node* a, int val)
{
    if (a == NULL) return NULL;
    else if (a->key == val) return a;
    else if (val < a->key) return search_val(a->left, val);
    else return search_val(a->right, val);
}



node* search(tree a, int val)
{
    return search_val(a.root, val);
}


/*void printInorder(node* x)
{
    if (x)
    {
        printInorder(x->left);
        printf("%i ", x->key);
        printInorder(x->right);
    }
}*/


tree a;


tree a;
int main() {

    int i = 0, x;
    node* y;
    node* z;
    while (i < 7) {
        scanf("%d", &x);
        i++;
        insert(&a, x);
    }
    y = search(a, 18);
    if (y != NULL)
        printf("Node 18 exists\n");
    else
        printf("Node 18 should be in the Tree\n");

    z = search(a, 5);
    if (z == NULL)
        printf("Node 5 is not present in the Tree\n");
    else
        printf("Node 5 should not be in the Tree\n");
}