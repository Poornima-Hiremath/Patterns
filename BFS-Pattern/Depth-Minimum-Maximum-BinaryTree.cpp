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

class MinMaxDepthOfTree
{
public:
	static int MinimumDepthOfTree(Node* root)
	{
		if (root == nullptr)
			return 0;

		int minimumDepth{0};
		std::queue<Node*> q;
		q.push(root);
		while(!q.empty())
		{
			minimumDepth++;
			int levelSize = q.size();
			for(int i = 0; i < levelSize; i++)
			{
				Node* currentNode = q.front();
				q.pop();
				if (currentNode->left == nullptr && currentNode->right == nullptr)
					return minimumDepth;
				if (currentNode->left != nullptr)
					q.push(currentNode->left);
				if (currentNode->right != nullptr)
					q.push(currentNode->right);
			}
		}
	}

	static int MaximumDepthOfTree(Node* root)
	{
		if (root == nullptr)
			return 0;

		int MaximumDepth{0};
		std::queue<Node*> q;
		q.push(root);
		while(!q.empty())
		{
			MaximumDepth++;
			int levelSize = q.size();
			for(int i = 0; i < levelSize; i++)
			{
				Node* currentNode = q.front();
				q.pop();

				if (currentNode->left != nullptr)
					q.push(currentNode->left);
				if (currentNode->right != nullptr)
					q.push(currentNode->right);
			}
		}
		return MaximumDepth;
	}

};

int main ()
{
	
	Node* head = new Node(1);
	head->left = new Node(2);
	head->right = new Node(3);
	//head->left->left = new Node(4);
	//head->left->right = new Node(5);
	head->right->right = new Node(9);
	cout << MinMaxDepthOfTree::MinimumDepthOfTree(head) << endl;
	cout << MinMaxDepthOfTree::MaximumDepthOfTree(head) << endl;
	return 0;
}
