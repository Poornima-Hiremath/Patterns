/*
Right View of Tree
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

class RightViewOfTree
{
public:

static vector<Node*> RightView(Node* head)
{
	vector<Node*> result;
	if (head == nullptr)
		return result;

	queue<Node*> q;
	q.push(head);
	while(!q.empty())
	{
		int levelSize = q.size();
		for (int i = 0; i<levelSize; i++)
		{
			Node* current = q.front();
			q.pop();
			if (i == levelSize-1)
				result.push_back(current);
			if (current->left!= nullptr)
				q.push(current->left);
			if (current->right!= nullptr)
				q.push(current->right);
		}
	}
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
	vector<Node*> result = RightViewOfTree::RightView(n);
	if (result.empty())
		cout << "Empty list" << endl;
	vector<Node*> result2 = RightViewOfTree::RightView(head);
	for (auto x:result2)
		cout << x->value << endl;
	return 0;
}
