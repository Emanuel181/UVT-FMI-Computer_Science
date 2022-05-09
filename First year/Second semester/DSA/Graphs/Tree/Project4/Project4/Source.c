#include <stdio.h>
#include <stdlib.h>


// [TASK]: Implementati parcurgerile intr-un arbore binar de cautare.


typedef struct node {
    int key;
    struct node* left;
    struct node* right;
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

    return nod;
}

void Preorder(node* r)
{
    if (r == NULL) return;
    printf("%i ", r->key);
    Preorder(r->left);
    Preorder(r->right);
}


void preorder(tree a)
{
    Preorder(a.root);
}


void Inorder(node* r)
{
    if (r == NULL) return;
    Inorder(r->left);
    printf("%i ", r->key);
    Inorder(r->right);
}

void inorder(tree a)
{
    Inorder(a.root);
}


void Postorder(node* r)
{
    if (r == NULL) return;
    Postorder(r->left);
    Postorder(r->right);
    printf("%i ", r->key);
}

void postorder(tree a)
{
    Postorder(a.root);
}

void insert(tree* a, int k)
{
    node* nod = getNode(k);
    if (a->root == NULL)
    {
        a->root = nod;
    }

    else
    {
        if (k < a->root->key) insert(&(a->root->left), k);
        else insert(&(a->root->right), k);
    }
}


tree a;
int main() {

    int i = 0, x;
    while (i < 9) {
        scanf("%d", &x);
        i++;
        insert(&a, x);
    }
    preorder(a);
    printf("\n");
    inorder(a);
    printf("\n");
    postorder(a);
    printf("\n");
}