#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// [TASK]: Suma a doua liste simplu înlantuite. Fiecare nod al listei contine un numar. 
// inceputul listei contine cea mai semnificativa cifra. Faceti suma a doua liste de acest fel, 
// punand rezultatul într-o noua lista simplu inlantuita. Cele doua liste de intrare pot avea dimensiuni diferite.


typedef struct Node {
    int val;
    struct node* next;
}node;

typedef struct List {
    struct node* head;
}list;

list l1, l2;


void append(list* l, int val)
{
    node* nou = malloc(sizeof(node));
    nou->val = val;
    nou->next = NULL;

    if (l->head == NULL) l->head = nou;

    else
    {
        node* tmp = l->head;
        while (tmp->next != NULL) tmp = tmp->next;

        tmp->next = nou;
    }
}


void print(list l)
{
    int number[100], k = 0;

    node* tmp = l.head;

    while (tmp)
    {
        number[k++] = tmp->val;
        tmp = tmp->next;
    }

    for (int i = k - 1; i > -1; --i) printf("%i", number[i]);
}

void adauga_in_spate(list* l1, int carry)
{
    node* nou = malloc(sizeof(node));
    nou->val = carry;
    nou->next = NULL;

    node* tmp = l1->head;

    while (tmp->next) tmp = tmp->next;

    tmp->next = nou;
}


void sum(list* l1, list l2)
{
    int carry = 0;

    node* tmp1 = l1->head;
    node* tmp2 = l2.head;

    while (tmp1 && tmp2)
    {
        tmp1->val += tmp2->val + carry;
        carry = tmp1->val / 10;
        tmp1->val %= 10;

        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }

    while (tmp1)
    {
        tmp1->val += carry;
        carry = (tmp1->val) / 10;
        tmp1->val = (tmp1->val) % 10;

        tmp1 = tmp1->next;
    }

    if (carry) adauga_in_spate(l1, carry);
}

int oglindit(int n)
{
    int ogl = 0;

    while (n)
    {
        ogl = ogl * 10 + n % 10;
        n /= 10;
    }

    return ogl;
}

void get_cif(int num, list* l)
{
    while (num)
    {
        append(l, num % 10);
        num /= 10;
    }
}

int main() {

    int num1, num2;

    scanf("%i", &num1);
    int len1 = log10(num1) + 1;
    get_cif(num1, &l1);

    scanf("%i", &num2);
    int len2 = log10(num2) + 1;
    get_cif(num2, &l2);

    if (len1 > len2)
    {
        sum(&l1, l2);
        print(l1);
    }

    else
    {
        sum(&l2, l1);
        print(l2);
    }
}