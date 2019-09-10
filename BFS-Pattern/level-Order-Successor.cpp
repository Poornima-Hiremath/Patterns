/*
Given a binary tree and a node, find the level order successor of the given node in the tree. The level order successor is the node that appears right after the given node in the level order traversal.
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

	Node(int val)
	{
		this->value = val;
	}
};

class levelOrderSuccessor
{
public:
	static Node* levelSuccessor(Node* root, int key)
	{
		if (root == nullptr)
			return nullptr;
		queue<Node*> q;
		q.push(root);
		while (!q.empty())
		{
			Node* currentNode = q.front();
			q.pop();

			if (currentNode->left != nullptr)
				q.push(currentNode->left);

			if (currentNode->right != nullptr)
				q.push(currentNode->right);

			if(currentNode->value == key)
				break;
		}
		return q.front();
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
	Node* successor = levelOrderSuccessor::levelSuccessor(head, 9);
	if(successor)
	cout << successor->value<< endl;
	else
	cout << "No successor" << endl;
	return 0;
}
