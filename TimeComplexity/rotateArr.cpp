#include <iostream>
#include<algorithm>
using namespace std;

void rotate(int* input, int d, int n)
{
	int output[1000000];
	for (int i = 0; i < n; i++)
	{	
		if (i+d < n)
		{
			output[i] = input[i+d];
		}

		else
		{
			output[i] = input[(i+d)-n];
		}
		
	}

	for (int i = 0; i < n; i++)
	{	
		//cout << output[i];
		input[i] = output[i];
	}
}

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}

	return 0;
}