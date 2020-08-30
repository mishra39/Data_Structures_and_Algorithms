#include <iostream>
#include<algorithm>
using namespace std;


int maximumProfit(int budget[], int n) {
    sort(budget,budget+n);

    int mid = n/2;
	int cost[n];

	for (int i=0; i < n; i++)
	{
		cost[i] = budget[i]*(n-i);
	}

	for (int i = 1; i < n; i++)
	{
		if (cost[0] < cost[i])
		{
			cost[0] = cost[i];
		}
	}

	return cost[0];
}

int main() {
    int n ,*input,i,*cost;
    cin>>n;
    input = new int[n];
    for(i = 0;i < n;i++)
        cin>>input[i];
    
    cout << maximumProfit(input, n) << endl;
    
}