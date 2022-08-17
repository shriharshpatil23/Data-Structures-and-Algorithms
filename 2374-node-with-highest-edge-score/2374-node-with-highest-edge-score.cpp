class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++){
            graph[edges[i]].push_back(i);
        }
        int ans = -1;
        long long int max_sum = -1;
        for(int i=0;i<n;i++){
            long long int curr_sum  = 0;
            for(auto x : graph[i])  curr_sum += x;
            
            if(curr_sum>max_sum)    ans=i , max_sum = curr_sum;
        }
        return ans;
    }
};