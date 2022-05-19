#include <stdio.h>
#include <stdlib.h>

// [TASK]: Inlaturati duplicatele dintr-o lista simplu inlantantuita.


typedef struct nod {
	int num;
	struct nod* next;
}nod;

nod* head;
int n;

void creeazaNod(int x)
{
	nod* nodNou = (nod*)malloc(sizeof(nod));
	nodNou->num = x;
	nodNou->next = NULL;

	if (head == NULL) head = nodNou;

	else
	{
		nod* aux = head;
		while (aux->next) aux = aux->next;
		aux->next = nodNou;
	}
}

void print()
{
	nod* aux = head;

	while (aux)
	{
		printf("%i ", aux->num);
		aux = aux->next;
	}
}


void elimina(int poz)
{
	if (poz == n)
	{
		nod* aux = head;
		while (aux->next->next) aux = aux->next;
		aux->next = NULL;
	}

	else
	{
		nod* aux = head;
		for (int i = 1; i < poz - 1; ++i) aux = aux->next;

		nod* aux2 = aux->next;
		aux->next = aux2->next;
		free(aux2);
	}
}

void prelucrare()
{
	nod* ptr1 = head;
	int i = 1, j;

	while (ptr1)
	{
		nod* ptr2 = ptr1->next;
		j = i + 1;
		while (ptr2)
		{
			if (ptr2->num == ptr1->num)
			{
				elimina(j);
				ptr2 = ptr1->next;
				j = i + 1;
			}
			else
			{
				ptr2 = ptr2->next;
				++j;
			}
		}

		++i;
		ptr1 = ptr1->next;
	}
}


int main()
{
	head = NULL;

	scanf("%i", &n);

	for (int i = 1; i <= n; ++i)
	{
		int x; scanf("%i", &x);
		creeazaNod(x);
	}

	prelucrare();

	print();

	return 0;
}