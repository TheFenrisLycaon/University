#include <iostream>

int gcd(int a, int b)
{
    if (a == 0)
        return b;

    return gcd(b % a, a);
}

int main()
{
    int a, b;
    std ::cout << "Enter two numbers ::\t";
    std ::cin >> a >> b;
    std::cout << "GCD(" << a << "," << b << ") =" << gcd(a, b) << "\n";
    return 0;
}