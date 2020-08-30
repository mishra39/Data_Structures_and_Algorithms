#include <iostream>
#include "PriorityQueue.h"
using namespace std;

void inplaceHeapSort(int input[], int n){

	// Build the heap in input array
	for (int i = 1; i < n; i++)
	{

		int childIdx = i;

		while (childIdx > 0)
		{
			int parentIndex = (childIdx - 1)/2;

			if (input[childIdx] < input[parentIndex])
			{
				int temp = input[childIdx];
				input[childIdx] = input[parentIndex];
				input[parentIndex] = temp;
			}

			else
			{
				break;
			}

			childIdx = parentIndex;
		}
	}

	// Remove Elements
	int size = n;

	while(size > 1)
	{
		int temp = input[0];
		input[0] = input[size - 1];
		input[size - 1] = temp;

		size--;

		int parentIndex = 0;
		int leftChildIdx = 2 * parentIndex - 1;
		int rightChildIdx = 2 * parentIndex + 1;
	
	while(leftChildIndex < size) {
			int minIndex = parentIndex;
			if(input[minIndex] > input[leftChildIndex]) {
				minIndex = leftChildIndex;
			}
			if(rightChildIndx < size && input[rightChildIndx] < input[minIndex]) {
				minIndex = rightChildIndx;
			}
			if(minIndex == parentIndex) {
				break;
			}
			int temp = input[minIndex];
			input[minIndex] = input[parentIndex];
			input[parentIndex] = temp;

			parentIndex = minIndex;
			leftChildIndex = 2 * parentIndex + 1;
			rightChildIndx = 2 * parentIndex + 2;
		}
	}
}