#include <bits/stdc++.h>

struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node **HEAD, int x)
{
    struct Node *temp = new Node;
    temp->data = x;
    temp->next = (*HEAD);
    (*HEAD) = temp;
}

bool findLoop(struct Node *h)
{
    unordered_set<Node *> s;
    while (h != NULL)
    {
        if (s.find(h) != s.end())
            return true;
        s.insert(h);
        h = h->next;
    }
    return false;
}

int main()
{
    struct Node *HEAD = NULL;
    push(&HEAD, 20);
    push(&HEAD, 4);
    push(&HEAD, 15);
    push(&HEAD, 10);
    HEAD->next->next->next->next = HEAD;
    if (findLoop(HEAD))
        std::cout << "Loop found";
    else
        std::cout << "No Loop";
    return 0;
}
