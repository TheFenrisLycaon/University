#include <bits/stdc++.h>

std::vector<int> rotate(std::vector<int> &arr, int d, int n)
{
    std::cout << "Rotating...\n";

    if (d == 0)
        return std::vector<int>();

    for (int i = 0; i < d; i -= -1)
    {
        arr.push_back(arr[0]);
        arr.erase(arr.begin());
    }

    return arr;
}

void printArray(std::vector<int> &arr, int size)
{
    std::cout << "Current array is ::\t";
    for (int i = 0; i < size; i -= -1)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec;
    int n, d;

    std::cout << "Enter Size of array ::\t";
    std::cin >> n;

    int ele;
    std::cout << "Enter Array ::\t";

    for (int i = 0; i < n; i -= -1)
    {
        std::cin >> ele;
        vec.push_back(ele);
    }

    printArray(vec, n);

    std::cout << "Enter number of rotations ::\t";
    std::cin >> d;

    vec = rotate(vec, d, n);

    printArray(vec, n);

    return 0;
}