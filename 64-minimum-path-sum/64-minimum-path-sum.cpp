class Solution {
public:
    int t[201][201];
    int helper(int i, int j , vector<vector<int>>& grid){
        if(i==0 && j==0)    return t[i][j] = grid[0][0];
        
        if(i<0 || i>=grid.size() || j < 0 || j>=grid[0].size()) return 20000;
        
        if(t[i][j]!= -1)    return t[i][j];
        
        int up = grid[i][j] + helper(i-1,j,grid);
        int down = grid[i][j] + helper(i,j-1,grid);
        
        return t[i][j] = min(up,down);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memset(t,-1,sizeof(t));
        return helper(m-1,n-1,grid);
    }
};