#include<iostream>

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

class ReverseEveryKSubList
{
public:
static Node* Reverse(Node* head, int k)
{

	if (k <= 1)
		return head;
	if (head == nullptr || head->next == nullptr)
		return head;

	Node* current = head;
	Node* prev = nullptr;
	while(true)
	{
		Node* LastNodePreviousSubList = prev;
		Node* LastNodeSubList = current;
		
		for (int i = 0; i < k && current!= nullptr; i++)
		{
			Node* next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		if (LastNodePreviousSubList != nullptr)
			LastNodePreviousSubList->next = prev;
		else
			head = prev;

		LastNodeSubList->next = current;
			

//		prev = LastNodeSubList;

		for (int i = 0; current!= nullptr && i< k; i++)
		{
			prev = current;
			current= current->next;
		}
		if (current == nullptr)
			break;

	}
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
	head->next->next->next->next->next->next = new Node(7);
	head->next->next->next->next->next->next->next = new Node(8);
	Node* reversed = ReverseEveryKSubList::Reverse(head, 3);
	while (reversed!= nullptr)
	{
		cout << reversed->value << endl;
		reversed = reversed->next;
	}
	return 0;
}
