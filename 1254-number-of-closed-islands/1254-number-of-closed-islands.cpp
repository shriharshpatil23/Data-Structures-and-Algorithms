class Solution {
public:
    bool vis[101][101];
    void dfs(int i, int j, bool &flg, vector<vector<int>> &grid){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==1 || vis[i][j]==true) return;
        
        if(i==0 || i==grid.size()-1 || j==0 || j==grid[0].size()-1){
            flg = false;
        }
        vis[i][j]=true;
        //up 
        dfs(i-1,j,flg,grid);
        //down
        dfs(i+1,j,flg,grid);
        //right
        dfs(i,j+1,flg,grid);
        //left
        dfs(i,j-1,flg,grid);
        
    }
    int closedIsland(vector<vector<int>>& grid) {
        memset(vis,false,sizeof(vis));
        int ans=0;
        for(int i=1;i<grid.size()-1;i++){
            for(int j=1;j<grid[0].size()-1;j++){
                if(grid[i][j]==0 && !vis[i][j]){
                    bool flg  = true;
                    dfs(i,j,flg,grid);
                    if(flg) ans++;
                }
            }
        }
        return ans;
    }
};