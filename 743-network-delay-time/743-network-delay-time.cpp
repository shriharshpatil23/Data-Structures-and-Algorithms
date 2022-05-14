class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> vis(n+1,-1);
        vector<int> dist(n+1,INT_MAX);
        
 vector<vector<pair<int,int>>> vec(n+1);
        
        for(int i=0;i<times.size();i++){
        
           int j = times[i][0];
           vec[j].push_back({times[i][1],times[i][2]}); 
        }
        
         vector<int> signal(n+1,INT_MAX);
        
        queue<int> q;
        q.push(k);
        dist[k]=0;
        vis[k]=1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto x : vec[node]){
                int t= x.second ;
                int adj = x.first;
                int time = t + dist[node];
                if(time < dist[adj]){
                    vis[adj]=1;
                    q.push(adj);
                    dist[adj]=time;
                    
                }
            }
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(vis[i]==-1)  return -1;
            // cout<<dist[i];
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};