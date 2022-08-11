class Solution {
public:
    
    void dfs(int src , vector<vector<int>> &graph ,set<pair<int,int>>&s, int &ans,vector<bool>&vis){
        vis[src]=true;
        for(auto x : graph[src]){
            if(!vis[x]){
                pair p = {src,x};
                if(s.find(p)!=s.end()) ans++;
                dfs(x,graph,s,ans,vis);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        vector<bool> vis(n+1,false);
        set<pair<int,int>> s;
        for(int i=0;i<connections.size();i++){
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
            s.insert({connections[i][0],connections[i][1]});
        }
        int ans = 0;
        dfs(0,graph,s,ans,vis);
        return ans;
    }
};