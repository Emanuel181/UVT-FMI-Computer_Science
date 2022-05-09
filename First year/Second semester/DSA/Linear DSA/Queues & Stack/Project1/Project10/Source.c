#include <stdio.h>
#include <stdlib.h>


// [TASK]: Implementati o structura de date de tip stiva folosind liste simplu inlantuite.


typedef struct node {
	int val;
	struct node* next;
}node;


typedef struct Stack {
	node* head;
}Stack;


Stack create_stack()
{
	Stack s;

	s.head = NULL;

	return s;
}

void push(Stack* s, int x)
{
	node* nod = (node*)malloc(sizeof(node));
	nod->val = x;
	nod->next = NULL;

	if (s->head == NULL) s->head = nod;

	else
	{
		nod->next = s->head;
		s->head = nod;
	}
}

void print(Stack* s)
{
	node* tmp = s->head;

	while (tmp)
	{
		printf("%i\n", tmp->val);
		tmp = tmp->next;
	}
}

Stack* pop(Stack* s)
{
	s->head = s->head->next;

	return s;
}


int main() {
	Stack s = create_stack();
	int x, i;

	scanf("%d", &x);
	while (x > 0) {
		scanf("%d", &i);
		push(&s, i);
		x--;
	}
	pop(&s);
	pop(&s);
	print(&s);
}