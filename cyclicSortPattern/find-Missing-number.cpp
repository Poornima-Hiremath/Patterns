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


int findMisisngNumber(vector<int> & vec)
{
	int i = 0;
	while (i < vec.size())
	{

	if (vec[i] < vec.size() && vec[i] != vec[vec[i]])
		swap(vec, i, vec[i]);
	else
		i++;
	}
	for (i = 0; i < vec.size(); i ++)
	{	
		if (vec[i] != i)
			return i;
	}
	return -1;
}

int main ()
{

	vector<int> v1 {5, 2, 1,0, 3};
	cout << findMisisngNumber(v1) << "\t" << endl;
	return 0;
}
