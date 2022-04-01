#include <bits/stdc++.h>
using namespace std;
bool compare(int a, int b)
{
	return a > b;
}
int main()
{
	int array[2][100], t, n, w, i, ratio[100];
	cout << "Enter total number of bags we want:";
	cin >> t;
	while (t-- > 0)
	{
		cout << "Enter number of objects:";
		cin >> n;
		cout << "Enter weight of knapsack:";
		cin >> w;

		for (i = 1; i <= n; i++)
		{
			cin >> array[0][i] >> array[1][i];
		}

		for (i = 1; i <= n; i++)
		{
			ratio[i] = double(array[0][i] / array[1][i]);
		}

		// sort the ratio array in decreasing order

		sort(ratio, ratio + n, compare);

		double maxprofit = 0;
		int i = 0;

		while (i < n && w != 0)
		{
			if (array[1][i] <= w)
			{
				maxprofit += array[0][i];
				w -= array[1][i];
			}
			else
			{
				maxprofit = double(array[0][i] * (w / array[0][i]));
				break;
			}
			i++;
		}
		cout << maxprofit << endl;
	}
}