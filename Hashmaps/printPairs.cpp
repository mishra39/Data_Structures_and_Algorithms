using namespace std;
#include<unordered_map>
#include<cstring>
#include <algorithm>
#include <vector>

void printPairs(int *input, int n, int k) {

	unordered_map<int, int> map;
	int count1=0;
	int count2=0;

	// insert elements
	for (int i = 0; i < n; i++)
	{
		map[input[i]]++;
	}

	for (int i = 0; i < n; i++)
	{
		int x = input[i];

		if (k==0)
		{
			for (int i = 0; i < map[x]*(map[x]-1); i++)
			{
				cout << x << " " << x << endl;
			}
		}

		if (x-k>=0 && map[x-k])
		{
			for (int i = 0; i < (map[x]*map[x-k]); i++)
			{
				cout << x-k << " " << x << endl;
			}
		}

		if (x-k < 10000 && map[x+k])
		{
			for (int i = 0; i < (map[x]*map[x+k]); i++)
			{
				cout << x << " " << x+k << endl;
			}
		}

		map[x] = 0;
	}
}
int main() {
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	int k;
	cin >> k;
	printPairs(input, n, k);
}
