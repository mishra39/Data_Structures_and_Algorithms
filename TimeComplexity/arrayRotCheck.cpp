#include <iostream>
#include<algorithm>
using namespace std;

int arrayRotateCheck(int *input, int size)
{
	int x=0;
    for (int i = 1; i < size; i++)
    {
    	if (input[0] > input[i])
    	{	
    		input[0] = input[i];
    		x = i;
    	}
    }

    return x;
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

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << arrayRotateCheck(input, size) << endl;
		delete[] input;
	}
	
	return 0;
}