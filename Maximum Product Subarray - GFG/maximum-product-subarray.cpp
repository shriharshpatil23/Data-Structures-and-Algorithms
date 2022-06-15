// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	   long long ans = arr[0];
	   long long curr = 1;
	   for(int i=0;i<n;i++){
	       if(curr==0)  curr=1;
	       curr = curr*arr[i];
	       ans = max(ans,curr);
	   }
	   curr =1;
	   for(int j=n-1;j>=0;j--){
	       if(curr==0)  curr=1;
	       curr *= arr[j];
	       ans = max(ans,curr);
	   }
	   return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends