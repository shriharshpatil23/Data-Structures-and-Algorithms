class Solution {
public:
    bool vis[101][101];
    bool isValid(int i,int j, vector<vector<int>>& grid){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==1 || vis[i][j]==true)   return false;
        
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        memset(vis,false,sizeof(vis));
        queue<pair<int,int>> q;
        if(grid[0][0]==0){
            q.push({0,0});
            vis[0][0]=true;
        }
        
        int ans = 0;
        while(!q.empty()){
            int nodesPushed = q.size();
            ans++;
            
            for(int cnt = 0; cnt < nodesPushed; cnt++){
                
                pair<int, int> frontNode = q.front();
                q.pop();
            
                int i = frontNode.first, j = frontNode.second;

                if(i==grid.size()-1 and j==grid.size()-1) return ans;

                for(int k = i - 1; k <= i + 1 ; k++){
                    for(int l = j - 1; l <= j + 1; l++){
                        if(isValid( k, l,grid)){
                            q.push({k, l});
                            vis[k][l] = true;
                        }
                    }
                }                
                
            }            
            
        }
        return -1;
    }
};