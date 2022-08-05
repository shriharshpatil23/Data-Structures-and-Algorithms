class Solution {
public:
    int m,n;
    int helper(int i, int j, vector<vector<int>> &grid){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]<=0)  return 0;
        
        grid[i][j] = -grid[i][j];
        
        //up
        int up = helper(i-1,j,grid);
        //down
        int down = helper(i+1,j,grid);
        //right
        int right = helper(i,j+1,grid);
        //left
        int left = helper(i,j-1,grid);
        
        grid[i][j] = -grid[i][j];
        
        return grid[i][j] + max({up,down,right,left});
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int ans  = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    ans = max(ans,helper(i,j,grid));
                }
            }
        }
        return ans;
    }
};