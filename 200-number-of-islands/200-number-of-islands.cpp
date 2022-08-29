class Solution {
public:
    int m,n;
    bool vis[301][301];
    vector<vector<int>> dir;
    bool isValid(int i, int j, vector<vector<char>>&grid){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]=='0' || vis[i][j]==true) return false;
        
        return true;
    }
    void dfs(int i, int j, vector<vector<char>>&grid){
        vis[i][j]=true;
        
        for(int d=0;d<4;d++){
            int x = i+dir[d][0];
            int y = j+dir[d][1];
            if(isValid(x,y,grid))   dfs(x,y,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        dir = {{-1,0},{1,0},{0,-1},{0,1}};
        memset(vis,false,sizeof(vis));
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]&&grid[i][j]=='1'){
                    dfs(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};