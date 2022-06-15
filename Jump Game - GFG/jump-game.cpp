// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  
// int helper(int i, int n, int a[],vector<int> &t){
//     if(i>=n-1)  return 0;
    
//     if(t[i]!= -1)   return t[i];
//     int max_jump = a[i];
//     int ans = INT_MAX-1;
//     for(int j = 1;j<=max_jump;j++){
//         ans = min(ans,helper(i+j,n,a,t));
//     }
//     return t[i] = 1 + ans;
// }
  
//     int canReach(int A[], int N) {
//         // code here
//         vector<int> t(N+1,-1);
//         int jump = helper(0,N,A,t);
//         if(jump == INT_MAX) return 0;
        
//         return 1;
//     }
 int canReach(int A[], int N) {
       int range=0;
       for(int i=0;i<N;i++){
           range=max(A[i],range);
           if(i!=N-1 && range==0) return 0;
           range--;
       }
       return 1;
   }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends