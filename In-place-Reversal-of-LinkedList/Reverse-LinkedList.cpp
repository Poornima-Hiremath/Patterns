#include<iostream>

using namespace std;

class Node
{
 public:
	int value;
	Node* next;
public:
Node(int val)
{
	cout << "Node ctor" << endl;
	this->value = val;
	this->next = nullptr;
}
static Node* ReverseLinkedList(Node* head)
{
	Node* current = head;
	Node* prev = nullptr;
	Node* next = nullptr;
	while(current!= nullptr)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}
~Node()
{
	cout << "Node dctor" << endl;
	if (this->next != nullptr)
		delete this->next;
}
};

int main ()
{
Node* head = new Node(1);
head->next = new Node(2);
head->next->next = new Node(3);
head->next->next->next = new Node(4);
head->next->next->next->next = new Node(5);
head->next->next->next->next->next = new Node(6);

Node* reversed = Node::ReverseLinkedList(head);
while (reversed != nullptr)
{
	cout << reversed->value << endl;
	reversed = reversed->next;
}

//delete head->next->next->next->next->next;
return 0;	
}
