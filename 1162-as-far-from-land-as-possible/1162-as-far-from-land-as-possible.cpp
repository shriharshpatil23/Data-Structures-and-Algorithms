class Solution {
public:
    bool vis[101][101];
    bool isValid(int i, int j , vector<vector<int>>&grid){
        if(i<0 || i>=grid.size() || j<0 || j>=grid.size() || vis[i][j]==true ||grid[i][j]==1)   return false;
        
        return true;
    }
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        memset(vis,false,sizeof(vis));
        int n = grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }   
            }
        }
        int dist = 0;
        if(q.size()==n*n)   return -1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                pair<int,int> p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                vis[x][y]=true;
                //up
                if(isValid(x-1,y,grid)){
                    q.push({x-1,y});
                    vis[x-1][y]=true;
                }
                //down
                if(isValid(x+1,y,grid)){
                    q.push({x+1,y});
                    vis[x+1][y]=true;
                }
                //right
                if(isValid(x,y+1,grid)){
                    q.push({x,y+1});
                    vis[x][y+1]=true;
                }
                //left
                if(isValid(x,y-1,grid)){
                    q.push({x,y-1});
                    vis[x][y-1]=true;
                }
            }
            dist++;
        }
        return dist-1;
    }
};