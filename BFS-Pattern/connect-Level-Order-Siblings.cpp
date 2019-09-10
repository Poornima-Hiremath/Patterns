/*
Given a binary tree, connect each node with its level order successor. The last node of each level should point to a null node.
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

class levelOrderConnector
{
public:

static void levelOrderConnect(Node* head)
{
	if (head == nullptr)
		return;

	std::queue<Node*> q;
	q.push(head);
	while(!q.empty())
	{
		int levelSize = q.size();
		Node* prev= nullptr;
		for (int i= 0; i < levelSize; i++)
		{
			Node* current = q.front();
			q.pop();

			if (prev != nullptr)
			{
				prev->next = current;
			}
			prev = current;

			if (current->left != nullptr)
				q.push(current->left);
			if (current->right != nullptr)
				q.push(current->right);
		}
	}
}

static void levelOrderConnectPrinter(Node* head)
{
	Node* NextLevelNode = head;
	while(NextLevelNode)
	{
		Node* currentNode = NextLevelNode;
		NextLevelNode = nullptr;
		while(currentNode)
		{
			cout << currentNode->value << endl;
			if (NextLevelNode == nullptr)
			{
				if (currentNode->left != nullptr)
					NextLevelNode = currentNode->left;
				else if (currentNode->right != nullptr)
					NextLevelNode = currentNode->right;	
			}
			currentNode = currentNode->next;
		}
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
	levelOrderConnector::levelOrderConnect(head);
	levelOrderConnector::levelOrderConnectPrinter(head);
	return 0;
}
