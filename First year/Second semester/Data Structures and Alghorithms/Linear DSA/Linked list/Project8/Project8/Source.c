#include <stdio.h>
#include <stdlib.h>


// [TASK]: Schimbati al k-lea nod de la capat cu al k-lea nod de la inceputul unei liste simple inlantuite


typedef struct nod {
	int val;
	struct nod* next;
}nod;

void append(nod** head, int numar)
{
	nod* nou = (nod*)malloc(sizeof(nod));
	nou->val = numar;
	nou->next = NULL;

	if ((*head) == NULL) (*head) = nou;

	else
	{
		nod* aux = (*head);
		while (aux->next) aux = aux->next;
		aux->next = nou;
	}
}


int find(nod* head, int poz)
{
	nod* ptr = head;

	for (int i = 1; i < poz; ++i) ptr = ptr->next;

	return ptr->val;
}

void replace(nod* head, int numar, int poz)
{
	nod* ptr = head;

	for (int i = 1; i < poz; ++i) ptr = ptr->next;

	ptr->val = numar;
}

void print(nod* head)
{
	nod* ptr = head;
	while (ptr)
	{
		printf("%i ", ptr->val);
		ptr = ptr->next;
	}
}
int main()
{
	nod* head = NULL;

	int n, k; scanf("%i%i", &n, &k);

	for (int i = 1; i <= n; ++i)
	{
		int numar; scanf("%i", &numar);
		append(&head, numar);
	}

	int a = find(head, k);
	int b = find(head, n - k + 1);

	replace(head, b, k);
	replace(head, a, n - k + 1);

	print(head);

	return 0;
}