#include <iostream>
using namespace std;

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l + (r - l) / 2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
  
/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d\n", A[i]); 
} 
  
void intersection(int input1[], int input2[], int size1, int size2) {
    mergeSort(input1, 0, size1-1);
    mergeSort(input2, 0, size2-1);
    int i = 0;
    int j = 0;
    int k = 0;
    int commn[1000];

    while(i < size1 && j < size2)
    {
        if (input1[i] < input2[j])
        {
            i++;
        }

        if (input1[i]==input2[j])
        {
            commn[k] = input1[i];
            i++;
            j++;
            k++;
        }

        if (input1[i] > input2[j])
        {
            j++;
        }
    }

    printArray(commn,k);
}

int main() {

    int size1,size2;

    cin>>size1;
    int *input1=new int[1+size1];   
    
    for(int i=0;i<size1;i++)
        cin>>input1[i];

    cin>>size2;
    int *input2=new int[1+size2];   
    
    for(int i=0;i<size2;i++)
        cin>>input2[i];
    
    
    intersection(input1,input2,size1,size2);

        
    return 0;
}
