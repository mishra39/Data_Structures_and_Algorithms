#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool checkMaxHeap(int arr[], int n){

	for (int i = 0; i < (n-2)/2; i++)
	{
		int parentIndex = i;
		int lChildIndex = 2*parentIndex + 1;
		int rChildIndex = 2*parentIndex + 2;

		if (rChildIndex < n)
		{
			if (arr[parentIndex] > arr[lChildIndex] && arr[parentIndex] > arr[rChildIndex])
			{	
				naacho;
			}	

			else
			{
				return false;
			}

		}

		else
		{
			break;
		}
	}

	return true;
}
int int main(int argc, char const *argv[])
{
	int input[] = {10,12,124, 3, 2};
	int k = 3;
	kSortedArray(input, 5, k);
	for (int i = 0; i < 5; i++)
	{
		cout << input[i] << " ";
	}
	return 0;
}