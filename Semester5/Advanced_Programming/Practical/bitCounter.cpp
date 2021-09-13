#include <bits/stdc++.h>

unsigned int countSetBits(int n)
{
	unsigned int count = 0;
	while (n)
	{
		n &= (n - 1);
		count++;
	}
	return count;
}

int main()
{
	int i = 101018;
	std ::cout << countSetBits(i) << std::endl;
	return 0;
}
