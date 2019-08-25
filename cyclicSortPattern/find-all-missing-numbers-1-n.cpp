/*
We are given an array containing ‘n’ distinct numbers taken from the range 0 to ‘n’. Since the array has only ‘n’ numbers out of the total ‘n+1’ numbers, find the missing number.

Example 1:

Input: [4, 0, 3, 1]

Output: 2
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


vector<int> findMisisngNumber(vector<int> & vec)
{
	int i = 0;
	vector<int> result;
	while (i < vec.size())
	{

	if (vec[i] != vec[vec[i]-1])
		swap(vec, i, vec[i]-1);
	else
		i++;
	}
	for (i = 0; i < vec.size(); i ++)
	{	
		if (vec[i] != i+1)
			result.push_back(i+1);
	}
	return result;
}

int main ()
{

	vector<int> v1 {5, 2, 1, 3, 4};
	vector<int> res = findMisisngNumber(v1);
	for (int i : res)
		cout << i << "\t";
	cout << endl;
	return 0;
}
