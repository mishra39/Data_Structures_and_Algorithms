#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int buyTicket(int *arr, int n, int k)
{
	queue<int> q;
	priority_queue<int> pq;
	int ans=0;

	for (int i = 0; i < n; i++)
	{	
		q.push(i);
		pq.push(arr[i]);
	}

	while(!q.empty())
	{	
		if (q.front()==k && arr[q.front()]==pq.top())
		{
			ans++;
			return ans;
		}

		if (arr[q.front()]==pq.top())
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

	return 0;
}

int main(){
    int n, k, s;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> k;
    cout << buyTicket(arr, n, k) << endl;
}
