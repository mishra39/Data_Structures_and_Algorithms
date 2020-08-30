#include <iostream>
#include <string>
using namespace std;


int atoi(char a)
{
    int i=a-'0';
    return i;
}
char itoa(int i)
{
    char c='a'+i-1;
    return c;
}


void printAllPossibleCodes(string input,string output="") {
    
	if(input.size()==0)
   {  
      	cout << output << endl;
       	return;
   }
    printAllPossibleCodes(input.substr(1),output+itoa(atoi(input[0])));
              
    if(input.size()>=1)
    {
    	int numSum = (atoi(input[0])*10) + atoi(input[1]);
    
        if(numSum >=10 && numSum <27)
        {
        	printAllPossibleCodes(input.substr(2),output+itoa(numSum));
        }

    }
}
int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
