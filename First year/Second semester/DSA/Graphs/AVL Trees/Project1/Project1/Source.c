#include <stdio.h>
#include <stdlib.h>


/*
    [TASK]:
    Implementati doua functii, una pentru LL Rotation si una pentru RR Rotation. 
    Fiecare functie primeste ca si parametru nodul X, efectuand rotirea nodurilor corespunzatoare fiecarei rotatii.
*/


typedef struct node
{
    int key;
    struct node* left;
    struct node* right;

}node;


typedef struct tree
{
    node* root;

} tree;


node* getNode(int val)
{
    node* nod = malloc(sizeof(node));
    nod->key = val;
    nod->left = NULL;
    nod->right = NULL;

    return nod;
}

void Insert(node** root, int k)
{
    if ((*root) == NULL) (*root) = getNode(k);
    else
    {
        if (k < (*root)->key) Insert(&(*root)->left, k);
        else Insert(&(*root)->right, k);
    }
}


void insert(tree* a, int k)
{
    Insert(&(a->root), k);
}


node* findParent(node* root, node* n)
{
    if (n->key > root->key)
    {
        if (root->right && root->right->key == n->key) return root;
        else findParent(root->right, n);
    }
    else
    {
        if (root->left && root->left->key == n->key) return root;
        else findParent(root->left, n);
    }
}


void rr_rotation(tree* a, node* n)
{
    node* parinte = NULL;
    parinte = findParent(a->root, n);

    if (parinte != NULL)
    {
        node* copilSt = n->left;

        if (parinte->left == n) parinte->left = copilSt;
        else parinte->right = copilSt;

        if (copilSt->right)
        {
            node* right_sub = copilSt->right;
            right_sub->right = n;
            n->left = right_sub;
        }
        else copilSt->right = n;
    }
}


void ll_rotation(tree* a, node* n)
{

    node* parinte = findParent(a->root, n);
    if (parinte == NULL)
    {
        printf("Eroare");
        exit(1);
    }

    if (parinte->left == n) parinte->left = n->right;
    else parinte->right = n->right;

    node* copilDr = n->right;
    if (copilDr->left)
    {
        node* left_sub = copilDr->left;
        copilDr->left = n;
        n->right = left_sub;
    }
    else copilDr->left = n;
}


int main()
{
    tree a;
    a.root = NULL;
    int i = 0, x;
    while (i < 5) {
        scanf("%d", &x);
        i++;
        insert(&a, x);
    }
    insert(&a, 7);
    rr_rotation(&a, a.root->right);
    if (a.root->right->key != 8)
        printf("Nodul cu cheia 8 trebuie sa fie in dreapta radacinii.");
    if (a.root->right->right->key != 9)
        printf("Nodul cu cheia 9 trebuie sa fie in dreapta lui 8.");
    if (a.root->right->left->key != 7)
        printf("Nodul cu cheia 7 trebuie sa fie in stanga lui 8");

    insert(&a, 10);
    insert(&a, 12);
    ll_rotation(&a, a.root->right->right);

    if (a.root->right->right->key != 10)
        printf("Nodul cu cheia 10 trebuie sa fie in dreapta lui 8.");
    if (a.root->right->right->right->key != 12)
        printf("Nodul cu cheia 12 trebuie sa fie in dreapta lui 10.");
    if (a.root->right->right->left->key != 9)
        printf("Nodul cu cheia 9 trebuie sa fie in stanga lui 10");


}
