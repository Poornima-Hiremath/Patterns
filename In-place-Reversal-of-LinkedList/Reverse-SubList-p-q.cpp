#include <iostream>

using namespace std;

class Node {
public :
	int value;
	Node* next;

	Node(int val)
	{
		this->value = val;
		this->next = nullptr;
	}
};

class ReverseSubList {
public:
static Node* Reverse(Node* head, int p, int q)
{
	if (head == nullptr && head->next == nullptr)
	{
		return head;
	}
	if (p == q)
		return head;
	Node* current = head;
	Node* prev = nullptr;

	//Move p-1 nodes ahead
	for (int i = 0; current != nullptr && i<p-1; i++)
	{
		prev = current;
		current = current->next;
	}
	Node* lastNodeOfPreviousList = prev;
	Node* lastNodeOfSubList = current;
	Node* next = nullptr;
	for (int i = 0; current != nullptr && i < q-p+1; i++)
	{
		next = current->next;
		current->next = prev;
		prev= current;
		current = next;
	}
	if (lastNodeOfPreviousList != nullptr)
		lastNodeOfPreviousList->next = prev;
	else
		head = prev;

	lastNodeOfSubList->next = current;
	return head;
}
};
int main()
{
	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);
	head->next->next->next->next->next = new Node(6);
	Node* reversed = ReverseSubList::Reverse(head, 2, 5);
	while (reversed!= nullptr)
	{
		cout << reversed->value << endl;
		reversed = reversed->next;
	}
	return 0;
}
