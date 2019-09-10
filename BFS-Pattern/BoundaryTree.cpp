/*
Given a binary tree, return an array containing all the boundary nodes of the tree in an anti-clockwise direction.
The boundary of a tree contains all nodes in the left view, all leaves, and all nodes in the right view. Please note that there should not be any duplicate nodes. For example, the root is only included in the left view; similarly, if a level has only one node we should include it in the left view.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class Node
{
public:
	int value{0};
	Node *left{nullptr};
	Node *right{nullptr};
	Node(int val)
	{
		this->value = val;
	}
};

class BoundaryOfTree
{
public:

static vector<Node*> FindLeaves(Node* root)
{
	vector<Node*> result;
	if (root == nullptr)
		return result;

	stack<Node*> st;
	st.push(root);
	while(!st.empty())
	{
		Node* currentNode = st.top();
		st.pop();
		if (currentNode->left == nullptr && currentNode->right == nullptr)
			result.push_back(currentNode);
		if (currentNode->right != nullptr)
			st.push(currentNode->right);

		if (currentNode->left != nullptr)
			st.push(currentNode->left);
	}
	return result;
}


static vector<Node*> FindBoundary(Node* root)
{
	vector<Node*> result;
	if (root == nullptr)
		return result;

	vector<Node*> leftView;
	deque<Node*> rightView;

	queue<Node*> q;
	q.push(root);

	while (!q.empty())
	{
		int levelSize = q.size();
		for (int i = 0; i < levelSize ; i++)
		{
			Node* currentNode = q.front();
			q.pop();
			if (currentNode->left == nullptr && currentNode->right == nullptr)
				continue;
			if (i == 0)
				leftView.push_back(currentNode);
			else if (i == levelSize -1)
				rightView.push_front(currentNode);

			else
			{ }
			if (currentNode->left != nullptr)
				q.push(currentNode->left);

			if (currentNode->right != nullptr)
				q.push(currentNode->right);
		}
	}
	vector<Node*> Leaves = FindLeaves(root);
	result.insert(result.end(),leftView.begin(), leftView.end());
	result.insert(result.end(), Leaves.begin(), Leaves.end());
	copy(rightView.begin(), rightView.end(), back_inserter(result));

	return result;
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
	vector<Node*> result = BoundaryOfTree::FindBoundary(n);
	if (result.empty())
		cout << "Empty list" << endl;
	vector<Node*> result2 = BoundaryOfTree::FindBoundary(head);
	for (auto x:result2)
		cout << x->value << endl;
	return 0;
}	
