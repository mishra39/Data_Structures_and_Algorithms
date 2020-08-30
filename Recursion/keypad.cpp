#include <iostream>
#include <string>
using namespace std;

string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
int keypad(int num, string output[]){
	
	if(num==0){
		output[0] = "";

		return 1;
	}
    string temp[1000];
	int smallOutputSize = keypad(num/10,temp);
	int k=0;
	string numStr = mapping[num%10];
	int strSize = numStr.size();
	for(int i=0;i<strSize;i++){
        for(int j=0;j<smallOutputSize;j++){
            output[k]=temp[j] + numStr[i] ;
            k++;
        }
    }
    
    
    return k;
	// return smallOutputSize*numStr.size();
}
}

int main(int argc, char const *argv[])
{

	return 0;
}