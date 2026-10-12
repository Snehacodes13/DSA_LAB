/*
Q.8.1.
Reversing a Delivery Route  using a Singly linked list.

A delivery Company Store it's delivery stops in a singly linked list.
Each Node Contains a Stop number and a pointer to the next stop .
After completing the deliveries , the driver needs to stops dilsplayed in
reverse order for the return journey.

Task: WACP to create the route , display it , reverse the singly linked , and display reversed route.

Example:
    Original Route : 101 -> 102 -> 103 -> 104 -> NULL
    Reversed Route : 104 -> 103 -> 102 -> 101 -> NULL
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int stop;
    struct node *next;
};

struct node *head = NULL;

void createList()
{
    struct node *newnode, *temp;
    int n, i;

    printf("Enter number of delivery stops: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter stop number: ");
        scanf("%d", &newnode->stop);

        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
            temp = head;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
}

void display()
{
    struct node *temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->stop);
        temp = temp->next;
    }

    printf("NULL\n");
}

void reverseList()
{
    struct node *prev = NULL;
    struct node *current = head;
    struct node *nextnode;

    while (current != NULL)
    {
        nextnode = current->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    }

    head = prev;
}

int main()
{
    printf("Create Delivery Route:\n");
    createList();

    printf("\nOriginal Route: ");
    display();

    reverseList();

    printf("Reversed Route: ");
    display();

    return 0;
}
