/*

Given a binary tree, connect each node with its level order successor. The last node of each level should point to the first node of the next level.

*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node
{
public :
	int value{0};
	Node* left{nullptr};
	Node* right{nullptr};
	Node* next{nullptr};

	Node(int val)
	{
		this->value = val;
	}
};

class AlllevelOrderConnector
{
public:

static void AlllevelOrderConnectPrinter(Node* head)
{
	if (head == nullptr)
	{
		cout << "Empty list" << endl;
		return;
	}

	Node* current = head;
	while(current != nullptr)
	{
		cout << current->value << endl;
		current= current->next;
	}
}


static void AlllevelOrderConnect(Node* head)
{
	if (head == nullptr)
		return;

	std::queue<Node*> q;
	Node* current = head;
	Node* previous = nullptr;
	q.push(current);
	while (!q.empty())
	{
		current = q.front();
		q.pop();
		//cout << current->value << endl;
		if (previous != nullptr)
			previous->next = current;
		previous = current;
		if (current->left != nullptr)
			q.push(current->left);
		if (current->right != nullptr)
			q.push(current->right);
	}
}

};

int main ()
{
	
	Node* head = new Node(1);
	head->left = new Node(2);
	head->right = new Node(3);
	head->left->left = new Node(4);
	head->left->right = new Node(5);
	head->right->right = new Node(9);
	Node* n = nullptr;
	AlllevelOrderConnector::AlllevelOrderConnect(n);
	AlllevelOrderConnector::AlllevelOrderConnectPrinter(n);

	AlllevelOrderConnector::AlllevelOrderConnect(head);
	AlllevelOrderConnector::AlllevelOrderConnectPrinter(head);
	return 0;
}
