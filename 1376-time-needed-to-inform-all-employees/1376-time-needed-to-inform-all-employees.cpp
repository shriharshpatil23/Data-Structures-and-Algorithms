class Solution {
public:
    void dfs(int i, unordered_map<int,vector<int>> &graph,vector<int>& informTime, int &ans, int curr){
        curr += informTime[i];
        ans = max(ans,curr);
        
        for(auto x = graph[i].begin(); x != graph[i].end() ;x++ ){
            dfs(*x, graph,informTime,ans,curr);
        }
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int> > graph;
        
        for(int i=0;i<n;i++){
            if(manager[i]!=-1)  graph[manager[i]].push_back(i);
        }
        int ans = 0;
        dfs(headID, graph,informTime,ans,0);
        return ans;
    }
};