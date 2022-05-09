#include <stdio.h>
#include <stdlib.h>


// [TASK]: Fie n scaune si un numar k de salt si 2 premii. Scaunele sunt asezate in cerc
//		   si eliminam din k in k scaune pana raman doar 2, care vor fi castigatoare.


int n, cate;


typedef struct node {
	int val;
	struct node* next;
}node;


typedef struct List {
	node* head;
}list;


list create_list()
{
	list s;

	s.head = NULL;

	return s;
}


void adauga(list* s, int x, int n)
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
		//if (x == n) nod->next = s->head;
	}
}


void elimina(list* s, int i)
{
	if (i == 1)
	{
		s->head = s->head->next;
		return;
	}

	node* tmp = s->head;

	for (int j = 1; j < i - 1; ++j) tmp = tmp->next;

	if (tmp->next->next == NULL)
	{
		tmp->next = NULL;
		return;
	}

	node* tmp2 = tmp->next;
	tmp->next = tmp2->next;

}


void prelucreaza(list* s, int k, int n)
{
	node* tmp = s->head;

	int i = 0;

	while (n != 2)
	{
		if (i + k <= n)
		{
			i += k;
			elimina(s, i);
			--n;
			--i;
		}

		else
		{
			i = ((i + k) % n);
			elimina(s, i);
			--n;
			--i;
		}

	}
}


void print(list s)
{
	node* tmp = s.head;

	while (tmp)
	{
		printf("%i ", tmp->val);
		tmp = tmp->next;
	}
}


int main() {
	list s = create_list();
	int k;

	scanf("%d%d", &n, &k);
	cate = n;

	for (int i = 1; i <= n; ++i)
	{
		adauga(&s, i, n);
	}

	prelucreaza(&s, k, n);

	print(s);

}