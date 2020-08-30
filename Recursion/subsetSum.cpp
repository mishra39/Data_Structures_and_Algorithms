#include <iostream>
using namespace std;

int subsetSumToK(int in[], int n, int out[][50], int k)
{
    // Write your code here
    if(n==0)
    {
        if(k==0)
        {
            out[0][0]=0;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int out1[1000][50],out2[1000][50],i,j;
    int size1=subsetSumToK(in+1,n-1,out1,k-in[0]);
    int size2=subsetSumToK(in+1,n-1,out2,k);
    for(i=0;i<size1;i++)
    {
        out1[i][0]++;
        out[i][0]=out1[i][0];
        out[i][1]=in[0];
        
    }
    for(i=0;i<size1;i++)
    {
        for(j=2;j<=out1[i][0];j++)
        {
            out[i][j]=out1[i][j-1];
        }
    }

    for(i=0;i<size2;i++)
    {
        for(j=0;j<=out2[i][0];j++)
        {
            out[i+size1][j]=out2[i][j];
        }
    }
    return size1+size2;
}

int main() 
{
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;
  
  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}