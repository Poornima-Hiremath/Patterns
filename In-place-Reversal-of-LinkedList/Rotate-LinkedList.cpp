/*
Given the head of a Singly LinkedList and a number ‘k’, rotate the LinkedList to the right by ‘k’ nodes.
*/

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

class RotateRightByK
{
public:
static Node* Rotate(Node* head, int k)
{

	if (head == nullptr && head->next == nullptr && k <= 0)
		return head;
	//Find length of list
	int length = 1;
	Node* lastNode = head;
	while (lastNode->next != nullptr)
	{
		length ++;
		lastNode= lastNode->next;
	}
	lastNode->next = head;

	int rotations = length % k;
	int skipLength = length - rotations;
	//skip to skiplength-1 nodes
	lastNode = head;
	for (int i = 1; i < skipLength-1; i ++)
	{
		lastNode = lastNode->next;
	}
	head = lastNode->next;
	lastNode->next = nullptr;
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
	Node* reversed = RotateRightByK::Rotate(head, 3);
	while (reversed!= nullptr)
	{
		cout << reversed->value << endl;
		reversed = reversed->next;
	}
	return 0;
}
