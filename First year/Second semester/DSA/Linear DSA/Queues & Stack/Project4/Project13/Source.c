#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
	int code;
	struct node* next;
	struct node* prev;
}node;


typedef struct list
{
	node* head;
	node* tail;
}list;


node* get_node(int code)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->code = code;
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}
void adauga_stocSpate(list* l1, int code)
{
	node* newNode = get_node(code);

	if (l1->head == NULL) l1->head = newNode;

	else
	{
		node* tmp = l1->head;
		while (tmp->next) tmp = tmp->next;

		tmp->next = newNode;
		newNode->prev = tmp;
		l1->tail = newNode;
	}
}


void adauga_stocuri(list* l1)
{
	for (int i = 1; i <= 10; ++i) adauga_stocSpate(l1, i);
}


void initList(list* l1)
{
	l1->head = NULL;
}


void print(list l1)
{
	node* tmp = l1.head;

	while (tmp)
	{
		printf("%i ", tmp->code);
		tmp = tmp->next;
	}
}


void adauga_stocFata(list* l1, int code)
{
	node* newNode = get_node(code);

	if (l1->head == NULL)
	{
		l1->head = newNode;
	}

	else
	{
		newNode->next = l1->head;
		l1->head->prev = newNode;
		l1->head = newNode;
	}
}

void adauga_stocInainte(list l1, int code, int value)
{
	node* newNode = get_node(value);

	node* tmp = l1.head;

	while (tmp->next->code != code) tmp = tmp->next;

	newNode->next = tmp->next;
	tmp->next->prev = newNode;
	tmp->next = newNode;
}


void adauga_stocDupa(list l1, int code, int value)
{
	node* newNode = get_node(value);

	node* tmp = l1.head;

	while (tmp->code != code) tmp = tmp->next;

	newNode->next = tmp->next;
	tmp->next = newNode;
}

void adauga(list l1, int code)
{
	node* tmp = l1.head;

	while (tmp->code <= code && tmp->next != NULL) tmp = tmp->next;

	node* newNode = get_node(code);

	if (tmp->next == NULL) tmp->next = newNode;

	else
	{
		newNode->next = tmp->next;
		tmp->next->prev = newNode;
		tmp->next = newNode;

	}

}


int main() {

	list l1;

	initList(&l1);

	printf("Adaugam primele stocuri\nStocuri: ");  adauga_stocuri(&l1);
	print(l1);

	printf("\n\n");
	printf("Adaugam un stoc in fata listei\n");
	printf("Codul stocului: ");
	int x; scanf("%i", &x);
	adauga_stocFata(&l1, x);
	print(l1);

	printf("\n\n");
	printf("Adaugam un stoc in spatele listei\n");
	printf("Codul stocului: "); scanf("%i", &x);
	adauga_stocSpate(&l1, x);
	print(l1);

	printf("\n\n");
	printf("Adaugam un stoc inaintea unei referinte\n");
	int y;
	printf("Codul referintei: "); scanf("%i", &y);
	printf("\n");
	printf("Codul stocului nou: "); scanf("%i", &x);
	adauga_stocInainte(l1, y, x);
	print(l1);

	printf("\n\n");
	printf("Adaugam un stoc dupa o referinta\n");
	printf("Codul referintei: "); scanf("%i", &y);
	printf("\n");
	printf("Codul stocului nou: "); scanf("%i", &x);
	adauga_stocInainte(l1, y, x);
	print(l1);

	printf("\n\n");
	printf("Adaugam un stoc (se adauga ordonat) \n");
	printf("Codul stocului nou: "); scanf("%i", &x);
	adauga(l1, x);
	print(l1);
}