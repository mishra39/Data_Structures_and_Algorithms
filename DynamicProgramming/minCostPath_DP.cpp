#include <iostream>
#include <vector>
#include <climits>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int minCostPath(int **input, int m, int n) {

    int **output = new int*[m];

    for (int i = 0; i < m; i++)
    {
        output[i] = new int[n];
    }

    // Initialization
   output[m-1][n-1] = input[m-1][n-1];

    // Fill last row from right to left
    for (int j = n-2; j >=0 ; j--)
    {
        output[m-1][j] = output[m-1][j+1] + input[m-1][j];
    }

    // Fill last column from bottom to top
    for (int i = m-2; i >= 0; i--)
    {
        output[i][n-1] = output[i+1][n-1] + input[i][n-1];  
    }

    // Fill remaining cells
    for (int i = m-2; i >= 0; i--)
    {
        for (int j = n-2; j >= 0; j--)
        {
            output[i][j] = min(output[i][j+1], min(output[i+1][j],output[i+1][j+1])) + input[i][j];
        }
    }

    return output[0][0];
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