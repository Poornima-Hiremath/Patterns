#include<iostream>
#include<vector>

using namespace std;

void swap (vector<int> & vec, int i , int j)
{
	int temp = vec[i];
	vec[i] = vec[j];
	vec[j] = temp;
}

int FindFirstPositiveMissingNumber(vector<int> &vec)
{
	int i = 0;
	while (i < vec.size() )
	{
		if (vec[i] > 0 && vec[i] <= vec.size() && vec[i] != vec[vec[i] - 1])
			swap (vec, i, vec[i]-1);
		else
			i++;
	}
	for (i = 0; i < vec.size(); i++)
	{
		if (vec[i] != i+1)
			return i+1;
	}
	return vec.size()+1;
}

int main ()
{

	vector<int> v {-3, 1, 5, 4, 2};
	cout << FindFirstPositiveMissingNumber(v) << endl;
	return 0;
}
