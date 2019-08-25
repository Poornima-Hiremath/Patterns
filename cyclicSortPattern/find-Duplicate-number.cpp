/*

We are given an unsorted array containing ‘n+1’ numbers taken from the range 1 to ‘n’. The array has only one duplicate but it can be repeated multiple times. Find that duplicate number without using any extra space. You are, however, allowed to modify the input array.

Example 1:

Input: [1, 4, 4, 3, 2]

Output: 4

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

int findDuplicateNumber(vector<int> & vec)
{
	int i = 0;
	while (i < vec.size())
	{
		if (vec[i] != i+1)
		{
			if (vec[i] != vec[vec[i]-1])
				swap (vec, i, vec[i]-1);
			else 
				return vec[i];
		}
		else
		{
			i++;
		}
	}
	return -1;	
}

int main ()
{

	vector<int> v1 {5, 2, 1,4, 3};
	cout << findDuplicateNumber(v1) << "\t" << endl;
	return 0;
}
