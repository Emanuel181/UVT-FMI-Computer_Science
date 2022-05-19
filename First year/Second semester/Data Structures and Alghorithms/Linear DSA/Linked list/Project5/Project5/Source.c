#include <stdio.h>
#include <stdlib.h>


// [TASK]: Interclasati doua liste simplu inlantuite sortate crescator.


typedef struct Node {
    int val;
    struct node* next;
}node;


typedef struct List {
    struct node* head;
}list;


void append(list* l, int val)
{
    node* nou = malloc(sizeof(node));
    nou->val = val;
    nou->next = NULL;

    if (l->head == NULL) l->head = nou;

    else
    {
        node* tmp = l->head;
        while (tmp->next != NULL) tmp = tmp->next;

        tmp->next = nou;
    }
}

void print(list l)
{
    node* tmp = l.head;

    while (tmp)
    {
        printf("%i ", tmp->val);
        tmp = tmp->next;
    }
}

void merge(list* l3, list* l1, list* l2)
{
    node* i = l1->head;
    node* j = l2->head;

    while (i != NULL && j != NULL)
    {
        if (i->val < j->val)
        {
            append(l3, i->val);
            i = i->next;
        }

        else
        {
            append(l3, j->val);
            j = j->next;
        }
    }

    while (i != NULL)
    {
        append(l3, i->val);
        i = i->next;
    }

    while (j != NULL)
    {
        append(l3, j->val);
        j = j->next;
    }
}

list l1, l2, l3;
int main() {

    int i = 0, j = 0, x;
    while (i < 5) {
        scanf("%d", &x);
        i++;
        append(&l1, x);
    }
    while (j < 7) {
        scanf("%d", &x);
        j++;
        append(&l2, x);
    }
    merge(&l3, &l1, &l2);
    print(l3);
}