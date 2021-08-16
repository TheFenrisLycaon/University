#include <bits/stdc++.h>

template <typename T, typename R>
R add(T a, R b)
{
    return a + b;
}

int main(int argc, char *argv[])
{
    std::cout << "Hello World!" << std::endl;
    std::cout<< add(2,3)<<std::endl;
    std::cout<< add("2", "3")<<std::endl;
    std::cout << add(2.0, 2.43) << std::endl;
    return 0;
}