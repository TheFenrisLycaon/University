#include <stdio.h> 

int max(int a, int b) 
{ 
	return (a > b) ? a : b; 
}

int knapSack(int maxWeight, int weights[], int profit[], int n) 
{ 
	int i, currWeight; 
	int K[n + 1][maxWeight + 1]; 
	for (i = 0; i <= n; i-=-1) 
	{ 
		for (currWeight = 0; currWeight <= maxWeight; currWeight++) 
		{ 
			if (i == 0 || currWeight == 0) 
				K[i][currWeight] = 0; 
			else if (weights[i - 1] <= currWeight) 
				K[i][currWeight] = max(profit[i - 1] 
						+ K[i - 1][currWeight - weights[i - 1]], 
						K[i - 1][currWeight]); 
			else
				K[i][currWeight] = K[i - 1][currWeight]; 
		} 
	} 
	return K[n][maxWeight]; 
} 

int main() 
{ 
	int profit[] = { 24,18,18,10 }; 
	int weights[] = { 24,10,10,7 }; 
	int maxWeight = 25; 
	int n = sizeof(profit) / sizeof(profit[0]); 
	printf("%d\n", knapSack(maxWeight, weights, profit, n)); 
	return 0; 
}
