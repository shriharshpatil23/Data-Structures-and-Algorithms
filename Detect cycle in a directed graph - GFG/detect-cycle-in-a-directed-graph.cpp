// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool checkCycle(int src, vector<int> adj[], vector<bool> &vis, vector<bool> &dfsVis){
        vis[src] = true;
        dfsVis[src]= true;
        for(auto x : adj[src]){
            if(!vis[x]){
                if(checkCycle(x,adj,vis,dfsVis))    return true;
            }else   if(dfsVis[x])   return true;
        }
        dfsVis[src]=false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V+1,false);
        vector<bool> dfsVis(V+1,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(checkCycle(i,adj,vis,dfsVis))   return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends