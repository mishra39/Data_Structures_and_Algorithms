#include <iostream>
#include<algorithm>
using namespace std;

bool helperFunc(int *input, int n, int start, int lsum, int rsum)
{
	if (start == n)
	{
		return lsum == rsum;
	}

	if ((input[start]%5) == 0)
	{
		lsum += input[start];
	}

	else if ((input[start]%3)==0)
	{
		rsum += input[start];
	}

	else
	{
		return (helperFunc(input, n, start+1, lsum+input[start],rsum) || helperFunc(input, n, start+1, lsum,rsum+input[start]));
	}

	return helperFunc(input,n,start+1, lsum, rsum);
}
bool splitArray(int *input, int size) {
    
    return helperFunc(input, size, 0, 0, 0);
}

int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
    if(splitArray(input, size)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

	
	return 0;

}