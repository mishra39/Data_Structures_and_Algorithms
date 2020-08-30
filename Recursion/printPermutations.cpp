#include <iostream>
#include <cstring>
using namespace std;



void printFunc(string input, int l, int size)
{

	if (l==size) {
		cout << input << endl;
		return;
	}

	else
	{

	for (int i=l; i <= size; i++) {
		swap(input[l],input[i]);
		printFunc(input,l+1,size);
		swap(input[l],input[i]);
	}
}

}
void printPermutations(string input) {
	printFunc(input, 0, input.size()-1);
}
int main(){
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}