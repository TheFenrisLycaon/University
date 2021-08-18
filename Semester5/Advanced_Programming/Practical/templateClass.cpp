#include <bits/stdc++.h>

template <class T>
class Gradebook
{
public:
    T a, b;

    Gradebook(T x, T y)
    {
        a = x;
        b = y;
    }

    void print()
    {
        std::cout << a << "\t| " << b << std::endl;
    }
};

int main()
{
    Gradebook<int> rishabh(3, 50);
    Gradebook<float> anand(7, 55.6);
    rishabh.print();
    anand.print();
    return 0;
}