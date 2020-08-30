#include <iostream>
#include<algorithm>
using namespace std;


void FindTriplet(int arr[], int size, int x)
{
	sort(arr, arr + size);
for (int i = 0; i < size-1; i++)
	{
	
	int l = i+1;
	int r = size -1;
	int v = arr[i];

	while(l < r)
	{
		if (v+arr[l]+arr[r]==x)
		{
            int c1=0,c2=0;
            for(int j=l;j<=r;j++){
                if(arr[j]==arr[l]){
                    c1++;
                }else{
                    break;
                }
            }
            for(int j=r;j>=l;j--){
                if(arr[j]==arr[r]){
                    c2++;
                }else{
                    break;
                }
            }
            int k=c1*c2;
            if(arr[l]==arr[r]){
                k=((r-l+1)*(r-l))/2; // counts number of occureces 
            }
            for(int t=0;t<k;t++){
                cout << v << " " << arr[l] << " " << arr[r] << endl;
            }
			// cout << v << " " << arr[l] << " " << arr[r] << endl;
			l+=c1;
			r-=c2;
		}

		else if (v+arr[l]+arr[r] < x)
		{
			l++;
		}

		else
		{
			r--;
		}
	}
}
}

int main() {

	int size;

	int x;
	cin>>size;
	
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	cin>>x;

	FindTriplet(input,size,x);
		
	return 0;
}