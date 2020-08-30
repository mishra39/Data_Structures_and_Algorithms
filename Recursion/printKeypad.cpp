#include <iostream>
#include <string>
using namespace std;

string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};


void printFunc(int num, string output) {

	if (num==0) {

    	cout << output << endl;
    	return;
    }

    string smallStr = mapping[num%10];

    for (int i = 0; i < smallStr.size(); i++) 
    {
    	printFunc(num/10, smallStr[i] + output);	
    }

    return;
}

void printKeypad(int num){
    string output;
    printFunc(num,output);

}



int main(int argc, char const *argv[])
{
	int num;
	cin >> num;
	printKeypad(num);

	return 0;
}