#include <iostream>
#include <stack>

bool checkRedundantBrackets(char *input) {

	stack<char> s;
	int count = 0;
	for (int i = 0; input[i] != '\0'; i++)
	{
		if (input[i]==')')
		{
			char top = s.top();
			s.pop();

			bool flag=true;

			while(top!='(')
			{
				flag = false;
				top = s.top();
				s.pop();
			}

			if (flag==true)
			{
				return true;
			}

		}

		else
			{
				s.push(input[i]);
			}
		}

		return false;
}

/*	stack<char> s;
	for (int i = 0; input[i] != '\0'; i++)
	{
		if (input[i]=='(' && input[i+1]=='(')
		{
			s.push(input[i]);	
		}
        	}

	return (s.size()>1);
}*/