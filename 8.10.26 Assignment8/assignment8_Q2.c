/*
Q.8.2.
Train coaches using Doubly Linked List:   
A railway system stores the coaches of a train in a doubly linked list. 
Each coach has a coach number and link to both previous and next coaches. 
This allows the railway staff to inspect the coaches from the engine towards 
the last coach and from the last coach back towards the engine.   

Task: — Write a C Program (WACP) to:   
i) Create a doubly linked list of coach numbers.   
ii) Traverse and display the coaches in forward order.   
iii) Traverse and display the coaches in backward order.  
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coach;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void createList()
{
    struct node *newnode;
    int n, i;

    printf("Enter number of coaches: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter coach number: ");
        scanf("%d", &newnode->coach);

        newnode->prev = NULL;
        newnode->next = NULL;

        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }
}

void forwardTraversal()
{
    struct node *temp = head;

    printf("Forward Order: ");

    while (temp != NULL)
    {
        printf("%d <-> ", temp->coach);
        temp = temp->next;
    }

    printf("NULL\n");
}

void backwardTraversal()
{
    struct node *temp = tail;

    printf("Backward Order: ");

    while (temp != NULL)
    {
        printf("%d <-> ", temp->coach);
        temp = temp->prev;
    }

    printf("NULL\n");
}

int main()
{
    createList();

    forwardTraversal();
    backwardTraversal();

    return 0;
}
