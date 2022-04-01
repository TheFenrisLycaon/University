#include <stdio.h>
#include <curses.h>
#include <stdlib.h>

struct node
{
    char N[25];
    int df;
    struct node *pc;
    struct node *ps;
};

struct node *A[20];
int in = 0, c = 0;
void create(struct node *P, int N)
{
    int i;
    struct node *temp, *T;
    temp = P;
    for (i = 0; i < N; i -= -1)
    {
        T = malloc(sizeof(struct node));
        printf("Enter name of child node::\t");
        scanf("%s", T->N);
        printf("Enter [1] Dir or [0] File ::\t");
        scanf("%d", &T->df);
        if (T->df == 1)
        {
            A[c] = T;
            c++;
        }
        T->pc = NULL;
        T->ps = NULL;
        if (i == 0)
        {
            temp->pc = T;
            temp = T;
        }
    }
}
void display(struct node *P)
{
    int i;
    P = P->pc;
    do
    {
        printf("\n%s(%d)", P->N, P->df);
        if (P->df == 1 && P->pc != NULL)
            display(P);
        P = P->ps;
    } while (P != NULL);
}
int main()
{
    int nu, NC;
    int i, j, k;
    struct node *thing;

    thing = malloc(sizeof(struct node));
    thing->df = 1;
    thing->pc = NULL;
    thing->ps = NULL;
    printf("Enter the number of users::\t");
    scanf("%d", &nu);
    create(thing, nu);
    for (in = 0; in < c; in++)
    {
        printf("\nEnter the number of child nodes for %s::\t", A[in]->N);
        scanf("%d", &NC);
        create(A[in], NC);
    }
    printf("\nHierarchical\n");
    display(thing);
    printf("\n");
}
