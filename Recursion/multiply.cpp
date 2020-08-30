#include <iostream>
using namespace std;

int multiplyNumbers(int m, int n){

	if (n==0){
		return 0;
	}

	int smallSum = multiplyNumbers(m,n-1);
	return smallSum + m ;
}

int main(int argc, char const *argv[])
{
	int x,y;
	cin >> x;
	cin >> y;

	int ans = multiplyNumbers(x,y);
	cout << ans;
	return 0;
}