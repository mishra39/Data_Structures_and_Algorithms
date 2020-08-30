#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

int countBracketReversals(char input[]){

stack<char> s;
if (strlen(input) % 2 !=0)
{
	return -1;
}

else
{
	for (int i = 0; input[i] != '\0'; i++)
	{

		if (input [i]=='{')
		{
			s.push(input[i]);
		}

		else if (input[i] == '}' && !s.empty())
		{
			if (s.top() == '}')
			{
				s.push(input[i]);
			}

			else
			{
				s.pop();
			}
		}

		else if (s.empty())
		{
			s.push(input[i]);
		}
	}

}

int count = 0;

for (int i = 0; i < s.size(); i++)
{
	char c1 = s.top();
	s.pop();
	char c2 = s.top();
	s.pop();

	if (c1 == c2)
	{
		count++;
	}

	else
	{
		count += 2;
	}
}

return count;
}

int main() {
    char input[10000];
    cin >> input;
    cout << countBracketReversals(input) << endl;
}