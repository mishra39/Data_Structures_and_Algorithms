#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int stringToNumber(char input[]) {

	if (strlen(input) == 1){

		return int(input[0]) - 48; 
	}

	int smallAns = stringToNumber(input + 1);

	int num = int(input[0]) - 48;

	int exp = pow(10,strlen(input)-1);

	return smallAns + (num*exp);

}

int main() 
{ 
    char input[100];
    cin.getline(input,100);
    
    cout << stringToNumber(input);
    
}