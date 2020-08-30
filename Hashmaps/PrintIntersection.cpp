#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

void pairSum(int *input, int n) 
{

	unordered_map<int, int> zeroSum;

	for (int i = 0; i < n; i++)
	{
		zeroSum[input[i]]++;
	}

	for (int i = 0; i < n; i++)
	{
		if (zeroSum[input[i]] && zeroSum[-input[i]])
		{
			for (int j = 0; j < (zeroSum[input[i]]*zeroSum[-input[i]]); j++)
			{
				cout << -input[i] << " " << input[i] << endl;
			}

			zeroSum[input[i]] = 0;
			zeroSum[-input[i]] = 0;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	pairSum(arr, n);

	delete[] arr;

	return 0;
}