#include <iostream>
using namespace std;

int firstIndex(int input[], int size, int x){

	//Base Case
	if (size == 0){
		return -1;
	}

	if (input[0] == x){
		return 0;
	}

	int smallCheck = firstIndex(input + 1, size -1 , x);
	if (smallCheck==-1){
		return -1;
	}

	else{
		return smallCheck + 1;;
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

	cout << firstIndex(input, n, x) << endl;

	return 0;
}