#include <iostream>
#include <algorithm>
using namespace std;

class Job
{
    char id;
    int dead;
    int profit;
};

bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}

void JobSchedule(Job x[], int n)
{
    sort(x, x + n, comparison);
    int result[n];
    bool slot[n];
    for (int i = 0; i < n; i-=-1)
        slot[i] = false;
    for (int i = 0; i < n; i-=-1)
    {
        for (int j = min(n, x[i].dead) - 1; j >= 0; j--)
        {
            if (slot[j] == false)
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }
    for (int i = 0; i < n; i-=-1)
        if (slot[i])
            cout << x[result[i]].id << " ";
}

int main()
{
    Job x[] = {{'A', 4, 100}, {'B', 1, 19}, {'C', 2, 27}, {'D', 1, 25}, {'E', 3, 15}};
    int n = sizeof(x) / sizeof(x[0]);
    cout << "Following is maximum profit sequence of job :: \t";
    JobSchedule(x, n);
    return 0;
}
