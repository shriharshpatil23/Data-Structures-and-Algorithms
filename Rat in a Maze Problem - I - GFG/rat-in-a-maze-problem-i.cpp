// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool vis[6][6];
    bool isValid(int i, int j, int n , vector<vector<int>> m){
        if(i<0 || i>=n || j<0 || j>=n || m[i][j]==0 || vis[i][j]==true) return false;
        
        return true;
    }
    void helper(int i, int j ,vector<vector<int>> &m, int n,vector<string> &ans, string &s){
        if(i==n-1 && j==n-1 ){
            ans.push_back(s);
            return;
        }
     //   if(isValid(i,j,n,m)==false)    return;
        //up
        if(isValid(i-1,j,n,m)){
            s.push_back('U');
            vis[i-1][j]=true;
            helper(i-1,j,m,n,ans,s);
            s.pop_back();
             vis[i-1][j]=false;
        }
        //down
        if(isValid(i+1,j,n,m)){
            s.push_back('D');
             vis[i+1][j]=true;
            helper(i+1,j,m,n,ans,s);
            s.pop_back();
             vis[i+1][j]=false;
        }
        //right
        if(isValid(i,j+1,n,m)){
            s.push_back('R');
             vis[i][j+1]=true;
            helper(i,j+1,m,n,ans,s);
            s.pop_back();
             vis[i][j+1]=false;
        }
        //left
        if(isValid(i,j-1,n,m)){
            s.push_back('L');
             vis[i][j-1]=true;
            helper(i,j-1,m,n,ans,s);
            s.pop_back();
             vis[i][j-1]=false;
        }
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        memset(vis,false,sizeof(vis));
       vector<string> ans;
        if(m[0][0]==0 || m[n-1][n-1]==0)  return ans;
       string tmp="";
       vis[0][0]=true;
       helper(0,0,m,n,ans,tmp);
       return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends