// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	int t[10001];
	int helper(int n){
	if(n<=2)	return t[n] = n;
	
	if(ceil(sqrt(n)) *ceil(sqrt(n))==n)		return t[n]=1; //base case

	
	if(t[n]!= -1)   return t[n];

	int ans = n;

	for(int i=1;i<n/2;i++){
		if(i*i<=n){
			ans = min(ans,1 + helper(n-(i*i)));
			}
	}
	    return t[n] = ans;
	}
	int MinSquares(int n)
	{
	    memset(t,-1,sizeof(t));
	    return helper(n);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends