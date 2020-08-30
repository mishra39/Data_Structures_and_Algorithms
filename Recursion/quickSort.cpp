#include <iostream>
#include <string.h>
using namespace std;

int partition(int input[],int s, int e)
{
	int i = s;
	int j = e;
	int tmp;

	for (int k = s+1; k < e; k++)
	{

		if (input[k] <= input[s])
		{
			i = i+1;
			// Swapping first element with the element currently in the partition slot
			tmp = input[k];
			input[k] = input[i];
			input[i] = tmp;
		}
	}

		tmp = input[s];
		input[s] = input[i];
		input[i] = tmp;

		return i;
}


void quickSortFunc(int input[], int s, int e)
{
	int c;
	if (s < e)
	{

	c = partition(input,s,e);

	quickSortFunc(input, s, c);
	quickSortFunc(input, c+1, e);
}
//return;
}

void quickSort(int input[], int size) {
	 quickSortFunc(input,0,size);
}




int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++) {


    cin >> input[i];
}

  quickSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}