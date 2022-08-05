class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m+1,vector<bool> (n+1,false));
        vector<vector<int>> dp(m+1,vector<int> (n+1,1e9));
        deque<pair<int,int>> dq;
        dq.push_front({0,0});
        dp[0][0]=0;
        while(!dq.empty()){
            auto fr = dq.front();
            dq.pop_front();
            int x = fr.first;
            int y = fr.second;
            for(int d=0;d<4;d++){
                int i = x + dir[d][0];
                int j = y + dir[d][1];
                if(i>=0 && i<=m-1 && j>=0 && j<=n-1 && vis[i][j]==false){
                    dp[i][j] = dp[x][y] + grid[i][j]; 
                    if(grid[i][j]==1){
                        dq.push_back({i,j});
                    }else{
                        dq.push_front({i,j});
                    }
                    vis[i][j]=true;
                }
            }
        }
        return dp[m-1][n-1];
    }
};