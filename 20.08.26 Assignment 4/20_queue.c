/*
A single screen cinema hall has one ticket counter. One customer arrives at a time. Simulate the ticket counter using queue. 
the requierments are:
1.Add customers
2.Serve customers
3.Show " housefull" if the seats are full
4.Display all customer
*/

#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void addCustomer()
{
    int ticket;

    if (rear == MAX - 1)
    {
        printf("Housefull! No more seats available.\n");
        return;
    }

    printf("Enter customer ticket number: ");
    scanf("%d", &ticket);

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = ticket;

    printf("Customer added successfully.\n");
}

void serveCustomer()
{
    if (front == -1 || front > rear)
    {
        printf("No customers in the queue.\n");
        return;
    }

    printf("Customer with ticket %d is served.\n", queue[front]);
    front++;

    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

void displayCustomers()
{
    int i;

    if (front == -1)
    {
        printf("No customers in the queue.\n");
        return;
    }

    printf("Customers waiting in queue:\n");

    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    printf("\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n--- Cinema Ticket Counter ---\n");
        printf("1. Add Customer\n");
        printf("2. Serve Customer\n");
        printf("3. Display All Customers\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addCustomer();
                break;

            case 2:
                serveCustomer();
                break;

            case 3:
                displayCustomers();
                break;

            case 4:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}