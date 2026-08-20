/*
Bank account a keeping transaction amount as it is processed by customer . The transaction amount of last customer is sorted at 
top position. After complrtion of all transaction , the manager pull the amount one by one and display  the amount and find 
total-transaction-amount to print.
Define following function:
Push(): to insert amount in
Pop(): to remove amount
dosum(): Find the sum of all transaction amount


Amount inserted in following order: 1050, 2090, 3000, 6000, 5500, 8900 
*/

#include <stdio.h>

#define MAX 2

int stack[MAX];
int top = -1;

void Push(int amount)
{
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = amount;
}

int Pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}


int dosum()
{
    int sum = 0;

    for (int i = 0; i <= top; i++)
        sum = sum + stack[i];

    return sum;
}

int main()
{
    int choice, amount, x;
    
    do
    {
        printf("\n--- BANK TRANSACTION ---\n");
        printf("1. Push Transaction\n");
        printf("2. Pop Transaction\n");
        printf("3. Display Total Transaction Amount\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter transaction amount: ");
                scanf("%d", &amount);
                Push(amount);
                break;

            case 2:
                x = Pop();

                if (x != -1)
                    printf("Popped Amount = %d\n", x);
                break;

            case 3:
                printf("Total Transaction Amount = %d\n", dosum());
                break;

            case 4:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 4);

    return 0;
}