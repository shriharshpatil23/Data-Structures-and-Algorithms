class Solution {
public:
    void dfs(int s, int d, vector<vector<int>> &graph,vector<bool> &vis, bool &flg){
        if(s==d)   flg = true ;
        
        vis[s]=true;
        for(auto x : graph[s]){
            if(!vis[x]){
                dfs(x,d,graph,vis,flg);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n+1);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(n+1,false);
        bool flg = false;
        dfs(source,destination,graph,vis,flg);
        return flg;
    }
};