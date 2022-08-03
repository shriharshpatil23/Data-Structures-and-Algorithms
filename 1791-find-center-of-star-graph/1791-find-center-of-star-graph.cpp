class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> graph[n+2];
        for(auto x : edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        for(int i=1;i<=n+1;i++){
            if(graph[i].size()==n)   return i; 
        }
        return -1;
    }
};