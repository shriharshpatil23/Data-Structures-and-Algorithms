class Solution {
public:
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
    
    
     int solve(vector<vector<int>>& grid,int k){
		// At a particular cell we will store the number of obstacles that we can still remove after walking through that cell
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),-1));
        queue<vector<int>> q;
		
		// queue stores (x,y,current path length,number of obstacles we can still remove)
        q.push({0,0,0,k});
        while(!q.empty()){
            auto t=q.front();
            int x=t[0],y=t[1];
            q.pop();
			
			// Exit if current position is outside of the grid
            if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size()){
                continue;
            }
			
			// Destination found
            if(x==grid.size()-1 && y==grid[0].size()-1)
                return t[2];

            if(grid[x][y]==1){
                if(t[3]>0) // If we encounter an obstacle and we can remove it
                    t[3]--;
                else
                    continue;
            }
			
			// The cell was previously visited by some path and we were able to remove more obstacles from the previous path.
			// Then we don't need to continue on our current path
            if(vis[x][y]!=-1 && vis[x][y]>=t[3])
                continue;
            vis[x][y]=t[3];
            
            q.push({x+1,y,t[2]+1,t[3]});
            q.push({x,y+1,t[2]+1,t[3]});
            q.push({x-1,y,t[2]+1,t[3]});
            q.push({x,y-1,t[2]+1,t[3]});
            
        }
        return -1;
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        return solve(grid,k);
    
    }
};