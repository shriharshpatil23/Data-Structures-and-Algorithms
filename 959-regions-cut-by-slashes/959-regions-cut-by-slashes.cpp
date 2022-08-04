class Solution {
public:
    int dfs(int i, int j, vector<vector<int>> &vec){
        if(i<0 || i>=vec.size() || j<0 || j>=vec.size() || vec[i][j]==1)    return 0;
        vec[i][j]=1;
        return 1 + dfs(i+1,j,vec) + dfs(i,j+1,vec)+dfs(i-1,j,vec)+dfs(i,j-1,vec);
        
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();//    memset(vis,false,sizeof(vis));
        vector<vector<int>> vec(n*3,vector<int> (n*3 ,0));
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]=='/')
                    vec[i*3][j*3 +2] = vec[i*3 +1][j*3 +1] = vec[i*3 +2][j*3 ] = 1;
                else   if(grid[i][j]=='\\')
                            vec[i*3][j*3] = vec[i*3 +1][j*3 +1] = vec[i*3 +2][j*3 +2] = 1;
            }
        }
        int ans = 0;
        for(int i=0;i<n*3;i++){
            for(int j=0;j<n*3;j++){
                ans += dfs(i,j,vec)?1:0;
            }
        }
        return ans;
    }
};