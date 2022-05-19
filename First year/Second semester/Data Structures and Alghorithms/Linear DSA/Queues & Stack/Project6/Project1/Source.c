#include <stdio.h>
#include <stdlib.h>


// [TASK]: Creati o implementare a cozilor circulare folosint tipul tablou.


typedef struct Queue {
	int* arr;
	int head;
	int tail;
	int size;
}Queue;


Queue create_queue(int limit)
{
	Queue q;
	q.arr = (int*)malloc(sizeof(int) * limit);
	q.head = -1;
	q.tail = -1;
	q.size = limit;

	return q;
}

int isFull(Queue* q)
{
	if ((q->head == 0 && q->tail == (q->size) - 1) || (q->tail + 1 == q->head)) return 1;
	return 0;
}

void enqueue(Queue* q, int x)
{
	if (isFull(q)) printf("Limit exceeded\n");

	else
	{
		if (q->head == -1) q->head = 0;
		q->tail = ((q->tail) + 1) % q->size;
		q->arr[q->tail] = x;
	}
}

int isEmpty(Queue* q)
{
	if (q->tail == -1) return 1;
	return 0;
}

int dequeue(Queue* q)
{
	int element;
	if (isEmpty(q)) return;

	else
	{
		element = q->arr[q->head];
		if (q->head == q->tail)
		{
			q->head = -1;
			q->tail = -1;
		}

		else q->head = (q->head + 1) % q->size;
	}

	return element;
}

void print(Queue* q)
{
	int i;
	if (isEmpty(q)) printf("Empty");

	else
	{
		for (i = q->head; i != q->tail; i = (i + 1) % q->size) printf("%i\n", q->arr[i]);

		printf("%i", q->arr[i]);
	}
}


int main()
{
	Queue q = create_queue(5);
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