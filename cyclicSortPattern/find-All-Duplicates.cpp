/*

We are given an unsorted array containing ‘n’ numbers taken from the range 1 to ‘n’. The array has some duplicates, find all the duplicate numbers without using any extra space.

Example 1:

Input: [3, 4, 4, 5, 5]

Output: [4, 5]

*/

#include <iostream>
#include <vector>

using namespace std;


void swap (vector<int> &arr, int i , int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

vector<int> findAllDuplicateNumber(vector<int> & vec)
{
	int i = 0;
	vector<int> dups;
	while (i < vec.size())
	{
			if (vec[i] != vec[vec[i]-1])
				swap (vec, i, vec[i]-1);
			else 
				i++;

	}
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] != i+1)
			dups.push_back(vec[i]);
	}
	return dups;	
}

int main ()
{

	vector<int> v1 {5, 2, 1,4, 4, 1, 6, 7, 7};
	vector<int> res = findAllDuplicateNumber(v1);
	for (auto i : res)
		cout << i << "\t";
	cout << endl;
	return 0;
}
