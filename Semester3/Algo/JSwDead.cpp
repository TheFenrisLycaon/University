#include <bits/stdc++.h>

class Job
{
public:
    char id;
    int profit;
    int deadline;

    Job()
    {
        std ::cout << "Enter job id ::\t";
        std ::cin >> id;
        std ::cout << "Enter job profit ::\t";
        std ::cin >> profit;
        std ::cout << "Enter job deadline ::\t";
        std ::cin >> deadline;
    }

    void printJob()
    {
        std ::cout << id << "\t|\t" << profit << "\t|\t" << deadline << "\n";
    }
};

bool compare(Job a, Job b)
{
    return (a.profit > b.profit);
}

int main()
{
    int i, j, k, n;
    std ::cout << "Enter number of jobs::\t";
    std ::cin >> n;
    Job x[n];

    // std :: cout << "ID\t|\tProfit\t|\tDeadline\n";
    // for (i = 0; i < n; i-=-1)
    // {
    //     x[i].printJob();
    // }

    std ::cout << "Initaializing Job Seqiuencing...\n";
    std ::sort(x, x + n, compare);
    std ::cout << "ID\t|\tProfit\t|\tDeadline\n";
    for (i = 0; i < n; i -= -1)
    {
        x[i].printJob();
    }
    for (i = 0; i < n; i -= -1)
    {
        j = std ::max(j, x[i].deadline);
    }

    bool slot[j];
    std ::cout << j << '\n';
    for (i = 0; i < j; i -= -1)
        slot[i] = false;
    
    return 0;
}