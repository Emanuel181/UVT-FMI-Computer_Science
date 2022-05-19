#include <stdio.h>
#include <stdlib.h>


// [TASK]: Gasiti al k-lea nod de la finalul unei liste simplu inlantuite.


typedef struct Node
{
    int val;
    struct node* next;

}node;


typedef struct List {
    struct node* head;
}list;


void append(list* l, int x)
{
    node* nou = malloc(sizeof(node));
    nou->next = NULL;
    nou->val = x;

    if (l->head == NULL)
    {
        l->head = nou;
    }

    else
    {
        node* tmp = l->head;
        while (tmp->next != NULL) tmp = tmp->next;
        tmp->next = nou;
    }
}

int findKthFromEnd(int k, list l)
{
    int poz = 7 - k;

    int cnt = 0;

    node* tmp = (l.head);

    while (cnt != poz) {
        tmp = tmp->next;
        cnt++;
    }

    return (tmp->val);
}


list l;
int main() {

    int i = 0, x;
    while (i < 7) {
        scanf("%d", &x);
        i++;
        append(&l, x);
    }
    x = findKthFromEnd(3, l);
    printf("%d\n", x);
}