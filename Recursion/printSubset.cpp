#include <iostream>
using namespace std;

void printFunc(int input[], int size, int output[],int n)
{
	//Base case
	if (size <=0) {
		for(int i=0;i<n;i++){
            cout<<output[i]<<' ';
          
        }
          cout<<endl;
		return ;
	}

	int output2[1000];
	for (int i = 0; i < n; i++) {
		output2[i] = output[i];
	}
	output2[n] = input[0];
	// Recursion
	printFunc(input+1,size-1,output,n);
	printFunc(input+1,size-1,output2,n+1);


}

void printSubsetsOfArray(int input[], int size) {
	int output[1000];
	printFunc(input,size,output,0);
}

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}