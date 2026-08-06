/*Write  a programe to take input in an array 10 unordered number and apply quick sort to order the array in accending order 
Input size=10
array item=[8,2,10,6,5,12,18,9,4,11]*/

#include <stdio.h>
void swap(int arr[], int i, int j) {
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr, i, j);
        }
    }

    swap(arr, i + 1, high);
    return i + 1;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main() {
    int arr[10] = {8, 2, 10, 6, 5, 12, 18, 9, 4, 11};
    int i;

    printf("Original Array:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    quickSort(arr, 0, 9);

    printf("\n\nSorted Array (Ascending Order):\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}