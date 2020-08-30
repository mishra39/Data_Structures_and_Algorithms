#include <iostream>
using namespace std;


int searchFunc(int input[], int s, int e, int element) {

	if(s > e )
	{
		return -1;
	}

	else
	{
		int mid = (s + (e-s))/2;

		if (input[mid] == element)
		{
			return mid;
		}

		else if (input[mid] > element)
		{
			int smallAns = searchFunc(input, s, mid-1,element);
		}

		else if (input[mid] < element)
		{
			int smallAns = searchFunc(input, mid+1, e, element);
		}

		else {
			return -1;
		}

	}
}

int binarySearch(int input[], int size, int element) {
    // Write your code here

    int index = searchFunc(input,0,size-1,element);
    return index;

}


int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}