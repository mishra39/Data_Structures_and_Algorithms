#include <iostream>
using namespace std;

void printFunc(int input[], int size, int k, int output[], int m) {
	
	// Base case
	if(size==0) {
		if (k==0) {
			for (int i=0; i < m; i++) {
				cout << output[i]<<" ";
				
			}
			cout << endl;
			return;
		}

		else {
			return;
		}
		}

	// Recursion
	printFunc(input+1, size-1, k,output, m);
	int out2[1000];

	for (int i =0; i < m; i++) {
		out2[i] = output[i];
	}

	out2[m] = input[0];
	printFunc(input+1, size-1, k-input[0], out2, m+1);
}

void printSubsetSumToK(int input[], int size, int k) {
	int out[1000];
	printFunc(input, size, k, out,0);
}


int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}
