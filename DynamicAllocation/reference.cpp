#include <iostream>
using namespace std;

void func(int i, int& j, int p){
	i++;
	j++;
	p++;
}

int main(int argc, char const *argv[])
{
	int i = 10;
	int j = 6;
	int &p = i;
	func(i,j,p);
    cout << i << " " << j << " " << p;
	 
	return 0;
}