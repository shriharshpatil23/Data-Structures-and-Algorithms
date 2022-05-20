class Solution {
public:
    int t[101][101];
    
    bool isValid(int i,int j,vector<vector<int>>& grid){
        if(i<0 || i>=grid.size() || j<0 || j>= grid[0].size() || grid[i][j]==1) return false;
        
        return true;
    }
    
    int helper(int i,int j,vector<vector<int>>& obstacleGrid){
        if(isValid(i,j,obstacleGrid)==false)    return 0;
        
        if(i==obstacleGrid.size()-1 && j== obstacleGrid[0].size()-1)  return 1;
        
        if(t[i][j]!= -1)    return t[i][j];
        
        //down
        int down = helper(i+1,j,obstacleGrid);
        //right
        int right = helper(i,j+1,obstacleGrid);
        
        return t[i][j] = down + right;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(t,-1,sizeof(t));
        int ans = helper(0,0,obstacleGrid);
        return ans;
    }
};