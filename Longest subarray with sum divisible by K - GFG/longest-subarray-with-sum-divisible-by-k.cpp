// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    unordered_map<int,int> m;
	    m[0]=-1;
	    long long int preSum = 0;
	    int ans = 0;
	    for(int i=0;i<n;i++){
	        preSum += arr[i];
	        int rem = preSum%k;
	        if(rem < 0) rem+= k;
	        if(m.find(rem)==m.end()){
	            m[rem]=i;
	        }else{
	            ans = max(ans,i - m[rem]);
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends