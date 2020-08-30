#include <iostream>
using namespace std;

void printSubSequence(string input, string output) {

	if (input.empty()) {

		cout << output << endl;

		return;
	}


	printSubSequence(input.substr(1), output);
	printSubSequence(input.substr(1), output + input[0]);
}

int main(int argc, char const *argv[])
{
	string input;
	cin >> input;
	string output;// = new string[1000];
	printSubSequence(input, output);

	return 0;
}