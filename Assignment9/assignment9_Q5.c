/* write a program to create two list  represent polynomial of uf to degree 3 
find sum of two polynomials 
exp 1: 3x^3+2x^2+5
exp 2: 4x^2-2
result: 3x^3+6x^2+3*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int pow;
    struct node *next;
};

struct node *create()
{
    struct node *head = NULL, *temp, *newnode;
    int i;

    for(i = 3; i >= 0; i--)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter coefficient of x^%d: ", i);
        scanf("%d", &newnode->coeff);

        newnode->pow = i;
        newnode->next = NULL;

        if(head == NULL)
            head = newnode;
        else
            temp->next = newnode;

        temp = newnode;
    }

    return head;
}

struct node *add(struct node *p1, struct node *p2)
{
    struct node *head = NULL, *temp, *newnode;

    while(p1 != NULL && p2 != NULL)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        newnode->coeff = p1->coeff + p2->coeff;
        newnode->pow = p1->pow;
        newnode->next = NULL;

        if(head == NULL)
            head = newnode;
        else
            temp->next = newnode;

        temp = newnode;

        p1 = p1->next;
        p2 = p2->next;
    }

    return head;
}

void display(struct node *head)
{
    while(head != NULL)
    {
        if(head->coeff != 0)
            printf("%dx^%d ", head->coeff, head->pow);

        head = head->next;

        if(head != NULL)
            printf("+ ");
    }
}

int main()
{
    struct node *p1, *p2, *sum;

    printf("Enter first polynomial:\n");
    p1 = create();

    printf("\nEnter second polynomial:\n");
    p2 = create();

    sum = add(p1, p2);

    printf("\nFirst Polynomial: ");
    display(p1);

    printf("\nSecond Polynomial: ");
    display(p2);

    printf("\nSum of Polynomials: ");
    display(sum);

    return 0;
}