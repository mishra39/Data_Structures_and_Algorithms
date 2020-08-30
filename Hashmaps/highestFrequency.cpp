#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;


int highestFrequency(int *input, int n){	 
		
	unordered_map<int, int> freq;

	for (int i = 0; i < n; i++)
	{
		freq[input[i]]++;
	}

		// find max frequency
    int max_count=0,res=0;
	for(int i=0;i<n;i++)
    {
        if(freq[input[i]]>max_count)
        {
            res=input[i];
            max_count=freq[input[i]];
        }
        
    }
    return res;
}

int main()
{
    int n;
    int input[100000];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>input[i];
    }
    int maxKey= highestFrequency(input, n);
    cout<<maxKey;
    return 0;
}