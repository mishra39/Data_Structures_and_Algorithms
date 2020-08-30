#include <iostream>
#include<algorithm>
#include<string>
using namespace std;


bool checksequenece(char large[] , char small[])
{
	if (large[0] == '\0' && small[0] !='\0')
	{
		return false;
	}
	if (small[0]=='\0')
	{
		return true;
	}

	if (large[0] == small[0])
	{
		return checksequenece(large+1,small+1);
	}

	else
	{
		return checksequenece(large+1,small);
	}
	
	return false;
}


int main() 
{ 
    char str2[] = "coding"; 
    char str1[] = "abchjsgsuohhdhyrikkknddg"; 

    cout << checksequenece(str1, str2) << endl;
    return 0; 
} 