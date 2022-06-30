// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
           int copy[r], i=l, j=m+1, k=0;
       while(i<=m && j<=r) {
           if(arr[i] < arr[j]) {
               copy[k++] = arr[i++];
           }
           else {
               copy[k++] = arr[j++];
           }
       }
       while(i<=m) {
           copy[k++] = arr[i++];
       }  
       while(j<=r) {
           copy[k++] = arr[j++];
       }
       for(i=l; i<=r; i++) {
           arr[i] = copy[i-l];
       }
       return;
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //base Case
        if(l>=r)    return ;
        
        int mid = l + ( r - l)/2;
        //left part
        mergeSort(arr,l,mid);
        //right part
        mergeSort(arr,mid+1,r);
        
        //merge the Broken parts
        merge(arr,l,mid,r);
    }
};

// { Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends