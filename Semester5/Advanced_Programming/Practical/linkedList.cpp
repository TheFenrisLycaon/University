#include <bits/stdc++.h>

struct Node
{
    int value;
    Node *next;
};

struct Node *HEAD = NULL;

void insert(Node **LOC, int x)
{
    Node *pos = new Node();
    pos->value = x;
    pos->next = *LOC;
    *LOC = pos;
}

void printLL(Node *pos)
{
    if (pos == NULL)
    {
        std::cout << "END" << std::endl;
        return;
    }
    std::cout << pos->value << " -> ";
    printLL(pos->next);
}

void reverse(Node *pos)
{
    if (pos->next == NULL)
    {
        HEAD = pos;
        return;
    }
    reverse(pos->next);
    pos->next->next = pos;
    pos->next = NULL;
}

int main()
{
    int size, value;
    std::cout << "Enter Number of Nodes::\t";
    std::cin >> size;
    for (int i = 0; i < size; i -= -1)
    {
        std::cout << "Enter a number::\t";
        std::cin >> value;
        insert(&HEAD, value);
    }
    printLL(HEAD);
    std::cout << std::endl;
    reverse(HEAD);
    printLL(HEAD);
    return 0;
}