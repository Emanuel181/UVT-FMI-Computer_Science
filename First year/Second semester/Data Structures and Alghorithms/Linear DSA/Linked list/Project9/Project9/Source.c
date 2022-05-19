#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/*[TASK]:

Gestiunea unui magazin. 
Pentru fiecare dintre produsele vandute in magazin sunt pastrate urmatoarele informatii: un cod unic, un nume, un pret, cantitate în stoc, data primirii, data de expirare.

Pentru urmarirea actiunilor proprietarul ar folosi o aplicatie software care poate face

urmatoarele operatiuni:

Se introduce un element cu toate datele asociate, pastrand o sortare a elementelor din lista dupa pret

Gasirea un element prin codul sau, si sa poata actualiza elementul gasit.

Listarea elementelor valide 

Lista cu produse expirate

Lista cu toate articolele

Stergerea unui element dat de codul sau.

Sterge toate articolele expirate.

*/


#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Product {
    int code;
    char name[50];
    float price;
    int quantity;
    char recDate[50];
    char expDate[50];
}Product;


Product createProduct(int code, char* name, float price, int quantity, char* recDate, char* expDate)
{
    Product p;
    p.code = code;
    strcpy(p.name, name);
    p.price = price;
    p.quantity = quantity;
    strcpy(p.recDate, recDate);
    strcpy(p.expDate, expDate);

    return p;
}


typedef struct Node {
    Product val;
    struct Node* next;
}Node;


typedef struct List {
    Node* head;
}List;

void appendSorted(List* l, Product p)
{
    Node* nod = (Node*)malloc(sizeof(Node));
    nod->val.code = p.code;
    strcpy((nod->val).name, p.name);
    (nod->val).price = p.price;
    (nod->val).quantity = p.quantity;
    strcpy((nod->val).recDate, p.recDate);
    strcpy((nod->val).expDate, p.expDate);

    if (l->head == NULL || l->head->val.price >= p.price)
    {
        nod->next = l->head;
        l->head = nod;
    }

    else
    {
        Node* tmp = l->head;
        while (tmp->next != NULL && tmp->next->val.price < p.price) tmp = tmp->next;

        nod->next = tmp->next;
        tmp->next = nod;
    }
}

void print(List l)
{
    Node* tmp = l.head;

    while (tmp)
    {
        printf("%d %s %.1f %d %s %s\n", tmp->val.code, tmp->val.name, tmp->val.price, tmp->val.quantity, tmp->val.recDate, tmp->val.expDate);
        tmp = tmp->next;
    }
}

void printValid(List l, char str[50])
{
    Node* tmp = l.head;

    while (tmp)
    {
        if ((int)tmp->val.expDate[4] < (int)str[4]) printf("%d %s %.1f %d %s %s\n", tmp->val.code, tmp->val.name, tmp->val.price, tmp->val.quantity, tmp->val.recDate, tmp->val.expDate);
        tmp = tmp->next;
    }
}

printExpired(List l, char str[50])
{
    Node* tmp = l.head;

    while (tmp)
    {
        if ((int)(tmp->val.expDate[0]) * 10 + (int)(tmp->val.expDate[1]) < (int)str[0] * 10 + (int)str[1]) printf("%d %s %.1f %d %s %s\n", tmp->val.code, tmp->val.name, tmp->val.price, tmp->val.quantity, tmp->val.recDate, tmp->val.expDate);
        tmp = tmp->next;
    }
}

Node* findByCode(List l, int x)
{
    Node* tmp = l.head;

    while (tmp != NULL && tmp->val.code != x) tmp = tmp->next;

    return tmp;
}

void deleteByCode(List* l, int x)
{
    if (l->head->val.code == x) l->head = l->head->next;

    else
    {
        Node* tmp = l->head;

        while (tmp != NULL && tmp->next->val.code != x) tmp = tmp->next;

        Node* tmp2 = tmp->next;
        tmp->next = tmp2->next;
        free(tmp2);
    }
}


void deleteExpired(List* l, char str[])
{
    Node* tmp = l->head;

    while (tmp)
    {
        if ((int)(tmp->val.expDate[0]) * 10 + (int)(tmp->val.expDate[1]) < (int)str[0] * 10 + (int)str[1])
        {
            deleteByCode(l, tmp->val.code);
            tmp = l->head;
        }
        tmp = tmp->next;
    }
}


int main() {
    int n, code, quantity;
    float price;
    char name[50], recDate[50], expDate[50];
    scanf("%d", &n);
    List l;
    l.head = NULL;
    while (n) {
        scanf("%d", &code);
        scanf("%s", name);
        scanf("%f", &price);
        scanf("%d", &quantity);
        scanf("%s", recDate);
        scanf("%s", expDate);
        //printf("%d, %s, %f, %d, %s, %s", code, name, price, quantity, recDate, expDate);
        appendSorted(&l, createProduct(code, name, price, quantity, recDate, expDate));
        n--;
    }
    printf("test 1\n");
    print(l);

    printf("test 2\n");
    Node* p = findByCode(l, 102);
    strcpy(p->val.name, "Poiana");
    print(l);

    printf("test 3\n");
    printValid(l, "20/03/2020");

    printf("test 4\n");
    printExpired(l, "20/03/2020");

    printf("test 5\n");
    deleteByCode(&l, 104);
    print(l);

    printf("test 6\n");
    deleteExpired(&l, "20/03/2020");
    print(l);
}