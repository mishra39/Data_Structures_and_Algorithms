#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

vector<int> removeDuplicates(int* a, int size)
{
	vector<int> output;
	unordered_map<int, bool> seen;

	for (int i = 0; i < size; i++)
	{
		if (seen.count(a[i]))
		{
			continue;
		}

			seen[a[i]] = true;
			output.push_back(a[i]);
	}

	return output;
}

int main()
{
	int a[] = {1,3,5,3,4,5,6,7,4,4,6,7,2};
	vector<int> output = removeDuplicates(a,13);

	for (int i = 0; i < output.size(); i++)
	{
		cout << output[i] << endl;
	}
}