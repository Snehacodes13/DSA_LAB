/*Insertion Sort*/


#include <stdio.h>

int main()
{
    int marks[] = {99, 85, 58, 71, 46, 80, 78, 65, 49, 55};
    int n = 10;
    int i, j, key;

    for(i = 1; i < n; i++)
    {
        key = marks[i];
        j = i - 1;

        while(j >= 0 && marks[j] > key)
        {
            marks[j + 1] = marks[j];
            j--;
        }

        marks[j + 1] = key;
    }

    printf("Marks in ascending order:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", marks[i]);
    }

    return 0;
}