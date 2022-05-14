#include <stdio.h>
#include <stdlib.h>


// [TASK]: Gasiti al k-lea cel mai mare nod dintr-un arbore binar de cautare.


typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;


typedef struct tree {
    node* root;
} tree;


node* getNode(int k)
{
    node* nod = (node*)malloc(sizeof(node));
    if (nod == NULL) printf("Memory excedeed");
    else
    {
        nod->data = k;
        nod->left = NULL;
        nod->right = NULL;

        return nod;
    }
}


void Insert(node** root, int k)
{
    node* nod = getNode(k);

    if ((*root) == NULL) (*root) = nod;

    else
    {
        if (k <= (*root)->data) Insert(&(*root)->left, k);
        else Insert(&(*root)->right, k);
    }
}


void insert(tree* a, int k)
{
    Insert(&(a->root), k);
}


int isFull(int k, int poz)
{
    return k == (poz - 1);
}


void largest(node* root, int k, node** arr, int poz)
{
    if (root != NULL)
    {
        if (isFull(k, poz) == 0)
        {
            arr[poz++] = root;
        }

        else
        {
            if ((arr[0]->data < arr[1]->data && arr[0]->data < arr[2]->data) && root->data > arr[0]->data) arr[0] = root;
            else if ((arr[1]->data < arr[0]->data && arr[1]->data < arr[2]->data) && root->data > arr[1]->data) arr[1] = root;
            else if ((arr[2]->data < arr[0]->data && arr[2]->data < arr[1]->data) && root->data > arr[2]->data) arr[2] = root;
        }

        largest(root->left, k, arr, poz);
        largest(root->right, k, arr, poz);
    }
}


node* find_largest_k(tree a, int k)
{
    node** arr = (node**)malloc(sizeof(node*) * k);
    if (arr == NULL) printf("Memory excedeed");
    else
    {
        largest(a.root->right, k, arr, 0);
        return arr[2];
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
    printf("%d\n", find_largest_k(a, 3)->data);


    printf("\n");

}