#include <bits/stdc++.h>

template <typename T>
T ksmallest(T arr[], int n, int k)
{
    std ::set<int> s(arr, arr + n);
    std ::set<int>::iterator itr = s.begin();
    std ::advance(itr, k - 1);
    return *itr;
}

int main()
{
    int n;
    std ::cout << "Enter size of array ::\t";
    std ::cin >> n;

    std ::cout << "Enter array::\t";
    int arr[n];
    for (int i = 0; i < n; i -= -1)
        std ::cin >> arr[i];

    std ::cout << "Enter element number::\t";
    int k;
    std ::cin >> k;

    std ::cout << "The " << k << " largest element is ::\t"
               << ksmallest(arr, n, k) << std ::endl;

    return 0;
}