#include <stdio.h>
#include <stdlib.h>


// [TASK]: Convertiti un arbore binar in oglinda.


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


void insert(tree* a, int k)
{
    node* nod = getNode(k);

    if (a->root == NULL) a->root = nod;

    else
    {
        if (k <= a->root->key) insert(&(a->root->left), k);
        else insert(&(a->root->right), k);
    }
}


void Preorder(node* root)
{
    if (root != NULL)
    {
        printf("%i ", root->key);
        Preorder(root->left);
        Preorder(root->right);
    }
}


void preorder(tree a)
{
    Preorder(a.root);
}


void MirrorTree(node* root)
{
    if (root != NULL)
    {
        MirrorTree(root->left);
        MirrorTree(root->right);

        node* aux = root->left;
        root->left = root->right;
        root->right = aux;
    }
}


void mirror_tree(tree* a)
{
    MirrorTree(a->root);
}

tree a;
int main()
{

    int i = 0, x;
    while (i < 5) {
        scanf("%d", &x);
        i++;
        insert(&a, x);
    }
    mirror_tree(&a);
    preorder(a);
    printf("\n");

}