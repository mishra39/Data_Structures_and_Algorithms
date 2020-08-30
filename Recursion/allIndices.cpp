#include <iostream>
using namespace std;

int allIndexes(int input[], int size, int x, int output[]) {

	if (size == 0){
		return 0;
	}

	int smallAns = allIndexes(input + 1, size - 1, x, output);

	// Building the output array

	// If element 0 matches x
	// increment each element in the output array by 1
	if (input[0]==x){
		// increment each element in the output array by 1
		for (int i=smallAns-1;i>=0;i--){
			output[i+1] = output[i] + 1;
		}

		/* shift elements of the output array
		for (int i=0;i<smallAns;i++){
			output[i+1] = output[i]+ 1;
		}

		//add one occurence for the 0th element*/
		output[0] = 0;
		smallAns++;
	}


	else{ // If the element at input[0] does not match x,
		// increment each element in the output array by 1
		for (int i=smallAns-1;i>=0;i--){
			output[i] = output[i] + 1;
		}

	}
	return smallAns;

}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;

}