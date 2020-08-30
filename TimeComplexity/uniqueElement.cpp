#include <iostream>
#include <string>
using namespace std;

int FindUnique(int arr[], int size)
{
	int uniq;
	for (int i = 0; i < size; i++) 
	{
		uniq ^= arr[i];

	}

	return uniq;
}
int main() {

	int size;

	cin>>size;
	int *arr=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>arr[i];
	
	cout<<FindUnique(arr,size)<<endl;
		
	return 0;
}