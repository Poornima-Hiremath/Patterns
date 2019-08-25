#include <iostream>
#include <vector>

using namespace std;

void swap (vector<int> &arr, int i , int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
void cyclicSort(vector<int> &arr)
{
	int i =0;
	while (i < arr.size())
	{

		if (arr[i] != arr[arr[i]-1])
			swap (arr, i, arr[i]-1);
		else
			i++;
	}
}


int main ()
{

	//vector<int> v1 {1, 2, 3, 4, 5};
	vector<int> v1 {5, 2, 1,4, 3};
	cyclicSort(v1);
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << "\t";
	cout << endl;
	return 0;
}
	
