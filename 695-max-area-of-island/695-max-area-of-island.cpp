class Solution {
public:
   int dfs(vector<vector<int>>& grid ,int row,int col, vector<vector<int>>&visited)
    {
        //base condition
        if(row<0 || row>=grid.size() ||col<0 || col>=grid[0].size() || grid[row][col]==0)return 0;
        if(visited[row][col]==1)return 0;
        visited[row][col]=1;
        int left= dfs(grid,row,col-1,visited);
        int right=dfs(grid,row,col+1,visited);
        int up= dfs(grid,row-1,col,visited);
        int down=dfs(grid,row+1,col,visited);
        return 1 + left + right +up + down;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>>visited(row,vector<int>(col,0));
        int ans=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1 && visited[i][j]==0){
                    int area=dfs(grid,i,j,visited);
                    ans=max(ans,area);
                }
            }
        }
        return ans==0?0:ans;
    }
};