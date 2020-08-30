#include <iostream>
using namespace std;

int countZeros(int n){
	if (n==0){ //when input is zero
		return 1;
	}

	//base case
	if (n < 10){
		return 0;
}
	
	int smallAns = countZeros(n/10);

	if (n % 10 == 0){
		return smallAns + 1;
	}
	else{
		return smallAns;
	}
}

int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}