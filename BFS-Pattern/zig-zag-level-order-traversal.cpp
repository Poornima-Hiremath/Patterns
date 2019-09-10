#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node
{
public:
	int value;
	Node* left;
	Node* right;
	
	Node (int val)
	{	
		this->value = val;
		this->left = this->right = nullptr;
	}
};

class LevelOrderTraversal
{
public:      	
static vector<vector<int>> LevelOrder(Node* head)
{
	bool leftToRight = true;
	vector<vector<int>> result;
	if (head == nullptr)
		return result;
	queue<Node*> q;
	q.push(head);
	while (!q.empty())
	{	
		int levelSize = q.size();
		vector<int> currentLevel(levelSize);
		for (int i = 0; i < levelSize; i ++)
		{
			Node* current = q.front();
			q.pop();
			if (leftToRight)
				currentLevel[i] = current->value;
			else
				currentLevel[levelSize-i-1] = current->value;
			if (current->left != nullptr)
				q.push(current->left);
			if (current->right != nullptr)
				q.push(current->right);
		}
		result.push_back(currentLevel);
		leftToRight = !leftToRight;
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
	vector<vector<int>> vec = LevelOrderTraversal::LevelOrder(head);
	for (auto i : vec)
	{
		for (auto j : i)
		{
			cout << j << endl;
		}
	}
	return 0;
}
