#include <iostream>
#include <vector>
#include <climits>
#include <bits/stdc++.h>
using namespace std;

int minCostPath(int **input, int m, int n, int i, int j) {

    // Base Case
    if (i == m-1 &&  j ==n-1)
    {
        return input[i][j];
    }

    if (i>=m || j>=n)
    {
        return INT_MAX;
    }
    // Recursive Calls
    int cost1 = minCostPath(input,m,n,i,j+1);
    int cost2 = minCostPath(input,m,n,i+1,j+1);
    int cost3 = minCostPath(input,m,n,i+1,j);

    // Small calc
    int ans = min(cost1,min(cost2,cost3))+input[i][j];

    return ans;
}

int minCostPath(int **input, int m, int n) {

    return minCostPath(input,m,n,0,0);
}

int main(int argc, char const *argv[])
{   
    int m,n;
    cin >> m;
    cin >> n;

    int **input = new int*[m];
    for (int i = 0; i < m; i++)
    {
        input[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> input[i][j];
        }
    }

    cout << minCostPath(input, m,n);
    return 0;
}