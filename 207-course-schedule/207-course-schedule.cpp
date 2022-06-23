class Solution {
public:
    int vis[2001];
    
    bool topoSort(int i, vector<int> adj[]){
        if(vis[i]==1)   return true;
        
        if(vis[i]==-1){
            vis[i]=1;
            for(auto edge : adj[i]){
                if(topoSort(edge,adj))  return true;
            }
        }
        vis[i]=2;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        memset(vis,-1,sizeof(vis));
        vector<int> adj[n];
        for(auto edge : prerequisites)    adj[edge[1]].push_back(edge[0]);
        
        for(int i=0;i<n;i++){
            if(topoSort(i,adj)) return false;
        }
        return true;
    }
};