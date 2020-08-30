#include <iostream>
#include<algorithm>
using namespace std;
void printArray(int A[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", A[i]); 
    cout << endl;
}

void pairSum(int input[], int size, int x)
{
    sort(input, input+size);
    
    for(int i=0; i < size;i++)
    {
        for (int j=i+1;j<size;j++)
        {
            if ((input[i]+input[j]) == x)
            {
                cout << input[i] << " " << input[j] << endl; 
            }
        }
    }
}
 

int main() {

    int size;
    int x;

    cin>>size;
    int *input=new int[1+size]; 
    
    for(int i=0;i<size;i++)
        cin>>input[i];
    cin>>x;
    pairSum(input,size,x);
        
    return 0;
}
