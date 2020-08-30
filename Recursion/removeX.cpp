#include <iostream>
#include <string.h>
using namespace std;

void movefunc(char input[]) {
	for(int i =0; i < strlen(input); i++) {
		input[i] = input[i+1];  
	}
}

void removeX(char input[]) {

	if (strlen(input) < 1) {
		return;
	}

	removeX(input+1);

	if(input[0] == 'x'){
		movefunc(input);
	}
}



int main() 
{ 
    char input[100];
    cin.getline(input,100);
    removeX(input);
    cout << input << endl;
}