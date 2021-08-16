#include <iostream>

int gcd(int a, int b)
{
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }

    return a;
}

int main()
{
    int a, b;
    std ::cout << "Enter two numbers ::\t";
    std ::cin >> a >> b;
    std::cout << "GCD(" << a << "," << b << ") =" << gcd(a, b)<< "\n";
    return 0;
}