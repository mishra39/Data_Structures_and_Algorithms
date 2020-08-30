#include <iostream>
#include <string.h>
using namespace std;

void removeConsecutiveDuplicates(char *input)
 {

	if (strlen(input)<=1) {
		return;
	}
	removeConsecutiveDuplicates(input+1);

	if (input[0] == input[1]){
		for (int i = 0; i <= strlen(input);i++){
			input[i] = input[i+1];
		}
	}

	
}


int main() {
    char input[1000000];
    cin >> input;
    removeConsecutiveDuplicates(input);
    cout << input << endl;
}