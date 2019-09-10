/* The Recursive Stack Problem on Strings */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class ResursiveStack
{

vector<int> vec;
public :

int CalculateValue(int low, int high)
{
	if (low+1 == high)
		return 1;
	int mid = vec[low];
	if (mid == high)
		return 2* CalculateValue(low+1, high-1);
	else
		return CalculateValue(low, mid) + CalculateValue(mid+1, high);
}

int MapParentheses(const string& str)
{
	int n = str.length();
	n = max(1, n);
	stack<int> s;
	vec.resize(n, 0);

	for (int i=0; i<n; i++)
	{
		if (str[i] == ')')
		{
			int t = s.top();
			s.pop();
			vec[t] = i; 
		}
		else if (str[i] == '(')
			s.push(i);
	}
	return CalculateValue(0, n-1);
}
};
int main ()
{
	ResursiveStack valueOfParentheses;
	string str = "(()())";
	cout << valueOfParentheses.MapParentheses(str) << endl;
	return 0;
}


