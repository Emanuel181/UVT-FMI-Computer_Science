#include <stdio.h>
#include <stdlib.h>


// [TASK]: Implementati o structura de date de tip coada (Queue) folosind liste simplu inlantuite.


typedef struct node {
	int val;
	struct node* next;
}node;


typedef struct Queue {
	node* head;
}Queue;


Queue create_queue()
{
	Queue s;

	s.head = NULL;

	return s;
}

void enqueue(Queue* s, int x)
{
	node* nod = (node*)malloc(sizeof(node));
	nod->val = x;
	nod->next = NULL;

	if (s->head == NULL) s->head = nod;

	else
	{
		node* tmp = s->head;
		while (tmp->next) tmp = tmp->next;
		tmp->next = nod;
	}
}

void print(Queue* s)
{
	node* tmp = s->head;

	while (tmp)
	{
		printf("%i\n", tmp->val);
		tmp = tmp->next;
	}
}

Queue* dequeue(Queue* s)
{
	s->head = s->head->next;

	return s;
}


int main() 
{
	Queue q = create_queue();
	int x, i;

	scanf("%d", &x);
	while (x > 0) {
		scanf("%d", &i);
		enqueue(&q, i);
		x--;
	}
	dequeue(&q);
	dequeue(&q);
	print(&q);
}