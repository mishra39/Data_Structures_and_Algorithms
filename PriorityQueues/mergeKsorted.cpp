#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, pair<int, int>> triplet;

vector<int> mergeKSortedArrays(vector<vector<int>*> input){

	queue<int> q;
	priority_queue<triplet, vector<triplet>, greater<triplet> > pq;
	vector<int>output;
	int ans;

	for (int i = 0; i < n; i++)
	{	
		q.push(i);
		pq.push(arr[i]);
	}

	while(!q.empty())
	{
		if (q.front()==pq.top())
		{
			ans++;
			q.pop();
			pq.pop();
		}

		else
		{
			int temp = q.front();
			q.pop();
			q.push(temp);
		}
	}

}
int main(){
    int n, k, s;
    vector<int> arr;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>s;
        arr.push_back(s);
    }
    cin >> k;
    cout << kthLargest(arr, n, k) << endl;
}