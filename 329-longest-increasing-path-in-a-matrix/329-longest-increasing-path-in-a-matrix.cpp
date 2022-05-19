class Solution {
public:
    int t[201][201];
    bool isValid(int i,int j, vector<vector<int>>& matrix,int prev){
        if(i<0 || i>=matrix.size() || j<0 || j>=matrix[0].size() || matrix[i][j]<=prev )   return false;
        
        return true;
    }
    
    int dfs(int i,int j, vector<vector<int>>& matrix, int prev){
        if(isValid(i,j,matrix,prev)==false) return 0 ;
        
        if(t[i][j]!=-1) return t[i][j];
        
        int up = dfs(i-1,j,matrix,matrix[i][j]);
        int down = dfs(i+1,j,matrix,matrix[i][j]);
        int left = dfs(i,j+1,matrix,matrix[i][j]);
        int right = dfs(i,j-1,matrix,matrix[i][j]);
        
        int ans = max({up,down,right,left});
        return t[i][j] = ans + 1;
        
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(t,-1,sizeof(t));
        int ans = 0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                ans = max(ans,dfs(i,j,matrix,-1));
            }
        }
        return ans;
    }
};