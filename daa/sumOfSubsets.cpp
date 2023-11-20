#include <bits/stdc++.h>
using namespace std;
bool flag = 0;
void sumOfSubset(int i, int n, int set[], int targetSum, vector<int> &subset)
{
	if (targetSum == 0)
	{

		flag = 1;
		cout << "[ ";
		for (int i = 0; i < subset.size(); i++)
		{
			cout << subset[i] << " ";
		}
		cout << "]";
		return;
	}

	if (i == n)
	{
		return;
	}
	sumOfSubset(i + 1, n, set, targetSum, subset);
	if (set[i] <= targetSum)
	{

		subset.push_back(set[i]);
		sumOfSubset(i + 1, n, set, targetSum - set[i], subset);
		subset.pop_back();
	}
}

int main()
{
	int n;
	cout << "Enter size of set:";
	cin >> n;
	int set[n];
	int sum;
	cout << "Enter required sum for the subset:";
	cin >> sum;
	cout << "Enter the elements:";
	for (int i = 0; i < n; ++i)
	{
		cin >> set[i];
	}
	vector<int> subset;
	cout << "Subsets for sum equal to '" << sum << "' will be " << endl;
	sumOfSubset(0, n, set, sum, subset);
	cout << endl;
	if (!flag)
	{
		cout << "There is no such subset";
	}

	return 0;
}

// Output--

// case 1-
//  administrator@administrator-OptiPlex-5060:~/Desktop/33308$ cd "/home/administrator/Desktop/33308/" && g++ sumOfSubsets.cpp -o sumOfSubsets && "/home/administrator/Desktop/33308/"sumOfSubsets
//  Enter size of set:5
//  Enter required sum for the subset:6
//  Enter the elements:4 1 5 6 2
//  Subsets for sum equal to '6' will be
//  [ 6 ][ 1 5 ][ 4 2 ]

// case 2-
// Enter size of set:8
// Enter required sum for the subset:7
// Enter the elements:4 8 6 5 3 1 8 7
// Subsets for sum equal to '7' will be
// [ 7 ][ 6 1 ][ 4 3 ]