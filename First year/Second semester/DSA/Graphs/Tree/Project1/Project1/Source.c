#include <stdlib.h>
#include <stdio.h>


// [TASK]: Propuneti o structura de date care sa poata retine un arbore binar.


typedef struct node {
    int key;
    struct node* left;
    struct node* right;
} node;

typedef struct tree {
    node* root;
} tree;


int main()
{


    return 0;
}