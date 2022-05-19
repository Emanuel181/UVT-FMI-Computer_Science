#include<stdio.h>
#include <stdlib.h>

// [TASK]: Continuati clasa List implementand functia append, care adauga un element la finalul listei. 

typedef struct node {
    int val;
    struct node* next;
} node;


typedef struct list {
    struct node* head;
} list;

void print(list l) {
    struct node* tmp = l.head;

    while (tmp)
    {
        printf("%i ", tmp->val);
        tmp = tmp->next;
    }

}
void append(list* l, int k) {
    struct node* nou = malloc(sizeof(struct node));
    nou->next = NULL;
    nou->val = k;

    if (l->head == NULL) l->head = nou;

    else {
        struct node* tmp = l->head;

        while (tmp->next) tmp = tmp->next;

        tmp->next = nou;
    }
}

list l;
int main() {

    int i = 0, x;
    while (i < 5) {
        scanf("%d", &x);
        i++;
        append(&l, x);
    }
    print(l);
}