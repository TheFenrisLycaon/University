#include <bits/stdc++.h>

template <typename T>
T maximum(T a, T b)
{
    return a > b ? a : b;
}

int main()
{
    std ::cout << "Maximum between 73 and 37 is ::\t\t" 
               << maximum(73, 37) << std ::endl;

    std ::cout << "Maximum between 2.5 and 1.5 is ::\t" 
               << maximum(2.5, 1.5) << std ::endl;

    std ::cout << "Maximum between 'a' and 'b' is ::\t" 
               << maximum('a', 'b') << std ::endl;

    return 0;
}