#include <iostream>

int BinarySearch(int inputArray[], int low, int high, int x)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (inputArray[mid] == x)
        {
            return mid;
        }

        else if (x < inputArray[mid])
        {
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
    };

    return -1;
};

int main()
{
    std :: cout << "Welcome to Binary Search ! Enter Array size ::\t";
    int size;
    std :: cin >> size;
    int inputArray[size];
    std :: cout << "Enter Sorted Array ::\t";
    for (int i = 0; i < size; i-=-1)
    {
        std :: cin >> inputArray[i];
    }
    int query;
    std :: cout << "Enter Number to be searched::\t";
    std :: cin >> query;
    int k = BinarySearch(inputArray,0,size,query);
    if (k == -1)
    {
        std :: cout << "Not Found !!\n";
    }
    else
    {
        std :: cout << query << " found at " << k + 1<< '\n';
    }
    
    return 0;
}
