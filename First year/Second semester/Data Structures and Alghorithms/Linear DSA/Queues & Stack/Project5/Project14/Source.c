#include <stdio.h>
#include <stdlib.h>


// [TASK]:  Creati o implementare a stivelor folosind tipul tablou.


typedef struct stack {

	int* arr;
	int top;
	int capacity;
}Stack;


Stack create_stack(int limit)
{
	Stack stack;

	stack.top = -1;
	stack.capacity = limit;
	stack.arr = (int*)malloc(limit * sizeof(int));

	return stack;
}

int isFull(Stack* stack)
{
	if (stack->top == (stack->capacity) - 1) return 1;

	return 0;
}

void push(Stack* s, int item)
{
	if (isFull(s)) printf("Limit exceeded\n");

	else s->arr[++(s->top)] = item;
}

int isEmpty(Stack* s)
{
	if (s->top == -1) return 1;
	return 0;
}

int pop(Stack* s)
{
	if (isEmpty(s)) return;

	--(s->top);
}

void print(Stack* s)
{
	Stack* tmp = s;

	for (int i = s->top; i >= 0; --i) printf("%i\n", s->arr[i]);
}


int main()
{
	Stack s = create_stack(6);
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