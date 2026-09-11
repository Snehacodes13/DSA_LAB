/*
a basic calculator needs to evaluate expression already written in postfix requirement:
Evaluate given postfix expression:
Input: 62+3*
*/
#include <stdio.h>
#include <ctype.h>

int stack[100];
int top = -1;

void push(int value)
{
    stack[++top] = value;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char postfix[100];
    int i;
    int a, b, result;
    char ch;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for (i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];

        // If operand
        if (isdigit(ch))
        {
            push(ch - '0');
        }

        // If operator
        else
        {
            b = pop();
            a = pop();

            if (ch == '+')
                result = a + b;

            else if (ch == '-')
                result = a - b;

            else if (ch == '*')
                result = a * b;

            else if (ch == '/')
                result = a / b;

            push(result);
        }
    }

    printf("Result = %d", pop());

    return 0;
}