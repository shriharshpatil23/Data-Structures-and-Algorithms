class Solution {
    vector<int>dirx = {0,0,1,-1};
    vector<int>diry = {1,-1,0,0};
    int m, n;
public:
    bool insideBoundary(int x, int y){
        return (x>=0 and x<m and y>=0 and y<n);
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        m= maze.size();
        n=maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        queue<vector<int>>q;

        q.push({entrance[0], entrance[1], 0});
        visited[entrance[0]][entrance[1]]=true;
        while(!q.empty()){
            vector<int> top = q.front();q.pop();
            int x = top[0], y=top[1], dist=top[2];
            if((x==0 or x==m-1 or y==0 or y==n-1) and (x!=entrance[0] or y!=entrance[1]))return dist;
            for(int i=0;i<4;i++){
                int xx = x+ dirx[i];
                int yy = y+ diry[i];
                if(!insideBoundary(xx,yy))continue;
                if(!visited[xx][yy] and maze[xx][yy]=='.'){
                    visited[xx][yy]=true;
                    q.push({xx,yy, dist+1});
                }
            }
        }
        return -1;
        
    }
};