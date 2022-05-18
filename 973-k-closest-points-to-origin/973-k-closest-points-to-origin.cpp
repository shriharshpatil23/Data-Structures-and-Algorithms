class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue <pair<long long,pair<int,int>>, vector<pair<long long,pair<int,int>>>, greater<pair<long long,pair<int,int>>> > q;
        vector<vector<int>> ans;
        for(auto x : points){
            long long temp = x[0]*x[0] + x[1]*x[1];
            q.push({temp,{x[0],x[1]}});
        }
        while(k--){
            pair<long,pair<int,int>> tp = q.top();
            pair<int,int> co = tp.second;
            ans.push_back({co.first,co.second});
            q.pop();
        }
        return ans;
    }
};