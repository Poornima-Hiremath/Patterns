#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
void swap (vector<int> & vec, int i, int j)
{
	int temp = vec[i];
	vec[i] = vec[j];
	vec[j] = temp;
}

vector<int> FindFirstKMissingPositiveNumbers(vector<int> & vec, int k)
{
	int i = 0;
	while (i < vec.size())
	{
		if (vec[i] > 0 && vec[i] <= vec.size() && vec[i] != vec[vec[i]-1])
			swap(vec, i, vec[i]-1);
		else
			i++;
	}
	vector<int> v;
	//v.reserve(k);
	unordered_set<int> extraNums;
	for (int i =0; i < vec.size() && v.size() < k; i++)
	{
		if (vec[i] != i+1)
		{
			v.push_back(i+1);
			extraNums.insert(vec[i]);
		}
	}

	for (int i = 1; v.size() < k; i++)
	{
		int c = i + vec.size();
		if (extraNums.find(c) == extraNums.end())
			v.push_back(c);
	}
	return v;
}

int main ()
{
	vector<int> v {4, -1, 3, 5, 5};
	int i = 3;
	vector<int> vec = FindFirstKMissingPositiveNumbers(v, i);
	for (int  k = 0 ; k < i; k++ )
	{
		cout << vec[k];
	}
	return 0;
}	
