#include <iostream>
#include <string>
using namespace std;

int DuplicateNumber(int arr[], int size)
{
	int sum1 = ((size-2)*(size-1))/2;
	int sum2 = 0;
	for (int i = 0; i < size; i++) 
	{
		sum2 += arr[i];

	}

	return sum2 - sum1;
}
int main() {

	int size;

	cin>>size;
	int *arr=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>arr[i];
	
	cout<<DuplicateNumber(arr,size)<<endl;
		
	return 0;
}