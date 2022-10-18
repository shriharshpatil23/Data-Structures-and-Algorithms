class Solution {
public:
    
    /// Simple DFS ////
//     int m,n;
//     bool vis[41][41];
//     bool isValid(int i, int j, vector<vector<int>>&grid){
//         if(i<0 || i>=m || j<0|| j>=n || vis[i][j]==true)    return false;
//         return true;
//     }
//     int dfs(int i, int j, vector<vector<int>>&grid,int k){
//         if(i==0 && j==0)    return 0;
        
//         if(k==0 && (i!=0 && j!=0))  return 2000;
        
//         vis[i][j]=true;
        
//         int up = 2000;
//         int down = 2000;
//         int right = 2000;
//         int left = 2000;
//         //up
//         if(isValid(i,j-1,grid)){
//             if(grid[i][j-1]==1 && k>0){
//                 up = dfs(i,j-1,grid,k-1);
//             }else{
//                 up = dfs(i,j-1,grid,k);
//             }
//         }
//         //down
//         if(isValid(i,j+1,grid)){
//             if(grid[i][j+1]==1 && k>0){
//                 down = dfs(i,j+1,grid,k-1);
//             }else{
//                 down = dfs(i,j+1,grid,k);
//             }
//         }
//         //left
//         if(isValid(i-1,j,grid)){
//             if(grid[i-1][j]==1 && k>0){
//                 left = dfs(i-1,j,grid,k-1);
//             }else{
//                 left = dfs(i-1,j,grid,k);
//             }
//         }
//         //right
//         if(isValid(i+1,j,grid)){
//             if(grid[i+1][j]==1 && k>0){
//                 right = dfs(i+1,j,grid,k-1);
//             }else{
//                 right = dfs(i+1,j,grid,k);
//             }
//         }
//         return 1 + min({up,right,left,down});
//     }
//     int shortestPath(vector<vector<int>>& grid, int k) {
//         m=grid.size();
//         n=grid[0].size();
//         return dfs(m-1,n-1,grid,k);
    
    /// Simple BFS Solution /////
//      int solve(vector<vector<int>>& grid,int k){
// 		// At a particular cell we will store the number of obstacles that we can still remove after walking through that cell
//         vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),-1));
//         queue<vector<int>> q;
		
// 		// queue stores (x,y,current path length,number of obstacles we can still remove)
//         q.push({0,0,0,k});
//         while(!q.empty()){
//             auto t=q.front();
//             int x=t[0],y=t[1];
//             q.pop();
			
// 			// Exit if current position is outside of the grid
//             if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size()){
//                 continue;
//             }
			
// 			// Destination found
//             if(x==grid.size()-1 && y==grid[0].size()-1)
//                 return t[2];

//             if(grid[x][y]==1){
//                 if(t[3]>0) // If we encounter an obstacle and we can remove it
//                     t[3]--;
//                 else
//                     continue;
//             }
			
// 			// The cell was previously visited by some path and we were able to remove more obstacles from the previous path.
// 			// Then we don't need to continue on our current path
//             if(vis[x][y]!=-1 && vis[x][y]>=t[3])
//                 continue;
//             vis[x][y]=t[3];
            
//             q.push({x+1,y,t[2]+1,t[3]});
//             q.push({x,y+1,t[2]+1,t[3]});
//             q.push({x-1,y,t[2]+1,t[3]});
//             q.push({x,y-1,t[2]+1,t[3]});
            
//         }
//         return -1;
//     }
    
//     int shortestPath(vector<vector<int>>& grid, int k) {
//         return solve(grid,k);
    
        
        
        ////DFS with DP///////
        
        int dp[42][42][1609];
    const static int MAX = 1e7;
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        return help(grid, grid.size() - 1, grid[0].size() - 1, k, k);
    }
    
    int help(vector<vector<int>>& grid, int x, int y, int z, int k){
        
        //Reached destination
        if(x == 0 && y  == 0)return 0;
        
        //Already visited/calculated
        if(dp[x][y][z]) return dp[x][y][z];
        
        //Cant remove any more obstacles
        if(grid[x][y] == 1 && z == 0)return MAX;
        
        //Manhattan optimization
        if(z >= x + y)return dp[x][y][z] = x+y;
        
        //Make sure to take direction left and up before right and top
        vector<vector<int>> dirs = {{-1,0}, {0,-1}, {1,0}, {0,1}};
        
        //Setting dp[x][y][z] to MAX so that it does not gets calculated again 
        dp[x][y][z] = MAX;
        
        for(auto dir:dirs){
            //DFS valid condition
            if(x + dir[0] >= 0 && x + dir[0] < grid.size() && y + dir[1] >=0 && y + dir[1] < grid[0].size() ){
                dp[x][y][z] = min(dp[x][y][z], help(grid, x + dir[0], y + dir[1], z - grid[x][y], k) + 1);
            }
        }
        //If not possible
        if(z == k && x == grid.size() - 1 && y == grid[0].size() - 1 && dp[x][y][z] == MAX)return -1;
        return dp[x][y][z];
        
        
        
        
    }
};