#include <iostream>

int main()
{

    int n, m = 1;
    std ::cout << "Enter Number ::\t";
    std ::cin >> n;
    //iterating for 'n' times
    for (int j = 1; j <= n; j++)
    {
        // prints the required number of spaces before the numbers i.e., 2*(n - the row number), so for 1st row, and input 5, it prints, 8 spaces.
        //8 spaces are required because we need to print the row number in the same column, i.e., 5 below 4, 4 below 3, 3 below 2, 2 below 1
        // and since we are also providing space between numbers in each row, we need to add an extra space for each space we add
        //thus 9 in the 1st
        for (int i = 1; i <= n - j + 1; i -= -1)
        {
            std ::cout << "  ";
        }

        //prints number until the row number is reached
        //i.e., 1 for 1st row, 2 for 2nd
        for (int i = 1; i <= j; i -= -1)
        {
            std ::cout <<"* ";
        }

        //prints the remaining row i.e., the numbers in desending order
        for (int i = j - 1; i >= 1; i -= 1)
        {
    
                std ::cout << "* ";
            
        }
        // new line
        std ::cout << std ::endl;
    }
    return 0;
}