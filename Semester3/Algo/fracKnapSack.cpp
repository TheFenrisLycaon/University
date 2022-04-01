#include <bits/stdc++.h>

struct Item
{
    int value, weight;
    Item(int value, int weight) : value(value), weight(weight)
    {
    }
};

bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, struct Item arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        std ::cout << arr[i].value << " \t" << arr[i].weight << "\t:\t"
                   << ((double)arr[i].value / arr[i].weight) << std ::endl;
    }

    std ::sort(arr, arr + n, cmp);
    int curWeight = 0;
    double finalvalue = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (curWeight + arr[i].weight <= W)
        {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
        }
        else
        {
            int remain = W - curWeight;
            finalvalue += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }
    }
    return finalvalue;
}

int main()
{
    int W = 50;
    Item arr[] = {{80, 10}, {10, 20}, {150, 30}, {90, 40}};
    int n = sizeof(arr) / sizeof(arr[0]);
    std ::cout << "Maximum value we can obtain =\n"
               << fractionalKnapsack(W, arr, n) << std ::endl;
    return 0;
}
