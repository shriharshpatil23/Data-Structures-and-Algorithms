// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int t[81];
    long long int helper(int n){
        if(n < 4)    return 1;
        
        if(t[n]!= -1)   return t[n];
       
       long long int x = helper(n-1);
       long long int y = helper(n-4);
       return t[n] = x + y;
    }
    long long int arrangeTiles(int N){
       memset(t,-1,sizeof(t));
       return helper(N);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.arrangeTiles(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends