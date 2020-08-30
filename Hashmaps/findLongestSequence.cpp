#include <iostream>
using namespace std;
#include<unordered_map>
#include<cstring>
#include <vector>

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
	unordered_map <int, bool> map;

	for (int i = 0; i < n; i++)
	{
		map[arr[i]]++;
	}
}

int main() {

	char input[1000000];
	cin >> input;
	cout << uniqueChar(input) << endl;
}
