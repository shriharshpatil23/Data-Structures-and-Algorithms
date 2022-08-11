class Solution {
public:
    void helper(int src, int target, vector<vector<int>>&graph , vector<vector<int>>&ans , vector<int> tmp)     {
        if(src==target){
            tmp.push_back(target);
            ans.push_back(tmp);
        }
        for(auto x : graph[src]){
            tmp.push_back(src);
            helper(x,target,graph,ans,tmp);
            tmp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        helper(0,n-1,graph,ans,{});
        return ans;
    }
};