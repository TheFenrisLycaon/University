#include <iostream>

using namespace std;

struct Node
{
	int value;
	struct Node *next;
};

Node *addition(Node *temp1, Node *temp2, int size1,
			   int size2)
{
	Node *temp = (struct Node *)malloc(sizeof(struct Node));
	if (temp1->next == NULL && temp2->next == NULL)
	{
		temp->value = (temp1->value + temp2->value);
		temp->next = NULL;
		return temp;
	}
	Node *returnedNode = (struct Node *)malloc(sizeof(struct Node));
	if (size2 == size1)
	{
		returnedNode = addition(temp1->next, temp2->next,
								size1 - 1, size2 - 1);
		temp->value = (temp1->value + temp2->value) + ((returnedNode->value) / 10);
	}
	else
	{
		returnedNode = addition(temp1, temp2->next, size1,
								size2 - 1);
		temp->value = (temp2->value) + ((returnedNode->value) / 10);
	}
	returnedNode->value = (returnedNode->value) % 10;
	temp->next = returnedNode;
	return temp;
}

struct Node *sumList(struct Node *HEAD1,
					 struct Node *HEAD2)
{
	struct Node *temp1, *temp2, *ans = NULL;
	temp1 = HEAD1;
	temp2 = HEAD2;
	int size1 = 0, size2 = 0;
	while (temp1 != NULL)
	{
		temp1 = temp1->next;
		size1++;
	}
	while (temp2 != NULL)
	{
		temp2 = temp2->next;
		size2++;
	}
	Node *returnedNode = (struct Node *)malloc(sizeof(struct Node));
	if (size2 > size1)
	{
		returnedNode = addition(HEAD1, HEAD2, size1, size2);
	}
	else
	{
		returnedNode = addition(HEAD2, HEAD1, size2, size1);
	}
	if (returnedNode->value >= 10)
	{
		ans = (struct Node *)malloc(sizeof(struct Node));
		ans->value = (returnedNode->value) / 10;
		returnedNode->value = returnedNode->value % 10;
		ans->next = returnedNode;
	}
	else
		ans = returnedNode;
	return ans;
}

void printLL(Node *HEAD)
{
	if (HEAD == NULL)
	{
		return;
	}
	while (HEAD->next != NULL)
	{
		cout << HEAD->value << " -> ";
		HEAD = HEAD->next;
	}
	cout << HEAD->value << endl;
}

void insert(Node **HEAD, int d)
{
	Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->value = d;
	temp->next = NULL;
	if (*HEAD == NULL)
	{
		temp->next = *HEAD;
		*HEAD = temp;
		return;
	}
	Node *last = *HEAD;
	while (last->next != NULL && last != NULL)
	{
		last = last->next;
	}
	last->next = temp;
	return;
}

int main()
{
	Node *first = NULL;
	Node *second = NULL;
	Node *sum = NULL;
	insert(&first, 5);
	insert(&first, 6);
	insert(&first, 3);
	insert(&second, 8);
	insert(&second, 4);
	insert(&second, 2);
	cout << "First List\t::\t";
	printLL(first);
	cout << "Second List\t::\t";
	printLL(second);
	sum = sumList(first, second);
	cout << "Sum List\t::\t";
	printLL(sum);
	return 0;
}
