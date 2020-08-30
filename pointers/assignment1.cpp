#include <iostream>
using namespace std;

void swap(char *x, char *y)
{
	char *t = x;
	x = y;
	y = t;
}

void Q(int z)
{
	z +=z;
	cout << z << " ";

}

void P(int* y)
{
	int x = *y + 2;
	Q(x);
	*y = x - 1;
	cout << x << " ";
}

int main(int argc, char const *argv[])
{
	int x = 5;
	P(&x);
	cout << x;
	
	/*char st[] = "ABCD";
	for (int i=0;st[i]!='\0';i++){
		cout << st[i] << *(st)+i << *(i+st) << i[st];
	}*/


	/*
	float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
	float *ptr1 = &arr[0];
	flot *ptr2 = ptr1 + 3;
	cout << *ptr2<" ";
	cout << ptr2 - ptr1;*/

	/*
	char *x = "geeksquiz";
	char *y = "geeksforgeeks";
	char *t;
	swap(x,y);
	cout << x <<" "<<y;

	t = x;
	x = y;
	y = t;
	cout << x <<" "<<y;*/
	/*char arr[20];
	int i;
	for (i=0;i<10;i++){
		*(arr+i) = 65 + i;
	}

	*(arr+i) = '\0';
	cout<<arr<<endl;*/
	/*
	char *ptr;
	char Str[]="abcdefg";
	ptr = Str;
	ptr+=5;
	cout<<ptr<<endl;

	int numbers[5];
	for (int n=0;n<5;n++){

		cout<<numbers[n] <<".";
	}
	cout <<endl;
	int *p;
	p = numbers;
	*p = 10;
	p = &numbers[2];
	*p = 20;*
	p--;
	*p=30;
	p = numbers + 3;
	*p = 40;
	p = numbers;
	*(p+4) = 50;

	for (int n=0;n<5;n++){

		cout<<numbers[n] <<".";
	}
*/
	return 0;
}