#include <stdio.h>
#include <stdlib.h>


/* 
    [TASK]: Implementati doua functii, una pentru LR Rotation si una pentru RL Rotation. 
    Fiecare functie primeste ca si parametru nodul X, efectuand rotirea nodurilor corespunzatoare 
    fiecarei rotatii. Utilizati functiile LL Rotation si RR Rotation definite la problema anterioara. 
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

    node* p = findParent(a->root, n);
    node* promo = n->left;
    if (p != NULL)
    {
        if (p->left == n)
        {
            p->left = promo;
        }
        else {
            p->right = promo;
        }
    }
    else {
        a->root = promo;
    }

    node* sub_dr = promo->right;
    promo->right = n;
    n->left = sub_dr;
}


void ll_rotation(tree* a, node* n)
{
    node* p = findParent(a->root, n);
    node* promo = n->right;
    if (p != NULL) {
        if (p->right == n) {
            p->right = promo;
        }
        else {
            p->left = promo;
        }
    }
    else {
        a->root = promo;
    }

    node* sub_st = promo->left;
    promo->left = n;
    n->right = sub_st;
}


void right_left_rotation(tree* a, node* n)
{
    rr_rotation(a, n->right);
    ll_rotation(a, n);
}


void left_right_rotation(tree* a, node* n)
{
    ll_rotation(a, n->left);
    rr_rotation(a, n);
}


int main()
{
    tree a;
    a.root = NULL;
    node* n;
    int i = 0, x;
    while (i < 8) {
        scanf_s("%d", &x);
        i++;
        insert(&a, x);
    }


    insert(&a, 8);
    n = a.root->left;
    left_right_rotation(&a, n); //nodul cu cheia 10 -> left right rotation

    if (a.root->left->key != 6)
        printf("Nodul cu cheia 6 trebuie sa fie in stanga radacinii");
    if (a.root->left->left->key != 5)
        printf("Nodul cu cheia 5 trebuie a fie in stanga lui 6");
    if (a.root->left->right->key != 10)
        printf("Nodul cu cheia 10 trebuie sa fie in dreapta lui 6");
    if (a.root->left->right->left->key != 8)
        printf("Nodul cu cheia 8 trebuie sa fie in stanga lui 10");

    
    insert(&a, 25);
    n = a.root->right;
    right_left_rotation(&a, n); //nodul cu cheia 25 ->  right left rotation

    if (a.root->right->key != 25)
        printf("Nodul cu cheia 25 trebuie sa fie in dreapta radacinii");
    if (a.root->left->left->key != 5)
        printf("Nodul cu cheia 5 trebuie a fie in stanga lui 6");
    if (a.root->right->right->key != 30)
        printf("Nodul cu cheia 30 trebuie sa fie in dreapta lui 25");
    if (a.root->right->left->key != 20)
        printf("Nodul cu cheia 20 trebuie sa fie in stanga lui 25");
     

}