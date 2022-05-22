class Solution {
public:
    bool isValid (int i, int j, vector<vector<int>>& grid){
        if(i<0 || i>= grid.size() || j<0 || j>= grid[0].size()) return false;
        
        return true;
    }
    
    void helper(int i, int j, vector<vector<int>>& grid, int &cnt){
        if(!isValid(i,j,grid))  return ;
        
        if(grid[i][j]==1){
            cnt++;
            grid[i][j]=0;
            
            for(int row = 0;row< grid.size();row++){
                if(grid[row][j]==1)     helper(row,j,grid,cnt);
            }
            
            for(int col = 0;col< grid[0].size();col++){
                if(grid[i][col]==1)     helper(i,col,grid,cnt);
            }
        }
    }
    
    
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
       vector<vector<int>> t(m,vector<int> (n,0));
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int cnt = 0;
                    helper(i,j,grid,cnt);
                    if(cnt > 1)     ans += cnt;
                }
            }
        }
        return ans;
    }
};