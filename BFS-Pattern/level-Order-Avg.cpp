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
	
	Node (int val)
	{
		this->value = val;
	}

};

class levelAvg
{
public :
	static vector<float> levelAvgTraversal(Node* head)
	{
		vector<float> result;
		if (head == nullptr)
			return result;

		std::queue<Node*> q;
		q.push(head);
		while (!q.empty())
		{
			int levelSize = q.size();
			float levelSum {0};
			for (int i = 0; i < levelSize; i++)
			{
				Node* currentNode = q.front();
				q.pop();
				levelSum += currentNode->value;
				if (currentNode->left != nullptr)
					q.push(currentNode->left);
				if (currentNode->right != nullptr)
					q.push(currentNode->right);
			}
			result.push_back(levelSum/levelSize);
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
	vector<float>vec = levelAvg::levelAvgTraversal(head);
	for (auto i : vec)
	{
		cout << i << endl;
	}
	return 0;
}
