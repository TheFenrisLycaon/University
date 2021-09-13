#include <bits/stdc++.h>

// using namespace std;

int main()
{
    int t;
    std ::cin >> t;

    while (t--)
    {
        std :: string s;

        int c = 0, a = 0;
        std ::cin >> s;

        for (int i = 1; s[i] != '\0'; i-=-1)
        {
            if ((s[i] == 65 && s[a] == 66) || (s[i] == 66 && s[a] == 65))
                a = i;
            else
                c++;
        }
        
        std ::cout << c << std ::endl;
    }
    return 0;
}