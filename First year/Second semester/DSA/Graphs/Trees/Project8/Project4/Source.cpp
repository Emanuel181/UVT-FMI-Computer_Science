#include <stdio.h>
#include <stdlib.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))


// [TASK]: Afisati nodurile dintr-un arbore binar pe nivele.


typedef struct node {
	int key;
	struct node* left;
	struct node* right;
} node;


typedef struct Queue
{
	node* arr;
	int head;
	int tail;
	int size;
}Queue;


typedef struct tree {
	node* root;
} tree;


node* getNode(int k)
{
	node* nod = (node*)malloc(sizeof(node));
	nod->key = k;
	nod->left = NULL;
	nod->right = NULL;

	return nod;
}


void Insert(node* (*root), int k)
{
	node* nod = getNode(k);

	if ((*root) == NULL) (*root) = nod;

	else
	{
		if (k <= (*root)->key) Insert((&(*root)->left), k);
		else Insert((&(*root)->right), k);
	}
}


void insert(tree* a, int k)
{
	Insert(&(a->root), k);
}


Queue create_queue(int limit)
{
	Queue q;
	q.arr = (node*)malloc(sizeof(node) * limit);
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

void enqueue(Queue* q, node* x)
{
	if (isFull(q)) printf("Limit exceeded\n");

	else
	{
		if (q->head == -1) q->head = 0;
		q->tail = ((q->tail) + 1) % q->size;
		q->arr[q->tail] = (*x);
	}
}

int isEmpty(Queue* q)
{
	if (q->tail == -1) return 1;
	return 0;
}

node dequeue(Queue* q)
{
	node element;
	if (isEmpty(q))
	{
		printf("Coada goala");
		exit(1);
	}

	else
	{
		element = (q->arr[q->head]);
		if (q->head == q->tail)
		{
			q->head = -1;
			q->tail = -1;
		}

		else q->head = (q->head + 1) % q->size;
	}

	return element;
}


int getHeight(node* root)
{
	if (root == NULL) return 0;
	else return MAX(1 + getHeight(root->left), 1 + getHeight(root->right));
}


node front(Queue* q)
{
	return (q->arr[q->head]);
}


void print_tree(tree a)
{
	int height = getHeight(a.root) - 2;
	height = 2 << height;
	Queue q = create_queue(height);

	enqueue(&q, ((a.root)));
	while (isEmpty(&q) != 1)
	{
		node curent = front(&q);
		dequeue(&q);
		printf("%i ", curent.key);
		if (curent.left != NULL) enqueue(&q, curent.left);
		if (curent.right != NULL) enqueue(&q, curent.right);
	}
}


tree a;
int main() {

	int i = 0, x;
	while (i < 9) {
		scanf("%d", &x);
		i++;
		insert(&a, x);
	}
	print_tree(a);
	printf("\n");

}