#include <queue>
#include <vector>
using namespace std;

vector<int> kSmallest(int *input, int n, int k) {
    priority_queue <int, vector<int>, greater<int>> pq;
	
	vector<int> Ksmall;
	for (int i = 0; i < n; i++)
	{
		pq.push(input[i]);
	}

	while(k--)
	{
		Ksmall.push_back(pq.top());
		pq.pop();
	}

	return Ksmall;
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