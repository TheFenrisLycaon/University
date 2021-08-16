#include <iostream>

extern "C" int _stdcall PROCEDURE1( int);

int main()
{
    char dest[100] = {0};
    char* source = "Enter a number";
    char* source1 = "The number is prime";
    char* source2 = "Tne number is not prime";

    int test1 = 7;
    int prime = PROCEDURE1(test1);

    if(prime == 1)
        printf("%s\n",source1);
    else
        printf("%s\n",source2);

    return 0;
}
