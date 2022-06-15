// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
   int solve(int ind, int n, int a[], int prev,  vector<vector<int>> &dp){
       
       if(n == ind) return 0; 
       if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];
       if(a[ind] > a[prev] || prev == -1){
           return dp[ind][prev+1] = max(solve(ind+1, n, a, ind, dp) + 1 ,solve(ind+1, n, a, prev, dp));
       }
       else{
           return dp[ind][prev+1] = solve(ind+1, n, a, prev, dp);
       }
       return dp[ind][prev+1];
   
   }
   int longestSubsequence(int n, int a[])
   {
      // your code here
      vector<vector<int>> dp(n+1, vector<int>(n+2, -1));
      return solve(0, n, a, -1, dp);
   }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends