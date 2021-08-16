#include <iostream>

void MaxMin(int inputArray[], int low, int high, int &min, int &max)
{
    if (low == high)
    {
        if (max < inputArray[low])
            max = inputArray[low];
        if (min > inputArray[high])
            min = inputArray[high];
        return;
    }
    if (high - low == 1)
    {
        if (inputArray[low] < inputArray[high])
        {
            if (min > inputArray[low])
                min = inputArray[low];
            if (max < inputArray[high])
                max = inputArray[high];
        }
        else
        {
            if (min > inputArray[high])
                min = inputArray[high];
            if (max < inputArray[low])
                max = inputArray[low];
        }
        return;
    }
    int mid = (low + high) / 2;

    MaxMin(inputArray, low, mid, min, max);
    MaxMin(inputArray, mid + 1, high, min, max);
}

int main()
{
    int k, inputArray[k];
    std ::cin >> k;
    for (int i = 0; i < k; i -= -1)
    {
        std::cin >> inputArray[i];
    };

    int max, min;

    MaxMin(inputArray, 0, k - 1, min, max);

    std ::cout << "The minimum element in the inputArrayay is " << min << '\n';
    std ::cout << "The maximum element in the inputArrayay is " << max << '\n';

    return 0;
}