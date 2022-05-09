#include <stdio.h>
#include <stdlib.h>


// [TASK]: Implementati stergerea intr-un arbore binar de cautare 


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


node* findMin(node* root)
{
    node* minim = (node*)malloc(sizeof(node));
    minim->key = 999999;

    while (root)
    {
        if (root->key < minim->key) minim = root;
        root = root->right;
    }

    return minim;
}


node* sterge(node* root, int v)
{
    if (root == NULL) return root;
    if (v < root->key) root->left = sterge(root->left, v);
    else if (v > root->key) root->right = sterge(root->right, v);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }

        else if (root->left == NULL)
        {
            node* tmp = root->right;
            root = root->right;
            free(tmp);
        }

        else if (root->right == NULL)
        {
            node* tmp = root;
            root = root->left;
            free(tmp);
        }

        else
        {
            node* succesor = findMin(root->right);
            root->key = succesor->key;
            root->right = sterge(root->right, succesor->key);
        }
    }

    return root;

}


void delete(tree* a, int v)
{
    sterge(a->root, v);
}


tree a;
int main() {

    int i = 0, x;
    while (i < 9) {
        scanf("%d", &x);
        i++;
        insert(&a, x);
    }
    delete(&a, 9);
    delete(&a, 5);
    delete(&a, 18);
    preorder(a);
    printf("\n");

}