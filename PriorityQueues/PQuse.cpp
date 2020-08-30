#include <iostream>
#include <queue>
using namespace std;

void kSortedArray(int input[], int n, int k)
{
	priority_queue<int> pq;

	for (int i = 0; i < k; i++)
	{
		pq.push(input[i]);
	}

	int j = 0;
	for (int i = k; i < n; i++)
	{
		input[j] = pq.top();
		pq.pop();
		pq.push(input[i]);
		j++;
	}

	while(!pq.empty())
	{
		input[j] = pq.top;
		pq.pop();
		j++;
	}



int int main(int argc, char const *argv[])
{
	int input[] = {10,12,124, 3, 2};
	int k = 3;
	kSortedArray(input, 5, k);
	for (int i = 0; i < 5; i++)
	{
		cout << input[i] << " ";
	}
	return 0;
}