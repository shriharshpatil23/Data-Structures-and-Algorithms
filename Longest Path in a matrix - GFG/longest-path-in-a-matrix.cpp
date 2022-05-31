// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int t[101][101];
    
    bool isValid(int i,int j, vector<vector<int>>& matrix){
        if(i<0 || i>= matrix.size() || j<0 || j>=matrix[0].size() ) return false;
        
        return true;
    }

    int helper(int i, int j ,vector<vector<int>>& matrix,int &prev){
        if(!isValid(i,j,matrix))    return 0;
        
        if(matrix[i][j] <=  prev )  return 0;
        
        if(t[i][j]!= -1)    return t[i][j];
        
        //up 
        int up = helper(i-1,j,matrix,matrix[i][j]);
        //down
        int down = helper(i+1,j,matrix,matrix[i][j]);
        //right
        int right = helper(i,j+1,matrix,matrix[i][j]);
        //left
        int left = helper(i,j-1,matrix,matrix[i][j]);
        
        return t[i][j]=1 + max({up,down,left,right});
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // Code here
        memset(t,-1,sizeof(t));
        int ans = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int prev = 0;
                ans = max(ans,helper(i,j,matrix,prev));
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends