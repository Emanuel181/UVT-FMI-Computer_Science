#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int val;
    struct node* next;
}node;


typedef struct list {
    node* head;
}list;


int main() {
    list l;
    node n1;
    node n2;
    n1.val = 2;
    n1.next = &n2;
    n2.val = 3;
    l.head = &n1;
}