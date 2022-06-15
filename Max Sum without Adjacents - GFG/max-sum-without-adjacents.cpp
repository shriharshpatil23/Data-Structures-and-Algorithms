// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int helper(int i, int n , int *arr, vector<int> &t){
	    if(i>=n)    return 0;
	    
	    if(t[i]!= -1)   return t[i];
	    
	    int take = arr[i] + helper(i+2,n,arr,t);
	    int not_take = helper(i+1,n,arr,t);
	    
	    return t[i] = max(take, not_take);
	}
	
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int> t(n,-1);
	    return helper(0,n,arr,t);
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends