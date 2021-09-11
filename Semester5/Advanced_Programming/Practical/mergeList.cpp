#include <iostream>

using namespace std;

struct Node
{
	int value;
	struct Node *next;
};

Node *reverse(Node *head)
{
	if (head->next == NULL)
		return head;
	Node *rest = reverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return rest;
}

Node *sortedMerge(Node *a, Node *b)
{
	a = reverse(a);
	b = reverse(b);
	Node *head = NULL;
	Node *temp;
	while (a != NULL && b != NULL)
	{
		if (a->value >= b->value)
		{
			temp = a->next;
			a->next = head;
			head = a;
			a = temp;
		}
		else
		{
			temp = b->next;
			b->next = head;
			head = b;
			b = temp;
		}
	}
	while (a != NULL)
	{
		temp = a->next;
		a->next = head;
		head = a;
		a = temp;
	}
	while (b != NULL)
	{
		temp = b->next;
		b->next = head;
		head = b;
		b = temp;
	}
	return head;
}

void printLL(struct Node *Node)
{
	while (Node != NULL)
	{
		cout << Node->value << " ";
		Node = Node->next;
	}
}

Node *newNode(int value)
{
	Node *temp = new Node;
	temp->value = value;
	temp->next = NULL;
	return temp;
}

int main()
{
	struct Node *res = NULL;
	Node *a = newNode(5);
	a->next = newNode(10);
	a->next->next = newNode(15);
	a->next->next->next = newNode(40);
	Node *b = newNode(2);
	b->next = newNode(3);
	b->next->next = newNode(20);
	cout << "List A before merge\t::\t";
	printLL(a);
	cout << "\nList B before merge\t::\t";
	printLL(b);
	res = sortedMerge(a, b);
	cout << "\nMerged Linked List is\t::\t";
	printLL(res);
	return 0;
}
