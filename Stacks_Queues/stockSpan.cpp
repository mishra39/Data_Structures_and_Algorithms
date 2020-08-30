#include <iostream>
using namespace std;
#include <stack>

int* stockSpan(int *price, int size) {
	stack<int> s;
	int* output;
	s.push(0);
	output[0] = 1;

	for (int i = 1; i < size; i++)
	{
		while(!s.empty() && price[s.top()] < price[i])
		{
			s.pop();
		}

		output[i] = (s.empty()) ? (i+1) : (i-s.top());
		s.push(i);
	}
	return output;
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for(int i = 0; i < size; i++) {
    	cin >> input[i];
    }
    int *output = stockSpan(input, size);
    for(int i = 0; i < size; i++) {
    	cout << output[i] << " ";
    }
}
