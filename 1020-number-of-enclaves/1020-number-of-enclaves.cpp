class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid ){
        if(i<0 || j<0 || i >=grid.size() || j>=grid[0].size()) return;
        if(grid[i][j]!=1)   return;
        grid[i][j]=0;
        //up
        dfs(i-1,j,grid);
        //left
        dfs(i,j-1,grid);
        //down
        dfs(i+1,j,grid);
        //right
        dfs(i,j+1,grid);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i==0 || i==grid.size()-1 || j==0 || j==grid[0].size()-1){
                    dfs(i,j,grid);
                }
            }
        }
        int cnt =0;
         for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)   cnt++;
            }
         }
        return cnt;
    }
};