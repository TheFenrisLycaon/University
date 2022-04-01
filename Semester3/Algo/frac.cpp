#include <iostream>
#include <bits/stdc++.h>

struct obj
{
    int profit;
    double weight;
    double ratio;
};

bool compare(obj p, obj q)
{
    return p.ratio > q.ratio;
}

int main()
{
    int t;
    std ::cout << "Enter how many time you want to perform this exp.:";
    std ::cin >> t;
    while (t-- > 0)
    {
        int n;
        std ::cout << "Enter no of objects present ::\t";
        std ::cin >> n;
        double w;
        std ::cout << "Enter weight of knapsack ::\t";
        std ::cin >> w;
        obj items[n];

        for (int i = 0; i < n; i++)
        {
            std ::cout << "\nEnter profit of object" << i + 1 << "::\t";
            std ::cin >> items[i].profit;
            std ::cout << "Enter weight of object" << i + 1 << "::\t";
            std ::cin >> items[i].weight;
        }

        for (int i = 0; i < n; i++)
        {
            items[i].ratio = ((double)items[i].profit / items[i].weight);
        }

        std ::sort(items, items + n, compare);
        double max_profit = 0;
        int i = 0;

        for (i = 0; i < n; i++)
        {
            if (w > 0 && items[i].weight <= w)
            {
                max_profit += items[i].profit;
                w -= items[i].weight;
            }
            else
            {
                break;
            }
        }

        if (w > 0)
        {
            max_profit += items[i].profit * (w / items[i].weight);
        }
        std ::cout << std ::fixed << std ::setprecision(2) << max_profit << std ::endl;
    }
}