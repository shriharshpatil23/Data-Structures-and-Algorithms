class Solution {
public:
    bool visPac[201][201];
    bool visAtl[201][201];
    int m,n;
    bool isValid(int i, int j, vector<vector<int>>&heights){
        if(i<0 || i>=m || j<0 || j>=n )    return false;    
        
        return true;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        memset(visPac,false,sizeof(visPac));
        memset(visAtl,false,sizeof(visAtl));
        m = heights.size();
        vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        n = heights[0].size();
        queue<pair<int,int>> q,pq;
        //for pacific Ocean
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0){
                    q.push({i,j});
                    visPac[i][j]=true;
                }
            }
        }
        while(!q.empty()){
            auto fr = q.front();
            q.pop();
            int x = fr.first;
            int y = fr.second;
            for(int d =0;d<4;d++){
                int i = x + dir[d][0];
                int j = y + dir[d][1];
                if(isValid(i,j,heights) && !visPac[i][j] && heights[i][j]>=heights[x][y]){
                    visPac[i][j]=true;
                    q.push({i,j});
                }
            }
        }
        //for Atlantic Ocean
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==m-1 || j==n-1){
                    pq.push({i,j});
                    visAtl[i][j]=true;
                }
            }
        }
        while(!pq.empty()){
            auto fr = pq.front();
            pq.pop();
            int x = fr.first;
            int y = fr.second;
            for(int d =0;d<4;d++){
                int i = x + dir[d][0];
                int j = y + dir[d][1];
                if(isValid(i,j,heights) && !visAtl[i][j] && heights[i][j]>=heights[x][y]){
                    visAtl[i][j]=true;
                    pq.push({i,j});
                }
            }
        }
        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visPac[i][j] && visAtl[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};