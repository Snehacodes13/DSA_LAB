/*Write a program to take input marks of 10 students randomly in an array.Sort the array using merge sort and show the highest
 and lowest marks.
 Input size of array=10
 [80,73,59,92,86,47,92,58,91,48] */
#include <stdio.h>
void merge(int arr[], int low, int mid, int high)
{
    int temp[10];
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main()
{
    int marks[10] = {80, 73, 59, 92, 86, 47, 92, 58, 91, 48};
    int i;

    printf("Original Marks:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", marks[i]);
    }

    mergeSort(marks, 0, 9);

    printf("\n\nSorted Marks (Ascending Order):\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", marks[i]);
    }

    printf("\n\nLowest Marks = %d", marks[0]);
    printf("\nHighest Marks = %d\n", marks[9]);

    return 0;
}