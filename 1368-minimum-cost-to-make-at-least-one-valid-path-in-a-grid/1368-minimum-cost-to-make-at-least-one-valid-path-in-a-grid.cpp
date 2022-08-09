class Solution {
public:
    bool vis[101][101];
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        deque<pair<pair<int,int>,int>> q;
        q.push_back({{0,0},0});
        vis[0][0]=true;
        memset(vis,false,sizeof(vis));
        while(!q.empty()){
            auto fr = q.front();
            q.pop_front();
            int x = fr.first.first;
            int y = fr.first.second;
            int cost = fr.second;         
            
            if(x<0 || x>=m || y<0 || y>=n || vis[x][y]) continue;
            
            if(x==m-1 && y==n-1)    return cost;
            
           vis[x][y]=true;
            
            for(int d=0;d<4;d++){
                int i = x + dir[d][0];
                int j = y + dir[d][1];
                
                if(i<0 || i>=m || j<0 || j>=n || vis[i][j]) continue;
                
                int curr_cost;
                if(grid[x][y]==1 && dir[d][0]==0 && dir[d][1]==1)   curr_cost = 0;
                else    if(grid[x][y]==2 && dir[d][0]==0 && dir[d][1]==-1)   curr_cost=0;
                else    if(grid[x][y]==3 && dir[d][0]==1 && dir[d][1]==0)   curr_cost=0;
                else    if(grid[x][y]==4 && dir[d][0]==-1 && dir[d][1]==0)   curr_cost=0;
                else    curr_cost=1;
                
                if(curr_cost==1) q.push_back({{i,j},cost+1});
                else    q.push_front({{i,j},cost});
            }
        }
        return -1;
    }
};