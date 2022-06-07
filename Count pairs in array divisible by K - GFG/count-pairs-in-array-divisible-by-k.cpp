// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int A[], int n, int K)
    {
        //code here
        long long cnt  = 0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if((A[i]+A[j])%K==0)    cnt++;
        //     }
        // }
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            int x = A[i]%K;
            int target = K - x;
            if(m.count(target)>0)   cnt += m[target];
            m[x]++;
        }
        int cnt0 = m[0];
        cnt += (cnt0*(cnt0-1))/2;
        return cnt;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}
  // } Driver Code Ends