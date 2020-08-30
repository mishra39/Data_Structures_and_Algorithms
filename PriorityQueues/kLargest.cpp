#include <queue>
#include <vector>
using namespace std;

vector<int> kLargest(int input[], int n, int k){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
	priority_queue <int> pq;
    vector<int> KLarge;
	for (int i = 0; i < n; i++)
	{
		pq.push(input[i]);
	}

	while(k--)
	{
		KLarge.push_back(pq.top());
		pq.pop();
	}

	return KLarge;
}

int main() {
	
	int size;
	cin >> size;
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
    
    int k;
    cin >> k;
    
    vector<int> output = kLargest(input, size, k);
    for(int i = 0; i < output.size(); i++)
        cout << output[i] << endl;
	
	return 0;
}
