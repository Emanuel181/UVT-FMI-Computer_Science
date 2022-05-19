#include <stdio.h>
#include <stdlib.h>


// [TASK]: Propuneti algoritmul de traversare a listei, intr-o functie print care apartine listei.

typedef struct node {
    int val;
    struct node* next;

} node;

typedef struct list {
    struct node* head;
} list;

void print(list l)
{
    node* tmp = l.head;
    int i = 0;

    while (i < 4)
    {
        printf("%i ", (*tmp).val);
        tmp = (*tmp).next;
        i++;
    }
}


int main() {
    list l;
    node* n1, * n2;
    int i = 0, x;
    scanf("%d", &x);
    n1 = malloc(sizeof(node));
    n1->val = x;
    l.head = n1;
    while (i < 3) {
        scanf("%d", &x);
        n2 = malloc(sizeof(node));
        n2->next = NULL;
        n2->val = x;
        n1->next = n2;
        n1 = n2;
        i++;
    }

    print(l);
}