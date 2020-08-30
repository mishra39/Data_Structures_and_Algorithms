#include <iostream>
#include <vector>
#include <climits>
#include <bits/stdc++.h>
using namespace std;

int minCostPath(int **input, int m, int n) {
    // Base Case
    if (m<0 || n<0)
    {
        return INT_MAX;
    }

    // Recursive Calls
    int cost1 = minCostPath(input,m-1,n);
    int cost2 = minCostPath(input,m,n-1);
    int cost3 = minCostPath(input,m-1,n-1);

    // Small calc
    int ans = min(cost1,min(cost2,cost3))+input[m][n];
    return ans;
}