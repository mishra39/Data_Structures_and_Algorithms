#include <iostream>
using namespace std;
#include<unordered_map>
#include<cstring>

char* uniqueChar(char *str){
    // Write your code here
int n= strlen(str);
    unordered_map<char, int> map;
    
    for (int i=0;str[i]!='\0';i++){
        
        if (map.count(str[i])>0){
            map[str[i]]++;
        }else{
            map[str[i]]=1;
        }
    }

    char* output=new char[n+1];
    int i;
    int count=0;
    for ( i=0;i<n;i++){
        if (map[str[i]]>0){
        output[count]=str[i];
        map[str[i]]=0;
            count++;
        }
    }
    output[count]='\0';
    return output;   
}

int main() {

	char input[1000000];
	cin >> input;
	cout << uniqueChar(input) << endl;
}
