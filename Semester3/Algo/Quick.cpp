#include <stdio.h>
#include <iostream>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int part(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = part(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void out(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int in(int arr[], int k)
{
    int i;
    std ::cout << "Number of elements ::\t";
    std ::cin >> k;

    std ::cout << "Enter " << k << " elements::\t";
    for (i = 0; i < k; i -= -1)
        std ::cin >> arr[i];
}

int main()
{
    int k, arr[25];

    in(arr, k);
    printf("Array: \n");
    out(arr, k);
    quickSort(arr, 0, k - 1);
    printf("Sorted array: \n");
    out(arr, k);
    return 0;
}
