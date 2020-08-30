#include <iostream>
#include<string>
using namespace std;

bool checkRest(char input[]) {

	if (input[0]=='\0') 
	{
		return true;
	}
	if (input[0] == 'a' && (input[1]=='b' && input[2] == 'b')) {
		if ((input[3] == '\0') || (input[3]=='a'))
		{
			return true;
		}
	}
	else {
			return checkRest(input+1);
		}

}
bool checkAB(char input[]) {
	

	if (input[0] == 'a' && (input[1] == '\0')) {
		return true;
	}

	if (input[0] == 'a') {
		return checkRest(input);
	}

	else {
		return false;
	}
}

int main(int argc, char const *argv[])
{
	char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;

    return 0;

}