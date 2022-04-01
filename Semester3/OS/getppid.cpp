// C++ Code to demonstrate getppid()
#include <iostream>
#include <unistd.h>
using namespace std;

// Driver Code
int main()
{
	int pid;
	pid = fork();
	if (pid == 0)
	{
		cout << "\nCurrent Process id : "
			 << getpid() << endl;
		cout << "\n parent id : "
			 << getppid() << endl;
	}
	return 0;
}
