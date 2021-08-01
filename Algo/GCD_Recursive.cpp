#include <iostream>

int gcd(int a, int b)
{
    if (a == 0) 
        return b;
    if (b == 0)
        return a;
    if (a == b) 
        return a;
    if (a > b) 
        return gcd(a - b, b);
    return gcd(a, b - a);
};

int main()
{
    int a, b;
    std ::cout << "Enter two numbers ::\t";
    std ::cin >> a >> b;
    std::cout << "GCD(" << a << "," << b << ") =" << gcd(a, b)<< "\n";
    return 0;
}