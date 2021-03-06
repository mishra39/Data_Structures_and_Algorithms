#include <iostream>
#include <bits/stdc++.h>
#include <vector>
class PriorityQueue
{
	vector<int> pq;
public:
	PriorityQueue(){

	} 

	bool isEmpty() {
		return pq.size();
	}	

	int getSize()
	{
		return pq.size();
	}

	int getMax()
	{
		if (isEmpty())
		{
			return 0; 
		}
		return pq[0];
	}

	void insert(int element)
	{
		pq.push_back(element);
		int chilldIndex = pq.size() - 1;

		while (chilldIndex > 0) {
		int parentIndex = (chilldIndex - 1) / 2;

		if (pq[chilldIndex] > pq[parentIndex])
		{
			int temp = pq[chilldIndex];
			pq[chilldIndex] = pq[parentIndex];
			pq[parentIndex] = temp;
		}

		else
		{
			break;
		}

		chilldIndex = parentIndex; // now the previous parent becomes child for further comparison
		}
	}

	int removeMax()
	{
		if (isEmpty()) {
			return INT_MIN;
		}
		int ans = pq[0];
		pq[0] = pq[pq.size()-1];
		pq.pop_back();

		// Satisfy heap order property. Down-heapify
		int parentIndex = 0;
		int LChildIndex = 2*parentIndex + 1;
		int rChildIndex = 2*parentIndex + 2;
		

		while (LChildIndex < pq.size())
		{
			int maxIndex = parentIndex;
			if (pq[maxIndex] < pq[LChildIndex])
			{
				maxIndex = LChildIndex;
			}

			if (rChildIndex < pq.size() && pq[rChildIndex] > pq[maxIndex])
			{
				maxIndex = rChildIndex;
			}

			if (maxIndex == parentIndex)
			{
				break;
			}

			int temp = pq[maxIndex];
			pq[maxIndex] = pq[parentIndex];
			pq[parentIndex] = temp;
			parentIndex = maxIndex;
			LChildIndex = 2*parentIndex + 1;
			rChildIndex = 2*parentIndex + 2;
		}

		return ans;
	}
};