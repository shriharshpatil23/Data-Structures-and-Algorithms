class Solution {
public:
    int m ;
    int n ;
    int t[101][101];
    bool isValid(int i, int j ,vector<vector<int>> &grid ){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==1) return false;
        
        return true;
    }
    
    int helper(int i, int j , vector<vector<int>> &grid){
        if(i==0 && j==0)    return t[i][j]=1;
        
        if(!isValid(i,j,grid))  return 0;
        
        if(t[i][j] != -1)   return t[i][j];
        
        //up
        int up = helper(i-1,j,grid);
        //left
        int left = helper(i,j-1,grid);
        
        return t[i][j]=up + left;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        memset(t,-1,sizeof(t));
        m = grid.size();
        n = grid[0].size();
        if(grid[m-1][n-1]==1 || grid[0][0]==1)  return 0;
        return helper(m-1,n-1,grid);
    }
};