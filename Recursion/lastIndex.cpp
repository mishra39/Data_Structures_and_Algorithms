#include <iostream>
using namespace std;

int lastIndex(int input[], int size, int x){

	//Base Case
	if (size == 0){
		return -1;
	}

	if (input[size-1] == x){
		return size-1;
	}

	int smallCheck = lastIndex(input, size -1 , x);
	if (smallCheck==-1){
		return -1;
	}

	else{
		return smallCheck;
	}

}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int *input = new int[n];

	for (int i=0;i<n;i++){
		cin>> input[i];
	}

	int x;
	cin >> x;

	cout << lastIndex(input, n, x) << endl;

	return 0;
}