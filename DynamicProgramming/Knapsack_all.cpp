#include <iostream>
#include <vector>
#include <climits>
#include <bits/stdc++.h>
#include <cmath>
#include <string>
using namespace std;

int knapsack(int* weights, int* values, int n, int maxWeight){

	// Base Case
	if(n==0 || maxWeight==0)
	{
		return 0;
	}	

	if (weights[0] > maxWeight)
	{
		return knapsack(weights+1, values+1, n-1, maxWeight);
	}

	// Recursive Calls
	int x = knapsack(weights+1, values+1, n-1, maxWeight - weights[0]) + values[0];
	int y = knapsack(weights+1, values+1, n-1, maxWeight);

	return max(x,y);
}

int knapsack_DP(int* weights, int* values, int n, int maxWeight){
	int i,w;
	int **output = new int*[n+1];

	for (int i=0; i<=n; i++)
	{
		output[i] = new int[maxWeight];
	}

	for (int i = 0; i <= n; i++)
	{
		for (int j=0; j<= maxWeight; j++)
		{
			if (i==0 || j==0)
			{
				output[i][j] = 0;
			}

			else if (weights[i-1] <= j)
			{
				output[i][j] = max(values[i-1]+output[i-1][j-weights[i-1]],output[i-1][j]);
			}

			else
			{
				output[i][j] = output[i-1][j];
			}
		}
	}

	return output[n][maxWeight];
}

int main() 
{
	int n; 
	cin >> n;
	int* weights = new int[n];
	int* values = new int[n];

	for(int i = 0; i < n; i++){
		cin >> weights[i];
	}

	for(int i = 0; i < n; i++){
		cin >> values[i];
	}

	int maxWeight;
	cin >> maxWeight;

	cout << knapsack(weights, values, n, maxWeight) << endl;
	cout << knapsack_DP(weights, values, n, maxWeight) << endl;
}