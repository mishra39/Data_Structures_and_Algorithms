using namespace std;
#include<unordered_map>
#include<cstring>
#include <algorithm>
#include <vector>

void intersection(int input1[], int input2[], int size1, int size2) {

	unordered_map<int, int> intr;

	for (int i = 0; i < size1; i++)
	{
		intr[input1[i]]++;
	}

	for (int i = 0; i < size2; i++)
	{
		if (intr[input2[i]])
		{
			cout << input2[i] << endl;
            intr[input2[i]]--;
		}
	}
}