#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// [TASK]: Evaluare expresiilor postfixate folosind stive

typedef struct Stiva {
	int size;
	int top;
	char* arr;
}stiva;


typedef struct Stiva2 {
	int size;
	int top;
	int* arr;
}stiva2;


int P(char ch)
{
	if (ch == '(') return 4;
	else if (ch == '^') return 3;

	else if (ch == '*' || ch == '/') return 2;

	else if (ch == '+' || ch == '-') return 1;

	return -1;

}

stiva init(int size)
{
	stiva st;
	st.size = size;
	st.top = -1;
	st.arr = (char*)malloc(sizeof(int) * size);

	return st;
}


int Operand(char ch)
{
	if (ch >= 'a' && ch <= 'z') return 1;
	else if (ch >= 'A' && ch <= 'Z') return 1;

	return 0;
}


int Operator(char ch)
{
	if (ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-') return 1;
	return 0;
}


int isEmpty(stiva* s)
{
	if (s->top == -1) return 1;
	return 0;
}


int isFull(stiva* s)
{
	if (s->top == s->size - 1) return 1;
	return 0;
}


void push(stiva* s, char ch)
{
	if (isFull(s) == 0) s->arr[++(s->top)] = ch;
}


char pop(stiva* s)
{
	if (isEmpty(s) == 0) return s->arr[(s->top)--];
}


char peek(stiva s)
{
	return s.arr[s.top];
}


void InfixToPostfix(stiva s, char str[])
{
	int k = 0, cnt = 0;

	for (int i = 0; str[i]; ++i) if (str[i] == '(' || str[i] == ')') ++cnt;

	for (int i = 0; str[i]; ++i)
	{

		if (isdigit(str[i])) str[k++] = str[i];

		else if (str[i] == ')')
		{
			while (peek(s) != '(') str[k++] = pop(&s);
			pop(&s);
		}

		else if (Operator(str[i]) || str[i] == '(')
		{
			while ((isEmpty(&s) == 0) && (peek(s) != '(') && (P(peek(s)) >= P(str[i]))) str[k++] = pop(&s);

			push(&s, str[i]);
		}

	}


	while (isEmpty(&s) == 0)
	{
		str[k++] = pop(&s);
	}

	str[strlen(str) - cnt] = '\0';
}


stiva2 init2(int size)
{
	stiva2 s;
	s.top = -1;
	s.size = size;
	s.arr = (int*)malloc(sizeof(int) * size);

	return s;
}


int isEmpty2(stiva2* s)
{
	if (s->top == -1) return 1;
	return 0;
}


int isFull2(stiva2* s)
{
	if (s->top == s->size - 1) return 1;
	return 0;
}


void push2(stiva2* s, char ch)
{
	if (isFull(s) == 0) s->arr[++(s->top)] = ch;
}


char pop2(stiva2* s)
{
	if (isEmpty(s) == 0) return s->arr[(s->top)--];
}


int solve(stiva2 s2, char str[])
{
	for (int i = 0; str[i]; ++i)
	{
		if (isdigit(str[i])) push2(&s2, str[i] - '0');

		/*if (isdigit(str[i]) && str[i + 1] == '-')
		{
			int x = pop2(&s2);
			x = -x;
			push2(&s2, x);
		}*/

		else
		{
			int x = pop2(&s2);
			int y = pop2(&s2);

			if (str[i] == '+') push2(&s2, y + x);
			else if (str[i] == '-') push2(&s2, y - x);
			else if (str[i] == '*') push2(&s2, y * x);
		}
	}

	return pop2(&s2);
}

// A*B-(C+D)+E
// 2+3*4+5*2

int main()
{
	stiva s;
	s.arr = NULL;

	char str[255]; gets(str);

	for (int i = 0; str[i]; ++i)
	{
		if (str[i] == ' ') strcpy(str + i, str + i + 1);
	}


	s = init(strlen(str));

	InfixToPostfix(s, str);

	//for (int i = 0; str[i]; ++i) printf("%c", str[i]);

	printf("\n");

	stiva2 s2;

	s2 = init2(strlen(str));

	printf("%i", solve(s2, str));

	return 0;

}