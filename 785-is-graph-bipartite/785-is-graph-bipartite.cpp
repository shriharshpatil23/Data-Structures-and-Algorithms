class Solution {
public:
    bool Bipartite(int src , vector<int> &color , vector<vector<int>> &graph){
        
        //************* Using BFS *****************//
        // queue<int> q;
        // q.push(src);
        // color[src]=1;
        // while(!q.empty()){
        //     int node = q.front();
        //     q.pop();
        //     for(auto x : graph[node]){
        //         if(color[x]==-1){
        //             color[x]= 1 - color[node];
        //             q.push(x);
        //         }else{
        //             if(color[x]==color[node])   return false;
        //         }
        //     }
        // }
        // return true;
        
        //******************* Using DFS ******************//
        if(color[src]==-1)  color[src]=1;
        
        for(auto x : graph[src]){
            if(color[x]==-1){
                color[x]= 1 - color[src];
                if(!Bipartite(x,color,graph))   return false;
            }else    if(color[x]==color[src])    return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!Bipartite(i,color,graph))   return false;
            }
        }
        return true;
    }
};