class Solution {
public:
    int m,n;
    int old_color;
    bool isValid(int i, int j ){
        if(i<0 || i>=m || j<0 || j>=n)  return false;
        
        return true;
    }
    
    bool isBorder(int i, int j, vector<vector<int>> &grid){
        if(i==m-1 || j ==n-1 || i==0 || j==0)   return true;
        
        int ctr = 0;
        //up
        if(grid[i-1][j]==-old_color)    ctr++;
        //down
        if(grid[i+1][j]==-old_color)    ctr++;
        //right
        if(grid[i][j+1]==-old_color)    ctr++;
        //left
        if(grid[i][j-1]==-old_color)    ctr++;
        
        if(ctr==4)  return false;
        
        return true;
    }
    void dfs(int i, int j, vector<vector<int>>&grid){
        grid[i][j]=-1*old_color;
        //
        if(isValid(i-1,j) && grid[i-1][j]==old_color){
            dfs(i-1,j,grid);
        }
        //down
        if(isValid(i+1,j) && grid[i+1][j]==old_color){
            dfs(i+1,j,grid);
        }
        //right
        if(isValid(i,j+1) && grid[i][j+1]==old_color){
            dfs(i,j+1,grid);
        }
        //left
        if(isValid(i,j-1) && grid[i][j-1]==old_color){
            dfs(i,j-1,grid);
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        m = grid.size();
        n = grid[0].size();
        old_color = grid[row][col];
        dfs(row,col,grid);
        vector<vector<int>> ans(m,vector<int> (n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==-old_color && isBorder(i,j,grid))    ans[i][j]=color;
                else    if(grid[i][j]==-old_color)   ans[i][j]=-grid[i][j];
                else    ans[i][j]=grid[i][j];
            }
        }
        return ans;
    }
};