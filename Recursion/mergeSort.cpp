#include <iostream>
#include <string.h>
using namespace std;

void merge(int input[], int s, int e, int mid) {

	int i = 0;
	int j = 0;
	int k = 0;
	int c[50];

	i = s;
	k = s;
	j = mid + 1;

	while (i <= mid && j <= e)
	{
		if (input[i] < input[j])
		{
			c[k] = input[i];
			k++;
			i++;
		}

		else
		{
			c[k] = input[j];
			k++;
			j++;
		}
	}

	while (i <= mid)
	{
		c[k] = input[i];
		k++;
		i++;
	}

	while (j <= e)
	{
		c[k] = input[j];
		k++;
		j++;
	}

	for (int i = s; i < k; i++)
	{
		input[i] = c[i];
	}

}

void mergeFunc(int input[], int s, int e) { 
	
	if (s >= e) {

		return;
	}

	int mid;
	mid = (s + e) / 2;

	mergeFunc(input, s, mid);
	mergeFunc(input, mid+1, e);

	merge(input,s,e,mid);
}


void mergeSort(int input[], int size) {
	mergeFunc(input,0,size -1);
}


int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++) {


    cin >> input[i];
}

cout << "Input Provided" << endl;
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}