// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
       int farthest(0),jump(0),reach(0);
        
        for(int i=0;i<n-1;i++)
        {
            farthest=max(farthest,arr[i]+i);  //for the farthest can be jumped 
            
            if(i==reach)  //if index ==reach then we need to jump from there
            {
                jump++;
                reach=farthest;
            }
            
        }
        
        if(reach<n-1)  //after traversing the array reach step is not satisfy the step
            return -1;
        
        
        return jump;  //return the required jumps
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends