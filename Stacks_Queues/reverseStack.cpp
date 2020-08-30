#include <stack>

void reverseStack(stack<int> &input, stack<int> &extra) {
	
	int x = 0;
	if (input.empty())
	{
		return;
	}

	
	while(!input.empty())
	{
		x = input.top();
		input.pop();
		extra.push(x);
	}
	input = extra;

	return;
}