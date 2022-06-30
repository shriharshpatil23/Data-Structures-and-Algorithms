// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        int n = arr.size();
        set<vector<int> > vec ;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            int x = k - arr[i];
            for(int j= i+1;j<n;j++){
                int target = x - arr[j];
                int start = j + 1;
                int end = n -1;
                while(start<end){
                    if(arr[start]+arr[end]==target){
                        vec.insert({arr[i],arr[j],arr[start],arr[end]});
                        start++;
                        end--;
                    }else   if(arr[start]+arr[end]>target)  end--;
                    else    start++;
                }
            }
        }
        vector<vector<int>> ans (vec.begin(),vec.end());
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends