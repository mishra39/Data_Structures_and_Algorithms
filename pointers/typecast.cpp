#include <iostream>
using namespace std;

void updateValue(int *p){
    *p = 610 % 255;
}

int main(int argc, char const *argv[])
{
	 char ch = 'A';
    updateValue((int*)&ch);
    cout << 610 % 255;

	return 0;
}