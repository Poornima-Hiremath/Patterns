#include <iostream>
#include <vector>

using namespace std;

void swap (vector<int>& vec, int i, int j)
{
	int temp = vec[i];
	vec[i] = vec[j];
	vec[j] = temp;
}

vector<int> findCorruptPair(vector<int> & vec)
{
	int i =0;
	while (i < vec.size())
	{
		cout <<"in here" << endl;
		if (vec[i] != vec[vec[i]-1])
			swap(vec, i, vec[i]-1);
		else
			i++;
	}
	for (i = 0; i < vec.size(); i++)
	{
		if (vec[i] != i+1)
			return vector<int>{vec[i], i+1};
	}

	return vector<int>{-1, -1};
}

int main ()
{
	vector<int> vec{3, 1, 2, 5, 2};
	vector<int> p = findCorruptPair(vec);
	cout << p[0] << endl;
	cout << p[1] << endl;
	return 0;
}
