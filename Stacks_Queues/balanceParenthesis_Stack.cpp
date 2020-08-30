#include <iostream>
#include <stack>
using namespace std;
bool checkBalanced(char *exp) {

	stack<char> s1;
	
	for (int i = 0; exp[i] != '\0'; i++)
	{
		if (exp[i]== '{' || exp[i]== '[' || exp[i]== '(')
		{
			s1.push(exp[i]);
		}
	}

	for (int i = 0; exp[i] != '\0'; i++)
	{
		if (exp[i]== '}' || exp[i]== ']' || exp[i]== ')')
		{
			if (!s1.empty() && s1.top() != exp[i])
			{
				return false;
			}
			else if (!s1.empty())
			{
				s1.pop();
			}
		}
	}

	if (s1.empty())
	{
		return true;
	}

	else
	{
		return false;
	}

}


int main() {
    char input[100000];
    cin.getline(input, 100000);
//    cin >> input;
    if(checkBalanced(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
