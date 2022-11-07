//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxGroupSize(int arr[], int N, int K) {
        // code here
        int freq[K+1] = {0};
        for(int i=0; i<N; i++){
            freq[arr[i]%K] += 1;
        }
        int c = freq[0] ? 1 : 0;
        for(int i=1; i<K/2; i++)
            c += max(freq[i], freq[K-i]);
        if(K%2)
            c += max(freq[K/2], freq[K-K/2]);
        if(K%2 == 0 && freq[K/2])
            c++;
        return c;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends