#include <iostream>
#include <string.h>
using namespace std;

bool helper(char str[],int s, int e){
	if (str[s] != str[e]){
		return false;
	}

	if (s < e + 1){
		return helper(str,s+1, e-1);
	}

	return true;

	}

bool checkPalindrome(char input[]){
	int n = strlen(input);

	if (n==0){
		return true;
	}

	return helper(input,0,n-1);
}

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
