#include <iostream>
#include <string>
using namespace std;


int returnPermutations(string input, string output[], int index, int len){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    
    if (input.length()-1==index) {
        output[len] = input[index];
        return len+1;
    }

    for(int i = index; i<input.length();i++) {
    	swap(input[i],input[index]);
    	if((input.substr(index).length() > 1))
    	{
    		int small = returnPermutations(input, output, index+1, len);
    		for (int j =0; j < small; j++) {
    			output[j+len] = input[i] + output[j+len];
    		}
    	}
    		swap(input[index],input[i]);
    	}
    	return len;
}

int returnPermutations(string input, string output[]){
	returnPermutations(input, output, 0,0);
}

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}