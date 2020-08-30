#include <iostream>
#include <queue>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;

void findMedian(int arr[], int n){

	// max heap to store the smaller half elements
	priority_queue<double> sPQ;

	// min heap to store the greater half elements
	priority_queue<double, vector<double>, greater<double> > gPQ;

	double med = arr[0];
	s.push(arr[0]);

	cout << med << endl;

	// reading elements of stream one by one 
    /*  At any time we try to make heaps balanced and 
        their sizes differ by at-most 1. If heaps are 
        balanced,then we declare median as average of 
        min_heap_right.top() and max_heap_left.top() 
        If heaps are unbalanced,then median is defined 
        as the top element of heap of larger size  */

	for (int i = 1; i < n; i++)
	{
		double x = arr[i];
		if (sPQ.size() > gPQ.size())
		{
			if (x < med)
			{
				gPQ.push(sPQ.top());
				sPQ.pop();
				sPQ.push(x);
			}

			else
			{
				gPQ.push(x);
			}

			med = (s.top() + g.top()) / 2.0;
		}

		// if both heaps are balanced
		else if (sPQ.size() == gPQ.size())
		{
			if (x < med)
			{
				sPQ.push(x);
				med = (double)s.top();
			}

			else
			{
				gPQ.push(x);
				med = (double)gPQ.top();
			}
		}

		else
		{
			if (x > med)
			{
				sPQ.push(gPQ.top());
				gPQ.pop();
				gPQ.push(x);
			}

			else
			{
				sPQ.push(x);
			}

			med = (s.top() + g.top()) / 2.0;
		}

		cout << med << endl;
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