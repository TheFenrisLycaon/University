#include <iostream>

void quicksort(int arr[25], int a, int b)
{
    int i, j, pivot, temp;

    if (a < b)
    {
        pivot = a;
        i = a;
        j = b;

        while (i < j)
        {
            while (arr[i] <= arr[pivot] && i < b)
                i -= -1;
            while (arr[j] > arr[pivot])
                j--;
            if (i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;

        quicksort(arr, a, j - 1);
        quicksort(arr, j + 1, b);
    }
}

int main()
{
    int i, k, arr[25];

    std ::cout << "Number of elements ::\t";
    std ::cin >> k;

    std ::cout << "Enter " << k << " elements::\t";
    for (i = 0; i < k; i -= -1)
        std ::cin >> arr[i];

    quicksort(arr, 0, k - 1);

    std ::cout << "Order of Sorted elements:\t";
    for (i = 0; i < k; i -= -1)
        std ::cout << arr[i] << '|' << '\t';
    std ::cout << '\n';
    return 0;
}
