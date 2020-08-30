#include <bits/stdc++.h>
using namespace std;
void printhelper(int arr[],int size,int out[],int k,int m){
    if (size==0){
        if (k==0){
            for(int i=0; i<m; i++){
                cout<<out[i]<<" ";}
                cout<<endl;                    // write 'endl' terminating statement here cos, we have take one complete row with required sum
                return;                        // in every step.        
        }
        else {
            return;
        }
    }
    printhelper(arr+1,size-1,out,k,m);
    int b[100];
    for (int i=0; i<m; i++){
        b[i]=out[i];
    }
    b[m]=arr[0];
    printhelper(arr+1,size-1,b,k-arr[0],m+1);
}

void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
   
    int output[100];
    printhelper(input,size,output,k,0);
    
}

int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}
