#include <bits/stdc++.h>

void kdane(int arr[], int n)
{
    int sum = a[0], res = a[0];
    for (int i = 1; i < n; i++)
    {
        sum += a[i];
        if (sum < 0)
            sum = 0;
        res = max(res, sum);
    }
}