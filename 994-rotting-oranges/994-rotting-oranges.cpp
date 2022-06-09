class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==0)    return 0;
        
        queue<pair<int,int>> q;
        int total  = 0 , cnt = 0, time = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!= 0)  total ++;
                if(grid[i][j]==2)   q.push({i,j});
            }
        }
        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        while(!q.empty()){
            int k = q.size();
            cnt += k;
            while(k--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx<0 || nx>=grid.size() || ny<0 || ny>=grid[0].size() || grid[nx][ny]!= 1)   continue;
                    
                    grid[nx][ny]=2;
                    q.push({nx,ny});
                }
            }
            if(!q.empty())  time++;
        }
        if(cnt == total)    return time;
        return -1;
    }
};